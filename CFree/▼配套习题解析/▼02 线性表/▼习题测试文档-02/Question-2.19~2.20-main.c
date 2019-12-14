#include <stdio.h>
#include <stdlib.h>													//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_19_1(LinkList L, int mink, int maxk); 
Status Algo_2_19_2(LinkList L, int mink, int maxk);
Status Algo_2_20(LinkList L);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList L;
	int mink, maxk_1, maxk_2, i;
	int a[] = {1, 2, 2, 3, 4, 4, 5, 6, 7, 7};
	
	mink = 2;
	maxk_1 = 4;
	maxk_2 = 6;
	
	InitList_L(&L);
	
	for(i=0; i<10; i++)
		ListInsert_L(L, i+1, a[i]);
	
	printf("ԭ����L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");
	
	printf("�������� 2.19 ��֤...������\n");
	printf("ɾ�������д��� %d ��С�� %d ��Ԫ��֮��...\n", mink, maxk_1);
	Algo_2_19_1(L, mink, maxk_1);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n");

	printf("ɾ�������д��� %d ��С�� %d ��Ԫ��֮��...\n", mink, maxk_2);
	Algo_2_19_2(L, mink, maxk_2);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");
	
	printf("�������� 2.20 ��֤...������\n");
	printf("ȥ�������ж�����ظ�Ԫ��...\n");
	Algo_2_20(L);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");	
	
	
	return 0;
}

/*��������������������������������������������������������
����2.19��ɾ���������Ա���Ԫ�ش���minkС��maxk֮��Ľ�㩧
��������������������������������������������������������*/
/* ����1 */
Status Algo_2_19_1(LinkList L, int mink, int maxk)
{
	LinkList p, pre, s;

	if(!L || !L->next)			//L�����ڻ�Ϊ�ձ�ʱ���޷�ɾ�� 
		return ERROR;

	if(mink>=maxk)				//��ֵ���ô��� 
		return ERROR;
			
	pre = L;
	p = pre->next;				//pָ���׽�� 

	while(p && p->data<maxk) 	//���� 
	{
		if(p->data<=mink) 		//���� 
		{
			pre = p;
			p = p->next;
		}
		else					//ɾ�����������Ľ�� 
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
	}
	
	return OK;
}

/*��������������������������������������������������������
����2.19��ɾ���������Ա���Ԫ�ش���minkС��maxk֮��Ľ�㩧
��������������������������������������������������������*/
/* ����2 */
Status Algo_2_19_2(LinkList L, int mink, int maxk)
{
	LinkList p, pre, s;

	if(!L || !L->next)				//L�����ڻ�Ϊ�ձ�ʱ���޷�ɾ�� 
		return ERROR;

	if(mink>=maxk)					//��ֵ���ô��� 
		return ERROR;

	pre = L;
	p = pre->next;					//pָ���׽�� 


	while(p && p->data<=mink)		//����
	{
		pre = p;
		p = p->next;
	}

	if(p)
	{
		while(p && p->data<maxk)	//����
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
		return OK;
	}
}

/*����������������������������������
����2.20��ɾ������ֵ��ͬ�Ķ����㩧
����������������������������������*/
Status Algo_2_20(LinkList L)
{
	LinkList p, pre, s;
		
	if(!L || !L->next)				//L�����ڻ�Ϊ�ձ�ʱ���޷�ɾ�� 
		return ERROR;

	pre = L->next;
	p = pre->next;					//pָ���׽��
	
	while(p)
	{
		if(pre->data==p->data)
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}	
	
	return OK;
} 

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
