#include <stdio.h>
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
int Algo_2_14(LinkList L);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//����L�����ɹ�
	{
		for(i=1; i<=10; i++)			//����L��Ԫ��1~20 
			ListInsert_L(L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 			//���L
	printf("\n\n");	
	
	printf("����L�ĳ���Ϊ %d \n", Algo_2_14(L)); 
	printf("\n");
		
	return 0;
}

/*������������������
����2.14����L���� ��
������������������*/
int Algo_2_14(LinkList L)
{
	return ListLength_L(L);				//�Ѷ��� 
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
