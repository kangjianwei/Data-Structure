#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager.h"

/*
 * 存储紧缩算法
 *
 * 该算法的实现过程与存储管理方案息息相关。
 * 此处的紧缩算法是建立在自己实现的MemoryManager之上的。
 * 如果有别的存储管理方案，那么紧缩算法也需要随之改变。
 *
 * 具体步骤的描述参见教材。
 */
void Algo_8_16(Space* space);

// 依照内存记录的首地址对内存记录进行排序时用到的比较器，该方法仅限内部使用
static int qsortCompar(const void* r1, const void* r2);

// 查找一条内存记录的索引，该内存记录拥有旧地址oldAddr，该方法仅限内部使用
static int search(Space space, int oldAddr);

// 对习题8.10给出的数据进行测试
void Test_8_10(Space* space, char* path);

// 使用自定义的测试数据，这里还可以测试用户变量的变更情况
void TestCustom(Space* space, int* p[]);


int main(int argc, char** argv) {

//    printf("=== 使用习题8.10中的测试数据 ===\n\n");
//    {
//        Space space;
//
//        // 初始化一片可用的存储
//        InitSpace(&space);
//        printf("初始内存布局：\n");
//        PrintMemoryLayout(space);
//
//        // 测试习题8.10的数据
//        Test_8_10(&space, "TestData_8_10.md");
//        printf("习题8.10中的内存布局：\n");
//        PrintMemoryLayout(space);
//
//        // 存储紧缩
//        Algo_8_16(&space);
//        printf("进行存储紧缩后的内存布局：\n");
//        PrintMemoryLayout(space);
//    }
    
    printf("=== 使用自定义的测试数据 ===\n\n");
    {
        Space space;
        int* p[10]; // 用户变量表(虚拟地址)
        char* data = (char*)malloc(sizeof(char));

        // 初始化一片可用的存储
        InitSpace(&space);
        printf("初始内存布局：\n");
        PrintMemoryLayout(space);

        // 自定义数据
        TestCustom(&space, p);

        // 存储紧缩
        Algo_8_16(&space);
        printf("进行存储紧缩后的内存布局：\n");
        PrintMemoryLayout(space);

        printf("对照内存布局，验证用户变量是否已经同步更新：\n");
        memmove(data, getPtr(space, p[9]), 1);
        printf("p10 = %d\n", *data);
        memmove(data, getPtr(space, p[6]), 1);
        printf("p7  = %d\n", *data);
        memmove(data, getPtr(space, p[7]), 1);
        printf("p8  = %d\n", *data);
        memmove(data, getPtr(space, p[5]), 1);
        printf("p6  = %d\n", *data);
        memmove(data, getPtr(space, p[8]), 1);
        printf("p9  = %d\n", *data);
    }
    
}


/*
 * 存储紧缩算法
 *
 * 该算法的实现过程与存储管理方案息息相关。
 * 此处的紧缩算法是建立在自己实现的MemoryManager之上的。
 * 如果有别的存储管理方案，那么紧缩算法也需要随之改变。
 *
 * 具体步骤的描述参见教材。
 */
void Algo_8_16(Space* space) {
    Record* r;
    int len;
    int i, j, k, count;
    int busy, free;
    int* oldPtr;    // 记录旧的虚拟地址
    
    // 当前包含的内存使用记录条数
    len = ListLength(space->recordList);
    
    /* 0. 对内存记录表进行排序，这有利于后续的内存数据迁移 */
    qsort(space->recordList.elem, len, sizeof(ElemType), qsortCompar);
    
//    printf("日志0. 对内存记录进行排序（至此，只完成了对首地址的顺序）：\n");
//    PrintMemoryLayout(*space);
    
    
    /* 1. 确定经过存储紧缩后，各内存块的新地址，换句话说，经过此步骤，可以生成一个新旧地址对照表 */
    
    free = 0;   // 统计空闲块的大小
    busy = 0;   // 统计占用块的大小，以确定各占用块的新地址
    count = 0;  // 统计紧缩后的内存块数量
    j = 0;
    
    for(i = 1; i <= len; i++) {
        GetElem(space->recordList, i, (ElemType*) &r);
        
        // 忽略空闲块，但是要统计它的大小
        if(r->tag == 0) {
            free += r->size;
            continue;
        }
        
        // 先统计占用块数量
        count++;
        
        // 收集占用块，更新其地址信息
        r->oldAddr = r->addr;
        r->addr = busy;
        busy += r->size;
        
        // 把新的占用块信息排列到链表前面
        space->recordList.elem[j++] = r;
    }
    
    // 记录空闲块的信息
    if(free != 0) {
        // 必须重新分配内存
        r = (Record*) malloc(sizeof(Record));
        r->addr = busy;
        r->size = free;
        r->tag = 0;
        r->oldAddr = -1;
        
        space->recordList.elem[j] = r;
        
        count++;
        
        // 指向最新的空闲块的记录
        space->cur = count;
    }
    
    // 内存使用记录的新长度
    space->recordList.length = count;
    
//    printf("日志1. 计算新旧地址对照表（至此，只完成了\"占用\"内存的前移，以及\"空闲\"内存的合并）：\n");
//    PrintMemoryLayout(*space);
    
    
    /* 2. 检查用户变量表，更新虚拟地址，以便紧缩之后的变量可以正常工作 */
    
    // 用户变量表长度
    len = ListLength(space->ptrList);
    
    for(i = 0; i < len; i++) {
        oldPtr = space->ptrList.elem[i];
        
        // 获取旧地址在内存记录表中的索引
        k = search(*space, *oldPtr);
        
        // 更新为新地址
        *oldPtr = ((Record*) (space->recordList.elem[k]))->addr;
    }
    
//    printf("日志2. 用户变量表更新完成（至此，用户变量(虚拟地址指针)已经指向了正确的内存，但是数据显示还不正常：\n");
//    PrintMemoryLayout(*space);
    
    
    /* 3. 检查链接，更新前驱和后继 */
    
    len = ListLength(space->recordList);
    
    for(i = 1; i <= len; i++) {
        GetElem(space->recordList, i, (ElemType*) &r);
    
        // 遇到空闲块时，可以结束循环了
        if(r->tag==0) {
            break;
        }
        
        if(r->pre != -1) {
            k = search(*space, r->pre);
            r->pre = ((Record*) (space->recordList.elem[k]))->addr;
        }
        
        if(r->next != -1) {
            k = search(*space, r->next);
            r->next = ((Record*) (space->recordList.elem[k]))->addr;
        }
    }
    
//    printf("日志3. 内存记录中的前驱和后继已经可以正常显示：\n");
//    PrintMemoryLayout(*space);
    
    
    /* 4. 迁移用户数据 */
    
    for(i = 1; i <= len; i++) {
        GetElem(space->recordList, i, (ElemType*) &r);
        
        // 紧缩后的空闲记录一定是排在最后的，所以遇到空闲记录时，就可以结束循环了
        if(r->tag == 0) {
            // 将该地址对应的内存处的数据抹掉(这是个可选操作)
            memset(getPtr(*space, &(r->addr)), 0, r->size * BYTE);
            break;
        }
        
        // 如果新旧地址一样，则无需迁移数据
        if(r->addr == r->oldAddr) {
            continue;
        }
        
        memmove(space->base + r->addr * BYTE, space->base + r->oldAddr * BYTE, r->size);
    }
    
//    printf("日志4. 数据迁移完成（至此，可以正常显示所有参数和用户数据：\n");
//    PrintMemoryLayout(*space);
    
}

// 使用自定义的测试数据，这里还可以测试用户变量的变更情况
void TestCustom(Space* space, int* p[]) {
    
    printf("+ 为 p1 申请10个内存，并向此内存中写入数据 1 ...\n");
    p[0] = AllocMemory(space, 10);
    memset(getPtr(*space, p[0]), 1, 1);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p2 申请50个内存，并向此内存中写入数据 2 ...\n");
    p[1] = AllocMemory(space, 50);
    memset(getPtr(*space, p[1]), 2, 1);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p3 申请20个内存，并向此内存中写入数据 3 ...\n");
    p[2] = AllocMemory(space, 20);
    memset(getPtr(*space, p[2]), 3, 1);
    PrintMemoryLayout(*space);
    
    printf("- 释放 p2 处的50个内存...\n");
    FreeMemory(space, p[1]);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p4 申请5个内存，并向此内存中写入数据 4 ...\n");
    p[3] = AllocMemory(space, 5);
    memset(getPtr(*space, p[3]), 4, 1);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p5 申请10个内存，并向此内存中写入数据 5 ...\n");
    p[4] = AllocMemory(space, 10);
    memset(getPtr(*space, p[4]), 5, 1);
    PrintMemoryLayout(*space);
    
    printf("- 释放 p4 处的5个内存...\n");
    FreeMemory(space, p[3]);
    PrintMemoryLayout(*space);
    
    printf("- 释放 p3 处的20个内存...\n");
    FreeMemory(space, p[2]);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p6 申请15个内存，并向此内存中写入数据 6 ...\n");
    p[5] = AllocMemory(space, 15);
    memset(getPtr(*space, p[5]), 6, 1);
    ((Record*)(space->recordList.elem[2]))->pre = 25;
    ((Record*)(space->recordList.elem[2]))->next = 0;
    PrintMemoryLayout(*space);
    
    printf("+ 为 p7 申请10个内存，并向此内存中写入数据 7 ...\n");
    p[6] = AllocMemory(space, 10);
    memset(getPtr(*space, p[6]), 7, 1);
    ((Record*)(space->recordList.elem[4]))->pre = 60;
    ((Record*)(space->recordList.elem[4]))->next = -1;
    PrintMemoryLayout(*space);
    
    printf("+ 为 p8 申请15个内存，并向此内存中写入数据 8 ...\n");
    p[7] = AllocMemory(space, 15);
    memset(getPtr(*space, p[7]), 8, 1);
    ((Record*)(space->recordList.elem[7]))->pre = -1;
    ((Record*)(space->recordList.elem[7]))->next = 15;
    PrintMemoryLayout(*space);
    
    printf("- 释放 p5 处的10个内存...\n");
    FreeMemory(space, p[4]);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p9 申请5个内存，并向此内存中写入数据 9 ...\n");
    p[8] = AllocMemory(space, 5);
    memset(getPtr(*space, p[8]), 9, 1);
    ((Record*)(space->recordList.elem[3]))->pre = 15;
    ((Record*)(space->recordList.elem[3]))->next = 60;
    PrintMemoryLayout(*space);
    
    printf("- 释放 p1 处的10个内存...\n");
    FreeMemory(space, p[0]);
    PrintMemoryLayout(*space);
    
    printf("+ 为 p10 申请5个内存，并向此内存中写入数据 10 ...\n");
    p[9] = AllocMemory(space, 5);
    memset(getPtr(*space, p[9]), 10, 1);
    ((Record*)(space->recordList.elem[0]))->pre = -1;
    ((Record*)(space->recordList.elem[0]))->next = -1;
    PrintMemoryLayout(*space);
    
}

// 对习题8.10给出的数据进行测试
void Test_8_10(Space* space, char* path) {
    FILE* fp;
    
    char line[100]; // 缓存读取到的行
    char* p;        // 指向分解出来的数字
    
    Record* record;
    
    // 每行读取到的数据
    int addr;
    int size;
    int tag;
    int pre;
    int next;
    
    // 记录虚拟地址
    int* free[100];
    int* ptr;
    
    int count;
    int i;
    
    char data;  // 用于验证数据迁移的测试数据
    
    fp = fopen(path, "r");
    
    // 没有有效内容，则直接返回空的顺序表
    if(fp == NULL) {
        return;
    }
    
    // 舍弃属于表头的前两行
    fgets(line, 100, fp);
    fgets(line, 100, fp);
    
    count = 0;
    i = 0;
    data = 0;
    
    // 如果没有到达文件尾，则一直读取
    while(fgets(line, 100, fp)!=NULL) {
        
        // 首地址
        p = strtok(line, " |\n\r");
        addr = atoi(p);
        
        // 块大小
        p = strtok(NULL, " |\n\r");
        size = atoi(p);
        
        // 标志域
        p = strtok(NULL, " |\n\r");
        tag = atoi(p);
        
        // 前驱地址
        p = strtok(NULL, " |\n\r");
        pre = atoi(p);
        
        // 后继地址
        p = strtok(NULL, " |\n\r");
        next = atoi(p);
        
        // 申请size个内存
        ptr = AllocMemory(space, size);
        
        // 获取刚刚创建的内存记录的指针，完成前驱和后继的初始化
        record = space->recordList.elem[i++];
        record->pre = pre;
        record->next = next;
        
        /*
         * 为刚刚申请的内存赋值，这是为了测试后续的数据迁移是否成功。
         * 注意这里赋值时要将虚拟地址转换为真实地址。
         */
        memset(getPtr(*space, ptr), ++data, 1);
        
        if(tag == 0) {
            // 该地址处的内存后续需要释放
            free[count++] = ptr;
        }
    }
    
    fclose(fp);
    
    // 释放内存
    for(i = 0; i < count; i++) {
        FreeMemory(space, free[i]);
    }
}

// 依照内存记录的首地址对内存记录进行排序时用到的比较器，该方法仅限内部使用
static int qsortCompar(const void* r1, const void* r2) {
    Record* record1 = *((Record**) r1);
    Record* record2 = *((Record**) r2);
    
    return record1->addr - record2->addr;
}

/*
 * 查找一条内存记录的索引，该内存记录拥有旧地址oldAddr
 *
 * 注：这个查找其实很低效，因为：
 * 　　首先，这个查找本身是顺序查找，效率不高；
 * 　　其次，这个查找会被大量重复调用，更导致总效率低效。
 * 　　更好的算法是使用后续学到的哈希表，将新旧地址存储到哈希表中会极大地加快查找速度。
 *
 * 该方法仅限内部使用
 */
static int search(Space space, int oldAddr) {
    int k;
    
    for(k = 0; k < space.recordList.length; k++) {
        // 找到了匹配的旧地址值
        if(oldAddr == ((Record*) (space.recordList.elem[k]))->oldAddr) {
            return k;
        }
    }
    
    return -1;
}
