#include <stdio.h>
#include "Status.h"   //**▲01 绪论**//
#include "SqStack.h"  //**▲03 栈和队列**//

// 判定表达式开闭括号是否配对出现，且类型是否匹配
Status Algo_3_19(char* s);

// 判断括号a和括号b之间的类型是否匹配
Status Matching(char a, char b);


int main(int argc, char* argv[]) {
    char* s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}";
    
    printf("判断表达式 %s 括号是否匹配...\n", s);
    
    if(Algo_3_19(s)) {
        printf("█ 表达式括号匹配！\n");
    } else {
        printf("█ 表达式括号不匹配！！\n");
    }
    
    return 0;
}


// 判定表达式开闭括号是否配对出现，且类型是否匹配
Status Algo_3_19(char* s) {
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
                
                // 判断括号是否匹配
                if(!Matching(e, s[i])) {
                    return ERROR;
                }
                break;
            
            default:
                break;
        }
    }
    
    if(StackEmpty(S)) {
        return OK;
    }
    
    return ERROR;
}

// 判断括号a和括号b之间的类型是否匹配
Status Matching(char a, char b) {
    switch(a) {
        case '(':
            if(b != ')') {
                return ERROR;
            }
            break;
        
        case '[':
            if(b != ']') {
                return ERROR;
            }
            break;
        
        case '{':
            if(b != '}') {
                return ERROR;
            }
            break;
        
        default:
            return ERROR;
    }
    
    return OK;
}
