/*=============================
 * ���Ա��˳��洢�ṹ��˳���
 *
 * �����㷨: 2.3��2.4��2.5��2.6
 =============================*/

#include "SqList.h"

/*
 * ���������������� �㷨2.3 ����������������
 *
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(SqList* L) {
    // ����ָ���������ڴ棬�������ʧ�ܣ��򷵻�NULL
    (*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if((*L).elem == NULL) {
        // �洢�ڴ�ʧ��
        exit(OVERFLOW);
    }

    (*L).length = 0;                    // ��ʼ��˳�����Ϊ0
    (*L).listsize = LIST_INIT_SIZE;     // ˳����ʼ�ڴ������

    return OK;                          // ��ʼ���ɹ�
}

/*
 * ����(�ṹ)
 *
 * �ͷ�˳�����ռ�ڴ档
 */
Status DestroyList(SqList* L) {
    // ȷ��˳���ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }

    // �ͷ�˳����ڴ�
    free((*L).elem);

    // �ͷ��ڴ���ÿ�ָ��
    (*L).elem = NULL;

    // ˳����ȸ�����������
    (*L).length = 0;
    (*L).listsize = 0;

    return OK;
}

/*
 * �ÿ�(����)
 *
 * ֻ������˳����д洢�����ݣ����ͷ�˳�����ռ�ڴ档
 */
Status ClearList(SqList* L) {
    // ȷ��˳���ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }

    (*L).length = 0;

    return OK;
}

/*
 * �п�
 *
 * �ж�˳������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˳���Ϊ��
 * FALSE: ˳���Ϊ��
 */
Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ����˳����������ЧԪ�ص�������
 */
int ListLength(SqList L) {
    return L.length;
}

/*
 * ȡֵ
 *
 * ��ȡ˳����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(SqList L, int i, ElemType* e) {
    // ��Ϊi�ĺ�����λ�ã�������Ϸ���Χ�ǣ�[1, length]
    if(i < 1 || i > L.length) {
        return ERROR;                    //iֵ���Ϸ�
    }

    *e = L.elem[i - 1];

    return OK;
}

/*
 * ���������������� �㷨2.6 ����������������
 *
 * ����
 *
 * ����˳������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    ElemType* p;

    // ȷ��˳���ṹ����
    if(L.elem == NULL) {
        return ERROR;
    }

    /*
     * i�ĳ�ֵΪ��1��Ԫ�ص�λ��
     *
     * ��ʵ������Ȼ��д���ǽ�i��ʼ��Ϊ��1��Ԫ�ص�����
     * �����ڽ̲����ǰ�λ������ģ�����������д��λ��
     */
    i = 1;

    // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
    p = L.elem;

    // ����˳���
    while(i <= L.length && !Compare(*p++, e)) {
        ++i;
    }

    if(i <= L.length) {
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
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e) {
    int i;

    // ȷ��˳���ṹ���ڣ������ٰ�������Ԫ��
    if(L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    // �����i��ʼ��Ϊ��1��Ԫ�صġ�������
    i = 0;

    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
    while(i < L.length && L.elem[i] != cur_e) {
        ++i;
    }

    // ���cur_e���׸�Ԫ��(û��ǰ��)������û�ҵ�Ԫ��cur_e������ERROR
    if(i==0 || i >= L.length) {
        return ERROR;
    }

    // �洢cur_e��ǰ��
    *pre_e = L.elem[i - 1];

    return OK;
}

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e) {
    int i;

    // ȷ��˳���ṹ���ڣ������ٰ�������Ԫ��
    if(L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    // �����i��ʼ��Ϊ��1��Ԫ�صġ�������
    i = 0;

    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
    while(i < L.length-1 && L.elem[i] != cur_e) {
        ++i;
    }

    // ���cur_e�����1��Ԫ��(û��ǰ��)������û�ҵ�Ԫ��cur_e������ERROR
    if(i >= L.length-1) {
        return ERROR;
    }

    // �洢cur_e��ǰ��
    *next_e = L.elem[i + 1];

    return OK;
}

/*
 * ���������������� �㷨2.4 ����������������
 *
 * ����
 *
 * ��˳����i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(SqList* L, int i, ElemType e) {
    ElemType* newbase;
    ElemType* p, * q;

    // ȷ��˳���ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }

    // iֵԽ��
    if(i < 1 || i > (*L).length + 1) {
        return ERROR;
    }

    // ���洢�ռ��������������¿ռ�
    if((*L).length >= (*L).listsize) {
        // �������пռ�����
        newbase = (ElemType*) realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL) {
            // �洢�ڴ�ʧ��
            exit(OVERFLOW);
        }

        // �»�ַ
        (*L).elem = newbase;
        // ��Ĵ洢�ռ�
        (*L).listsize += LISTINCREMENT;
    }

    // qΪ����λ��
    q = &(*L).elem[i - 1];

    // 1.����Ԫ�أ��ڳ�λ��
    for(p = &(*L).elem[(*L).length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }

    // 2.����e
    *q = e;

    // 3.����1
    (*L).length++;

    return OK;
}

/*
 * ���������������� �㷨2.5 ����������������
 *
 * ɾ��
 *
 * ɾ��˳����i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(SqList* L, int i, ElemType* e) {
    ElemType* p, * q;

    // ȷ��˳���ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }

    // iֵԽ��
    if(i < 1 || i > (*L).length) {
        return ERROR;
    }

    // pΪ��ɾ��Ԫ�ص�λ��
    p = &(*L).elem[i - 1];

    // 1.��ȡ��ɾ��Ԫ��
    *e = *p;

    // ��βԪ��λ��
    q = (*L).elem + (*L).length - 1;

    // 2.����Ԫ�أ���ɾ��Ԫ�ص�λ���ϻ�����Ԫ�ؽ���
    for(++p; p <= q; ++p) {
        *(p - 1) = *p;
    }

    // 3.����1
    (*L).length--;

    return OK;
}

/*
 * ����
 *
 * ��visit��������˳���L
 */
void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;

    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }

    printf("\n");
}

