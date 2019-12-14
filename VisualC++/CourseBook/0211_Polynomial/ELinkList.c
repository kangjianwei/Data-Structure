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

/*
 * �ڴ����
 *
 * �ͷ�����������ָ���Ľ�㡣
 *
 *����ע��
 * static���εĺ����Ǹú������޵�ǰ�ļ���ʹ��
 */
void FreeNode(Link* p) {
    if(p == NULL || *p == NULL) {
        return;
    }
    
    free(*p);
    
    *p = NULL;
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

/*
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyList(ELinkList* L) {
    
    // ��������ʱû��Ҫ����
    if(L == NULL || (*L).head == NULL) {
        return ERROR;
    }
    
    ClearList(L);
    
    free((*L).head);
    
    (*L).head = (*L).tail = NULL;
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(ELinkList* L) {
    Link p, q;
    
    // û����ЧԪ��ʱ����Ҫ����
    if(L == NULL || (*L).head == NULL || (*L).len <= 0) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    p = (*L).head->next;
    
    // �ͷ�����Ԫ����ռ�ڴ�
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    (*L).head->next = NULL;
    (*L).tail = (*L).head;
    (*L).len = 0;
    
    return OK;
}

/*
 * ����
 *
 * ���������������ЧԪ�ص�������
 */
int ListLength(ELinkList L) {
    return L.len;
}

/*
 * ����
 *
 * ������Һ����봫ͳ�İ汾��һ����
 * �������Ȼ������Ԫ��e����Compare()==0��Ԫ�أ�����ҵ���ʹ��q�洢�����ã�������True��
 * ����������������ã�������׸���Ԫ��e����Compare()>0��Ԫ�ص�ǰ����������FALSE��
 * ��������е�Ԫ�ؾ�����e��q�洢ͷ������á�
 * ��������е�Ԫ�ؾ�С��e��q�洢β������á�
 * ���������£��Ὣq�ÿա�
 *
 *����ע��
 * 1.Ԫ��e��Compare�����ڶ����β�
 */
Status LocateElem(ELinkList L, ElemType e, Position* q, Status(Compare)(ElemType, ElemType)) {
    Position pre, p;
    
    *q = NULL;
    
    // �������ڣ����ش�����Ϣ
    if(L.head == NULL) {
        return FALSE;
    }
    
    pre = L.head;
    p = pre->next;
    
    while(p != NULL && Compare(p->data, e) < 0) {
        pre = p;
        p = p->next;
    }
    
    // �ҵ�����e����"���"������Ԫ��
    if(p != NULL && Compare(p->data, e) == 0) {
        *q = p;
        return TRUE;
    }
    
    // ����Ԫ�ؾ�С��e������pԪ�ش���e���ֻ���Ϊ�ձ�
    *q = pre;
    
    return FALSE;
}


/*�������������������������������������������� ������չ���� ��������������������������������������������*/

/*
 * ȡֵ
 *
 * ��ȡ���p��Ԫ��ֵ��
 */
ElemType GetCurElem(Link p) {
    ElemType e;
    
    if(p == NULL) {
        e.coef = 0.0f;
        e.expn = -1;
        return e;
    }
    
    return p->data;
}

/*
 * ��ֵ
 *
 * Ϊ���p����Ԫ��ֵ��
 */
Status SetCurElem(Link p, ElemType e) {
    if(p == NULL) {
        return ERROR;
    }
    
    p->data = e;
    
    return OK;
}

/*
 * ͷ���
 *
 * ��ȡͷ������á�
 */
Position GetHead(ELinkList L) {
    return L.head;
}

/*
 * ���
 *
 * ��ȡ���p�ĺ�̣���������ڣ���NULL��
 */
Position NextPos(ELinkList L, Link p) {
    
    // ȷ������(ͷ���)����
    if(L.head == NULL) {
        return NULL;
    }
    
    if(p == NULL) {
        return NULL;
    }
    
    return p->next;
}

/*
 * ����
 *
 * ��s�����뵽h�����棬��Ϊh����ĵ�һ�����
 *
 *����ע��
 * �̲��ж��ڸ÷�����������Щ���⣬�������������İ汾
 */
Status InsFirst(ELinkList* L, Link h, Link s) {
    if(L == NULL || (*L).head == NULL || h == NULL || s == NULL) {
        return ERROR;
    }
    
    s->next = h->next;
    h->next = s;
    
    // ��hΪβ��㣬����Ҫ����β���
    if(h == (*L).tail) {
        (*L).tail = h->next;
    }
    
    (*L).len++;
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ��h����ĵ�һ����㣬����q�洢��ɾ����������
 *
 *����ע��
 * �̲��ж��ڸ÷����Ķ������Դֲڣ��������������İ汾
 */
Status DelFirst(ELinkList* L, Link h, Link* q) {
    if(L == NULL || (*L).head == NULL || h == NULL || q == NULL) {
        return ERROR;
    }
    
    // ���û�н���ɾ�������ش�����Ϣ
    if(h->next == NULL) {
        return ERROR;
    }
    
    *q = h->next;
    
    h->next = (*q)->next;
    
    // ����ɾ������ɹ����Ľ��
    (*q)->next = NULL;
    
    // ���h��ֻ��һ����㣬����β���ָ��
    if(h->next == NULL) {
        (*L).tail = h;
    }
    
    // �����ͷű�ɾ�����ռ�ռ�
    (*L).len--;
    
    return OK;
}

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
