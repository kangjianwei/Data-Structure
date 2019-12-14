/****************************
 *                          *
 * �ļ���: ��11 �ⲿ����    *
 *                          *
 * �ļ���: LoserTree.c      *
 *                          *
 * ��  ��: 11.1��11.2��11.3 *
 *                          *
 ****************************/

#ifndef LOSERTREE_C
#define LOSERTREE_C

#include "LoserTree.h"			//**��11 �ⲿ����**//

/*�T�T�T�T�[
�U�㷨11.1�U 
�^�T�T�T�T*/
void K_Merge(FILE *fp_out, LoserTree ls, External b)
{
	int i, q;
	FILE *fp_in[K] = {};				//k������鲢�� 
		
	for(i=0; i<K; i++)					//�ֱ��k���鲢����ζ���öε�ǰ�׸���¼�Ĺؼ��ֵ�����
		input(fp_in, &(b[i].key), i);	//b[0..k-1]Ϊ�������ϵ�k��Ҷ�ӽ�㣬�ֱ���k������鲢���е�ǰ��¼�Ĺؼ���
	
	CreateLoserTree(ls, b);				//��������ls��ѡ����С�ؼ���Ϊb[ls[0]].key 
	
	while(b[ls[0]].key!=MAXKEY)
	{
		q = ls[0];						//qָʾ��ǰ��С�ؼ������ڹ鲢�� 
		output(fp_out, b[q].key);		//�����Ϊq�Ĺ鲢���е�ǰ(�ؼ���Ϊb[q].key)�ļ�¼д������鲢��
		input(fp_in, &(b[q].key), q);	//�ӱ��Ϊq������鲢���ж�����һ����¼�Ĺؼ��� 
		Adjust(ls, b, q);				//������������ѡ���µ���С�ؼ��� 
	}
	
	output(fp_out, b[ls[0]].key);		//�������ؼ���MAXKEY�ļ�¼д������鲢��
	
	fclose(fp_out);
}

/*�T�T�T�T�[
�U�㷨11.2�U 
�^�T�T�T�T*/
void Adjust(LoserTree ls, External b, int s)
{
	int t, tmp;
	
	t = (s+K)/2;						//ls[t]��b[s]��˫�׽�� 
	
	while(t>0)							//�ش�Ҷ�ӽ��b[s]�������ls[0]��·������������ 
	{
		if(b[s].key>b[ls[t]].key)		//sָʾ�µ�ʤ���ߣ�СΪʤ�����ϱȽϣ���Ϊ�ܣ�����˫�׽�㣩 
		{
			tmp = s;
			s = ls[t];
			ls[t] = tmp;
		}
		
		t = t/2;
	}
	
	ls[0] = s;							//�������Ϊ��Сֵ 
}

/*�T�T�T�T�[
�U�㷨11.3�U 
�^�T�T�T�T*/
void CreateLoserTree(LoserTree ls, External b)
{										//b[0..k-1]Ϊ��ȫ������ls��Ҷ�ӽ�����k���ؼ���
	int i;
	 
	b[K].key = MINKEY;					//��MINKEYΪ�ؼ��ֿ��ܵ���Сֵ		 
	
	for(i=0; i<K; i++)
		ls[i] = K;						//����ls�С����ߡ��ĳ�ֵ 
	
	for(i=K-1; i>=0; i--)				//���δ�b[k-1..0]������������ 
		Adjust(ls, b, i);
}

void Cut_Sort(FILE *fp)					//�ֶι鲢���� 
{
	FILE *fptr;							//fptrָ��[0..n-1].txt 
	SqList_sort L;	
	int i, j;
	KeyType tmp;
	int len, m, n;
	char str1[100], str2[100], str3[100] = ".txt";
	
	Scanf(fp, "%d", &len);				//�ؼ����ܸ��� 
		
	m = len/K;							//mΪһ�ο��Դ����������ָ���					
	n = K+(len%m!=0);					//nΪ�鲢�θ��� 

	system("md tmpfile");				//������ʱ�ļ���tmp 
	
	for(i=0; i<n; i++)					//��n����ȡ
	{
		strcpy(str1, "tmpfile/");		
		itoa(i, str2, 10);				//[0..k-1]
	 	strcat(str1, strcat(str2, str3));//tmpfile/[0..k-1].txt
		
		fptr = fopen(str1, "w+");		//�洢�ֲ�����ؼ���(�鲢����)��[0..n-1].txt 
		
		L.length = 0;		
		for(j=1; j<=m; j++)				 
		{
			if(Scanf(fp, "%d", &tmp)==1)
			{
				L.length++;
				L.r[L.length].key = tmp;
			}
			else
				break;
		}
		
		MergeSort(&L);

		for(j=1; j<=L.length; j++)
			fprintf(fptr, "%d��", L.r[j].key);
		fprintf(fptr, "%d", MAXKEY);		//д�������־ 
		fclose(fptr);
	}
	
	fclose(fp);	
}

void input(FILE *fp[K], int *x, int i)		//i=0..k-1
{
	int tmp;
	char str1[100], str2[100], str3[100] = ".txt";
		
	if(!fp[i])								//�����ļ���ȡ 
	{
		strcpy(str1, "tmpfile/");		
		itoa(i, str2, 10);					//[0..k-1]
	 	strcat(str1, strcat(str2, str3));	//tmpfile/[0..k-1].txt

		fp[i] = fopen(str1, "r");			//��fp[i]�п�ʼ��ȡ 
	}
			
	if(Scanf(fp[i], "%d", &tmp)==1)
	{
		*x = tmp;

		if(tmp==MAXKEY)
			fclose(fp[i]);
	}
}

void output(FILE *fp, int x)
{
	fprintf(fp, "%d��", x);
}

void RandomNum(FILE *fp)
{
	int i, j, number, tag;
	int x[MAX+1]={0};						//����MAX������� 

	srand((unsigned)time(NULL)); 
	
	for(i=1; i<=MAX; i++)
	{		
		do
		{		
			number = rand()%(4*MAX-1) + 1;	//�������Χ1..4*MAX-1 

			tag = 0;			
			for(j=1; j<=x[0]; j++)			//��֤��������ظ� 
			{
				if(number==x[j])
				{
					tag = 1;
					break;
				}		
			}
			
			if(tag==0)
			{
				x[0]++;
				x[x[0]] = number;
			}
		}while(tag==1);
	}
 
	fprintf(fp, "��%d����", MAX);
	for(i=1; i<=x[0]; i++)
		fprintf(fp, "%d��", x[i]);

	fclose(fp);
}

#endif
