/*==============
 * 边界标识法
 *
 * 包含算法: 8.1
 ===============*/

#include "BoundaryTagMethod.h"  //**▲08 动态存储管理**//

/*
 * 全局变量：永远指向初始空间的头部。
 * 该变量有两个作用：
 * 1.用来追踪内存布局，即查看内存的使用情况。
 * 2.指示内存的起始和结尾
 */
static Space av;

// 记录空间容量，用于追踪内存布局
static int len;


/*
 * 初始化一块总大小为n个字的内存，并返回指向该内存的起点的指针
 * 注：返回的初始内存已经包含了head和foot。
 */
Space InitSpace(int n) {
    Space space, head, foot;
    
    // 初始化空闲内存
    space = (Space) malloc(n * sizeof(WORD));
    if(space == NULL) {
        return NULL;
    }
    
    // 初始化头部信息
    head = space;
    head->llink = space;  // 前驱指向自身
    head->rlink = space;  // 后继指向自身
    head->size = n;     // 空间大小，已经包含了head和foot
    head->tag = 0;        // 标记空间空闲
    
    // 初始化底部信息
    foot = FootLoc(head); // 初始化底部指针
    foot->uplink = head;  // 底部域链接到本结点的头部
    foot->tag = 0;        // 标记空间空闲
    
    // 记下空间的起始位置和容量
    av = space;
    len = n;
    
    return space;
}

/*
 * ████████ 算法8.1 ████████
 *
 * 边界标识法的内存分配算法
 *
 * 从空间pav中申请一块大小至少为n的空间，并返回指向申请到的空间的指针。如果分配失败，则返回NULL。
 * 为了使分配后的剩余块尽量均匀分布，每次分配完之后都要把空间指针pav向前移动，具体描述参见教材。
 *
 * 注：
 * 1.这里采用首次拟合法，即一遇到满足条件的内存块就进行分配操作。
 * 2.为了避免空间碎片化过快，这里增加了一个容差e，具体含义参考教材描述。
 * 3.这里申请分配n个字的空间，指的是已经完成换算的空间。
 *   比如用户想要容量为10个字的空间，但每个空间又包含head和foot这两个字存储空间使用信息，
 *   因此实际上分配的空间大小应为12个字，这个"12"就是n的含义。
 *   教材中提到"head和foot在分配时忽略不计"，这样是为了伪码书写的方便。实际写代码时，这两个空间是不能忽略的。
 *   但是如果按照上面的描述，把n解释为已经换算后空间，而不是用户原始申请的空间，
 *   那么既满足了没有忽略空间，又满足了在书面效果上，跟教材伪码统一，可谓两全其美。
 */
Space AllocBoundTag(Space* pav, int n) {
    Space p, f;
    
    /*
     * 增加一个判断：如果换算后的空间容量小于3，则直接返回。
     * 因为head和foot本身就占了2个字空间，用户至少申请1个字的话，总申请空间至少为3个字。
     */
    if(n < 3) {
        printf("日志：分配失败！申请的\"字\"数应当不小于3\n");
        return NULL;
    }
    
    // 查找不小于n的空闲块
    for(p = *pav; p && p->size < n && p->rlink != *pav; p = p->rlink) {
    }
    
    // 找不到合适的空闲块，返回空指针
    if(!p || p->size < n) {
        return NULL;
    }
    
    /* 至此，p指向了满足条件的空闲块 */
    
    // 让f指向该空闲块的底部
    f = FootLoc(p);
    
    // pav指向p结点的后继结点，即指向下一个空闲块
    *pav = p->rlink;
    
    // 如果空闲块比申请的容量大不了多少，则需要整块分配，即不保留<=e的剩余量
    if(p->size - n <= e) {
        // 由于上面已经让pav指向了下一个空闲块，所以如果pav与p相等，说明此时只有一个空闲块了(注意空闲块链表是双循环的)
        if(*pav == p) {
            *pav = NULL;  // 如果仅剩一个空闲块了，那么被占用后，可利用空间表变为空表
            
            // 否则，在表中删除分配的结点
        } else {
            (*pav)->llink = p->llink;   // 修改pav的前驱
            p->llink->rlink = *pav;     // 修改pav前驱的后继
            
            /* 在上述操作中，p结点的前驱与后继并没有改变，这是为了方便将来的回收操作 */
        }
        
        // 更新占用块为占用状态
        p->tag = f->tag = 1;
        
        printf("日志：分配成功！申请 %d 个\"字\"，实际分配了 %d 个\"字\"。空闲空间容量为 %d ...\n", n, n + e, AvailableSpace(*pav));
        
        // 如果空闲块很大，则从中间切割，占用后面的n个字
    } else {
        f->tag = 1;    // 修改分配块的底部标志，表示其处于占用状态
        p->size -= n;  // 设置剩余块大小
        
        f = FootLoc(p);  // 计算剩余块的新底部位置
        f->tag = 0;      // 设置新底部标志为空闲
        f->uplink = p;   // 新底部依然指向空闲块头部
        
        p = f + 1;       // 计算分配块的新头部位置
        p->tag = 1;      // 设置分配块新头部标志为占用
        p->size = n;     // 设置分配块的容量
        
        // 修改分配块底部的链接(教材中缺失了此步骤)
        (FootLoc(p))->uplink = p;
        
        printf("日志：分配成功！申请并分配了 %d 个\"字\"。空闲空间容量为 %d ...\n", n, AvailableSpace(*pav));
    }
    
    // 返回分配块首地址
    return p;
}

/*
 * 边界标识法的内存回收算法
 *
 * 对指针p处的内存进行释放(这类似于free()，只是对内存进行释放操作，至于置空指针p的操作，应交给调用方完成)
 *
 * 注：以下描述中的"释放块"就是指针p指向的内存
 */
void FreeBoundTag(Space* pav, Space p) {
    Space h, f, q;
    int Ltag, Rtag;
    
    if(p == NULL) {
        printf("日志：回收失败！内存指针为空。空闲空间容量为 %d ...\n", AvailableSpace(*pav));
        return;
    }
    
    Ltag = p == av ? 1 : (p - 1)->tag;                           // 块p的左邻区标志。特别注意，如果块p位于内存起始处，则认为它的左邻区为占用。
    Rtag = (p + p->size) == (av + len) ? 1 : (p + p->size)->tag; // 块p的右邻区标志。特别注意，如果块p位于内存结尾处，则认为它的右邻区为占用。
    
    /*
     * 1.释放块的左、右邻区均为占用块
     *
     * 此时仅需要将块p插入到pav所指结点的之前即可(当然，插入到之后也是可以的)
     */
    if(Ltag == 1 && Rtag == 1) {
        printf("日志：\"释放块\"的容量为 %d ，且它的左、右邻区均为占用块...\n", p->size);
        
        f = FootLoc(p);
        f->uplink = p;
        f->tag = 0;
        
        p->tag = 0;
        
        // 空闲链表为空时，直接将块p变为新的独立的空闲块
        if((*pav) == NULL) {
            *pav = p->llink = p->rlink = p;
            
            // 否则，将块p插入到pav之前
        } else {
            q = (*pav)->llink;
            p->rlink = *pav;
            p->llink = q;
            q->rlink = (*pav)->llink = p;
            
            // 令刚释放的结点成为下次分配空间时最先查找的结点
            *pav = p;
        }
        
        printf("日志：回收成功！空闲空间容量为 %d ...\n", AvailableSpace(*pav));
        
        return;
    }
    
    /*
     * 2.释放块的左邻区为空闲块，右邻区为占用块
     *
     * 此时需要合并左邻区与释放块
     */
    if(Ltag == 0 && Rtag == 1) {
        printf("日志：\"释放块\"的容量为 %d ，且它的左邻区为空闲块，右邻区为占用块...\n", p->size);
        
        h = (p - 1)->uplink;  // 左邻区的头部，这将成为合并后的新块的头部
        h->size += p->size;   // 左邻区容量增大
        
        f = FootLoc(p);       // 将释放块的底部做为合并后的新块的底部
        f->uplink = h;
        f->tag = 0;
        
        printf("日志：回收成功！空闲空间容量为 %d ...\n", AvailableSpace(*pav));
        
        return;
    }
    
    /*
     * 3.释放块的左邻区为占用块，右邻区为空闲块
     *
     * 此时需要合并释放块与右邻区
     */
    if(Ltag == 1 && Rtag == 0) {
        printf("日志：\"释放块\"的容量为 %d ，且它的左邻区为占用块，右邻区为空闲块...\n", p->size);
        
        h = p + p->size;  // 右邻区的头部
        
        f = FootLoc(h); // 右邻区的底部，这将成为合并后的新块的底部
        f->uplink = p; // 释放块的头部将作为合并后新块的头部
        
        p->tag = 0;
        p->size += h->size;
        
        // 释放块的头部链接域要更新为与右邻区头部的链接域一致
        p->llink = h->llink;
        p->rlink = h->rlink;
        h->llink->rlink = p;
        h->rlink->llink = p;
        
        // pav指向合并后的结点的新头部
        *pav = p;
        
        printf("日志：回收成功！空闲空间容量为 %d ...\n", AvailableSpace(*pav));
        
        return;
    }
    
    /*
     * 4.释放块的左、右邻区均为空闲块
     *
     * 此时需要合并左邻区、释放块、右邻区
     */
    if(Ltag == 0 && Rtag == 0) {
        printf("日志：\"释放块\"的容量为 %d ，且它的左、右邻区均为空闲块...\n", p->size);
        
        h = (p - 1)->uplink;  // 左邻区的头部，这将成为合并后的新块的头部
        q = p + p->size;      // 右邻区的头部
        f = FootLoc(q);       // 右邻区的底部，这将成为合并后的新块的底部
        
        h->size += p->size + q->size; // 合并后的新块大小
        f->uplink = h;                // 新块底部信息也要更新
        
        // 移除右邻区
        q->rlink->llink = q->llink;
        q->llink->rlink = q->rlink;
        
        printf("日志：回收成功！空闲空间容量为 %d ...\n", AvailableSpace(*pav));
        
        return;
    }
}

/*
 * 打印内存布局，查看当前内存的使用情况
 * 注：仅限内部测试使用
 */
void PrintMemoryLayout() {
    Space p;
    int count;
    int i;
    
    p = av;
    count = av->size;
    
    for(i = 1; i <= count; i++) {
        if(p->tag == 0) {
            printf("□");
        } else {
            printf("■");
        }
        
        if(i == count && count < len) {
            p = p + p->size;
            count += p->size;
            printf("|");
        } else {
            printf(" ");
        }
        
        // 每隔20个换一下行
        if(i % 20 == 0) {
            printf("\n");
        }
    }
    
    if(len % 20 != 0) {
        printf("\n");
    }
}

/*
 * 计算可用的空闲空间容量
 *
 * 注：仅限内部使用，用在日志打印中
 */
static int AvailableSpace(Space pav) {
    Space p;
    int count;
    
    if(pav == NULL) {
        return 0;
    }
    
    p = pav;
    count = 0;
    
    do {
        count += p->size;
        p = p->rlink;
    } while(p != pav);
    
    return count;
}
