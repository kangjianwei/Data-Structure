/***********************************
 *						           *
 * �ļ���: ��10 �ڲ�����           *
 * 						           *
 * �ļ���: SequenceListType-main.c *
 * 							       *
 * ��  ��: ˳�����غ�������      *
 *                                 *
 ***********************************/

#include <stdio.h>
#include "SequenceListType.c" 	//**��10 �ڲ�����**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{		
	SqList_sort L;
	
	printf("��1��2\n������ CreateSortList�� ����...\n");	//1��2.����CreateSortList�Ȳ���		
	{
		FILE *fp;
		
		printf("���������һ����������...\n");
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
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
