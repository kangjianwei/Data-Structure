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
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ����Ϊ��
 */
Status ListEmpty(ELinkList L) {
    if(L.len <= 0) {
        return TRUE;
    } else {
        return FALSE;
    }
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
 * �����������׸���e����Compare��ϵ��Ԫ�����á�
 * ���������������Ԫ�أ��򷵻�NULL��
 *
 *����ע��
 * 1.Ԫ��e��Compare�����ڶ����β�
 * 2.����ķ���ֵ��Ŀ��Ԫ�ص����ã���������λ��
 */
Position LocateElem(ELinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    Position p;
    
    if(L.len <= 0) {
        return NULL;
    }
    
    // ָ���1��Ԫ��
    p = L.head->next;
    
    while(p != NULL && !Compare(p->data, e)) {
        p = p->next;
    }
    
    return p;
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
 * ɾ��
 *
 * ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 * ���Կ������㷨2.10�ĸ�д
 */
Status ListDelete(ELinkList* L, int i, ElemType* e) {
    Link h, q;
    
    if(L == NULL || (*L).head == NULL) {
        return ERROR;
    }
    
    // ȷ��iֵ�Ϲ�[1, len]
    if(i < 1 || i > (*L).len) {
        return ERROR;
    }
    
    // ���ҵ�i-1��Ԫ�ص����ã��洢��h��
    if(LocatePos(*L, i - 1, &h) == ERROR) {
        return ERROR;
    }
    
    // ɾ��h����ĵ�һ����㣬����q�洢��ɾ����������
    if(DelFirst(L, h, &q) == ERROR) {
        return ERROR;
    }
    
    // ���±�ɾ��Ԫ�ص�ֵ
    *e = q->data;
    
    // �ͷű�ɾ�����Ŀռ�
    FreeNode(&q);
    
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
 * β���
 *
 * ��ȡβ������á�
 */
Position GetLast(ELinkList L) {
    return L.tail;
}

/*
 * ǰ��
 *
 * ��ȡ���p��ǰ������������ڣ��򷵻�NULL��
 */
Position PriorPos(ELinkList L, Link p) {
    Link pre;
    
    // ȷ������(ͷ���)����
    if(L.head == NULL) {
        return NULL;
    }
    
    if(p == NULL) {
        return NULL;
    }
    
    // ָ��ͷ���
    pre = L.head;
    
    // ��һ�������ǰ��
    if(pre->next == p) {
        return NULL;
    }
    
    // ����P��ǰ��
    while(pre != NULL && pre->next != p) {
        pre = pre->next;
    }
    
    return pre;
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
 * ǰ�����
 *
 * ��s�����뵽p���֮ǰ������pָ���½��
 */
Status InsBefore(ELinkList* L, Link* p, Link s) {
    Link pre;
    
    if(L == NULL || (*L).head == NULL || p == NULL || s == NULL) {
        return ERROR;
    }
    
    // ָ��ͷ���
    pre = (*L).head;
    
    // ����p���Ĺ���ǰ���������ڵ�һ��Ԫ�أ���ǰ��Ϊͷ���
    while(pre != NULL && pre->next != (*p)) {
        pre = pre->next;
    }
    
    // û�ҵ�����ǰ��
    if(pre == NULL) {
        return ERROR;
    }
    
    s->next = *p;
    pre->next = s;
    *p = s;
    
    (*L).len++;                            //�޸�len�����õ�*L
    
    return OK;
}

/*
 * �������
 *
 * ��s�����뵽p���֮ǰ������pָ���½��
 */
Status InsAfter(ELinkList* L, Link* p, Link s) {
    Link r;
    
    if(L == NULL || (*L).head == NULL || p == NULL || s == NULL) {
        return ERROR;
    }
    
    r = (*L).head;
    
    while(r != NULL && r != (*p)) {
        r = r->next;
    }
    
    // ���δ�ҵ����p�����ش�����Ϣ
    if(r == NULL) {
        return ERROR;
    }
    
    // ���pָ�����һ����㣬����Ҫ����βָ��
    if(*p == (*L).tail) {
        (*L).tail = s;
    }
    
    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;
    
    (*L).len++;
    
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

/*
 * ��β���Ƴ�
 *
 * �������β����Ƴ����������Ƴ��Ľ�����ô洢��q��
 */
Status Remove(ELinkList* L, Link* q) {
    Link p;
    
    if(L == NULL || (*L).head == NULL || q == NULL) {
        return ERROR;
    }
    
    // û��Ԫ�ؿɹ��Ƴ�
    if((*L).len == 0) {
        *q = NULL;
        return ERROR;
    }
    
    *q = (*L).tail;
    
    // ȷ���µ�β���λ��
    p = (*L).head;
    while(p->next != (*L).tail) {
        p = p->next;
    }
    p->next = NULL;
    (*L).tail = p;
    
    (*L).len--;
    
    return OK;
}
