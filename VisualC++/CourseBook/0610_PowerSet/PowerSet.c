/*===================
 * �缯
 *
 * �����㷨: 6.14/6.15
 ====================*/

#include "PowerSet.h"

/*
 * ��������A������Ԫ�����������Ա�Ԫ������һ�¡�
 */
Status CreatePowerSet(List* A, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("�����뼯�ϵ�Ԫ����Ϣ...\n");
        Create(A, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Create(A, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * ���������������� 6.14/6.15 ����������������
 *
 * ��ȡ����A���ݼ�������B�����ݴ�ÿһ��������ݼ��Ӽ���
 */
void GetPowerSet(int i, List A, List B) {
    int k;
    ElemType e;
    
    // i����׷�ٵ�ǰ����Ĳ㼶
    if(i > ListLength(A)) {
        PrintPowerSet(B);
    } else {
        GetElem(A, i, &e);
        k = ListLength(B);
        
        ListInsert(B, k + 1, e);    //+��i��Ԫ��
        GetPowerSet(i + 1, A, B);
        
        ListDelete(B, k + 1, &e);   //-��i��Ԫ��
        GetPowerSet(i + 1, A, B);
    }
}

/*
 * �����ǰ���ϡ�
 */
void PrintPowerSet(List A) {
    LinkList p;
    int len;
    
    if(A == NULL) {
        printf("\n");
        return;
    }
    
    len = ListLength(A);
    
    // ����ռ�
    if(len == 0) {
        printf("��");
    } else {
        // ��������е�Ԫ��
        for(p = A->next; p; p = p->next) {
            printf("%-2d ", p->data);
        }
    }
    
    printf("\n");
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������ϵ��ڲ�����
static void Create(List* A, FILE* fp) {
    int n, i, e;
    
    InitList(A);
    
    if(fp == NULL) {
        printf("�����뼯��Ԫ��������");
        scanf("%d", &n);
    
        for(i=1; i<=n; i++) {
            printf("������� %2d ��Ԫ�أ�", i);
            scanf("%d", &e);
            ListInsert(*A, i, e);
        }
    } else {
        // ¼��Ԫ������
        ReadData(fp, "%d", &n);
        
        // ¼��Ԫ��
        for(i=1; i<=n; i++) {
            ReadData(fp, "%d", &e);
            ListInsert(*A, i, e);
        }
    }
}
