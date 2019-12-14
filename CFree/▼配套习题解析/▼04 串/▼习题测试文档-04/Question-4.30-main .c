#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* ����ԭ�� */
Status Algo_4_30(SString S, SString Sub, int *pos);

int main(int argc, char *argv[])
{
	char *s = "abcdeabcabcbcdefbcdefefghefgh";
	SString Sub, S;
	int pos;
	
	StrAssign_Sq(S, s);
	printf("����...\n");
	printf("S   = ");
	StrPrint_Sq(S);
	printf("\n\n");

	printf("�׸�����ظ��Ӵ�...\n");
	printf("Sub = ");
	Algo_4_30(S, Sub, &pos);
	StrPrint_Sq(Sub);
	printf("\n");
	printf("Sub �� S���״γ��ֵ�λ��Ϊ %d\n", pos);
	printf("\n");
	
	return 0;
}

/*������������������������������������������
����4.30�����״γ��ֵ���ظ��Ӵ�����λ�é�
������������������������������������������*/
/*
**�˴�����ظ��Ӵ������㺬�壺
**��һ�����Ӵ��������ظ��Ӵ������׸���������ģ�
**�ڶ����Ӵ�������ص���������ȡabcabca�Ľ��Ϊabca�� 
**�������Ӵ��ڿ����ظ�������ȡaaaa�Ľ��Ϊaaa�� 
*/
Status Algo_4_30(SString S, SString Sub, int *pos)	//0�ŵ�Ԫ 
{
	int i, j, k, len, start, end;
	
	if(S[0]<2)								//����Ԫ�ظ�����������2 
		return ERROR;
	
	Sub[0] = 0;
	
	for(k=1; k<S[0]; k++)				//��Χ��1��S[0]-1 
	{
		i = k;
		j = k+1;
		
		while(j<=S[0] && S[i]!=S[j])
			j++;						//�ҵ��׸�Ǳ�ڵ�ѭ����� 
		
		if(j<=S[0])
		{
			start = i;
			end = j;
			len = 0;
			while(j<=S[0] && S[i]==S[j])
			{
				i++;
				j++;
				len++;
			}
			
			if(len>Sub[0] && start+len-1>=end-1 )		//��֤�����Ժ������������ 
			{
				*pos = start;
				SubString_Sq(Sub, S, start, len);			
			}
		}
	}
	
	if(Sub[0])
		return OK;
	else
		return ERROR;
} 
