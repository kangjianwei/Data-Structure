#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 删除广义表中值为x的原子项（扩展线性链表存储表示）
 */
void Algo_5_37_2(GList* L, AtomType x);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((b),(e),(a,(b,c,d)),(b,((b),b)),x,b,(y))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);
    
    printf("删除 L 中的元素 'b' ...\n");
    Algo_5_37_2(&L, 'b');
    printf("L = ");
    PrintGList(L);
    
    return 0;
}


/*
 * 删除广义表中值为x的原子项（扩展线性链表存储表示）
 */
void Algo_5_37_2(GList* L, AtomType x) {
    GList p;
    
    if(L == NULL || *L == NULL) {
        return;
    }
    
    if((*L)->tag == List) {
        Algo_5_37_2(&((*L)->Node.hp), x);
        Algo_5_37_2(&((*L)->tp), x);
    } else {
        if((*L)->Node.atom == x) {
            p = *L;
            *L = (*L)->tp;
            free(p);
            
            Algo_5_37_2(L, x);
        } else {
            Algo_5_37_2(&((*L)->tp), x);
        }
    }
}
