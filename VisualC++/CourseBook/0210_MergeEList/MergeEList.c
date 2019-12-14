/*===============
 * �鲢�ǽ�������
 *
 * �����㷨: 2.21
 ================*/

#include "MergeEList.h"

Status MergeEList(ELinkList* La, ELinkList* Lb, ELinkList* Lc, int(Compare)(ElemType, ElemType)){
    Link ha, hb, pa, pb, q;
    ElemType a, b;
    
    if(InitList(Lc) == ERROR) {
        return ERROR;
    }
    
    ha = GetHead(*La);   // ָ��Laͷ���
    hb = GetHead(*Lb);   // ָ��Lbͷ���
    
    // ��֤La��Lb����Ч�����������п����ǿձ�
    if(ha == NULL || hb ==NULL) {
        return ERROR;
    }
    
    pa = NextPos(*La, ha);   // ָ��La��1��Ԫ��
    pb = NextPos(*La, hb);   // ָ��Lb��1��Ԫ��
    
    // ����La��Lb��ѡ����С��Ԫ�أ����μ��뵽Lc��
    while(pa !=NULL && pb!=NULL){
        a = GetCurElem(pa);
        b = GetCurElem(pb);
    
        // ���La<=Lb
        if(Compare(a, b)<=0) {
            // ժ��La���׸�Ԫ��
            DelFirst(La, ha, &q);
            
            // ������ժ�µ�Ԫ��׷�ӵ�Lc��
            Append(Lc, q);
            
            // ��Ȼ�ǻ�ȡLa�е�1��Ԫ��
            pa = NextPos(*La, ha);
        } else {
            // ժ��Lb���׸�Ԫ��
            DelFirst(Lb, hb, &q);
    
            // ������ժ�µ�Ԫ��׷�ӵ�Lc��
            Append(Lc, q);
    
            // ��Ȼ�ǻ�ȡLa�е�1��Ԫ��
            pb = NextPos(*Lb, hb);
        }
    }
    
    // ���La����ʣ��
    if(pa!=NULL) {
        Append(Lc, pa);
    } else {
        Append(Lc, pb);
    }
    
    // �ͷ�La��ͷ��㡣�̲��������Ƕ�ha���������������޷��ÿ�La��ͷָ�룬������������޸�
    FreeNode(&(La->head));
    
    // �ͷ�Lb��ͷ��㡣�̲��������Ƕ�hb���������������޷��ÿ�Lb��ͷָ�룬������������޸�
    FreeNode(&(Lb->head));
    
    La->tail = NULL;
    Lb->tail = NULL;
    
    La->len = 0;
    Lb->len = 0;
    
    return OK;
}