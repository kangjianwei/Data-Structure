#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     //**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* ����ԭ�� */
Status Algo_4_12(SString S, SString T, SString V);

int main(int argc, char *argv[])
{
	char *s = "----***--*-**-****-*****-----";
	char *t = "**";
	char *v = "^";
	SString T, S, V;

	printf("�滻ǰ...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	StrAssign_Sq(V, v);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n");
	printf("V = ");
	StrPrint_Sq(V);
	printf("\n\n");

	printf("�滻��...\n");
	printf("S = ");
	Algo_4_12(S, T, V);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*��������������������
����4.12���ַ����滻��
��������������������*/
Status Algo_4_12(SString S, SString T, SString V)
{
	if(Replace_Sq(S, T, V))		//�Ѷ��� 
		return OK;
	else
		return ERROR;
} 
