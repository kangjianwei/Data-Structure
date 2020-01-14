#include <stdio.h>
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 输出广义表中所有原子项及其所在层次（扩展线性链表存储表示）
 */
void Algo_5_33_2(GList L, int d);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);
    
    Algo_5_33_2(L, 0);
    
    return 0;
}


/*
 * 输出广义表中所有原子项及其所在层次（扩展线性链表存储表示）
 */
void Algo_5_33_2(GList L, int d) {
    int i = d;  // d初值赋为0
    
    if(L == NULL) {
        return;
    }
    
    if(L->tag == Atom) {
        printf("%c -> 第%d层\n", L->Node.atom, i);
    }
    
    
    if(L->tag == List) {
        Algo_5_33_2(L->Node.hp, i + 1); // 表头指针指向表的话层数增一
    }
    
    Algo_5_33_2(L->tp, i);
}
