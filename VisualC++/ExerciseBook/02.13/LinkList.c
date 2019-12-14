/*===============================
 * ���Ա����ʽ�洢�ṹ������
 *
 * �����㷨: 2.8��2.9��2.10��2.11
 ================================*/

#include "LinkList.h" //**��02 ���Ա�**//

/*
 * ��ʼ��
 *
 * ֻ�ǳ�ʼ��һ��ͷ��㡣
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(LinkList* L) {
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    (*L)->next = NULL;
    
    return OK;
}

/*
 * ����
 *
 * �����������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    LinkList p;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return 0;
    }
    
    i = 1;          // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L->next;    // p�ĳ�ֵΪ��1��Ԫ�ص�ָ��
    
    while(p != NULL && !Compare(p->data, e)) {
        i++;
        p = p->next;
    }
    
    if(p != NULL) {
        return i;
    } else {
        return 0;
    }
}

/*
 * ���������������� �㷨2.9 ����������������
 *
 * ����
 *
 * �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(LinkList L, int i, ElemType e) {
    LinkList p, s;
    int j;
    
    // ȷ�������
    if(L == NULL) {
        return ERROR;
    }
    
    p = L;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý�㱾��ΪNULL
    while(p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(p == NULL || j > i - 1) {
        return ERROR;
    }
    
    // �����½��
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return;
    }
    
    p = L->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}
