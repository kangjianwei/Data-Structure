#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

// 稀疏多项式的项
typedef struct {
    int coef;   // 系数
    int exp;    // 指数
} PolyTerm;

// 稀疏多项式链式结构（这里采用循环链表结构）
typedef struct PolyNode {
    PolyTerm data;
    struct PolyNode* next;
} PolyNode;

typedef PolyNode* PolyLink;
typedef PolyLink LinkedPoly;


/*
 * 题2.41
 *
 * 求多项式的导函数。
 */
Status Algo_2_41(LinkedPoly P);

/*
 * 题2.42
 *
 * 按指数奇偶性拆分多项式。
 */
Status Algo_2_42(LinkedPoly* P, LinkedPoly* P_Odd, LinkedPoly* P_Even);

// 创建稀疏多项式
Status CreatPoly(LinkedPoly* P, PolyTerm Data[], int n);

// 输出稀疏多项式
void OutputPoly(LinkedPoly P);


int main(int argc, char* argv[]) {
    LinkedPoly P1, P2;
    PolyTerm a[7] = {{-2, 1}, {4, 2}, {2, 3}, {11, 5}, {-7, 6}, {8, 9}, {-3, 10}};
    
    // 准备测试数据
    CreatPoly(&P1, a, 7);
    CreatPoly(&P2, a, 7);
    printf("Pn(x) = ");
    OutputPoly(P1);
    printf("\n");
    
    printf("████████ 题 2.41 验证...\n");
    {
        
        Algo_2_41(P1);
        printf("█ 求多项式的导函数之后...\n");
        printf("█ Pn(x) = ");
        OutputPoly(P1);
        printf("\n");
    }
    
    printf("████████ 题 2.42 验证...\n");
    {
        LinkedPoly P_odd, P_even;
        Algo_2_42(&P2, &P_odd, &P_even);
        printf("█ 按指数奇偶性拆分多项式之后...\n");
        printf("█ 奇次幂 P_odd  = ");
        OutputPoly(P_odd);
        printf("█ 偶次幂 P_even = ");
        OutputPoly(P_even);
    }
    
    return 0;
}


// 求多项式的导函数
Status Algo_2_41(LinkedPoly P) {
    LinkedPoly r, pre;
    
    if(P == NULL || P->next == P) {
        return ERROR;
    }
    
    pre = P;
    r = P->next;
    
    while(r != P) {
        // 存在不为0的指数
        if(r->data.exp != 0) {
            r->data.coef *= r->data.exp;    // 系数与指数想乘
            r->data.exp--;                  // 指数减一
            pre = r;
            
            // 指数为0时，该项求导后为0，需要删除当前结点
        } else {
            pre->next = r->next;
            free(r);
        }
        
        r = pre->next;
    }
    
    return OK;
}

// 按指数奇偶性拆分多项式
Status Algo_2_42(LinkedPoly* P, LinkedPoly* P_Odd, LinkedPoly* P_Even) {
    LinkedPoly r, s, p, q;
    
    // 创建头结点
    *P_Odd = (LinkedPoly) malloc(sizeof(PolyNode));
    *P_Even = (LinkedPoly) malloc(sizeof(PolyNode));
    if(*P_Odd == NULL || *P_Even == NULL) {
        exit(OVERFLOW);
    }
    (*P_Odd)->next = *P_Odd;
    (*P_Even)->next = *P_Even;
    
    if(P == NULL || *P == NULL) {
        return ERROR;
    }
    
    p = *P_Odd;
    q = *P_Even;
    r = (*P)->next;
    
    // 遍历多项式，并将其拆分
    while(r != (*P)) {
        s = r;
        r = r->next;
        
        // 指数为奇数
        if(s->data.exp % 2 != 0) {
            s->next = p->next;
            p->next = s;
            p = p->next;
    
            // 指数为偶数
        } else {
            s->next = q->next;
            q->next = s;
            q = q->next;
        }
    }
    
    // 销毁原来的多项式
    free(*P);
    *P = NULL;
    
    return OK;
}

// 创建稀疏多项式
Status CreatPoly(LinkedPoly* P, PolyTerm Data[], int n) {
    int i;
    LinkedPoly s, r;
    
    // 创建头结点
    *P = (LinkedPoly) malloc(sizeof(PolyNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    (*P)->next = *P;
    
    for(i = 0, r = *P; i < n; i++) {
        s = (LinkedPoly) malloc(sizeof(PolyNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = Data[i];
        
        // 链接到多项式中
        s->next = r->next;
        r->next = s;
        
        r = r->next;
    }
    
    return OK;
}

// 输出稀疏多项式
void OutputPoly(LinkedPoly P) {
    LinkedPoly r;
    
    if(P == NULL || P->next == P) {
        return;
    }
    
    for(r = P->next; r != P; r = r->next) {
        if(r == P->next) {
            printf("%d", r->data.coef);
        } else {
            if(r->data.coef < 0) {
                printf(" - ");
                printf("%d", -r->data.coef);
            } else {
                printf(" + ");
                printf("%d", r->data.coef);
            }
        }
        
        if(r->data.exp) {
            printf("x");
            
            if(r->data.exp != 1) {
                printf("^%d", r->data.exp);
            }
        }
    }
    
    printf("\n");
}
