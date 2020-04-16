/*==============
 * 伙伴系统
 *
 * 包含算法: 8.2
 ===============*/

#include "BuddySystem.h"

// 记录内存的起始地址，在计算伙伴块时候需要用到
WORD* start;


/*
 * 初始化一块大小为2^M个字的内存，并返回指向该内存的起点的指针
 * 注：返回的初始内存已经包含了head。
 */
void InitSpace(FreeList avail) {
    int k;
    WORD* r;

    // 遍历M+1个元素
    for(k = 0; k <= M; k++) {
        avail[k].nodesize = (int) pow(2, k);
        avail[k].first = NULL;
    }

    r = (WORD*) malloc((int) pow(2, M) * sizeof(WORD));
    if(r == NULL) {
        exit(OVERFLOW);
    }

    // 设置头部信息
    r->llink = r->rlink = r;
    r->tag = 0;
    r->kval = M;

    avail[M].first = r;

    start = r;
}

/*
 * ████████ 算法8.2 ████████
 *
 * 伙伴系统的内存分配算法
 *
 * 从空间avail中申请一块大小至少为n(原始值)的空间，并返回指向申请到的空间的指针。如果分配失败，则返回NULL。
 *
 * 注：
 * 1.这里采用首次拟合法，即一遇到满足条件的内存块就进行分配操作。
 * 2.这里申请分配n个字的空间，指的是用户申请的原始空间。
 *   实际在申请时，还要考虑到每个块前面有1个字的head信息，即经过换算后，实际需要申请(n+1)个字。
 *   这里的n与算法8.1里面的n含义正好相反，需要注意。
 */
WORD* AllocBuddy(FreeList avail, int n) {
    int k, i;
    WORD* pa, * pre, * suc, * pi;

    /*
     * 增加一个判断：如果换算后的空间容量小于1，则直接返回。
     */
    if(n < 1) {
        printf("日志：分配失败！申请的\"字\"数应当不小于1\n");
        return NULL;
    }

    // 查找不小于n的空闲块
    for(k = 0; k <= M && (avail[k].nodesize < n + 1 || !avail[k].first); k++) {
    }

    // 找不到合适的空闲块，返回空指针
    if(k > M) {
        printf("日志：分配失败！没有足够的空闲块\n");
        return NULL;
    }

    pa = avail[k].first; // 指向可分配子表的第一个结点
    pre = pa->llink;     // 分别记下前驱和后继
    suc = pa->rlink;

    // 如果此处仅有一个空闲块，则分配后该子表变为空
    if(pa == suc) {
        avail[k].first = NULL;

        // 否则，从链表头部摘下一个可用的空闲块，并将子表头指针指向下一个空闲块
    } else {
        pre->rlink = suc;
        suc->llink = pre;
        avail[k].first = suc;
    }

    /*
     * 从k-1处开始逆向遍历FreeList数组，向其中填充剩余的空闲块。
     * 剩余的空闲块是对剩余可用空间的拆分。
     *
     * 这里用到一个公式：2^m-2^n = 2^n+2^(n+1)+...+2^(m-1)
     * 比如初始容量为2^16，此时总共申请1500个字，那么需要分配一块2^11的空闲块给它。
     * 分配完之后，剩余的容量为：2^16-2^11 = 2^11+2^12+2^13+2^14+2^15。
     * 这些剩余容量可以拆分为5个空闲块，分别存储到15、14、13、12、11这五个索引处。
     */
    for(i = 1; k - i >= 0 && avail[k - i].nodesize >= n + 1; i++) {
        pi = pa + (int) pow(2, k - i);  // 每次将pi指向剩余空间的后一半
        pi->rlink = pi->llink = pi;     // 初始化pi的前驱和后继
        pi->tag = 0;                    // 标记为空闲块
        pi->kval = k - i;               // 设置该块的容量标志，真实容量为2^(k-i)
        avail[k - i].first = pi;

        /*
         * 注：
         * 上面分解出来的pi直接添加到了avail中，并没有考虑同位置处会不会有别的容量相同的空闲块。
         * 这里不需要考虑的原因是如果同位置处已经存在别的容量相同的空闲块，
         * 那么这里根本不需要分解剩余空间，换句话说，连这个循环都进不来。
         * 只要进来这个循环，说明目标位置处已经为空了，没有找到合适的空闲块，所以这才进一步向高游标处寻找空闲块。
         */
    }

    // 最后剩下的最靠前的空间就是需要分配的空间(这里没有设置pa的前驱和后继，因为没必要)
    pa->tag = 1;
    pa->kval = k - (--i);

    printf("日志：分配成功！用户申请 %d 个字，系统申请 %d 个字，实际分配 %d 个字\n", n, n + 1, (int) pow(2, pa->kval));

    return pa;
}

/*
 * 伙伴系统的内存回收算法
 *
 * 对指针p处的内存进行释放(这类似于free()，只是对内存进行释放操作，至于置空指针p的操作，应交给调用方完成)
 *
 * 注：这里没有验证p的取值，调用方应当确保p在合规的范围
 */
void FreeBuddy(FreeList avail, WORD* p) {
    int k;
    WORD* r;
    WORD* buddy = Buddy(p);

    if(p == NULL) {
        return;
    }

    /*
     * 这里将p结点简单地插入到avail中，包含三种情形：
     * 1.伙伴块非空闲
     * 2.伙伴空闲，但是伙伴的大小跟p的大小不一致，说明伙伴还没拼合好
     * 3.p拼接成了最后一个最大的空闲块
     */
    if(buddy->tag == 1 || buddy->kval != p->kval || p->kval == M) {
        for(k = 0; k <= M && k < p->kval; k++) {
            // 查找p结点应当进入的插槽
        }

        // 找到插槽，采用头插法将空闲块插入到目标插槽
        if(k <= M && k == p->kval) {
            p->tag = 0;

            if(avail[k].first == NULL) {
                p->llink = p->rlink = p;
            } else {
                p->llink = avail[k].first->llink;
                p->rlink = avail[k].first;
                p->llink->rlink = p;
                p->rlink->llink = p;
            }

            avail[k].first = p;

            printf("日志：回收成功！[%d, (2^%d)]进入插槽 %d 的空闲块链表上\n", (int) (p - start), k, k);
        }

        // 如果伙伴块是空闲的，此时应当进行合并操作
    } else {
        for(k = 0; k <= M && k < p->kval; k++) {
            // 查找伙伴块所在的插槽
        }

        // 找到插槽，将伙伴块从空闲块链表中摘下来
        if(k <= M && k == p->kval) {
            // 伙伴在链表第一个位置
            if(avail[k].first == buddy) {
                buddy->rlink->llink = buddy->llink;
                buddy->llink->rlink = buddy->rlink;

                avail[k].first = buddy->rlink;

                // 伙伴在中间位置
            } else {
                for(r = avail[k].first; r->rlink != buddy; r = r->rlink) {
                    // 查找伙伴，r指向伙伴的前驱
                }

                r->rlink = buddy->rlink;
                buddy->rlink->llink = r;
            }

            printf("日志：合并成功！[%d, (2^%d)]和[%d, (2^%d)]合并成了", (int) (p - start), k, (int) (buddy - start), k);

            // 合并之前，需要确定哪个伙伴靠前
            if(p < buddy) {
                p->tag = 0;
            } else {
                p = buddy;
            }

            p->kval = k + 1;  // 指数增一后，即完成合并

            printf("[%d, (2^%d)]\n", (int) (p - start), k + 1);

            // 出现新的空闲块之后，要进入递归，查看该空闲块是否也存在空闲伙伴
            FreeBuddy(avail, p);
        }
    }
}

/*
 * 打印内存布局，查看当前内存的使用情况
 * 注：仅限内部测试使用
 */
void PrintMemoryLayout() {
    int i, count, total;
    WORD* p;

    printf("|");

    p = start;
    count = (int) pow(2, p->kval);

    for(i = 1; i <= count; i++) {
        if(p->tag == 0) {
            printf("_");
        } else {
            printf("*");
        }

        // 进入到下一个块
        if(i == count && count < (int) pow(2, M)) {
            p = start + count;
            count += (int) pow(2, p->kval);
            printf("|");
        }
    }

    printf("|\n");
}

/*
 * 查找块p的伙伴
 *
 * 将一个空闲块对半分裂后，会生成的两个小空闲块，这两个小空闲块互为伙伴。
 *
 * 计算伙伴的算法为：
 * 对于起始地址为p，大小为2^k的内存块：
 * 1.若 p MOD 2^(k+1) == 0   ,则p的伙伴块的起始地址为p+2^k，
 * 2.若 p MOD 2^(k+1) == 2^k ,则p的伙伴块的起始地址为p-2^k。
 *
 * 注：仅限内部使用，用在回收算法中
 */
static WORD* Buddy(WORD* p) {
    long s, m, n;

    if(p == NULL) {
        return NULL;
    }

    // start是整个空闲块的绝对起始地址，s是p在伙伴系统中的绝对地址，从0开始
    s = p - start;
    if(s < 0) {
        return NULL;
    }

    m = (long) pow(2, p->kval);
    n = (long) pow(2, p->kval + 1);

    if(s % n == 0) {
        return p + m;
    }

    if(s % n == m) {
        return p - m;
    }

    return NULL;
}

