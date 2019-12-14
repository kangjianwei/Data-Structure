/**********************************
 *                                *
 * �ļ���: ��11 �ⲿ����          *
 *                                *
 * �ļ���: ReSeSort.c             *
 *                                *
 * ��  ��: 11.4��11.5��11.6��11.7 *
 *                                *
 **********************************/

#ifndef RESESORT_C
#define RESESORT_C

#include "ReSeSort.h" 					//**��11 �ⲿ����**//

/*�T�T�T�T�[
�U�㷨11.4�U 
�^�T�T�T�T*/
void Replace_Selectiom(FILE *fi, LoserTree ls, WorkArea wa)
{
	FILE *fo;
	char str1[100], str2[100], str3[100] = ".txt";
	
	Construct_Loser(fi, ls, wa);			//����������
	
	rc = rmax = 1;							//��ʼ����ǰ�κź����κ�Ϊ1 
											
	system("md tmpfile");					//������ʱ�ļ���tmp 
	
	while(rc<=rmax)							//"rc=rmax+1"��־�����ļ����û�-ѡ����������� 
	{
		strcpy(str1, "tmpfile/");		
		itoa(part, str2, 10);				//[0..k-1]
	 	strcat(str1, strcat(str2, str3));	//tmpfile/[0..k-1].txt

		fo = fopen(str1, "w+");				//�洢���鲢�Σ�[0..n-1].txt
			
		get_run(fi, fo, ls, wa);			//���һ����ʼ�鲢��
		fprintf(fo, "%d", RUNEND_SYMBOL);	//���ν�����־д������ļ�
		fclose(fo);
		part++;
		rc = wa[ls[0]].rnum;				//������һ�εĶκ�
	}
}

void get_run(FILE *fi, FILE *fo, LoserTree ls, WorkArea wa)
{
	int q, minimax;
	
	while(wa[ls[0]].rnum==rc)						//ѡ�õ�MINIMAX��¼����ǰ��ʱ
	{
		q = ls[0];									//qָʾMINIMAX��¼��wa�е�λ�� 
		minimax = wa[q].key;
		fprintf(fo, "%d��", wa[q].rec.key);			//����ѡ�õ�MINIMAX��¼д������ļ�
											
		//�������ļ�������һ��¼
		if(Scanf(fi, "%d", &(wa[q].rec.key))!=1)	//��ȡʧ�ܣ��������ļ�����
		{
			wa[q].rnum = rmax + 1;					//�����¼(����rmax+1����)
			wa[q].key = MAXKEY;				 
		}
		else
		{
			wa[q].key = wa[q].rec.key;				//��ȡ�ؼ���
			
			if(wa[q].key<minimax)					//�¶���ļ�¼������һ��
			{
				rmax = rc + 1;
				wa[q].rnum = rmax;
			}
			else
				wa[q].rnum = rc;					//�¶���ļ�¼���ڵ�ǰ�� 
		}
		
		Select_MiniMax(ls, wa, q); 					//ѡ���µ�MINIMAX��¼ 
	}
}

void Select_MiniMax(LoserTree ls, WorkArea wa, int q)
{
	int p, t, tmp;
	 
	for(t=(W+q)/2,p=ls[t]; t>0; t=t/2,p=ls[t])
	{
		if(wa[p].rnum<wa[q].rnum || wa[p].rnum==wa[q].rnum&&wa[p].key<wa[q].key)
		{
			tmp = q;								//qָ���µ�ʤ���� 
			q = ls[t];
			ls[t] = tmp;
		}
	}
	
	ls[0] = q;
}

void Construct_Loser(FILE *fi, LoserTree ls, WorkArea wa)	//������wa��һ�ð����� 
{
	int i;
	 
	for(i=0; i<W; i++)
		wa[i].rnum = wa[i].key = ls[i] = 0;			//��������ʼ��
		
	for(i=W-1; i>=0; i--)
	{
		Scanf(fi, "%d", &(wa[i].rec.key));			//����һ����¼	
		wa[i].key = wa[i].rec.key; 					//��ȡ�ؼ���
		wa[i].rnum = 1;								//��κ�Ϊ��1��
		Select_MiniMax(ls, wa, i);					//�������� 
	}
}

#endif
