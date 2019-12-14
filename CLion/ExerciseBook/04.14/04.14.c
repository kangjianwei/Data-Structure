#include <stdio.h>
#include <string.h>
#include "SqStack.h"    //**▲03 栈和队列**//
#include "String.h"     //**字符串**//

/*
 * 将前缀表达式prefix转换为后缀表达式
 *
 *【注】
 * 未对前缀表达式的正确性进行验证
 */
Status Algo_4_14(const char* prefix, char** suffix) {
    StringType P, S;
    StringType Operator;    // 运算符
    SqStack stack;          // 表达式栈
    StringType e;           // 栈顶元素
    StringType o;           // 靠近栈顶的运算符
    int i, len;
    int readStr;    // 是否需要读取字符串
    
    len = (int) strlen(prefix);
    
    if(len == 0) {
        *suffix = NULL;
        return ERROR;
    }
    
    // 运算符和操作数
    StrAssign(&Operator, "+-*/");
    
    // 前缀表达式
    StrAssign(&P, prefix);
    
    // 后缀表达式栈
    InitStack(&stack);
    
    readStr = 1;
    i = 1;
    
    // 遍历前缀表达式，逐个获取元素
    while(TRUE) {
        if(readStr == 1) {
            S = SubString(P, i++, 1);
        }
        
        // 如果遇到了运算符，则直接入栈
        if(Index(Operator, S, 1) != 0) {
            Push(&stack, S);
            readStr = 1;
            
            // 如果遇到了操作数
        } else {
            // 获取栈顶元素，如果栈已经为空，则S中存储了后缀表达式
            if(GetTop(stack, &e) == ERROR) {
                break;
            }
            
            // 如果栈顶元素是运算符，则将操作数直接入栈
            if(Index(Operator, e, 1) != 0) {
                Push(&stack, S);
                readStr = 1;
                
                // 否则栈顶也是操作数，需要进行简单运算
            } else {
                Pop(&stack, &e);    // 弹出栈顶操作数
                Pop(&stack, &o);    // 弹出靠近栈顶的运算符
                
                S = Concat(e, S);
                S = Concat(S, o);
                
                // 此种情形下不需要读取字符串，而需要判断刚刚计算出的Sub
                readStr = 0;
            }
        }
    }
    
    // 获取后缀表达式
    *suffix = S;
    
    return OK;
}


int main(int argc, char* argv[]) {
    char* prefix = "-+a*bc/de";  // 其后缀表达式为：abc*+de/-
    char* suffix;
    
    Algo_4_14(prefix, &suffix);
    
    printf("前缀表达式：%s\n", prefix);
    printf("后缀表达式：%s\n", suffix);
}
