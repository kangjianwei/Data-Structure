/***************************************
 *						               *
 * �ļ���: ��03 ջ�Ͷ���\05 Expression *
 * 						               *
 * ��  ��: ���ʽ��ֵ��غ�������      *
 *                                     *
 ***************************************/

#include "Expression.c"			//**��03 ջ�Ͷ���**//					

int main(int argc, char **argv)
{
	char opnd;
	char *exp = "(2+3)*4*6#";
	
	opnd = EvaluateExpression(exp);
	
	printf("��Ϊʾ����%s �ļ�����Ϊ��%d\n", exp, opnd-'0');
	
	printf("\n");
	
	return 0;
}
