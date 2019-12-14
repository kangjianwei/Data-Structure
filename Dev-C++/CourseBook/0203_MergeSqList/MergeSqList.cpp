/*==================
 * �鲢�ǽ���˳���
 *
 * �����㷨: 2.2��2.7
 ===================*/

#include "MergeSqList.h"    //**��02 ���Ա�**//


/*
 * ���������������� �㷨2.2 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * �鲢˳���La��Lb�������µ�˳���Lc��
 * ���У�La��Lb��Lc��Ϊ�ǵݼ����С�
 */
void MergeSqList_1(SqList La, SqList Lb, SqList* Lc) {
    int La_len, Lb_len;
    int i, j, k;
    ElemType ai, bj;
    
    i = j = 1;
    k = 0;
    
    // ��ʼ��Lc
    InitList(Lc);
    
    // ��ȡLa��Lb�ĳ���
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    
    // ���La��Lb��δ������
    while(i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        
        // �Ƚϱ�������Ԫ�أ��Ƚ��Ƚ�С��Ԫ�ؼ���˳���Lc
        if(ai <= bj) {
            ListInsert(Lc, ++k, ai);
            i++;
        } else {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    
    // ���Lb�ѱ����꣬��La��δ�����꣬��La��ʣ��Ԫ�ؼ���Lc
    while(i <= La_len) {
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }
    
    // ���La�ѱ����꣬��Lb��δ�����꣬��Lb��ʣ��Ԫ�ؼ���Lc
    while(j <= Lb_len) {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}

/*
 * ���������������� �㷨2.7 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * �鲢˳���La��Lb�������µ�˳���Lc��
 * ���У�La��Lb��Lc��Ϊ�ǵݼ����С�
 */
void MergeSqList_2(SqList La, SqList Lb, SqList* Lc) {
    ElemType* pa, * pb, * pc;
    ElemType* pa_last, * pb_last;
    
    pa = La.elem;                        // ָ��La��һ��Ԫ��
    pb = Lb.elem;                        // ָ��Lb��һ��Ԫ��
    
    // û��ʹ��InitList����Lc
    (*Lc).listsize = (*Lc).length = La.length + Lb.length;
    pc = (*Lc).elem = (ElemType*) malloc((*Lc).listsize * sizeof(ElemType));
    if(pc == NULL) {
        exit(OVERFLOW);
    }
    
    pa_last = La.elem + La.length - 1;    // ָ��La���һ��Ԫ��
    pb_last = Lb.elem + Lb.length - 1;    // ָ��Lb���һ��Ԫ��
    
    // ���La��Lb��δ������
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    
    // ���Lb�ѱ����꣬��La��δ�����꣬��La��ʣ��Ԫ�ؼ���Lc
    while(pa <= pa_last) {
        *pc++ = *pa++;
    }
    
    // ���La�ѱ����꣬��Lb��δ�����꣬��Lb��ʣ��Ԫ�ؼ���Lc
    while(pb <= pb_last) {
        *pc++ = *pb++;
    }
}