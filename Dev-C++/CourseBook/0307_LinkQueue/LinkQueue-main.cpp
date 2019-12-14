#include <stdio.h>
#include "LinkQueue.h"        //**03 ջ�Ͷ���**//

// ���Ժ�������ӡ����
void PrintElem(QElemType e);

int main(int argc, char** argv) {
    LinkQueue Q;
    int i;
    QElemType e;
    
    printf("���������������� ���� InitQueue \n");
    {
        printf("�� ��ʼ������ Q ...\n");
        InitQueue(&Q);
    }
    PressEnterToContinue();
    
    printf("���������������� ���� QueueEmpty \n");
    {
        QueueEmpty(Q) ? printf("�� Q Ϊ�գ���\n") : printf("�� Q ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    printf("���������������� ���� EnQueue \n");
    {
        for(i = 1; i <= 6; i++) {
            EnQueue(&Q, 2 * i);
            printf("�� Ԫ�� \"%2d\" ���...\n", 2 * i);
        }
    }
    PressEnterToContinue();
    
    printf("���������������� ���� QueueTraverse \n");
    {
        printf("�� Q �е�Ԫ��Ϊ��Q = ");
        QueueTraverse(Q, PrintElem);
    }
    PressEnterToContinue();
    
    printf("���������������� ���� QueueLength \n");
    {
        i = QueueLength(Q);
        printf("�� Q �ĳ���Ϊ %d \n", i);
    }
    PressEnterToContinue();
    
    printf("���������������� ���� DeQueue \n");
    {
        DeQueue(&Q, &e);
        printf("�� ��ͷԪ�� \"%d\" ����...\n", e);
        printf("�� Q �е�Ԫ��Ϊ��Q = ");
        QueueTraverse(Q, PrintElem);
    }
    PressEnterToContinue();
    
    printf("���������������� ���� GetHead \n");
    {
        GetHead(Q, &e);
        printf("�� ��ͷԪ�ص�ֵΪ \"%d\" \n", e);
    }
    PressEnterToContinue();
    
    printf("���������������� ���� ClearQueue \n");
    {
        printf("�� ��� Q ǰ��");
        QueueEmpty(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
        
        ClearQueue(&Q);
        
        printf("�� ��� Q ��");
        QueueEmpty(Q) ? printf(" Q Ϊ�գ���\n") : printf(" Q ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    printf("���������������� ���� DestroyQueue \n");
    {
        printf("�� ���� Q ǰ��");
        Q.front != NULL && Q.rear != NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
        
        DestroyQueue(&Q);
        
        printf("�� ���� Q ��");
        Q.front != NULL && Q.rear != NULL ? printf(" Q ���ڣ�\n") : printf(" Q �����ڣ���\n");
    }
    PressEnterToContinue();
    
    return 0;
}

// ���Ժ�������ӡ����
void PrintElem(QElemType e) {
    printf("%d ", e);
}
