/*=================================
 * ��̬����
 *
 * �����㷨: 2.13��2.14��2.15��2.16
 ==================================*/

#include "SLinkList.h"

/*
 * ���� ��ʾ ����
 *
 * �������к������β��У�
 * space��ָʾ���ÿռ�
 * S    ��ָʾ��̬����ͷ�������
 */

/*�������������������������������������������� ���ÿռ���� ��������������������������������������������*/

/*
 * ���������������� �㷨2.14 ����������������
 *
 * ��ʼ�����ÿռ�
 *
 * ���ÿռ�Ϊ��̬�����ṩ���õ��ڴ档
 */
void InitSpace(SLinkList space) {
    int i;
    
    for(i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    
    space[MAXSIZE - 1].cur = 0;
}

/*
 * ���������������� �㷨2.15 ����������������
 *
 * ����ռ�
 *
 * Ϊ��̬����ӱ��ÿռ�������ռ䣬
 * �������ɹ������ؿ��ÿռ��������
 * ����ʧ��ʱ������0��
 */
int Malloc(SLinkList space) {
    int i = space[0].cur;
    
    if(i != 0) {
        // �����뵽�Ŀռ�ӱ��ÿռ���ɾȥ
        space[0].cur = space[i].cur;
    }
    
    // �������������±�
    return i;
}

/*
 * ���������������� �㷨2.16 ����������������
 *
 * ���տռ�
 *
 * ��������k���Ľ��ռ��Թ���̬����������ã�
 * ���շ�ʽ���ǽ��ý��ռ�Ӿ�̬�������Ƴ���
 * ��������ӵ����ÿռ���б��С�
 */
void Free(SLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}


/*�������������������������������������������� ��̬������� ��������������������������������������������*/

/*
 * ��ʼ��
 *
 * �ȳ�ʼ�����ÿռ䣬����ӱ��ÿռ�������ͷ���Ŀռ䣬������ɾ�̬����ĳ�ʼ����
 * ��ʼ���ɹ���ʹ��S�洢ͷ����������ҷ���OK�����򷵻�ERROR��
 */
Status InitList(SLinkList space, int* S) {
    int index;
    
    // ��ʼ�����ÿռ�
    InitSpace(space);
    
    // ����ͷ���ռ�
    index = Malloc(space);
    
    if(index == 0) {
        return ERROR;
    }
    
    space[index].cur = 0;
    
    *S = index;
    
    return OK;
}

/*
 * ����(�ṹ)
 *
 * �ͷž�̬������ռ�ڴ棬������̬�������н��ռ����뱸�ÿռ��б��С�
 */
Status DestroyList(SLinkList space, int* S) {
    int cur;
    
    // ȷ����̬�������
    if(S == NULL || *S == 0) {
        return ERROR;
    }
    
    while(*S != 0) {
        // �ݴ���һ����������
        cur = space[*S].cur;
        // ���յ�ǰ�����ռ�ռ�
        Free(space, *S);
        // ǰ������һ������������
        *S = cur;
    }
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷž�̬�����з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(SLinkList space, int S) {
    int P;
    int cur;
    
    // ȷ����̬�������
    if(S == 0) {
        return ERROR;
    }
    
    // ��ȡ��̬�����׸���������
    P = space[S].cur;
    
    while(P != 0) {
        // �ݴ���һ����������
        cur = space[P].cur;
        // ���յ�ǰ�����ռ�ռ�
        Free(space, P);
        // ǰ������һ������������
        P = cur;
    }
    
    space[S].cur = 0;
    
    return OK;
}

/*
 * �п�
 *
 * �жϾ�̬�������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��̬����Ϊ��
 * FALSE: ��̬����Ϊ��
 */
Status ListEmpty(SLinkList space, int S) {
    // ֻ����ͷ���ľ�̬������Ϊ�ձ�
    if(S != 0 && space[S].cur == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ����
 *
 * ���ؾ�̬�����������ЧԪ�ص�������
 */
int ListLength(SLinkList space, int S) {
    int count;
    
    // ��̬�������ڣ���̬����Ϊ��ʱ������0
    if(S == 0 || space[S].cur == 0) {
        return 0;
    }
    
    // ��ȡ��̬�����׸�Ԫ�ص�����
    S = space[S].cur;
    count = 0;
    
    while(S != 0) {
        count++;
        S = space[S].cur;
    }
    
    return count;
}

/*
 * ȡֵ
 *
 * ��ȡ��̬�����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(SLinkList space, int S, int i, ElemType* e) {
    int count;
    
    // ȷ����̬��������Ҳ�Ϊ��
    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }
    
    // ��ȡ��̬�����׸�Ԫ�ص�����
    S = space[S].cur;
    count = 0;
    
    while(S != 0 && count < i - 1) {
        count++;
        S = space[S].cur;
    }
    
    if(S == 0 || count > i - 1) {
        return ERROR;
    }
    
    *e = space[S].data;
    
    return OK;
}

/*
 * ���������������� �㷨2.13 ����������������
 *
 * ����
 *
 * ���ؾ�̬�������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * 1.Ԫ��e��Compare�����ڶ����β�
 * 2.�����ʵ����̲��ϵ��㷨2.13����ͬ��ԭ��μ������ġ�ע�⡱��Ϣ
 */
int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    int p;
    
    // ȷ����̬��������Ҳ�Ϊ��
    if(S == 0 || space[S].cur == 0) {
        return 0;
    }
    
    i = 1;              // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = space[S].cur;   // p�ĳ�ֵΪ��1��Ԫ�ص�����
    
    while(p != 0 && !Compare(space[p].data, e)) {
        i++;
        p = space[p].cur;
    }
    
    if(p != 0) {
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
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e) {
    int pre, next;
    
    // ȷ����̬��������Ҳ�Ϊ��
    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    pre = space[S].cur;
    
    // ��1��Ԫ��û��ǰ��
    if(space[pre].data == cur_e) {
        return ERROR;
    }
    
    // ָ���2��Ԫ��
    next = space[pre].cur;
    
    // �ӵ�2��Ԫ�ؿ�ʼ������cur_e��λ��
    while(next != 0 && space[next].data != cur_e) {
        pre = next;
        next = space[next].cur;
    }
    
    // ���û�ҵ�Ԫ��cur_e������ʧ�ܣ�����ERROR
    if(next == 0) {
        return ERROR;
    }
    
    *pre_e = space[pre].data;
    
    return OK;
}

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e) {
    int pre;
    
    // ȷ����̬��������Ҳ�Ϊ��
    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }
    
    // ָ���1��Ԫ��
    pre = space[S].cur;
    
    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̴���
    while(space[pre].cur != 0 && space[pre].data != cur_e) {
        pre = space[pre].cur;
    }
    
    // ���û�ҵ�cur_e�������ҵ��ˣ�����û�к�̣�������ERROR
    if(space[pre].cur == 0) {
        return ERROR;
    }
    
    *next_e = space[space[pre].cur].data;
    
    return OK;
}

/*
 * ����
 *
 * ��̬�����i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(SLinkList space, int S, int i, ElemType e) {
    int p, s;
    int j;
    
    // ȷ����̬�������
    if(S == 0) {
        return ERROR;
    }
    
    p = S;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý�㱾�����
    while(p != 0 && j < i - 1) {
        p = space[p].cur;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(p == 0 || j > i - 1) {
        return ERROR;
    }
    
    // �����½��
    s = Malloc(space);
    space[s].data = e;
    space[s].cur = space[p].cur;
    space[p].cur = s;
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ����̬�����i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(SLinkList space, int S, int i, ElemType* e) {
    int p, q;
    int j;
    
    // ȷ����̬�������
    if(S == 0) {
        return ERROR;
    }
    
    p = S;
    j = 0;
    
    // Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̴���
    while(space[p].cur != 0 && j < i - 1) {
        p = space[p].cur;
        ++j;
    }
    
    // ���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��
    if(space[p].cur == 0 || j > i - 1) {
        return ERROR;
    }
    
    // ɾ����i�����
    q = space[p].cur;
    space[p].cur = space[q].cur;
    *e = space[q].data;
    Free(space, q);
    
    return OK;
}

/*
 * ����
 *
 * ��visit�������ʾ�̬����S
 */
void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)) {
    int p;
    
    // ȷ���������
    if(S == 0 || space[S].cur == 0) {
        return;
    }
    
    p = space[S].cur;
    
    while(p != 0) {
        Visit(space[p].data);
        p = space[p].cur;
    }
    
    printf("\n");
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(SLinkList space, int S) {
    int i = 0;
    
    printf("==== ���ÿռ� ====\n");
    while(i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
    
    printf("==== ��̬���� ====\n");
    i = S;
    while(i>0 && i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}

