/*=============================
 * �������Ķ�������洢�ṹ
 *
 * �����㷨: 6.1��6.2��6.3��6.4
 =============================*/

#include "BiTree.h"
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//

/*
 * ���������������� �㷨6.4 ����������������
 *
 * ����
 *
 * ����Ԥ��Ķ�����������������
 * ����Լ��ʹ�á��������С���������������
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
Status CreateBiTree(BiTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("��������������������У����û���ӽ�㣬ʹ��^���棺");
        CreateTree(T, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        CreateTree(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(BiTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(BiTree T) {
    int LD, RD;
    
    if(T == NULL) {
        return 0;                       // �������Ϊ0
    } else {
        LD = BiTreeDepth(T->lchild);    // �����������
        RD = BiTreeDepth(T->rchild);    // �����������
        
        return (LD >= RD ? LD : RD) + 1;
    }
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiTree* T, FILE* fp) {
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
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild), fp); // ����������
        CreateTree(&((*T)->rchild), fp); // ����������
    }
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(BiTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    LinkQueue Q;
    BiTree e;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    level = BiTreeDepth(T);         // ����ȫ���������ṹ�߶�
    width = (int)pow(2, level)-1;   // ����ȫ���������ṹ���
    
    // ��̬������
    tmp = (TElemType**)malloc(level* sizeof(TElemType*));
    
    // ��̬������
    for(i = 0; i < level; i++) {
        tmp[i] = (TElemType*)malloc(width* sizeof(TElemType));
        
        // ��ʼ���ڴ�ֵΪ���ַ�
        memset(tmp[i], '\0', width);
    }
    
    // ��������ʵ�ֲ������
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    // ������������Ԫ�أ����䰲�ŵ���ά����tmp�к��ʵ�λ��
    for(i = 0; i < level; i++) {
        w        = (int) pow(2, i);             // ��������ǰ��Ŀ��
        distance = width / w;                   // ��������ǰ���Ԫ�ؼ��
        begin    = width / (int) pow(2, i + 1); // ��������ǰ���׸�Ԫ��֮ǰ�Ŀո���
        
        for(k = 0; k < w; k++) {
            DeQueue(&Q, &e);
            
            if(e == NULL) {
                EnQueue(&Q, NULL);
                EnQueue(&Q, NULL);
            } else {
                j = begin + k * (1 + distance);
                tmp[i][j] = e->data;
                
                // �������
                EnQueue(&Q, e->lchild);
                
                // �Һ������
                EnQueue(&Q, e->rchild);
            }
        }
    }
    
    for(i = 0; i < level; i++) {
        for(j = 0; j < width; j++) {
            if(tmp[i][j] != '\0') {
                printf("%c", tmp[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
