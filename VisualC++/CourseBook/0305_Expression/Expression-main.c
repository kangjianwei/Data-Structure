#include "Expression.h"            //**��03 ջ�Ͷ���**//

int main(int argc, char** argv) {
    char opnd;
    char* exp = "(1+3)*2/4#";
    
    opnd = EvaluateExpression(exp);

    printf("��Ϊʾ���� %s �ļ�����Ϊ��%d\n", exp, opnd - '0');

    return 0;
}
