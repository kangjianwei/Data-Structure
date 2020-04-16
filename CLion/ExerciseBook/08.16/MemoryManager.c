/*=======================
 * 存储管理，适用于习题8.16
 ========================*/

#include "MemoryManager.h"

// 初始化一片可用的存储
void InitSpace(Space* space) {
    void* base;    // 内存起始地址
    Record* record; // 第一条记录
    
    // 初始分配MAXSIZE个字节的内存，且清零
    base = calloc(MAXSIZE, BYTE);
    space->base = base;
    
    // 初始化内存使用记录
    InitList(&(space->recordList));
    
    record = (Record*) malloc(sizeof(Record));
    
    record->addr = 0;
    record->size = MAXSIZE;
    record->tag = 0;
    record->pre = -1;
    record->next = -1;
    record->oldAddr = -1;
    
    // 插入第一条内存使用记录(空闲)
    ListInsert(&(space->recordList), 1, record);
    
    // 第一个可用的空闲块
    space->cur = 1;
    
    // 初始化地址链表
    InitList(&(space->ptrList));
}

// 分配大小为n的内存，并返回指向该内存的虚拟地址
int* AllocMemory(Space* space, int n) {
    int found;  // 标记是否找到可用的空闲块
    int i, cur, len;
    Record* record;
    Record* newRecord;
    int* ptr;
    
    // 记下当前的空闲块记录位置
    i = cur = space->cur;
    found = 0;
    
    // 获取当前内存记录表的长度
    len = ListLength(space->recordList);
    
    // 查找可用的空闲内存块
    while(1) {
        // 获取当前块的内存使用信息
        GetElem(space->recordList, i, (ElemType*) &record);
        
        // 跳过占用块，已经跳过容量不足的空闲块
        if(record->tag == 1 || record->size < n) {
            // 前进到下一条记录，注意是循环的
            i = (i + 1) % len == 0 ? len : (i + 1) % len;
            if(i == cur) {
                break;  // 如果又回到了本次搜索的起点，说明没有找到合适的空闲块
            }
            continue;
        }
        
        // 找到合适的空闲块
        found = 1;
        break;
    }
    
    // 没找到合适的空闲块
    if(found == 0) {
        return NULL;
    }
    
    // 在容差范围内，则整块分配
    if(record->size - e <= n) {
        record->tag = 1;                    // 转换为占用状态
        
        // 否则，需要拆分空闲块
    } else {
        // 新建一条空闲记录
        newRecord = (Record*) malloc(sizeof(Record));
        newRecord->addr = record->addr + n;
        newRecord->size = record->size - n;
        newRecord->tag = 0;
        newRecord->pre = -1;
        newRecord->next = -1;
        newRecord->oldAddr = -1;
        
        // 插入新的空闲记录
        ListInsert(&(space->recordList), len + 1, newRecord);
        len += 1;    // 链表长度增一
        
        // 当前的空闲记录转为使用记录
        record->size = n;
        record->tag = 1;
    }
    
    // 构造一个虚拟地址
    ptr = (int*) malloc(sizeof(int));
    ListInsert(&(space->ptrList), ListLength(space->ptrList)+1, ptr);
    *ptr = record->addr;
    
    // 将游标cur指向下一条空闲记录
    while(1) {
        // 获取当前块的内存使用信息
        GetElem(space->recordList, i, (ElemType*) &record);
        
        // 跳过占用块
        if(record->tag == 1) {
            // 前进到下一条记录，注意是循环的
            i = (i + 1) % len == 0 ? len : (i + 1) % len;
            if(i == cur) {
                break;  // 如果又回到了本次搜索的起点，说明没有找到合适的空闲块
            }
            continue;
        }
        
        // 存储下一个可用空闲块的位置(不管找没找到都存储)
        space->cur = i;
        
        break;
    }
    
    return ptr;  // 返回可用内存的虚拟地址
}

// 释放虚拟地址p处的内存
void FreeMemory(Space* space, int* p) {
    int i, len;
    Record* record;
    
    // 获取当前内存记录的长度
    len = ListLength(space->recordList);
    
    // 遍历所有内存记录，查找待释放内存所在的记录
    for(i = 1; i <= len; i++) {
        // 获取当前块的内存使用信息
        GetElem(space->recordList, i, (ElemType*) &record);
        
        // 跳过不匹配的记录
        if(*p != record->addr) {
            continue;
        }
        
        // 如果该记录本来就是空闲，则直接返回
        if(record->tag == 0) {
            return;
        }
        
        // 将使用记录更改为空闲
        record->tag = 0;
        
        // 将游标指向刚刚回收的内存
        space->cur = i;
        
        // 将该地址对应的内存处的数据抹掉(这是个可选操作)
        memset(getPtr(*space, p), 0, record->size*BYTE);
        
        // 查找该虚拟地址在地址表中的位置
        for(i = 0; i < space->ptrList.length; i++) {
            if(space->ptrList.elem[i] == p) {
                break;
            }
        }
        
        // 删除该虚拟地址（用链表后面的数据覆盖前面的数据）
        memmove(&(space->ptrList.elem[i]), &(space->ptrList.elem[i + 1]), (space->ptrList.length - i - 1) * sizeof(void*));
        
        space->ptrList.length -= 1;
        
        return;
    }
    
}

// 将虚拟地址addr转换为底层的真实地址
void* getPtr(Space space, const int* addr) {
    if(addr == NULL) {
        return NULL;
    } else {
        if(*addr < 0 || *addr > MAXSIZE) {
            return NULL;
        }
        
        return space.base + (*addr * BYTE);
    }
}

// 打印内存布局，显示格式为：首地址 块大小 标志域 | 前驱 后继 | 数据
void PrintMemoryLayout(Space space) {
    Record* record;
    int i, len;
    char* data;
    
    len = ListLength(space.recordList);
    
    for(i = 0; i < len; i++) {
        record = space.recordList.elem[i];
        
        printf("%2d ", record->addr);
        printf("%2d ", record->size);
        printf("%1d ", record->tag);
        
        // 接下来输出前驱和后继信息
        printf(" | ");
        
        if(record->tag == 0) {
            printf("       ▍\n");
            continue;
        }
        
        if(record->pre == -1) {
            printf("   ");
        } else {
            printf("%2d ", record->pre);
        }
        
        if(record->next == -1) {
            printf("   ");
        } else {
            printf("%2d ", record->next);
        }
    
        // 接下来输出该内存中的数据，这里只输出第一个字节中存储的数据，只是用于测试
        printf(" ▍ ");
        
        data = (char*)calloc(1, sizeof(char));
        memmove(data, getPtr(space, &(record->addr)), 1);
        printf("%d", *data);
        
        printf("\n");
    }
    
    printf("\n");
}
