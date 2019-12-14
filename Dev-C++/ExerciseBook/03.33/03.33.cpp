#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqQueue.h"    //**▲03 栈和队列**//

// 测试函数，打印整型
void PrintElem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char* argv[]) {
    SqQueue Q;
    QElemType e;
    int i;
    int random;
    
    printf("████ 初始化队列...\n");
    InitQueue(&Q);
    
    printf("████ 进行 5 次连续入队操作...\n");
    srand((unsigned) time(NULL));
    for(i = 1; i <= 5; i++) {
    
        random = rand() % 100;
        
        EnQueue_3_33(&Q, random);
        
        printf("█ 元素 \"%2d\" 入队后，队列中的元素为：", random);
        QueueTraverse(Q, PrintElem);
    }
    
    printf("████ 进行 5 次连续出队操作...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue(&Q, &e);
        
        printf("█ 元素 \"%2d\" 出队后，队列中的元素为：", e);
        QueueTraverse(Q, PrintElem);
    }
    
    return 0;
}
