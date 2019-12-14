#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SqList.h"     //**��02 ���Ա�**//

/*
 * ��2.21
 *
 * ˳������á�
 */
Status Algo_2_21(SqList L);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // ׼����������
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(&L, i, i);
    }
    
    printf("˳��L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_21(L);
    
    printf("���ã�L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// ˳�������
Status Algo_2_21(SqList L) {
    int i, mid;
    ElemType tmp;
    
    // ȷ��˳������
    if(L.elem == NULL) {
        return ERROR;
    }
    
    // ֻ��Ҫ����ǰһ���Ԫ�ؼ���
    mid = L.length / 2;
    
    for(i = 1; i <= mid; i++) {
        tmp = L.elem[i - 1];
        L.elem[i - 1] = L.elem[L.length - i];
        L.elem[L.length - i] = tmp;
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
