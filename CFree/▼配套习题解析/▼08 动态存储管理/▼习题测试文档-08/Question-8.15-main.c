#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"

/* �궨�� */
#define MAX 1000

/* ���Ͷ��� */
typedef struct Block
{
	int tag;					//0������У�1����ռ�� 
	int cellsize;				//����Ŀ��С
	struct Block *next;			//ָ����һ�����п�
}Block;
typedef struct
{
	Block *lowbound;
	Block *highbound;
}Memory;

/* ȫ�ֱ��� */
Memory Space;
Block *Heap;

/* ����ԭ�� */
void Algo_8_15();
void InitSpace();				//��ʼ���ڴ�ռ�
Block* MallocSpace(int n);		//�����СΪn���ڴ�� 
void FreeSpace(Block *p);		//����pָ����ڴ�� 
void PrintLayout();				//����ڴ�ռ����� 

int main(int argc, char *argv[])
{
	Block *p1, *p2, *p3, *p4, *p5, *p6;

	printf("��ʼ���ڴ�ռ�...\n");	
	InitSpace();
	PrintLayout();
	printf("\n");
	
	printf("���� %d ���ڴ�� p1\n", 200); 
	p1 = MallocSpace(200);
	PrintLayout();	
	printf("\n");

	printf("���� %d ���ڴ�� p2\n", 200); 		
	p2 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("���� %d ���ڴ�� p3\n", 200); 			
	p3 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("���� %d ���ڴ�� p4\n", 300); 				
	p4 = MallocSpace(300);
	PrintLayout();
	printf("\n");

	printf("���մ�СΪ %d ���ڴ�� p1\n", 200);		
	FreeSpace(p1);
	PrintLayout();	
	printf("\n");

	printf("���մ�СΪ %d ���ڴ�� p3\n", 200);			
	FreeSpace(p3);
	PrintLayout();	
	printf("\n");
	
	printf("�����ڴ棬������Ƭ...\n");		
	Algo_8_15();
	PrintLayout();
	printf("\n");

	printf("���մ�СΪ %d ���ڴ�� p5\n", 300);			
	p5 = MallocSpace(300);
	PrintLayout();	
	printf("\n");

	printf("���մ�СΪ %d ���ڴ�� p2\n", 200);			
	FreeSpace(p2);
	PrintLayout();
	printf("\n");
		
	printf("���մ�СΪ %d ���ڴ�� p6\n", 200);	
	p6 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("���մ�СΪ %d ���ڴ�� p4\n", 300);			
	FreeSpace(p4);
	PrintLayout();
	printf("\n");

	printf("�����ڴ棬������Ƭ...\n");			
	Algo_8_15();
	PrintLayout();
	printf("\n");
										
	return 0;
}

/*��������������������
����8.15�����ڴ���թ�
��������������������*/
void Algo_8_15()
{
	Block *p, *q;
	int count, k;
	
	for(p=Space.lowbound,count=0,Heap=NULL; p<=Space.highbound; p++)
	{
		if(p->tag==0)				//������Ƭ����δʹ�õĿռ�����յ�һ�� 
		{
			count++;
			if(!Heap)
				Heap = q = p;
			else
			{
				q->next = p;
				q = q->next;			
			}
		}
	}
	
	q->next = NULL;
	Heap->cellsize = count;
}

void InitSpace()				//��ʼ���ڴ�ռ�
{
	Block *pre, *p;
	
	Space.lowbound = (Block *)malloc(MAX*sizeof(Block));
	Space.highbound = Space.lowbound + MAX - 1;
	
	Heap = Space.lowbound;
	Heap->cellsize = MAX;
	
	pre=Space.lowbound;
	pre->tag = 0;
	if(MAX>1)
	{
		for(p=pre+1; p<=Space.highbound; p++,pre++)
		{
			p->tag = 0;
			pre->next = p;
		}
	}
	pre->next = NULL;
}

Block* MallocSpace(int n)
{
	Block *p, *q;
	int count;
	
	if(!Heap || Heap->cellsize<n)		//�ڴ��Ѳ��� 
		return NULL;
	
	p = q = Heap;
	
	for(count=1; count<n; count++)
	{
		q->tag = 1;
		q = q->next;
	}
	
	Heap = q->next;
	if(Heap)
		Heap->cellsize = p->cellsize - n;
	
	q->tag = 1;
	q->next = NULL;
	p->cellsize = n;
	
	return p;
}

void FreeSpace(Block *p)
{
	Block *r = p;
		
	while(r)
	{
		r->tag = 0;
		r = r->next; 
	}
}

void PrintLayout()
{
	int x, y, z, k;
	Block *p, *q;
	
	if(Heap)
		x = Heap->cellsize;				//�����ڴ���� 					
	else
		x = 0;
		
	for(p=Space.lowbound,y=0; p<=Space.highbound; p++)
	{
		if(p->tag==1)				//ͳ�Ʊ�ռ�õ��ڴ�� 
			y++;
	}
	
	z = MAX - x - y;				//ͳ����Ƭ��
	
	printf("���ÿռ� %4d��δ�ÿռ� %4d����Ƭ�� %4d���ڴ��ܿռ� %4d��\n", y, x, z, MAX);
}
