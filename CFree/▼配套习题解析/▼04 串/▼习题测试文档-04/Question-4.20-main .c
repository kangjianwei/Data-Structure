#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* ����ԭ�� */
void Algo_4_20(SString S, SString T);

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
	Algo_4_20(S, T);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*������������������������
����4.20��ɾ��S�а�����T��
������������������������*/
void Algo_4_20(SString S, SString T)
{
	int i, j, k;
	
	i = 1;
	j = 1;	
	while(i<=S[0] && j<=T[0])				//Ѱ�ҵ�һ��ƥ���λ�� 
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;				//j-1����ͽ�͵�ǰ����j-1��λ�� 
			j = 1;
		}
	}
	if(j>T[0] && T[0])						//T��Ϊ�մ� 
		i = i-T[0];							//ƥ��ɹ� 
	else
		i = 0;
										
	while(i!=0)								//��ƥ����ַ���
	{	
		for(k=i+T[0]; k<=S[0]; k++)
			S[k-T[0]] = S[k];
		S[0] = S[0] - T[0];					//�ı�S���� 
				
		j = 1;	
		while(i<=S[0] && j<=T[0])			//��λ��һ��ƥ����ַ��� 
		{
			if(S[i]==T[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - (j-1) +1;			//j-1����ͽ�͵�ǰ����j-1��λ�� 
				j = 1;
			}
		}
		
		if(j>T[0] && T[0]!=0)				//T��Ϊ�մ� 
			i = i-T[0];						//ƥ��ɹ� 
		else
			i = 0;
	}
} 
