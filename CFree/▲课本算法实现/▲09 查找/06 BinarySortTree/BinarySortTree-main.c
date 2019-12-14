/**********************************
 *						          *
 * �ļ���: ��09 ����              *
 * 						          *
 * �ļ���: BinarySortTree-main.c  *
 * 							      *
 * ��  ��: ������������غ������� *
 *                                *
 **********************************/

#include <stdio.h>
#include "BinarySortTree.c" 								//**��09 ����**//

#define Max 7												//���ұ���Ԫ�ظ���

int main(int argc, char *argv[])
{		
	Table T;
	BSTree BST;
		
	printf("���������һ�����ұ�...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("��1��3��4��5\n������ CreateBSTree�� ����...\n");	//1��3��4��5.����CreateBSTree�Ȳ���		
	{
		printf("����������������������ؼ��֣�");
		CreateBSTree(&BST, T);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n\n");	
	}
	PressEnter; 
	
	printf("��2\n������ SearchBST_1 ����...\n");				//2.����SearchBST_1����		
	{
		printf("�ؼ��� 24 ");
		SearchBST_1(BST, 24)==NULL ? printf("����") : printf("��");
		printf("�����������У�"); 
		printf("\n\n");	
	}
	PressEnter; 	

	printf("��6��7\n������ DeleteBST�� ����...\n");			//6��7.����DeleteBST�Ȳ���		
	{
		printf("ɾ���ؼ��� 24 ��Ĺؼ�������Ϊ��");	
		DeleteBST(&BST, 24);
		InOrderTraverse_BST(BST, PrintKey);	
		printf("\n\n");	
	}
	PressEnter; 

	return 0;
}
