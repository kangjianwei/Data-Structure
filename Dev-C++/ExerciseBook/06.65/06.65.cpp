#include <stdio.h>
#include <string.h>     // �ṩstrlenԭ��
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

/* ȫ�ֱ��� */
char Pre[] = "ABDGEHICFJ";  // ǰ������
char In[] = "GDBHEIAFJC";  // ��������

/*
 * ��ǰ�����к��������й��������
 */
Status Algo_6_65(BiTree* T);

// ������������ڲ�ʵ��
BiTree BuildTree(int pre_start, int pre_end, int in_start, int in_end);    //�ݹ鴴��������


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("��������������Ϊ��%s\n", Pre);
    printf("��������������Ϊ��%s\n", In);
    printf("\n");
    
    printf("�ɴ˹���Ķ�����Ϊ T = \n");
    Algo_6_65(&T);
    PrintGraph(T);
    printf("\n");
    
    return 0;
}


/*
 * ��ǰ�����к��������й��������
 */
Status Algo_6_65(BiTree* T) {
    int len_pre, len_in;
    
    len_pre = strlen(Pre);
    len_in = strlen(In);
    
    if(len_pre == 0 || len_in == 0 || len_pre != len_in) {
        return ERROR;
    }
    
    *T = BuildTree(0, len_pre - 1, 0, len_in - 1);
    
    return OK;
}

// ������������ڲ�ʵ��
BiTree BuildTree(int pre_start, int pre_end, int in_start, int in_end) {
    BiTree T;
    int i, LTreeLen, RTreeLen;
    
    T = (BiTree) malloc(sizeof(BiTNode));   // ���������
    if(T == NULL) {
        exit(OVERFLOW);
    }
    T->data = Pre[pre_start];       // ����ǰ��洢�Ľ��
    T->lchild = T->rchild = NULL;   // ��ʼ��ʱ�ÿ����Һ���ָ��
    
    i = in_start;
    while(In[i] != T->data) {   // ������������Ѱ�Ҹ����λ��
        i++;
    }
    
    LTreeLen = i - in_start;    // ����������
    RTreeLen = in_end - i;      // ����������
    
    // ����������
    if(LTreeLen) {
        T->lchild = BuildTree(pre_start + 1, pre_start + LTreeLen, in_start, i - 1);
    }
    
    // ����������
    if(RTreeLen) {
        T->rchild = BuildTree(pre_start + LTreeLen + 1, pre_end, i + 1, in_end);
    }
    
    return T;
}
