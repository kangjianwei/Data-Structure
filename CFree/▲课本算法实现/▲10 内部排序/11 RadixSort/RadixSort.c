/*******************************
 *                             *
 * �ļ���: ��10 �ڲ�����       *
 *                             *
 * �ļ���: RadixSort.c         *
 *                             *
 * ��  ��: 10.15��10.16��10.17 *
 *                             *
 *******************************/

#ifndef RADIXSORT_C
#define RADIXSORT_C

#include "RadixSort.h" 							//**��10 �ڲ�����**//

void CreateSLList(FILE *fp, SLList *L)
{
	int i;
	char s[1000];
		
	Scanf(fp, "%d", &((*L).keynum));			//�ؼ��ָ��� 
	
	(*L).recnum = 0;							//��̬����ǰ���� 
	
	while(Scanf(fp, "%s", &s)==1)
	{
		(*L).recnum++;
		
		for(i=0; i<(*L).keynum; i++)			//����λ����λ��˳�򽫹ؼ��ִ洢��keys 
			(*L).r[(*L).recnum].keys[(*L).keynum-1-i] = s[i];
	}
	
	for(i=0; i<(*L).recnum; i++)				//��L����Ϊ��̬����ѭ���� 
		(*L).r[i].next = i + 1;
	(*L).r[(*L).recnum].next = 0;	
}

void Traverse(SLList L)
{
	int i, j;
	
	for(i=L.r[0].next; i; i=L.r[i].next)
	{
		for(j=L.keynum-1; j>=0; j--)
			printf("%c", L.r[i].keys[j]);
		
		printf(" ");
	}
	
	printf("\n");
}

/*�T�T�T�T�T�[
�U �㷨10.17�U 
�^�T�T�T�T�T*/
void RadixSort(SLList *L)
{
	int i;
	ArrType f, e;

	for(i=0; i<(*L).keynum; i++)				//�����λ�������ζԸ��ؼ��ֽ��з�����ռ� 
	{
		Distribute((*L).r, i, f, e);			//��i�˷��� 
		Collect((*L).r, i, f, e);				//��i���ռ�
	}
}

/*�T�T�T�T�T�[
�U �㷨10.15�U 
�^�T�T�T�T�T*/
void Distribute(SLCell r[], int i, ArrType f, ArrType e)
{
	int j, p;
	
	for(j=0; j<RADIX; j++)						//���ӱ��ʼ��Ϊ�ձ�
	{
		f[j] = 0;
		e[j] = 0;	
	}
	
	for(p=r[0].next; p; p=r[p].next)
	{
		j = ord(r[p].keys[i]);					//ord����¼�е�i���ؼ���ӳ�䵽[0..RADIX-1] 
		
		if(!f[j])
			f[j] = p;
		else
			r[e[j]].next = p;
		
		e[j] = p;								//��p��ָ�Ľ������j���ӱ��� 
	}
} 

/*�T�T�T�T�T�[
�U �㷨10.16�U 
�^�T�T�T�T�T*/
void Collect(SLCell r[], int i, ArrType f, ArrType e)
{
	int j, t;
	 
	for(j=0; j<RADIX&&!f[j]; j=succ(j))			//�ҵ�һ���ǿ��ӱ�succΪ���̺��� 
		;
	
	if(j<RADIX)
	{
		r[0].next = f[j];						//r[0].nextָ���һ���ǿ��ӱ��е�һ����� 
		t = e[j];
		
		while(j<RADIX)
		{
			for(j=succ(j); j<RADIX-1&&!f[j]; j=succ(j))
				;								//Ѱ����һ���ǿ��ӱ� 
			
			if(f[j]&&j<=RADIX-1)				//���������ǿ��ӱ� 
			{
				r[t].next = f[j];
				t = e[j];
			}
		}
		
		r[t].next = 0;							//tָ�����һ���ǿ��ӱ��е����һ����� 
	}
}

#endif
