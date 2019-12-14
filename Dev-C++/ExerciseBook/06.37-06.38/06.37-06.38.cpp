#include <stdio.h>
#include "Status.h"     //**01 ����**//
#include "SqStack.h"    //**03 ջ�Ͷ���**//
#include "BiTree.h"     //**06 ���Ͷ�����**//

/*
 * ��������ķǵݹ���ʽ
 */
Status Algo_6_37(BiTree T);

/*
 * ��������ķǵݹ���ʽ
 */
Status Algo_6_38(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("���������� T ��...\n");
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("�������� 6.37 ��֤...������\n");
    {
        printf("�����������������Ϊ��");
        Algo_6_37(T);
        printf("\n");
    }
    
    printf("�������� 6.38 ��֤...������\n");
    {
        printf("�����������������Ϊ��");
        Algo_6_38(T);
        printf("\n");
    }
    
    return 0;
}


/*
 * ��������ķǵݹ���ʽ
 */
Status Algo_6_37(BiTree T) {
    SqStack S;
    SElemType e;
    
    if(BiTreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitStack(&S);
    Push(&S, T);
    
    while(!StackEmpty(S)) {
        GetTop(S, &e);
        printf("%c ", e->data);
        
        if(e->lchild) {
            Push(&S, e->lchild);
        } else {
            while(!StackEmpty(S)) {
                Pop(&S, &e);
                
                if(e->rchild) {
                    Push(&S, e->rchild);
                    break;
                }
            }
        }
    }
    
    printf("\n");
    return OK;
}

/*
 * ��������ķǵݹ���ʽ
 */
Status Algo_6_38(BiTree T) {
    SqStack S;
    BiTree p;
    SElemType e;
    int StackMark[100] = {0};    // ���ջ�����ø������ʱ�ǣ���ʼ��Ϊ0��
    int k;
    
    if(BiTreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitStack(&S);
    p = T;
    k = -1;
    
    while(TRUE) {
        while(p) {
            Push(&S, p);
            k++;
            StackMark[k] = 1;   // ���õ�һ�η��ʵı��
            p = p->lchild;
        }
        
        // pΪ�յ�ջ��Ϊ��
        while(!p && !StackEmpty(S)) {
            GetTop(S, &p);
            
            // �ѷ��ʹ�һ�Σ���ǰ�ǵڶ��η���
            if(StackMark[k] == 1) {
                StackMark[k] = 2;
                p = p->rchild;
                
                // �ѷ��ʹ����Σ���ǰ�ǵ����η���
            } else {
                printf("%c ", p->data);
                Pop(&S, &e);
                StackMark[k] = 0;
                k--;
                p = NULL;
            }
        }
        
        if(StackEmpty(S)) {
            break;
        }
    }
    
    printf("\n");
    return OK;
}
