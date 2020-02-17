/*=====
 * 集合
 ======*/

#include "MFSet.h"

/*
 * 初始化一个由多个子集（每个子集只包含单个成员）构成的集合S。
 *
 *
 *【备注】
 *
 * 这里对第6章的MFSet做了改动：
 * 1.直接在参数中传入子集数量
 * 2.子集编号从0开始计数，这会影响到后面的函数中关于下标的判断
 */
Status initial_mfset(MFSet* S, int n) {
    int i;
    
    if(n <= 0) {
        return ERROR;
    }
    
    S->n = n;
    S->r = 0;   // 第一个子集的位置在0号单元
    
    // 子集编号从0开始计数
    for(i = 0; i < n; i++) {
        S->nodes[i].parent = -1;
    }
    
    return OK;
}

/*
 * 求两个互不相交的子集Si和子集Sj的并集。
 */
Status merge_mfset(MFSet* S, int i, int j) {
    
    // 索引越界
    if(i < 0 || i > S->n - 1 || j < 0 || j > S->n - 1) {
        return ERROR;
    }
    
    // 相同的子集无需合并，直接返回
    if(i == j) {
        return OK;
    }
    
    S->nodes[i].parent = j;
    
    return OK;
}

/*
 * 在集合S中查找元素i当前所属的子集。
 */
int find_mfset(MFSet S, int i) {
    int j;
    
    // 索引越界
    if(i < 0 || i > S.n - 1) {
        return -1;
    }
    
    // 查找i所属的子集的根结点
    for(j = i; S.nodes[j].parent >= 0; j = S.nodes[j].parent) {
        // 从下往上查找
    }
    
    return j;
}

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 */
Status build_mfset(MFSet* S, Relation R) {
    int k;
    int i, j;
    
    for(k = 0; k < R.n; k++) {
        // 先获取子集根结点
        i = find_mfset(*S, R.pairs[k].i);
        j = find_mfset(*S, R.pairs[k].j);
        
        // 对两个互不相交的子集进行归并
        if(!merge_mfset(S, i, j)) {
            return ERROR;
        }
    }
    
    return OK;
}
