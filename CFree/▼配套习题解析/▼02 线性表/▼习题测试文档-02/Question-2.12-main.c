#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
int Algo_2_12(SqList A, SqList B);
	
void PrintElem(LElemType_Sq e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	int i, mark;
	SqList A, B;
	int a[7] = {1, 2, 3, 4, 5, 9, 12};
	int b[7] = {1, 2, 3, 4, 5, 11, 12};
	
	InitList_Sq(&A);
	InitList_Sq(&B);
	
	for(i=1; i<=7; i++)
	{
		ListInsert_Sq(&A, i, a[i-1]);
		ListInsert_Sq(&B, i, b[i-1]);
	}
	
	printf("������ɵ�˳���Ϊ��\n");
	printf("A = ");
	ListTraverse_Sq(A, PrintElem);
	printf("\n");
	printf("B = ");
	ListTraverse_Sq(B, PrintElem);
	printf("\n\n");		
	
	mark = Algo_2_12(A, B);
	printf("��׺�ȽϽ����");
	if(mark<0)
		printf("A<B\n");
	else if(mark>1)
		printf("A>B\n");
	else
		printf("A==B\n");
	printf("\n");				
	
	return 0;
}

/*����������������������������
����2.12���Ƚ�˳����׺��С��
����������������������������*/
int Algo_2_12(SqList A, SqList B)
{
	int i;

	i = 0;
	
	while(i<A.length && i<B.length)			//A��B��δɨ���� 
	{
		if(A.elem[i]>B.elem[i])
			return 1;
		else if(A.elem[i]<B.elem[i])
			return -1;
		else
			i++;							//���ʱ�Ƚ���һԪ�� 
	}
	
	if(i<A.length)							//A����ʣ�࣬A�� 
		return 1;
	else if(i<B.length)						//B����ʣ�࣬B�� 
		return -1;
	else
		return 0;							//ͬʱɨ���꣬��� 
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
