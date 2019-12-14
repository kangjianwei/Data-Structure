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
 * ���������������� �㷨2.20 ����������������
 *
 * ����
 *
 * �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 * ���Կ������㷨2.9�ĸ�д
 */
Status ListInsert(ELinkList* L, int i, ElemType e) {
    Link h, s;
    
    if(L == NULL || (*L).head == NULL) {
        return ERROR;
    }
    
    // ȷ��iֵ�Ϲ�[1, len+1]
    if(i < 1 || i > (*L).len + 1) {
        return ERROR;
    }
    
    // ���ҵ�i-1��Ԫ�ص����ã��洢��h��
    if(LocatePos(*L, i - 1, &h) == ERROR) {
        return ERROR;
    }
    
    // �����½��s
    if(MakeNode(&s, e) == ERROR) {
        return ERROR;
    }
    
    // ��s�����뵽h�����棬��Ϊh����ĵ�һ�����
    if(InsFirst(L, h, s) == ERROR) {
        return ERROR;
    }
    
    return OK;
}

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(ELinkList L, void(Visit)(ElemType)) {
    Link p;
    
    if(L.len <= 0) {
        return;
    }
    
    // ָ���1��Ԫ��
    p = L.head->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}


/*�������������������������������������������� ������չ���� ��������������������������������������������*/

/*
 * ȡֵ
 *
 * ��ȡ���p��Ԫ��ֵ��
 */
ElemType GetCurElem(Link p) {
    if(p == NULL) {
        return INT_MIN;
    }
    
    return p->data;
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
 * ��������L�е�i(����Ϊ0)����㣬���������ô���p���ҷ���OK
 * ���iֵ���Ϲ棬�򷵻�ERROR
 * �ر�ע�⣬��iΪ0ʱ��p�洢����ͷ��������
 */
Status LocatePos(ELinkList L, int i, Link* p) {
    int j;
    Link r;
    
    // ע��i����Ϊ0
    if(i < 0 || i > L.len) {
        return ERROR;
    }
    
    // ��֤����(ͷ���)����
    if(L.head == NULL) {
        return ERROR;
    }
    
    // iΪ0ʱ��ȡͷ���
    if(i == 0) {
        *p = L.head;
        return OK;
    }
    
    j = 0;         // ����
    r = L.head;    // ָ��ͷ���
    
    while(r != NULL && j < i) {
        j++;
        r = r->next;
    }
    
    if(r == NULL) {
        return ERROR;
    }
    
    *p = r;
    
    return OK;
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
    
    // �ｫ��ɾ������ɹ����Ľ��
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
