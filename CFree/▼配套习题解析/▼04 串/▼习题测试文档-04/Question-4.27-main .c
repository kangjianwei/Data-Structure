#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"	//**��04 ��**//

/* ����ԭ�� */
int Algo_4_27(SString S, SString T, int pos);

int main(int argc, char *argv[])
{
	char *s = "aaaaaaaaaaaaaaab";
	char *t = "aaaab";
	SString S, T;
	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");	
	
	printf("T��S���״γ��ֵ�λ��Ϊ��");
	printf("%d\n", Algo_4_27(S, T, 1));
	printf("\n");
		
	return 0;
}

/*������������������
����4.27���Ӵ���λ��
������������������*/
int Algo_4_27(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	
	if(pos<1)
		return 0;
		
	while(i<=S[0] && j<=T[0])
	{

		if((j!=1&&S[i]==T[j])||(j==1&&S[i]==T[j]&&S[i+T[0]-1]==T[T[0]]))
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;
			j = 1;
		}
	}
	
	if(j>T[0] && T[0])											//T��Ϊ�մ� 
		return i-T[0];											//ƥ��ɹ� 
	else
		return 0;	 
}
