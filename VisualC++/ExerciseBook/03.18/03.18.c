#include <stdio.h>
#include "Status.h"   //**▲01 绪论**//
#include "SqStack.h"  //**▲03 栈和队列**//

/*
 * 判定表达式开闭括号是否配对出现
 *
 *【注】
 * 只是判断括号是否配对出现，而不是判断括号类型、顺序是否正确
 */
Status Algo_3_18(char* s);


int main(int argc, char* argv[]) {
    char* s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}";
    
    printf("判断表达式 %s 开闭括号数量是否匹配...\n", s);
    
    if(Algo_3_18(s) == TRUE) {
        printf("█ 表达式开闭括号数量匹配！\n");
    } else {
        printf("█ 表达式开闭括号数量不匹配！！\n");
    }
    
    return 0;
}


/*
 * 判定表达式开闭括号是否配对出现
 *
 *【注】
 * 只是判断括号是否配对出现，而不是判断括号类型、顺序是否正确
 */
Status Algo_3_18(char* s) {
    SqStack S;
    SElemType e;
    int i;
    
    InitStack(&S);
    
    for(i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            // 遇到左括号，则入栈
            case '(':
            case '[':
            case '{':
                Push(&S, s[i]);
                break;
                
            // 遇到右括号，则出栈
            case ')':
            case ']':
            case '}':
                if(StackEmpty(S)) {
                    return ERROR;
                }
                Pop(&S, &e);
                break;
                
            default:
                break;
        }
    }
    
    // 如果栈正好为空了，说明校验成功
    if(StackEmpty(S)) {
        return OK;
    }
    
    return ERROR;
}
