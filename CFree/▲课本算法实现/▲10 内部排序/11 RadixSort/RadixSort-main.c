/********************************
 *						        *
 * �ļ���: ��10 �ڲ�����        *
 * 						        *
 * �ļ���: RadixSort-main.c     *
 * 							    *
 * ��  ��: ����������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "RadixSort.c" 									//**��10 �ڲ�����**//

int main(int argc, char *argv[])
{	
	SLList L;
			
	printf("���������һ����������...\n");
	printf("��1��2\n������ CreateSLList�� ����...\n");	//1��2.����CreateSLList�Ȳ���
	{
		FILE *fp;
		fp = fopen("TestData.txt", "r");
		CreateSLList(fp, &L);
		Traverse(L);
		printf("\n");
	}	
	PressEnter; 
	
	printf("��3��4��5\n������ RadixSort�� ����...\n");	//3��4��5.����RadixSort�Ȳ���
	{
		printf("�����ؼ��ְ�����˳������...\n");
		RadixSort(&L); 
		Traverse(L);
		printf("\n");
	}	
	PressEnter; 
		
	return 0;
}
