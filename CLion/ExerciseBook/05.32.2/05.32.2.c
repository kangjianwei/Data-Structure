#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 判断广义表是否相等（扩展线性链表存储表示）
 */
Status Algo_5_32_2(GList A, GList B);


int main(int argc, char* argv[]) {
    GList A, B;
    char* a = "((),(e),(a,(b,c,d)))";
    char* b = "((),(e),(a,(b,c,f)))";
    SString Sa, Sb;
    
    printf("创建广义表 A、B ...\n");
    StrAssign(Sa, a);
    CreateGList(&A, Sa);
    StrAssign(Sb, b);
    CreateGList(&B, Sb);
    printf("A = ");
    PrintGraph(A);
    printf("B = ");
    PrintGraph(B);
    
    Algo_5_32_2(A, B) ? printf("两广义表相等！\n") : printf("两广义表不相等！！\n");
    
    return 0;
}


/*
 * 判断广义表是否相等（扩展线性链表存储表示）
 */
Status Algo_5_32_2(GList A, GList B) {
    if(!A && !B) {
        return TRUE;  // 两个空表相等
    }
    
    // 两个表均不为空
    if(A && B) {
        // 元素类型相同
        if(A->tag == B->tag) {
            // 原子结点
            if(A->tag == Atom) {
                if(A->Node.atom == B->Node.atom) {
                    if(Algo_5_32_2(A->tp, B->tp) == TRUE) {
                        return TRUE;
                    }
                }
                
                // 表结点
            } else {
                if(Algo_5_32_2(A->Node.hp, B->Node.hp) == TRUE) {
                    if(Algo_5_32_2(A->tp, B->tp) == TRUE) {
                        return TRUE;
                    }
                }
            }
        }
    }
    
    return FALSE;
}
