#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     //**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* �궨�� */
#define Sl 2000

/* ���Ͷ��� */
typedef struct
{
	SString String;			//ĳ����Ĺ��� 
	int start;				//�ַ������ 
}PString;
typedef struct
{
	PString Sub[MAXSTRLEN+1];
	int count;
}StringSet;					//�����������Ӵ����� 

/* ����ԭ�� */
Status Algo_4_31(SString S, SString T, StringSet *Set_s, StringSet *Set_t);
Status StringSetPrint(StringSet Set);

int main(int argc, char *argv[])
{
	char *s = "abcd*lokis***hyuij**vfgh*lokis****yu*mklng***u****wy*c*vdgry*pklnh";
	char *t = "-vdgry--vfgh-hyuij---abcd-pklnh---yu----lokis-----uio-u--wy---mklng-c ";
	SString S, T;
	StringSet Set_s, Set_t;
	
	printf("��ʼ��...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");
	
	printf("��ȡ�����Ӵ��ļ���...\n");
	Algo_4_31(S, T, &Set_s, &Set_t);
	printf("\n");
	
	printf("��� S �й����Ӵ���Ϣ...\n");
	StringSetPrint(Set_s);
	printf("\n");

	printf("��� T �й����Ӵ���Ϣ...\n");
	StringSetPrint(Set_t);
	printf("\n");
		
	return 0;
}

/*����������������������
����4.31��������Ӵ���
����������������������*/
/* �ṹStringSet���洮S�ʹ�T���е�������Ӵ�������ʼλ�ú����� */
Status Algo_4_31(SString S, SString T, StringSet *Set_s, StringSet *Set_t)
{
	int i, j;					//i���S��j���T 
	int m, n;
	int k, flag;
	int len[MAXSTRLEN+1][MAXSTRLEN+1];
	
	if(!S[0] || !T[0])			//���ַ���Ϊ�� 
		return ERROR;
		
	for(m=0; m<=T[0]; m++)		//��ʼ������Ϊ0 
		len[m][0] = 0;
	for(n=0; n<=S[0]; n++)		//��ʼ������Ϊ0 
		len[0][n] = 0;
	
	m = T[0]+1;
	n = 1;
	while(n<=S[0])
	{
		m>1 ? m-- : n++;
		
		for(i=m,j=n; i<=T[0]&&j<=S[0]; i++,j++)
		{
			if(T[i]==S[j])
				len[i][j] = len[i-1][j-1] + 1;
			else
				len[i][j] = 0;	
		
			if(len[i][j]>len[m-1][n-1])
				len[m-1][n-1] = len[i][j];
			
			if(len[i][j]>len[0][S[0]])
				len[T[0]][0] = len[0][S[0]] = len[i][j];			
		}
	}
	
	if(!len[0][S[0]])//���ַ�����������Ӵ� 
		return ERROR; 
	
	m = T[0]+1;
	n = 1;
	(*Set_s).count = (*Set_t).count = 0;

	while(n<=S[0])
	{
		m>1 ? m-- : n++;

		if(len[m-1][n-1]==len[0][S[0]])//����������Ӵ� 
		{
			for(i=m,j=n; i+len[0][S[0]]-1<=T[0]&&j+len[0][S[0]]-1<=S[0]; i++,j++)
			{
				if(len[i+len[0][S[0]]-1][j+len[0][S[0]]-1]==len[0][S[0]])//�����������ַ������ 
				{
					for(k=1,flag=0; k<=(*Set_t).count; k++)//�Ƿ��Ѽ���T��
					{
						if((*Set_t).Sub[k].start==i)
						{
							flag = 1;
							break;
						}
					}
					
					if(!flag)//�ռ�T�г��ֵ�������ַ���									
					{
						(*Set_t).count++;
						(*Set_t).Sub[(*Set_t).count].start = i;
						SubString_Sq((*Set_t).Sub[(*Set_t).count].String, T, i, len[T[0]][0]);					
					}

					for(k=1,flag=0; k<=(*Set_s).count; k++)//�Ƿ��Ѽ���S��
					{
						if((*Set_s).Sub[k].start==j)
						{
							flag = 1;
							break;
						}
					}
					
					if(!flag)//�ռ�S�г��ֵ�������ַ���	
					{
						(*Set_s).count++;
						(*Set_s).Sub[(*Set_s).count].start = j;
						SubString_Sq((*Set_s).Sub[(*Set_s).count].String, S, j, len[0][S[0]]);					
					}
				}
			}		
		}
	}
	
	return OK;	
}

Status StringSetPrint(StringSet Set)
{
	int i, j, k;
	
	for(k=1; k<=Set.count; k++)
	{
		printf("�� %2d ��λ�ã�", Set.Sub[k].start);
		StrPrint_Sq(Set.Sub[k].String);
		printf("\n");
	}
}
