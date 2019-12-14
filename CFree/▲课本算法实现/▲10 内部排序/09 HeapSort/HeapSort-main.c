/******************************
 *						      *
 * �ļ���: ��10 �ڲ�����      *
 * 						      *
 * �ļ���: HeapSort-main.c    *
 * 							  *
 * ��  ��: ��������غ������� *
 *                            *
 ******************************/

#include <stdio.h>
#include "HeapSort.c" 									//**��10 �ڲ�����**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{		
	HeapType H;
			
	printf("���������һ����������...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &H);
		Traverse(H, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("��1��2\n������ HeapSort�� ����...\n");			//1��2.����HeapSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n");
		HeapSort(&H); 
		Traverse(H, PrintKey);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
