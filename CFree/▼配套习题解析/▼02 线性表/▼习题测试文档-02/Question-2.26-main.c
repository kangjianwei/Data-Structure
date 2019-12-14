#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_26(LinkList La, LinkList Lb, LinkList Lc);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList La, Lb, Lc;
	int i;
	
	if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))	//�������ɹ�
	{
		for(i=1; i<=10; i++)				//����ֵ
		{
			ListInsert_L(La, i, i);		
			ListInsert_L(Lb, i, 2*i);		
		}
	}
	
	printf("La = ");
	ListTraverse_L(La, PrintElem); 				//���
	printf("\n");
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 	
	printf("\n\n");	
	
	Algo_2_26(La, Lb, Lc);
	printf("Lc=La��Lb= "); 
	ListTraverse_L(Lc, PrintElem); 	
	printf("\n\n");	
		
	return 0;
}

/*����������������
����2.26��C=A��B��
����������������*/
Status Algo_2_26(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc, s;

	if(!La || !Lb)
		return ERROR;
	
	pa = La->next;
	pb = Lb->next;
	pc = Lc;
	
	while(pa && pb)
	{
		if(pa->data==pb->data)
		{
			s = (LinkList)malloc(sizeof(LNode));
			if(!s)
				exit(OVERFLOW);
			s->data = pa->data;
			s->next = NULL;
					
			pc->next = s;
		
			pc = pc->next;	
			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->data<pb->data)
			pa = pa->next;
		else
			pb = pb->next;
	}
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
