#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 逆置广义表（扩展线性链表存储表示）
 */
Status Algo_5_34_2(GList* L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "(a,((b,c),()),(((d),e),f))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);
    
    printf("逆置广义表...\n");
    Algo_5_34_2(&L);
    printf("L = ");
    PrintGList(L);
    
    return 0;
}


/*
 * 逆置广义表（扩展线性链表存储表示）
 */
Status Algo_5_34_2(GList* L) {
    GList head, tail;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // 从后向前，从里到外逆置
    head = *L;
    tail = (*L)->tp;
    
    if(head->tag == List && head->Node.hp != NULL) {
        Algo_5_34_2(&(head->Node.hp));
    }
    
    // 对表尾进行逆置
    if(tail != NULL) {
        Algo_5_34_2(&((*L)->tp));
        
        // 头尾交换
        *L = (*L)->tp;
        tail->tp = head;
        head->tp = NULL;
    }
    
    return OK;
}
