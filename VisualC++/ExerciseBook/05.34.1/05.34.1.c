#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//
#include "GList-HT.h"   //**��05 ����͹����**//

/*
 * ���ù����ͷβ����洢��ʾ��
 */
Status Algo_5_34_1(GList* L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "(a,((b,c),()),(((d),e),f))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    printf("���ù����...\n");
    Algo_5_34_1(&L);
    printf("L = ");
    PrintGraph(L);
    
    return 0;
}


/*
 * ���ù����ͷβ����洢��ʾ��
 */
Status Algo_5_34_1(GList* L) {
    GList head, tail;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // �Ӻ���ǰ�����ﵽ������
    head = *L;
    tail = (*L)->Node.ptr.tp;
    
    // �Ա�ͷ��������
    if(head->Node.ptr.hp != NULL && head->Node.ptr.hp->tag == List) {
        Algo_5_34_1(&(head->Node.ptr.hp));
    }
    
    // �Ա�β��������
    if(tail != NULL) {
        Algo_5_34_1(&((*L)->Node.ptr.tp));
        
        // ͷβ����
        *L = (*L)->Node.ptr.tp;
        tail->Node.ptr.tp = head;
        head->Node.ptr.tp = NULL;
    }
    
    return OK;
}
