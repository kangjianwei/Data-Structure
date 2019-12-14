/*=======================
 * ��չ�ĵ�������������
 *
 * �����㷨: 2.20
 ========================*/

#include "ELinkList.h"  //**��02 ���Ա�**//


/*�������������������������������������������� �ڴ���� ��������������������������������������������*/

/*
 * �ڴ����
 *
 * Ϊ������������һ����㣬������ָ��������e��
 *
 *����ע��
 * static���εĺ����Ǹú������޵�ǰ�ļ���ʹ��
 */
Status MakeNode(Link* p, ElemType e) {
    if(p == NULL) {
        return ERROR;
    }
    
    // ����ռ�
    *p = (Link) malloc(sizeof(LNode));
    if(*p == NULL) {
        // ����û���˳����򣬶��Ƿ��ش�����ʾ
        return ERROR;
    }
    
    (*p)->data = e;
    (*p)->next = NULL;
    
    return OK;
}


/*�������������������������������������������� ��������� ��������������������������������������������*/

/*
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(ELinkList* L) {
    Link p;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // ����ͷ���
    p = (Link) malloc(sizeof(LNode));
    if(p == NULL) {
        exit(OVERFLOW);
    }
    p->next = NULL;
    
    // ֻ��ͷ���ʱ����λ�α�ָ������
    (*L).head = (*L).tail = p;
    (*L).len = 0;
    
    return OK;
}


/*�������������������������������������������� ������չ���� ��������������������������������������������*/

/*
 * ��β�����
 *
 * ��s��ָ��һ���������������L����
 */
Status Append(ELinkList* L, Link s) {
    int count;
    
    if(L == NULL || (*L).head == NULL || s == NULL) {
        return ERROR;
    }
    
    count = 0;
    (*L).tail->next = s;
    
    // ȷ���µ�β���λ��
    while(s != NULL) {
        (*L).tail = s;
        s = s->next;
        count++;
    }
    
    (*L).len += count;
    
    return OK;
}
