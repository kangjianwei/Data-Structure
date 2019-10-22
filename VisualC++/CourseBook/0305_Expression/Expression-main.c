#include "Expression.h"            //**▲03 栈和队列**//

int main(int argc, char** argv) {
    char opnd;
    char* exp = "(1+3)*2/4#";
    
    opnd = EvaluateExpression(exp);

    printf("作为示例， %s 的计算结果为：%d\n", exp, opnd - '0');

    return 0;
}
