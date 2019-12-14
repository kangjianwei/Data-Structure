#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"     //**��01 ����**//
#include "SqQueue.h"    //**��03 ջ�Ͷ���**//

// ���Ժ�������ӡ����
void PrintElem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char* argv[]) {
    SqQueue Q;
    QElemType e;
    int i;
    int random;
    
    printf("�������� ��ʼ������...\n");
    InitQueue(&Q);
    
    printf("�������� ���� 5 ��������Ӳ���...\n");
    srand((unsigned) time(NULL));
    for(i = 1; i <= 5; i++) {
    
        random = rand() % 100;
        
        EnQueue_3_33(&Q, random);
        
        printf("�� Ԫ�� \"%2d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", random);
        QueueTraverse(Q, PrintElem);
    }
    
    printf("�������� ���� 5 ���������Ӳ���...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue(&Q, &e);
        
        printf("�� Ԫ�� \"%2d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);
        QueueTraverse(Q, PrintElem);
    }
    
    return 0;
}
