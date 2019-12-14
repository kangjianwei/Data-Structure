/*=====================
 * ˫��ѭ������
 *
 * �����㷨: 2.18��2.19
 ======================*/

#include "DuLinkList.h"        //**��02 ���Ա�**//

/*
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(DuLinkList* L) {
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    // ǰ���ͺ�̾�ָ������
    (*L)->next = (*L)->prior = *L;
    
    return OK;
}

/*
 * ���������������� �㷨2.18 ����������������
 *
 * ����
 *
 * ��˫��ѭ�������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(DuLinkList L, int i, ElemType e) {
    DuLinkList p, s;
    
    // ȷ��˫��ѭ��������ڣ�������Ϊ�ձ�
    if(L == NULL) {
        return ERROR;
    }
    
    // ���ҵ�i�����λ�ã����ã�
    if((p = GetElemP(L, i)) == NULL) {
        return ERROR;
    }
    
    // �����½��
    s = (DuLinkList) malloc(sizeof(DuLNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    
    // ��s���뵽p��ǰ�棬��Ϊ��i�����
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    
    return OK;
}

/*
 * ����
 *
 * ��visit��������˫��ѭ������L
 */
void ListTraverse(DuLinkList L, void(Visit)(ElemType)) {
    DuLinkList p;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return;
    }
    
    p = L->next;
    
    while(p != L) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}

/*
 * ��ȡѭ������L�ϵ�i��Ԫ�ص�����
 *
 * �������� ע ��������
 * 1.��static�ĺ����ǵ�ǰ����ֻ��DuLinkList��ʹ�ã����ᱻ����ļ�����
 * 2.����������Ϊlen������Ҫ��ȡ��len+1��Ԫ�ص�����ʱ������������ѭ���������Է��ص���ͷ���
 */
static DuLinkList GetElemP(DuLinkList L, int i) {
    DuLinkList p;
    int count;
    
    // ȷ��˫��ѭ��������ڣ�������Ϊ�ձ�
    if(L == NULL) {
        return NULL;
    }
    
    // λ�ò��Ϲ�
    if(i < 1) {
        return NULL;
    }
    
    p = L;
    count = 0;
    
    // ���Բ��ҵ�i��Ԫ��
    while(p->next != L && count < i) {
        p = p->next;
        ++count;
    }
    
    // ǡ���ҵ���i��Ԫ��
    if(count == i) {
        return p;
    }
    
    // ���ˣ�˵��p->next==L����ʱ��Ҫ�ж�i�Ƿ����
    if(count + 1 < i) {
        return NULL;
    }
    
    // ���ˣ�˵����Ҫ��len+1��λ���ϲ���Ԫ��
    return L;
}
