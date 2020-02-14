#include <stdio.h>
#include "SqStack.h"    //**▲03 栈和队列**//

// 测试函数，打印元素
void PrintElem(SElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqStack S;
    int i;
    SElemType e;
    
    printf("████████ 函数 InitStack \n");
    {
        printf("█ 初始化顺序栈 S ...\n");
        InitStack(&S);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 StackEmpty \n");
    {
        StackEmpty(S) ? printf("█ S 为空！！\n") : printf("█ S 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 Push \n");
    {
        for(i = 1; i <= 6; i++) {
            Push(&S, 2 * i);
            printf("█ 将 \"%2d\" 压入栈 S ...\n", 2 * i);
        }
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 StackTraverse \n");
    {
        printf("█ S 中的元素为：S = ");
        StackTraverse(S, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 StackLength \n");
    {
        i = StackLength(S);
        printf("█ S 的长度为 %d \n", i);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 Pop \n");
    {
        Pop(&S, &e);
        printf("█ 栈顶元素 \"%d\" 出栈...\n", e);
        printf("█ S 中的元素为：S = ");
        StackTraverse(S, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 GetTop \n");
    {
        GetTop(S, &e);
        printf("█ 栈顶元素的值为 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 ClearStack \n");
    {
        printf("█ 清空 S 前：");
        StackEmpty(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
        
        ClearStack(&S);
        
        printf("█ 清空 S 后：");
        StackEmpty(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ 函数 DestroyStack \n");
    {
        printf("█ 销毁 S 前：");
        S.base != NULL && S.top != NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
        
        DestroyStack(&S);
        
        printf("█ 销毁 S 后：");
        S.base != NULL && S.top != NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}
