#include <stdio.h>
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 输出广义表中第l层的原子项(扩展线性链表存储表示)
 */
void Algo_5_38_2(GList L, int d, int l);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);
    
    printf("广义表第 2 层的原子项为：");
    Algo_5_38_2(L, 0, 2);
    printf("\n");
    
    return 0;
}


/*
 * 输出广义表中第l层的原子项(扩展线性链表存储表示)
 */
void Algo_5_38_2(GList L, int d, int l) {
    int i = d;  // d的初值赋值为0
    
    if(L && l >= i) {
        if(L->tag == Atom) {
            // 层数符合
            if(l == i) {
                printf("%c ", L->Node.atom);
            }
        } else {
            Algo_5_38_2(L->Node.hp, i + 1, l);  // 表头指针指向表的话层数增一
        }
        
        Algo_5_38_2(L->tp, i, l);
    }
}
