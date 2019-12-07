#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//

/* 元素最大数量 */
#define MAX 100

/*
 * 根据左/右孩子列表，判断u是否为v的子孙
 */
Status Algo_6_33(int L[MAX + 1], int R[MAX + 1], int u, int v);

/*
 * 根据双亲结点列表，判断u是否为v的子孙
 */
Status Algo_6_34(int T[MAX + 1], int u, int v);


int main(int argc, char* argv[]) {
    int T[MAX + 1] = {0, 0, 1, 1, 2, 2, 3, 5, 5, 6};    // 0号单元弃用
    int L[MAX + 1] = {0, 2, 4, 6, 0, 7, 0, 0, 0, 0};
    int R[MAX + 1] = {0, 3, 5, 0, 0, 8, 9, 0, 0, 0};
    int u, v;
    
    printf("作为示例，建立如下的树：\n");
    printf("    → 1 2 3 4 5 6 7 8 9\n");    // 序号
    printf("T[n]→ 0 1 1 2 2 3 5 5 6\n");    // 双亲结点列表
    printf("L[n]→ 2 4 6 0 7 0 0 0 0\n");    // 左孩子列表
    printf("R[n]→ 3 5 0 0 8 9 0 0 0\n");    // 右孩子列表
    printf("\n");
    
    printf("请输入需要验证的子孙及祖先...\n\n");
    
    printf("子孙(1~9) u = ");
    scanf("%d", &u);
    printf("祖先(1~9) v = ");
    scanf("%d", &v);
    printf("\n");
    
    printf("███题 6.33 验证...███\n");
    {
        if(Algo_6_33(L, R, u, v) == TRUE) {
            printf("u=%d 是 v=%d 的子孙！\n", u, v);
        } else {
            printf("u=%d 不是 v=%d 的子孙！！\n", u, v);
        }
        
        printf("\n");
    }
    
    
    printf("███题 6.34 验证...███\n");
    {
        if(Algo_6_34(T, u, v) == TRUE) {
            printf("u=%d 是 v=%d 的子孙！\n", u, v);
        } else {
            printf("u=%d 不是 v=%d 的子孙！！\n", u, v);
        }
        
        printf("\n");
    }
    
    return 0;
}


/*
 * 根据左/右孩子列表，判断u是否为v的子孙
 */
Status Algo_6_33(int L[MAX + 1], int R[MAX + 1], int u, int v) {
    // 如果u是v的孩子
    if(L[v] == u || R[v] == u) {
        return TRUE;
    } else {
        // 如果存在左孩子，向左搜索
        if(L[v]!=0 && Algo_6_33(L, R, u, L[v])==TRUE) {
            return TRUE;
        }
    
        // 如果存在右孩子，向左搜索
        if(R[v]!=0 && Algo_6_33(L, R, u, R[v])==TRUE) {
            return TRUE;
        }
    }
    
    return FALSE;
}

/*
 * 根据双亲结点列表，判断u是否为v的子孙
 */
Status Algo_6_34(int T[MAX + 1], int u, int v) {
    // 如果u的双亲是v
    if(T[u] == v) {
        return TRUE;
    } else {
        if(T[u] != 0 && Algo_6_34(T, T[u], v) == TRUE) {
            return TRUE;
        }
    }
    
    return FALSE;
}
