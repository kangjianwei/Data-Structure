/*=================================
 * 静态链表
 *
 * 包含算法: 2.13、2.14、2.15、2.16
 ==================================*/

#include "SLinkList.h"

/*
 * ██ 提示 ██
 *
 * 以下所有函数的形参中：
 * space：指示备用空间
 * S    ：指示静态链表头结点索引
 */

/*━━━━━━━━━━━━━━━━━━━━━━ 备用空间操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * ████████ 算法2.14 ████████
 *
 * 初始化备用空间
 *
 * 备用空间为静态链表提供可用的内存。
 */
void InitSpace(SLinkList space) {
    int i;
    
    for(i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    
    space[MAXSIZE - 1].cur = 0;
}

/*
 * ████████ 算法2.15 ████████
 *
 * 申请空间
 *
 * 为静态链表从备用空间申请结点空间，
 * 如果申请成功，返回可用空间的索引，
 * 申请失败时，返回0。
 */
int Malloc(SLinkList space) {
    int i = space[0].cur;
    
    if(i != 0) {
        // 将申请到的空间从备用空间中删去
        space[0].cur = space[i].cur;
    }
    
    // 返回新申请结点下标
    return i;
}

/*
 * ████████ 算法2.16 ████████
 *
 * 回收空间
 *
 * 回收索引k处的结点空间以供静态链表后续复用，
 * 回收方式就是将该结点空间从静态链表上移除，
 * 并将其添加到备用空间的列表当中。
 */
void Free(SLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 静态链表操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 遍历
 *
 * 用visit函数访问静态链表S
 */
void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)) {
    int p;
    
    // 确保链表存在
    if(S == 0 || space[S].cur == 0) {
        return;
    }
    
    p = space[S].cur;
    
    while(p != 0) {
        Visit(space[p].data);
        p = space[p].cur;
    }
    
    printf("\n");
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintList(SLinkList space, int S) {
    int i = 0;
    
    printf("==== 备用空间 ====\n");
    while(i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
    
    printf("==== 静态链表 ====\n");
    i = S;
    while(i>0 && i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}
