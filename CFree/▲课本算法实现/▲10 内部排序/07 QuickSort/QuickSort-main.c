/********************************
 *						        *
 * �ļ���: ��10 �ڲ�����        *
 * 						        *
 * �ļ���: QuickSort-main.c     *
 * 							    *
 * ��  ��: ����������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "QuickSort.c" 										//**��10 �ڲ�����**//

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
	
	printf("��1��2��3��4\n������ QuickSort�� ����...\n");		//1��2��3��4.����QuickSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n");
		QuickSort(&L); 
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
