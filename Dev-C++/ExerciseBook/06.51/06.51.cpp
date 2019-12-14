#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

/*
 * ����������ʽ���ɵĶ����������������
 */
void Algo_6_51(BiTree T);

// �ж��ַ�c�Ƿ�Ϊ������
Status IsOperator(char c);

// �ж����������������ȼ�
Status Priority(char a, char b);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("�������������������У�T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("����������ʽ��");
    Algo_6_51(T);
    printf("\n");
    
    return 0;
}


/*
 * ����������ʽ���ɵĶ����������������
 */
void Algo_6_51(BiTree T) {
    if(T == NULL) {
        return;
    }
    
    if(T->lchild != NULL) {
        // ��ǰ���������ǲ����������ȼ����ڵ�ǰ���
        if(IsOperator(T->lchild->data) && Priority(T->lchild->data, T->data) < 0) {
            printf("(");
            Algo_6_51(T->lchild);
            printf(")");
        } else {
            Algo_6_51(T->lchild);
        }
    }
    
    printf("%c", T->data);
    
    if(T->rchild != NULL) {
        // ��ǰ�����Һ����ǲ����������ȼ����ڵ�ǰ���
        if(IsOperator(T->rchild->data) && Priority(T->rchild->data, T->data) < 0) {
            printf("(");
            Algo_6_51(T->rchild);
            printf(")");
        } else {
            Algo_6_51(T->rchild);
        }
    }
}

// �ж��ַ�c�Ƿ�Ϊ������
Status IsOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return TRUE;
    } else {
        return ERROR;
    }
}

// �ж����������������ȼ�
Status Priority(char a, char b) {
    // a�����ȼ���
    if((a == '+' || a == '-') && (b == '*' || b == '/')) {
        return -1;
        
        // a�����ȼ���
    } else if((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return 1;
        
        // ���ȼ���ͬ
    } else {
        return 0;
    }
}
