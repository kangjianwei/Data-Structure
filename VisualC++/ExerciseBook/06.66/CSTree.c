/*===================================
 * ���Ķ�����������-�ֵܣ��ṹ�洢��ʾ
 ====================================*/

#include "CSTree.h"

/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree_CS(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty_CS(CSTree T) {
    return T == NULL ? TRUE : FALSE;
}

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph_CS(CSTree T) {
    
    // ���������������������
    if(TreeEmpty_CS(T)) {
        printf("\n");
        return;
    }
    
    Print_CS(T, 0);
    
    printf("\n");
}

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print_CS(CSTree T, int row) {
    int k;
    
    if(T == NULL) {
        return;
    }
    
    // ���ʵ�ǰ���
    printf("%c ", T->data);
    
    Print_CS(T->firstchild, row + 1);
    
    if(T->nextsibling != NULL) {
        printf("\n");
        
        for(k = 0; k < row; k++) {
            printf(". ");
        }
        
        Print_CS(T->nextsibling, row);
    }
}
