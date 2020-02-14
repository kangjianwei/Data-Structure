#include <stdio.h>
#include "LinkQueue.h"        //**03 栈和队列**//

// 测试函数，打印整型
void PrintElem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkQueue Q;
    int i;
    QElemType e;
    
    printf("████████ 函数 InitQueue \n");
    {
        printf("█ 初始化链队 Q ...\n");
        InitQueue(&Q);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 QueueEmpty \n");
    {
        QueueEmpty(Q) ? printf("█ Q 为空！！\n") : printf("█ Q 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 EnQueue \n");
    {
        for(i = 1; i <= 6; i++) {
            EnQueue(&Q, 2 * i);
            printf("█ 元素 \"%2d\" 入队...\n", 2 * i);
        }
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 QueueTraverse \n");
    {
        printf("█ Q 中的元素为：Q = ");
        QueueTraverse(Q, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 QueueLength \n");
    {
        i = QueueLength(Q);
        printf("█ Q 的长度为 %d \n", i);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 DeQueue \n");
    {
        DeQueue(&Q, &e);
        printf("█ 队头元素 \"%d\" 出队...\n", e);
        printf("█ Q 中的元素为：Q = ");
        QueueTraverse(Q, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 GetHead \n");
    {
        GetHead(Q, &e);
        printf("█ 队头元素的值为 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 ClearQueue \n");
    {
        printf("█ 清空 Q 前：");
        QueueEmpty(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
        
        ClearQueue(&Q);
        
        printf("█ 清空 Q 后：");
        QueueEmpty(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 DestroyQueue \n");
    {
        printf("█ 销毁 Q 前：");
        Q.front != NULL && Q.rear != NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
        
        DestroyQueue(&Q);
        
        printf("█ 销毁 Q 后：");
        Q.front != NULL && Q.rear != NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}
