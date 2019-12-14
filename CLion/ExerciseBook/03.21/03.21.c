#include <stdio.h>
#include <string.h>   // 提供strlen原型
#include <ctype.h>    // 提供isalpha原型
#include "SqStack.h"  //**▲03 栈和队列**//

// 运算符表，即表达式中允许出现的符号
static const char OP[] = {'+', '-', '*', '/'};

/*
 * 运算符优先级表，与上面的OP表是呼应的。
 * 这里只有四则运算符号的优先级
 */
static const char PrecedeTable[7][7] = {
    {'>', '>', '<', '<'},
    {'>', '>', '<', '<'},
    {'>', '>', '>', '>'},
    {'>', '>', '>', '>'}
};

/*
 * 根据给定的中缀表达式，返回其对应的逆波兰表达式（后缀表达式）
 * 如将"a+b*c-d/e"将转化为："abc*+de/-"
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
char* Algo_3_21(char s[]);

/*
 * 判断运算符栈中操作符o1与表达式中的操作符o2的优先级。
 *
 * 返回'>'、'<'、'='，以指示o1和o2的优先级
 */
char Precede(char o1, char o2);


int main(int argc, char* argv[]) {
    char* s = "a+b*c-d/e";
    
    printf("中缀表达式为：");
    printf("%s\n", s);
    
    printf("后缀表达式为：");
    printf("%s\n", Algo_3_21(s));
    
    return 0;
}


/*
 * 根据给定的中缀表达式，返回其对应的逆波兰表达式（后缀表达式）
 * 如将"a+b*c-d/e"将转化为："abc*+de/-"
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
char* Algo_3_21(char s[]) {
    int i, j;
    SqStack S;      // 运算符栈，临时存储操作符
    SElemType e;    // SElemType被定义char类型，char和int类型可直接比较
    char* c;
    
    // 逆波兰式序列
    c = (char*) malloc((strlen(s) + 1) * sizeof(char));
    
    InitStack(&S);
    
    for(i = j = 0; s[i] != '\0'; i++) {
        // 如果读到了字母，将其视为操作数，
        if(isalpha(s[i])) {
            c[j++] = s[i];  // 将字母直接存入逆波兰式中
            
            // 如果读到的是运算符
        } else {
            while(!StackEmpty(S)) {
                // 获取栈顶元素
                GetTop(S, &e);
                
                // 如果运算符栈中运算符优先级高
                if(Precede(e, s[i]) == '>') {
                    Pop(&S, &e);    // 将运算符栈中优先级高的操作符出栈
                    c[j++] = e;     // 将出栈后的操作符添加到逆波兰式中
                    
                    // 如果遇到运算符栈中操作符优先级低时，结束循环
                } else {
                    break;
                }
            }
            
            // 将表达式中读取到的操作符压入运算符栈
            Push(&S, s[i]);
        }
    }
    
    // 将运算符栈中所有操作符追加到逆波兰式中
    while(!StackEmpty(S)) {
        Pop(&S, &e);
        c[j++] = e;
    }
    
    // 数组中转换后的逆波兰式以"\0"标记结束
    c[j] = '\0';
    
    return c;
}

/*
 * 判断运算符栈中操作符o1与表达式中的操作符o2的优先级。
 *
 * 返回'>'、'<'、'='，以指示o1和o2的优先级
 */
char Precede(char o1, char o2) {
    int x, y;
    
    // 获取指定的运算符在运算符表中的位置
    char* p1 = strchr(OP, o1);
    char* p2 = strchr(OP, o2);
    
    // 计算出一个运算符优先级表坐标
    x = p1 - OP;
    y = p2 - OP;
    
    return PrecedeTable[x][y];
}
