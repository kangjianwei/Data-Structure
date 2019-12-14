/**********************************
 *						          *
 * �ļ���: ��10 �ڲ�����          *
 * 						          *
 * �ļ���: TInsertSort-main.c     *
 * 							      *
 * ��  ��: �����������غ������� *
 *                                *
 **********************************/

#include <stdio.h>
#include "TInsertSort.c" 	//**��10 �ڲ�����**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{
	SLinkList_sort L;
			
	printf("���������һ����������...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("��1��2\n������ TInsertSort�� ����...\n");	//1��2.����TInsertSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n"); 
		TInsertSort(&L); 
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
