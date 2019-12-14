/*===============
 * �鲢�ǽ�������
 *
 * �����㷨: 2.12
 ================*/

#include "MergeList.h"                    //**��02 ���Ա�**//

/*
 * ���������������� �㷨2.12 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * ������A��B�鲢ΪC���ұ���Ԫ�����λ�ò��䡣
 * Lc����La��ͷ��㣬Lb�н�������������Lc�С�
 */
void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc) {
    LinkList pa, pb, pc;
    
    pa = (*La)->next;
    pb = (*Lb)->next;
    pc = *Lc = *La;                        // ��La��ͷ�����ΪLc��ͷ���
    
    // ����La��Lb
    while(pa && pb) {
        if(pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    
    // ����ʣ���
    pc->next = pa ? pa : pb;
    
    // �ͷ�Lb��ͷ�����ռ�ڴ�
    free(*Lb);
    
    *La = NULL;
    *Lb = NULL;
}
