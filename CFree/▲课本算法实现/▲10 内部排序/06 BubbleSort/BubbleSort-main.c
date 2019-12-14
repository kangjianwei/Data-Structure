/********************************
 *						        *
 * �ļ���: ��10 �ڲ�����        *
 * 						        *
 * �ļ���: BubbleSort-main.c    *
 * 							    *
 * ��  ��: ����������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "BubbleSort.c" 									//**��10 �ڲ�����**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{		
	SqList_sort L;
			
	printf("���������һ����������...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("��1\n������ BubbleSort ����...\n");					//1.����BubbleSort����
	{
		printf("���ؼ��ְ�����˳������...\n");
		BubbleSort(&L); 
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
