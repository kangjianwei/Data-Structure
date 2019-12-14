#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ��2.13
 *
 * Ѱ��Ԫ��x��L�е�λ�á�
 * �������0����˵��x�����ڡ�
 */
int Algo_2_13(LinkList L, ElemType x);

// �ж�data==e�Ƿ����
Status Equals(ElemType data, ElemType e);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // ��ʼ��˳���
    InitList(&L);
    
    // ���ֵ
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, 2 * i);
    }
    
    // ���˳���
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("Ԫ�� \"12\" ������L�е�λ��Ϊ %d \n", Algo_2_13(L, 12));
    
    return 0;
}


// Ѱ��Ԫ��x��L�е�λ��
int Algo_2_13(LinkList L, ElemType x) {
    // ֱ�ӵ�������Ĳ��Һ���
    return LocateElem(L, x, Equals);
}

// �ж�data==e�Ƿ����
Status Equals(ElemType data, ElemType e) {
    if(data == e) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
