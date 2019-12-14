#include <stdio.h>
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
int Algo_2_13(LinkList L, LElemType_L x);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//����L�����ɹ�
	{
		for(i=1; i<=10; i++)
			ListInsert_L(L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 			//���L
	printf("\n\n");	
	
	printf("Ԫ�� \"12\" ������L�е�λ��Ϊ %d \n", Algo_2_13(L, 18)); 
	printf("\n");
		
	return 0;
}

/*������������������������������
����2.13��Ѱ��Ԫ��x��L�е�λ�é�
������������������������������*/
int Algo_2_13(LinkList L, LElemType_L x)
{
	int i;
	LinkList p;
		
	if(L)
	{
		i = 1;		
		p = L->next;
		while(p)
		{
			if(p->data==x)
				return i;
			i++;
			p = p->next;
		}
	}
	
	return 0;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
