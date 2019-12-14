/*==============
 * �󲢼�
 *
 * �����㷨: 2.1
 ===============*/

#include "Union.h"      //**��02 ���Ա�**//

/*
 * ���������������� �㷨2.1 ����������������
 *
 * A=A��B
 *
 * ����La��Lb�Ĳ��������ء�
 * �������ɵĲ�����ƴ����La�ϣ�����La�����Ϊָ�����͡�
 */
void Union(SqList* La, SqList Lb) {
    int La_len, Lb_len;
    int i;
    ElemType e;
    
    // ��˳�����
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    
    for(i = 1; i <= Lb_len; i++) {
        // ȡLb�е�i��Ԫ�ظ���e
        GetElem(Lb, i, &e);
        
        // ��e����La�������
        if(!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

/*
 * �е�
 *
 * �ж���Ԫ���Ƿ���ȡ�
 * �����ȣ��򷵻�TRUE�����򣬷���FALSE��
 */
Status equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}
