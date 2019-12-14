#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//
#include "GList-E.h"    //**��05 ����͹����**//

/*
 * ���ù������չ��������洢��ʾ��
 */
Status Algo_5_34_2(GList* L);


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
    Algo_5_34_2(&L);
    printf("L = ");
    PrintGraph(L);
    
    return 0;
}


/*
 * ���ù������չ��������洢��ʾ��
 */
Status Algo_5_34_2(GList* L) {
    GList head, tail;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // �Ӻ���ǰ�����ﵽ������
    head = *L;
    tail = (*L)->tp;
    
    if(head->tag == List && head->Node.hp != NULL) {
        Algo_5_34_2(&(head->Node.hp));
    }
    
    // �Ա�β��������
    if(tail != NULL) {
        Algo_5_34_2(&((*L)->tp));
        
        // ͷβ����
        *L = (*L)->tp;
        tail->tp = head;
        head->tp = NULL;
    }
    
    return OK;
}
