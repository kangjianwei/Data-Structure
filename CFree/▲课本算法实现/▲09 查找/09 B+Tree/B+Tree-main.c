/****************************
 *						    *
 * �ļ���: ��09 ����        *
 * 						    *
 * �ļ���: B+Tree-main.c    *
 * 						    *
 * ��  ��: B+����غ������� *
 *                          *
 ****************************/

#include <stdio.h>
#include "B+Tree.c" 						//**��09 ����**//

/* �궨�� */ 
#define Max 15								//���ұ���Ԫ�ظ���

int main(int argc, char *argv[])
{	
	Table T;
	B_Tree B_T;
	
	printf("���������һ�����ұ�...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");	
	}
	PressEnter; 

	printf("��1����8\n������ CreateB_Tree�� ����...\n");		//1����8.����CreateB_Tree�Ȳ���		
	{
		printf("����B+��...\n");
		CreateB_Tree(&B_T, T);
		printf("\n");
	}	
	PressEnter; 

	printf("��9\n������ PrintB_Tree ����...\n");				//9.����PrintB_Tree����	 
	{
		printf("���B+���Ĺؼ���...\n");
		PrintB_Tree(B_T); 
		printf("\n");
	}
	PressEnter;
	
	printf("��\n�����Ҳ���...\n");								//���Ҳ���	 
	{
		Result r;
		KeyType key = 30;
		
		printf("���ҹؼ���%d...\n", key);
		r = SearchB_Tree(B_T, key);
		if(r.tag==1)
			printf("���ҳɹ���%d ���������ĵ� %d ��λ�á�\n", key, Search(r.pt,key));
		else
			printf("����ʧ�ܣ�\n");
		printf("\n");
	}
	PressEnter; 
}
