/*==============
 * 表达式计算
 *
 * 包含算法: 3.4
 ===============*/

#include "Expression.h"        //**▲03 栈和队列**//

/*
 * ████████ 算法3.4 ████████
 *
 * 从exp读入表达式，并计算表达式的运算结果
 *
 *【注】
 * 1.教材使用的是控制台输入，这里为了便于测试，直接改为从形参接收参数
 * 2.该计算功能有限，理论上仅支持对个位数运算，且要求每一步的运算结果也是个位数。
 *   教材提供此算法的目的是验证栈的使用，如果想扩展对运算符的支持，并扩大对操作数的支持，
 *   则可以顺着此思路进行改版
 */
OperandType EvaluateExpression(const char exp[]) {
    SElemType c;   // 输入序列
    
    SqStack OPTR;   // 运算符栈
    SqStack OPND;   // 操作数栈
    
    OperatorType theta, x;  // 运算符
    OperandType a, b;       // 操作数
    
    int i = 0;
    
    // 初始化运算符栈，并将一个界限符'#'入栈
    InitStack(&OPTR);
    Push(&OPTR, '#');
    
    // 初始化操作数栈，并开始读取输入
    InitStack(&OPND);
    c = exp[i++];
    
    // 当输入中遇到界限符'#'，且运算符栈的栈顶元素也是界限符'#'时，则表示读取结束，且运算结束
    while(c != '#' || GetTop(OPTR) != '#') {
        // 如果ch不是运算符，则视其为操作数，将其入栈
        if(!In(c, OP)) {
            Push(&OPND, c);    // 将操作数入栈
            c = exp[i++];      // 获取下一个输入字符
        } else {
            switch(Precede(GetTop(OPTR), c)) {
                // 栈中运算符优先级低，继续进栈
                case '<':
                    Push(&OPTR, c);
                    c = exp[i++];
                    break;
        
                // 优先级相等时，说明这里遇到括号，需要脱括号
                case '=':
                    Pop(&OPTR, &x);
                    c = exp[i++];
                    break;
                    
                /*
                 * 栈中运算符优先级高时，先计算，再将计算结果压入栈
                 *
                 * 注：这儿没有读字符，c保留的还是刚才读到的字符
                 */
                case '>':
                    Pop(&OPTR, &theta); // 弹出运算符
                    Pop(&OPND, &b);     // 弹出右边的操作数
                    Pop(&OPND, &a);     // 弹出左边的操作数
                    Push(&OPND, Operate(a, theta, b));
                    break;
            }
        }
    }
    
    return GetTop(OPND);
}

// 判断指定的运算符是否合规
Status In(SElemType c, const char OP[]) {
    
    SElemType* e = strchr(OP, c);
    
    // 如果运算符c不在合规范围内，说明指定的运算符不合规
    if(e == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/*
 * 判断运算符栈中操作符o1与表达式中的操作符o2的优先级。
 *
 * 返回'>'、'<'、'='，以指示o1和o2的优先级
 */
OperatorType Precede(OperatorType o1, OperatorType o2) {
    int x, y;
    
    // 获取指定的运算符在运算符表中的位置
    char* p1 = strchr(OP, o1);
    char* p2 = strchr(OP, o2);
    
    // 计算出一个运算符优先级表坐标
    x = p1 - OP;
    y = p2 - OP;
    
    return PrecedeTable[x][y];
}

/*
 * 对操作数进行运算
 *
 * a、b是操作数，theta是运算符。
 * 对于操作数和运算结果，仅保证对个位数的支持
 */
OperandType Operate(OperandType a, OperatorType theta, OperandType b) {
    int x, y, z = CHAR_MAX - 48;
    
    // 先从字符型转为整型
    x = a - '0';
    y = b - '0';
    
    switch(theta) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
    }
    
    // 计算完成后，将整型转换为字符型返回
    return z + 48;
}
