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
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ棬ͷ���Ҳ�ᱻ����
 */
Status DestroyList(LinkList* L) {
    LinkList p;
    
    // ȷ������ṹ����
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    p = *L;
    
    while(p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    
    *L = NULL;
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(LinkList L) {
    LinkList pre, p;
    
    // ȷ���������
    if(L == NULL) {
        return ERROR;
    }
    
    p = L->next;
    
    // �ͷ����������н����ռ�ڴ�
    while(p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    
    L->next = NULL;
    
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
Status ListEmpty(LinkList L) {
    // ����ֻ��ͷ���ʱ����Ϊ������Ϊ��
    if(L != NULL && L->next == NULL) {
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
int ListLength(LinkList L) {
    LinkList p;
    int i;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return 0;
    }
    
    i = 0;
    p = L->next;
    
    // �������н��
    while(p != NULL) {
        i++;
        p = p->next;
    }
    
    return i;
}

/*
 * ���������������� �㷨2.8 ����������������
 *
 * ȡֵ
 *
 * ��ȡ�����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(LinkList L, int i, ElemType* e) {
    LinkList p;
    int j;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    p = L;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̲�ΪNULL
    while(p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(p->next == NULL || j > i - 1) {
        return ERROR;
    }
    
    *e = p->next->data;
    
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
 * ǰ��
 *
 * ��ȡԪ��cur_e��ǰ����
 * ������ڣ�����洢��pre_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
    LinkList pre, next;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    pre = L->next;
    
    // ��1��Ԫ��û��ǰ��
    if(pre->data == cur_e) {
        return ERROR;
    }
    
    // ָ���2��Ԫ��
    next = pre->next;
    
    // �ӵ�2��Ԫ�ؿ�ʼ������cur_e��λ��
    while(next != NULL && next->data != cur_e) {
        pre = next;
        next = next->next;
    }
    
    // ���û�ҵ�Ԫ��cur_e������ʧ�ܣ�����ERROR
    if(next == NULL) {
        return ERROR;
    }
    
    *pre_e = pre->data;
    
    return OK;
}

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e) {
    LinkList pre;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    pre = L->next;
    
    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̲�ΪNULL
    while(pre->next != NULL && pre->data != cur_e) {
        pre = pre->next;
    }
    
    // ���û�ҵ�cur_e�������ҵ��ˣ�����û�к�̣�������ERROR
    if(pre->next == NULL) {
        return ERROR;
    }
    
    *next_e = pre->next->data;
    
    return OK;
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
 * ���������������� �㷨2.10 ����������������
 *
 * ɾ��
 *
 * ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(LinkList L, int i, ElemType* e) {
    LinkList p, q;
    int j;
    
    // ȷ����������Ҳ�Ϊ�ձ�
    if(L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    p = L;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̲�ΪNULL
    while(p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(p->next == NULL || j > i - 1) {
        return ERROR;
    }
    
    // ɾ����i�����
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    
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

/*
 * ���������������� �㷨2.11 ����������������
 *
 * ͷ�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Head(LinkList* L, int n, char* path) {
    int i;
    LinkList p;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        printf("������%d������Ԫ�أ�", n);

        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            scanf("%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }

        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }

        fclose(fp);
    }

    return OK;
}

/*
 * β�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Tail(LinkList* L, int n, char* path) {
    int i;
    LinkList p, q;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        printf("������%d������Ԫ�أ�", n);

        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            scanf("%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }

        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;

        fclose(fp);
    }

    return OK;
}

