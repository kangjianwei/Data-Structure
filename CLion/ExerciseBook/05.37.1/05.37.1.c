#include <stdio.h>
#include "SString.h"    //**▲04 串**//
#include "GList-HT.h"   //**▲05 数组和广义表**//

/*
 * 删除广义表中值为x的原子项（头尾链表存储表示）
 */
void Algo_5_37_1(GList* L, AtomType x);


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
    Algo_5_37_1(&L, 'b');
    printf("L = ");
    PrintGList(L);
    
    return 0;
}


/*
 * 删除广义表中值为x的原子项（头尾链表存储表示）
 */
void Algo_5_37_1(GList* L, AtomType x) {
    GList h, p;
    
    if(L == NULL || *L == NULL || (*L)->tag == Atom) {
        return;
    }
    
    h = (*L)->Node.ptr.hp;
    
    if(h != NULL) {
        if(h->tag == List) {
            Algo_5_37_1(&((*L)->Node.ptr.hp), x);
            Algo_5_37_1(&((*L)->Node.ptr.tp), x);
        } else {
            if(h->Node.atom == x) {
                p = *L;
                *L = (*L)->Node.ptr.tp;
                p->Node.ptr.tp = NULL;
                DestroyGList(&p);
                Algo_5_37_1(L, x);
            } else {
                Algo_5_37_1(&((*L)->Node.ptr.tp), x);
            }
        }
    } else {
        if((*L)->Node.ptr.tp != NULL) {
            Algo_5_37_1(&((*L)->Node.ptr.tp), x);
        }
    }
}
