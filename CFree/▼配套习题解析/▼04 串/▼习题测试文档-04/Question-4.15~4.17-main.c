#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"	//**��04 ��**//

/* ����ԭ�� */
Status Algo_4_15(SString T, char *chars);
int Algo_4_16(SString S, SString T);
Status Algo_4_17(SString S, SString T, SString V);

int main(int argc, char *argv[])
{
	char *t = "ab**c*de***fg";
	char *s = "ab**c*de***fh";
	int i;
	SString T, S, M1, M2;
	
	printf("�������� 4.15 ��֤...������\n");
	Algo_4_15(T, t);
	Algo_4_15(S, s);
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n");
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	printf("�������� 4.16 ��֤...������\n");
	i = Algo_4_16(S, T);
	if(i>0)
		printf("S > T\n");
	else if(i<0)
		printf("S < T\n");
	else
		printf("S == T\n");
	printf("\n");
	
	printf("�������� 4.17 ��֤...������\n");
	Algo_4_15(M1, "**");
	Algo_4_15(M2, "^");
	Algo_4_17(S, M1, M2);
	printf("�� \"^\" �滻 \"**\" ��S = ");
	StrPrint_Sq(S);
	printf("\n\n");
		
	return 0;
}

/*��������������������
����4.15���ַ�����ֵ��
��������������������*/
Status Algo_4_15(SString T, char *chars)
{
	int i, len;
	
	len = strlen(chars);
	
	if(len>MAXSTRLEN)								//chars���� 
		return ERROR;
	else
	{
		T[0] = len;
		for(i=1; i<=len; i++)
			T[i] = chars[i-1];						//charsΪ���� 

		return OK;
	}
}

/*��������������������
����4.16���ַ����Ƚϩ�
��������������������*/
int Algo_4_16(SString S, SString T)
{
	int i = 1;
	
	while(i<=S[0] && i<=T[0])
	{
		if(S[i]==T[i])
			i++;
		else
			return S[i] - T[i];	
	}
	
	return S[0] - T[0];	
}

/*��������������������
����4.17���ַ����滻��
��������������������*/
Status Algo_4_17(SString S, SString T, SString V)
{
	int count = 1;									//count����S 
	int i, j, k;
	SString Tmp_beh;
	
	i = count;
	j = 1;	
	while(i>=1 && i<=S[0] && j<=T[0])				//Ѱ�ҵ�һ��ƥ���λ�� 
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;						//j-1����ͽ�͵�ǰ����j-1��λ�� 
			j = 1;
		}
	}
	if(j>T[0] && T[0]!=0)							//T��Ϊ�մ� 
		count = i-T[0];								//ƥ��ɹ� 
	else
		count = 0;
										
	while(S[0]-T[0]+V[0]<=MAXSTRLEN && count!=0)	//��ƥ����ַ����ҿ��Ա���ȫ�滻
	{			
		Tmp_beh[0] = S[0]-i+1;						//ժȡS��ƥ���ַ���֮����ַ���Tmp_beh
		for(k=1; k<=S[0]-i+1; k++)
			Tmp_beh[k] = S[k+i-1];
		
		S[0] = S[0]-T[0]+V[0];
		for(k=1; k<=V[0]; k++)						//����V��S�� 
			S[k+count-1] = V[k];
		
		for(k=count+V[0]; k<=S[0]; k++)				//����ȡ��S�еĺ�벿�ֵ�S�� 
			S[k] = Tmp_beh[k-count-V[0]+1];
				
		count += V[0];								//i�л�����һ��λ�� 
				
		i = count;
		j = 1;	
		while(i>=1 && i<=S[0] && j<=T[0])			//��λ��һ��ƥ����ַ��� 
		{
			if(S[i]==T[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - (j-1) +1;					//j-1����ͽ�͵�ǰ����j-1��λ�� 
				j = 1;
			}
		}
		if(j>T[0] && T[0]!=0)						//T��Ϊ�մ� 
			count = i-T[0];							//ƥ��ɹ� 
		else
			count = 0;
	}
	
	if(count==0)									//S�е�T��ȫ�����滻 
		return OK;
	else											//S������T������V�Ѿ��岻��ȥ�� 
		return ERROR;
}
