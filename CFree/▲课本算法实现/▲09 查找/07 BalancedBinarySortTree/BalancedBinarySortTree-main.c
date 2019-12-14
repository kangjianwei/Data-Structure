/*****************************************
 *						                 *
 * �ļ���: ��09 ����                     *
 * 						                 *
 * �ļ���: BalancedBinarySortTree-main.c *
 * 							             *
 * ��  ��: ƽ�������������غ�������    *
 *                                       *
 *****************************************/

#include <stdio.h>
#include "BalancedBinarySortTree.c" 		//**��09 ����**//

/* �궨�� */
#define Max 7								//���ұ���Ԫ�ظ���

int main(int argc, char *argv[])
{
	Table T;
	BBSTree BBST; 
		
	printf("���������һ�����ұ�...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("��1��3��5��6��7��8��9\n������ CreateAVL�� ����...\n");		//1��3��5��6��7��8��9.����CreateAVL�Ȳ���		
	{
		printf("����������������������ؼ��֣�");
		CreateAVL(&BBST, T);
		InOrderTraverse_AVL(BBST, PrintKey);
		printf("\n\n");
	}	
	PressEnter;

	printf("��10��11\n������ PrintAVLTree�� ����...\n");				//10��11.����PrintAVLTree�Ȳ���		
	{
		printf("��ӡƽ���������\n");
		PrintAVLTree(BBST);
		printf("\n");
	} 
	PressEnter;
	
	printf("��2\n������ SearchAVL ����...\n");							//2.����SearchAVL����		
	{
		printf("�ؼ��� %2d ", T.elem[1].key);
		SearchAVL(BBST, T.elem[1].key)==NULL ? printf("����") : printf("��");
		printf("ƽ��������У�\n");
		printf("\n");
	}	
	PressEnter;

	printf("��4\n������ DeleteAVL ����...\n");							//4.����DeleteAVL����		
	{
		BBSTree f, p;
		Boolean taller;
	
		f = NULL;
		p = BBST;
		taller = FALSE;
		DeleteAVL(&BBST, T.elem[1], f, p, &taller, 0);	
		printf("ɾ���ؼ��� %2d ���ƽ�������Ϊ��\n", T.elem[1].key);
		PrintAVLTree(BBST);
		printf("\n");
	} 
	PressEnter;
	
	return 0;
}
