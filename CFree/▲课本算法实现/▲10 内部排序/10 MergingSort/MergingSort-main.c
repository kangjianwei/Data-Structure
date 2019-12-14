/********************************
 *						        *
 * �ļ���: ��10 �ڲ�����        *
 * 						        *
 * �ļ���: MergingSort-main.c   *
 * 							    *
 * ��  ��: �鲢������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "MergingSort.c"	//**��10 �ڲ�����**//

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
	
	printf("��1��2��3\n������ MergingSort�� ����...\n");	//1��2��3.����MergingSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n");
		MergeSort(&L); 
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
