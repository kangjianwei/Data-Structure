/***************************
 *						   *
 * �ļ���: ��09 ����       *
 * 						   *
 * �ļ���: B-Tree-main.c   *
 * 						   *
 * ��  ��: B����غ������� *
 *                         *
 ***************************/

#include <stdio.h>
#include "B-Tree.c" 							//**��09 ����**//

/* �궨�� */
#define Max 15									//���ұ���Ԫ�ظ���

int main(int argc, char *argv[])
{	
	Table T;
	BTree BT;

	printf("���������һ�����ұ�...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("��1����8\n������ CreateBTree�� ����...\n");		//1����8.����CreateBTree�Ȳ���		
	{
		printf("����B��...\n");
		CreateBTree(&BT, T);
		printf("\n");
	}	
	PressEnter; 
	
	printf("��16\n������ PrintBT_InOreder ����...\n");		//16.����PrintBT_InOreder����	 
	{
		printf("���������B���ؼ��֣�");
		PrintBT_InOreder(BT); 
		printf("\n\n");
	}
	PressEnter;
	
	printf("��17\n������ PrintBT_InOreder�� ����...\n");	//17.����PrintBT_Level����
	{
		printf("��������B���ؼ��֣�\n");
		PrintBT_Level(BT);
		printf("\n");
	}	
	PressEnter; 
	
	printf("��9����15\n������ DeleteKey�� ����...\n");		//9����15.����DeleteKey�Ȳ���
	{
		int K = 45;
			
		printf("ɾ���ؼ��� %d ...\n", K);
		DeleteKey(&BT, K);
		printf("���������B���ؼ��֣�");
		PrintBT_InOreder(BT); 
		printf("\n");
		printf("��������B���ؼ��֣�\n");
		PrintBT_Level(BT);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}
