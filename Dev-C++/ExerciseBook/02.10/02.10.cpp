#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SqList.h"     //**��02 ���Ա�**//

/*
 * ��2.10
 *
 * ɾ��˳����дӵ�i��Ԫ�����k��Ԫ��
 * ���i��k��ֵ���Ϲ棬��˳������б仯
 */
Status Algo_2_10(SqList* a, int i, int k);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // ��ʼ��˳���
    InitList(&L);
    
    // ���ֵ
    for(i = 1; i <= 15; i++) {
        ListInsert(&L, i, i);
    }
    
    printf("ɾ��ǰ��L = ");
    ListTraverse(L, PrintElem);
    
    printf("ɾ���� 6 ��Ԫ����� 5 ��Ԫ��...\n");
    Algo_2_10(&L, 6, 5);
    
    printf("ɾ����L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// ɾ��˳����дӵ�i��Ԫ�����k��Ԫ��
Status Algo_2_10(SqList* a, int i, int k) {
    int j;
    
    // ȷ��˳������
    if(a == NULL || a->elem == NULL) {
        return ERROR;
    }
    
    // �±�Խ��
    if(i < 1 || i > (*a).length || k < 0 || i + k - 1 > (*a).length) {
        return ERROR;
    }
    
    for(j = i; j <= i + k - 1; j++) {
        (*a).elem[j - 1] = (*a).elem[j + k - 1];
    }
    
    (*a).length -= k;
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
