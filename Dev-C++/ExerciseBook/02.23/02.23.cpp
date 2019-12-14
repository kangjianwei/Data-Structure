#include <stdio.h>
#include "Status.h"      //**��01 ����**//
#include "LinkList.h"    //**��02 ���Ա�**//

/*
 * ��2.23��������һ����La���뵽Lb��
 *
 * �ϲ�����������
 * �ϲ���ɺ󣬽�La��Lb�ÿգ��������١�
 */
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc);

/*
 * ��2.23��������������La��Lb�е�Ԫ�ؽ�����뵽Lc��
 *
 * �ϲ�����������
 * �ϲ���ɺ󣬽�La��Lb�ÿգ��������١�
 */
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // ׼����������
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 5; i++) {
        ListInsert(La, i, 2 * i - 1);
        ListInsert(Lb, i, 2 * i);
    }
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // �ϲ���������
//    Algo_2_23_1(La, Lb, &Lc);
    Algo_2_23_2(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


// �ϲ�����������
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pb;
    
    // ȷ��La��Lb����
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    pb = Lb;
    
    while(La->next != NULL && pb->next != NULL) {
        // ��La��ժ�½��
        p = La->next;
        La->next = p->next;
        
        // ��La��ժ�µĽ����뵽Lb��
        p->next = pb->next;
        pb->next = p;
        
        // ǰ����ԭLb����һ������λ��
        pb = pb->next->next;
    }
    
    // ���La��ʣ�࣬��Ҫ����ȫ�����ӵ�Lb��β��
    if(pb->next == NULL && La->next != NULL) {
        pb->next = La->next;
        La->next = NULL;
    }
    
    InitList(Lc);
    
    (*Lc)->next = Lb->next;
    Lb->next = NULL;
    
    return OK;
}

// �ϲ�����������
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pc;
    int flag;   // ָ�Ӳ���La�е�Ԫ�ػ��ǲ���Lb�е�Ԫ��
    
    // ȷ��La��Lb����
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    flag = 0;
    pc = *Lc;
    
    while(La->next!=NULL && Lb->next!=NULL){
        // ��Ҫ����La�е�Ԫ��
        if(flag==0) {
            // ժ��La�е�Ԫ��
            p = La->next;
            La->next = p->next;
            
            flag = 1;
        } else {
            // ժ��La�е�Ԫ��
            p = Lb->next;
            Lb->next = p->next;
    
            flag = 0;
        }
    
        // ��ժ�µ�Ԫ�ز��뵽Lc
        pc->next = p;
        pc = pc->next;
    }
    
    // ���Lb������ʣ��
    if(La->next==NULL) {
        // ժ��Lb�е�Ԫ��
        p = Lb->next;
        Lb->next = NULL;
        pc->next = p;
    
        // ���La��ʣ��
    } else {
        // ժ��La�е�Ԫ��
        p = La->next;
        La->next = NULL;
        pc->next = p;
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
