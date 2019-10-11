/***************************************
 *						               *
 * 文件夹: ▲03 栈和队列\05 Expression *
 * 						               *
 * 内  容: 表达式求值相关函数测试      *
 *                                     *
 ***************************************/

#include "Expression.c"			//**▲03 栈和队列**//					

int main(int argc, char **argv)
{
	char opnd;
	char *exp = "(2+3)*4*6#";
	
	opnd = EvaluateExpression(exp);
	
	printf("作为示例，%s 的计算结果为：%d\n", exp, opnd-'0');
	
	printf("\n");
	
	return 0;
}
