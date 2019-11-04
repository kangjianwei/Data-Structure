#include <stdio.h>
#include <ctype.h>    // 提供isdigit原型
#include "Status.h"   //**▲01 绪论**//
#include "SqStack.h"  //**▲03 栈和队列**//

/*
 * 对逆波兰表达式求值（理论上要求操作数与运算结果均为个位数）
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
Status Algo_3_22(char c[], SElemType* Value);

/* 计算 a oper b 的值 */
char Operate(char a, char oper, char b);


int main(int argc, char* argv[]) {
    char c[] = "124*+93/-";
    SElemType value;
    
    printf("已知逆波兰式为：");
    printf("%s\n", c);
    
    Algo_3_22(c, &value);
    printf("逆波兰式的计算结果为：%d\n", value - 48);
    
    return 0;
}


/*
 * 对逆波兰表达式求值（理论上要求操作数与运算结果均为个位数）
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
Status Algo_3_22(char c[], SElemType* Value) {
    int i;
    SqStack S;
    SElemType a, b;
    
    InitStack(&S);
    
    for(i = 0; c[i]!='\0'; ++i) {
        // 如果遇到数字字符
        if(isdigit(c[i])) {
            Push(&S, c[i]);
        } else {
            // 先弹出来的在操作数后边
            Pop(&S, &b);
            Pop(&S, &a);
            Push(&S, Operate(a, c[i], b));
        }
    }
    
    Pop(&S, Value);
    
    if(!StackEmpty(S)) {
        return ERROR;
    } else {
        return OK;
    }
}

/* 计算 a oper b 的值 */
char Operate(char a, char oper, char b) {
    char c;
    
    switch(oper) {
        case '+':
            c = (a - 48) + (b - 48) + 48;
            break;
        case '-':
            c = (a - 48) - (b - 48) + 48;
            break;
        case '*':
            c = (a - 48) * (b - 48) + 48;
            break;
        case '/':
            c = (a - 48) / (b - 48) + 48;
            break;
    }
    
    return c;
}
