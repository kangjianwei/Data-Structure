/*===================================
 * ���Ķ�����������-�ֵܣ��ṹ�洢��ʾ
 ====================================*/

#include "CSTree.h"

/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * ����
 *
 * ����Ԥ��Ķ�������������
 * ����Լ��ʹ�á��������С�����������
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
Status CreateTree(CSTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("�����������������У����û�к��ӽ���û���ֵܽڵ㣬ʹ��^���棺");
        Create(T, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Create(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty(CSTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(CSTree T) {
    int max = 0;
    
    Depth(T, 0, &max);
    
    return max;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(CSTree* T, FILE* fp) {
    char ch;
    
    // ��ȡ��ǰ����ֵ
    if(fp == NULL) {
        scanf("%c", &ch);
    } else {
        ReadData(fp, "%c", &ch);
    }
    
    if(ch == '^') {
        *T = NULL;
    } else {
        // ���ɸ����
        *T = (CSTree) malloc(sizeof(CSNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        Create(&((*T)->firstchild), fp);    // ��������
        Create(&((*T)->nextsibling), fp);   // �������ֵ�
    }
}

// ����������ȵ��ڲ�ʵ��
static void Depth(CSTree T, int d, int* max) {
    if(T == NULL) {
        return;
    }
    
    d++;    // ָʾ��ǰ���ڵĲ���
    
    if(d > *max) {
        *max = d;
    }
    
    Depth(T->firstchild, d, max);       // ���±���
    Depth(T->nextsibling, --d, max);    // ���ұ���
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(CSTree T) {
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    Print(T, 0);
    
    printf("\n");
}

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(CSTree T, int row) {
    int k;
    
    if(T == NULL) {
        return;
    }
    
    // ���ʵ�ǰ���
    printf("%c ", T->data);
    
    Print(T->firstchild, row + 1);
    
    if(T->nextsibling != NULL) {
        printf("\n");
        
        for(k = 0; k < row; k++) {
            printf(". ");
        }
        
        Print(T->nextsibling, row);
    }
}
