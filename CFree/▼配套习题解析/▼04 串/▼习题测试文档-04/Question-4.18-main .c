#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"	//**��04 ��**//

/* ����ԭ�� */
void Algo_4_18(SString S, int total[]);

int main(int argc, char *argv[])
{
	char *s = "dbasydujhge638940[gptokljrsehgadcsbnmv,c.b'ng[p098437eywdghswqdecxvghju";
	SString S;
	int total[128] = {};
	int i;
	
	StrAssign_Sq(S, s);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	Algo_4_18(S, total);
	printf(" S �в�ͬ���ַ����� %d ����\n", total[0]);
	for(i=1; i<=127; i++)
	{
		if(total[i]!=0)
			printf("�ַ� \'%c\' �� %d ��.\n", i, total[i]);
	}
	printf("ͳ�����...\n");
	printf("\n");
	
	return 0;
}

/*��������������������������������������������������
����4.18��ͳ���ַ����в�ͬ�ַ�������ÿ���ַ��ĸ�����
��������������������������������������������������*/
/* �����ַ������ֶ�Ӧ������ */ 
void Algo_4_18(SString S, int total[])	//total������Ϊ128��������ֲ�ͬ�ַ�
{
	int i;			 
	
	for(i=1; i<=S[0]; i++)				//�ַ����м��޿��ַ� 
	{
		if(!total[S[i]])				//�˴����ַ� 
			total[0]++;					//��ͬ�ַ����� 

		total[S[i]]++;					//�����ַ����� 
	}
}
