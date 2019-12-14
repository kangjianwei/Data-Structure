#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "SqList.h"     //**��02 ���Ա�**//

/*
 * ��2.11
 *
 * ��x���뵽��������va��
 */
Status Algo_2_11(SqList* va, ElemType x);

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // ��ʼ��˳���
    InitList(&L);
    
    // ���ֵ
    for(i = 1; i <= 5; i++) {
        ListInsert(&L, i, 2 * i);
    }
    
    printf("����ǰ��L = ");
    ListTraverse(L, PrintElem);
    
    printf("��Ԫ��\"5\"���뵽˳�����...\n");
    Algo_2_11(&L, 5);
    
    printf("�����L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// ��x���뵽��������va��
Status Algo_2_11(SqList* va, ElemType x) {
    int i, j;
    ElemType* newbase;
    
    // ȷ��˳������
    if(va == NULL || va->elem == NULL) {
        return ERROR;
    }
    
    // ���洢�ռ��������迪���¿ռ�
    if((*va).length == (*va).listsize) {
        newbase = (ElemType*) realloc((*va).elem, ((*va).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL) {
            exit(OVERFLOW);
        }
        
        (*va).elem = newbase;
        (*va).listsize += LISTINCREMENT;
    }
    
    // ����˳������׸�����Ԫ��x��Ԫ��λ�����λ�����x��Ҫ�����λ��
    i = LocateElem(*va, x, CmpGreater);
    if(i == 0) {
        // ��Ҫ���뵽˳������
        i = (*va).length + 1;
    }
    
    // Ԫ�غ��ƣ��ڳ�λ�á�ע��j��λ�򣬼�1֮���������
    for(j=(*va).length + 1; j>i; j--){
        (*va).elem[j-1] = (*va).elem[j-2];
    }
    
    (*va).elem[j-1] = x;
    (*va).length++;
    
    return OK;
}

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
