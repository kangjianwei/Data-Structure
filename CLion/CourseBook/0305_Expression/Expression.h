/*==============
 * 表达式计算
 *
 * 包含算法: 3.4
 ===============*/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "SqStack.h"    //**▲03 栈和队列**//

typedef SElemType OperatorType;                // 运算符类型
typedef SElemType OperandType;                 // 操作数类型

// 运算符表，即表达式中允许出现的符号（包括界限符'#'）
static const char OP[] = {'+', '-', '*', '/', '(', ')', '#'};

/*
 * 运算符优先级表（包括界限符'#'），与上面的OP表是呼应的。
 * 可参见教材中的"算符间的优先关系"表
 */
static const char PrecedeTable[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                                        {'>', '>', '<', '<', '<', '>', '>'},
                                        {'>', '>', '>', '>', '<', '>', '>'},
                                        {'>', '>', '>', '>', '<', '>', '>'},
                                        {'<', '<', '<', '<', '<', '=', ' '},
                                        {'>', '>', '>', '>', ' ', '>', '>'},
                                        {'<', '<', '<', '<', '<', ' ', '='}};


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
OperandType EvaluateExpression(const char exp[]);

/*
 * 判断指定的运算符是否合规
 *
 * OP中存储了合规的运算符，包括界限符'#'
 */
Status In(SElemType c, const char OP[]);

/*
 * 判断运算符栈中操作符o1与表达式中的操作符o2的优先级。
 *
 * 返回'>'、'<'、'='，以指示o1和o2的优先级
 */
OperatorType Precede(OperatorType o1, OperatorType o2);

/*
 * 对操作数进行运算
 *
 * a、b是操作数，theta是运算符。
 * 对于操作数和运算结果，仅保持对个位数的支持
 */
OperandType Operate(OperandType a, OperatorType theta, OperandType b);


#endif
