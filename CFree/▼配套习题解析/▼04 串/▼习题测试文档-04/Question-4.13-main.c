#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* ����ԭ�� */
void Algo_4_13(SString S, SString T);

int main(int argc, char *argv[])
{
	char *s = "----***--*-**-****-*****-----";
	char *t = "**";
	SString T, S;

	printf("ɾ��ǰ...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");

	printf("ɾ����...\n");
	printf("S = ");
	Algo_4_13(S, T);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*������������������������
����4.13��ɾ��S�а�����T��
������������������������*/
void Algo_4_13(SString S, SString T)
{
	int i;
	
	for(i=1; i=Index_Sq_1(S, T, 1); i++)
		StrDelete_Sq(S, i, T[0]);	
} 
