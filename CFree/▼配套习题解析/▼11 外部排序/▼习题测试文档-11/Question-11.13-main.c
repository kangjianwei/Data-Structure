#include <stdio.h>
#include <limits.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"  	//**��01 ����**//

/* �궨�� */
#define MAXKEY INT_MAX									//�ؼ��ֿ��ܵ����ֵ 
#define W 6												//����������

/* ���Ͷ��� */
typedef int KeyType;									//����ؼ�������Ϊ��������
typedef int LoserTree[W];								//������Ҷ�ڵ�洢�ṹ
typedef KeyType WorkArea[W];							//�ڴ湤����������ΪW 

/* ȫ�ֱ��� */
KeyType cache[W+1];										//�����洢��������ΪW 
int output[11][101];									//�洢�鲢�������

/* ����ԭ�� */
void Algo_11_13(FILE *fi, LoserTree ls, WorkArea wa);
void GetRun_11_13(FILE *fi, LoserTree ls, WorkArea wa);
	//���һ����ʼ�鲢��
void MiniMax_11_13(LoserTree ls, WorkArea wa, int q);
void BuildLoser_11_13(KeyType cache[W+1], LoserTree ls, WorkArea wa);
	//�Ӹ�����ȡ����ȡ��¼����������

int main(int argc, char *argv[])
{	
	FILE *fi;									//�����ļ� 
	LoserTree ls;								//������ 
	WorkArea wa;								//�����ռ�
	int i,j,k;
		
	printf("��Ȼѡ������...\n");
	fi = fopen("Data/Algo_11_13.txt", "r");		//��ȡ�����ļ�	
	Algo_11_13(fi, ls, wa);						//�ָ�fi
	printf("\n");	
	
	printf("����ǰ������...\n");
	fi = fopen("Data/Algo_11_13.txt", "r");		//��ȡ�����ļ�
	while(!feof(fi))
	{
		Scanf(fi,"%d",&k);
		printf("%d ", k);
	}
	printf("\n\n");
	fclose(fi);	

	printf("����������...\n");		
	for(i=1; i<=output[0][0]; i++)
	{
		printf("RUN%2d��", i);
		for(j=1; j<=output[i][0]; j++)
			printf("%d ", output[i][j]);
		printf("\n");
	}
	printf("\n");
		
	return 0;
}

/*������������������������
����11.13����Ȼѡ������ ��
������������������������*/
void Algo_11_13(FILE *fi, LoserTree ls, WorkArea wa)
{
	int i;
	FILE *fo;
	
	for(i=1; i<=W; i++)
		Scanf(fi, "%d", &cache[i]),cache[0]++;	
	BuildLoser_11_13(cache, ls, wa);				//�Ӹ�����ȡ����ȡ��¼����������
											
	output[0][0] = 0;
	
	while(!feof(fi) || cache[0])					//���κλ����ڴ� 
	{
		output[0][0]++;
		output[output[0][0]][0] = 0;
		
		if(cache[0]==W || (cache[0]>0&&feof(fi)))
			BuildLoser_11_13(cache, ls, wa);		//�Ӹ�����ȡ����ȡ��¼����������
			
		GetRun_11_13(fi, ls, wa);					//���һ����ʼ�鲢��
	}
	
	fclose(fi);
}

void GetRun_11_13(FILE *fi, LoserTree ls, WorkArea wa)
{
	int q, minimax, tag;
	int m, n;
	
	m = output[0][0];
	n = output[m][0];
	
	if(wa[ls[0]]!=MAXKEY)	
	{
		q = ls[0];								//qָʾMINIMAX��¼��wa�е�λ�� 
		minimax = wa[q];
		n++;
		output[m][n] = wa[q];
	}
	
	while(cache[0]!=W && wa[ls[0]]!=MAXKEY)
	{
		tag=Scanf(fi, "%d", &wa[q]);
		
		if(tag!=1)								//��ȡʧ�ܣ��������ļ�����
		{
			wa[q] = MAXKEY;
			break;
		}			 
		else
		{			
			if(wa[q]<minimax)					//�¶���ļ�¼������һ��
			{
				cache[0]++;
				cache[cache[0]] = wa[q];
				if(cache[0]==W)
				{
					wa[q] = MAXKEY;	
					break;
				}
			}
			else
			{
				MiniMax_11_13(ls, wa, q); 		//ѡ���µ�MINIMAX��¼			
				q = ls[0];						//qָʾMINIMAX��¼��wa�е�λ�� 
				minimax = wa[q];
				n++;
				output[m][n] = wa[q];
			}
		}		 
	}
	
 
	while(minimax!=MAXKEY)
	{		
		MiniMax_11_13(ls, wa, q); 				//ѡ���µ�MINIMAX��¼
		
		if(wa[ls[0]]!=MAXKEY)
		{
			q = ls[0];
			minimax = wa[q];
			n++;
			output[m][n] = wa[q];
			wa[q] = MAXKEY;
		}
		else
			minimax = MAXKEY;
	}
	
	output[m][0] = n;
}

void MiniMax_11_13(LoserTree ls, WorkArea wa, int q)
{
	int p, t, tmp;
	 
	for(t=(W+q)/2,p=ls[t]; t>0; t=t/2,p=ls[t])
	{
		if(wa[p]<wa[q])
		{
			tmp = q;						//qָ���µ�ʤ���� 
			q = ls[t];
			ls[t] = tmp;
		}
	}
	
	ls[0] = q;
}

void BuildLoser_11_13(KeyType cache[W+1], LoserTree ls, WorkArea wa)	//������wa��һ�ð����� 
{
	int i;
	 
	for(i=0; i<W; i++)
		wa[i] = ls[i] = 0;					//��������ʼ��
		
	for(i=W-1; i>=0; i--)
	{		
		if(cache[0]>0)
		{
			cache[0]--;
			wa[i] = cache[W-i];				//����һ����¼
		}			
		else
			wa[i] = MAXKEY;

		MiniMax_11_13(ls, wa, i);			//�������� 
	}
}
