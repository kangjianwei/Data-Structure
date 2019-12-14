#include <stdio.h>
#include "SqList.h"     //**��02 ���Ա�**//

/*
 * ��2.12
 *
 * �Ƚ�˳����С���Ƚϲ����Ǵ������ұ�������˳���
 * �����׶Բ�ͬ��Ԫ��ʱ�����ݸ�Ԫ�صĴ�С��ϵ��ȷ��˳���Ĵ�С��ϵ
 *
 * ����ֵ��-1��0��1���ֱ����A<B��A=B��A>B
 */
int Algo_2_12(SqList A, SqList B);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    int i, mark;
    SqList A, B;
    
    int a[7] = {1, 2, 3, 4, 5, 9, 12};
    int b[7] = {1, 2, 3, 4, 5, 11, 12};
    
    // ��ʼ��
    InitList(&A);
    InitList(&B);
    
    // ��ֵ
    for(i = 1; i <= 7; i++) {
        ListInsert(&A, i, a[i - 1]);
        ListInsert(&B, i, b[i - 1]);
    }
    
    printf("A = ");
    ListTraverse(A, PrintElem);
    
    printf("B = ");
    ListTraverse(B, PrintElem);
    
    mark = Algo_2_12(A, B);
    if(mark < 0) {
        printf("==> A<B\n");
    } else if(mark > 1) {
        printf("==> A>B\n");
    } else {
        printf("A==B\n");
    }
    
    return 0;
}


// �Ƚ�˳����С
int Algo_2_12(SqList A, SqList B) {
    int i = 0;
    
    // ɨ��˳���A��B
    while(i < A.length && i < B.length) {
        if(A.elem[i] > B.elem[i]) {
            return 1;
        } else if(A.elem[i] < B.elem[i]) {
            return -1;
        } else {
            i++;    //���ʱ�Ƚ���һԪ��
        }
    }
    
    // ���A����ʣ�࣬A��
    if(i < A.length) {
        return 1;
        
        // ���B����ʣ�࣬B��
    } else if(i < B.length) {
        return -1;
        
        // ���ͬʱɨ���꣬���
    } else {
        return 0;
    }
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
