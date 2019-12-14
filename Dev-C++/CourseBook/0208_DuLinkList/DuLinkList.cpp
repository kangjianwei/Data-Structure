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
 * ����(�ṹ)
 *
 * �ͷ�˫��ѭ��������ռ�ڴ档
 */
Status DestroyList(DuLinkList* L) {
    // ȷ������ṹ����
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    ClearList(*L);
    
    free(*L);
    
    *L = NULL;
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ�˫��ѭ�������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(DuLinkList L) {
    DuLinkList p, q;
    
    if(L == NULL) {
        return ERROR;
    }
    
    p = L->next;
    
    while(p != L) {
        q = p->next;
        free(p);
        p = q;
    }
    
    L->next = L->prior = L;
    
    return OK;
}

/*
 * �п�
 *
 * �ж�˫��ѭ���������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˫��ѭ������Ϊ��
 * FALSE: ˫��ѭ������Ϊ��
 */
Status ListEmpty(DuLinkList L) {
    if(L != NULL && L->next == L && L->prior == L) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ����
 *
 * ����˫��ѭ�������������ЧԪ�ص�������
 */
int ListLength(DuLinkList L) {
    DuLinkList p;
    int i;
    
    if(L == NULL || L->next == L || L->prior == L) {
        return 0;
    }
    
    i = 0;
    p = L->next;
    
    // �������н��
    while(p != L) {
        i++;
        p = p->next;
    }
    
    return i;
}

/*
 * ȡֵ
 *
 * ��ȡ˫��ѭ�������е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(DuLinkList L, int i, ElemType* e) {
    DuLinkList p;
    int j;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return ERROR;
    }
    
    p = L;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̲�ΪL
    while(p->next != L && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(p->next == L || j > i - 1) {
        return ERROR;
    }
    
    *e = p->next->data;
    
    return OK;
}

/*
 * ����
 *
 * ����˫��ѭ���������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(DuLinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    DuLinkList p;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return 0;
    }
    
    i = 1;          // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L->next;    // p�ĳ�ֵΪ��1��Ԫ�ص�ָ��
    
    while(p != L && !Compare(p->data, e)) {
        i++;
        p = p->next;
    }
    
    if(p != L) {
        return i;
    } else {
        return 0;
    }
}

/*
 * ǰ��
 *
 * ��ȡԪ��cur_e��ǰ����
 * ������ڣ�����洢��pre_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType* pre_e) {
    DuLinkList p;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    p = L->next;
    
    // ��1��Ԫ��û��ǰ��
    if(p->data == cur_e) {
        return ERROR;
    }
    
    // ָ���2��Ԫ��
    p = p->next;
    
    // �ӵ�2��Ԫ�ؿ�ʼ������cur_e��λ��
    while(p != L && p->data != cur_e) {
        p = p->next;
    }
    
    // ���û�ҵ�Ԫ��cur_e������ʧ�ܣ�����ERROR
    if(p == L) {
        return ERROR;
    }
    
    *pre_e = p->prior->data;
    
    return OK;
}

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType* next_e) {
    DuLinkList p;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    p = L->next;
    
    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̲�ΪL
    while(p->next != L && p->data != cur_e) {
        p = p->next;
    }
    
    // ���û�ҵ�cur_e�������ҵ��ˣ�����û�к�̣�������ERROR
    if(p->next == L) {
        return ERROR;
    }
    
    *next_e = p->next->data;
    
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
 * ���������������� �㷨2.19 ����������������
 *
 * ɾ��
 *
 * ɾ��˫��ѭ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(DuLinkList L, int i, ElemType* e) {
    DuLinkList p;
    
    // ȷ��˫��ѭ���������
    if(L == NULL || L->next == L || L->prior == L) {
        return ERROR;
    }
    
    // ���ҵ�i�����λ�ã����ã�
    if((p = GetElemP(L, i)) == NULL) {
        return ERROR;
    }
    
    // ���p==L��˵����ɾ��Ԫ���ǵ�len+1��Ԫ�أ����Ϲ�
    if(p == L) {
        return ERROR;
    }
    
    *e = p->data;
    
    // �Ƴ�p���
    p->prior->next = p->next;
    p->next->prior = p->prior;
    
    free(p);
    
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
