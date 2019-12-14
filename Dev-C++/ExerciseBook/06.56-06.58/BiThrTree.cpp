/*=======================
 * ����������
 *
 * �����㷨: 6.5��6.6��6.7
 ========================*/

#include "BiThrTree.h"

/*
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
Status CreateBiTree(BiThrTree* T, char* path) {
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
 * ���������������� �㷨6.6 ����������������
 *
 * �������������T��������ȫ������Ϊ����������Thrt��
 * ע���������������ǰ����������������
 */
Status InOrderThreading(BiThrTree* Thrt, BiThrTree T) {
    // ����ͷ���
    *Thrt = (BiThrTree) malloc(sizeof(BiThrNode));
    if(!*Thrt) {
        exit(OVERFLOW);
    }
    
    (*Thrt)->data = '\0';
    
    (*Thrt)->LTag = Link;       // ���ӣ���Ҫָ��������ĸ����
    (*Thrt)->RTag = Thread;     // ��ָ�룬��Ҫָ�������������һ��Ԫ�أ��Ա��������������������
    
    (*Thrt)->rchild = *Thrt;
    
    // ��������Ϊ�գ�����ָ���ָ
    if(!T) {
        (*Thrt)->lchild = *Thrt;
    } else {
        (*Thrt)->lchild = T;    // ָ�������ͷ���
        pre = *Thrt;            // ��¼ǰ����Ϣ����ʼ��Ϊ����������ͷ���
        
        InTheading(T);          // ����������Խ�������������
        
        pre->rchild = *Thrt;    // ���һ�����ָ������������ͷ���
        pre->RTag = Thread;     // ���һ�����������
        (*Thrt)->rchild = pre;  // ͷ���ָ�����һ����㣬����˫����ϵ
    }
    
    return OK;
    
}

/*
 * ���������������� �㷨6.5 ����������������
 *
 * �����������ȫ�������������ǵݹ��㷨����
 */
Status InOrderTraverse_Thr(BiThrTree T, Status(Visit)(TElemType)) {
    BiThrTree p = T->lchild;    // pָ�����������㣨��ͬ��������������ͷ��㣩
    
    // �������������ʱ��p==T
    while(p != T) {
        // ����������ӣ�������������
        while(p->LTag == Link) {
            p = p->lchild;
        }
        
        // ����������Ϊ�յĽ�㣨����ߣ�
        if(!Visit(p->data)) {
            return ERROR;
        }
        
        // ������ں����������û����������
        while(p->RTag == Thread && p->rchild != T) {
            p = p->rchild;   // ��pָ������
            Visit(p->data);  // ���ʺ�̽��
        }
        
        // ����������
        p = p->rchild;
    }
    
    printf("\n");
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiThrTree* T, FILE* fp) {
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
        *T = (BiThrTree) malloc(sizeof(BiThrNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild), fp); // ����������
        CreateTree(&((*T)->rchild), fp); // ����������
    }
}

/*
 * ���������������� �㷨6.7 ����������������
 *
 * ����ȫ���������ڲ�ʵ��
 */
static void InTheading(BiThrTree p) {
    if(p) {
        InTheading(p->lchild);  // ������������
        
        // �����ǰ����������Ϊ�գ�����Ҫ����ǰ������
        if(!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
            
            // �����������Ϊ�գ�������ӱ�ǣ��̲���ȱ����һ���裩
        } else {
            p->LTag = Link;
        }
        
        // ���ǰ������������Ϊ�գ���Ϊǰ����㽨���������
        if(!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
    
            // �����������Ϊ�գ�����Һ��ӱ�ǣ��̲���ȱ����һ���裩
        } else {
            p->RTag = Link;
        }
        
        pre = p;                // pre��ǰŲһ��
        
        InTheading(p->rchild);  // ������������
    }
}
