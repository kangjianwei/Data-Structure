#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_15(LinkList ha, LinkList hb, LinkList *hc);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList ha, hb, hc;
	int i;
	
	if(InitList_L(&ha) && InitList_L(&hb) && InitList_L(&hc))	//�������ɹ�
	{
		for(i=1; i<=5; i++)					//����ֵ
			ListInsert_L(ha, i, i);		
		for(i=1; i<=7; i++)					//����ֵ
			ListInsert_L(hb, i, 2*i);		
	}
	
	printf("ha = ");
	ListTraverse_L(ha, PrintElem); 				//���
	printf("\n");
	printf("hb = ");
	ListTraverse_L(hb, PrintElem); 	
	printf("\n\n");	
	
	Algo_2_15(ha, hb, &hc);
	printf("����ha��hb֮�������Ϊ��\nhc = "); 
	ListTraverse_L(hc, PrintElem); 	
	printf("\n\n");	
		
	return 0;
}

/*��������������������
����2.15������ha��hb��
��������������������*/
Status Algo_2_15(LinkList ha, LinkList hb, LinkList *hc)
{
	LinkList pa, pb;					//pa��pb�ֱ�ָ��ha��hbͷ��� 

	if(ha && hb)
	{
		pa = ha;
		pb = hb;
		
		while(pa->next && pb->next)
		{
			pa = pa->next;
			pb = pb->next;
		}
		
		if(!pa->next)
		{
			*hc = ha;
			pa->next = hb->next;		
		}
		
		if(!pb->next)
		{
			*hc = hb;
			pb->next = ha->next;
		}
		
		return OK;
	}
	
	return ERROR;	
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
