#include <stdio.h>
#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ��2.14
 *
 * ��ȡ˳���L�ĳ��ȡ�
 */
int Algo_2_14(LinkList L);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // ��ʼ��˳���
    InitList(&L);
    
    // ���ֵ
    for(i = 1; i <= 15; i++) {
        ListInsert(L, i, 2 * i);
    }
    
    // ���˳���
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("����L�ĳ���Ϊ %d \n", Algo_2_14(L));
    
    return 0;
}


// ��ȡ˳���L�ĳ���
int Algo_2_14(LinkList L) {
    // ֱ�ӵ�������ļ�������
    return ListLength(L);
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
