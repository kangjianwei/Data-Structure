/********************************************
 *										    *
 * �ļ���: ��06 ���Ͷ�����\01 SeqBinaryTree *
 * 									        *
 * �ļ���: SeqBinaryTree-main.c             *
 * 										    *
 * ��  ��: ��������˳��洢����غ�������   *
 *                                          *
 ********************************************/

#include <stdio.h> 
#include "SeqBinaryTree.c" 									//**��06 ���Ͷ�����**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	SqBiTree T;

	printf("��1\n������ InitBiTree_Sq ����...\n");			//1.����InitBiTree_Sq����
	{
		printf("��ʼ���ն����� T ...\n");
		InitBiTree_Sq(T);
		printf("\n");
	}
	PressEnter; 
	
	printf("��4\n������ BiTreeEmpty_Sq ����...\n");			//4.����BiTreeEmpty_Sq����
	{
		BiTreeEmpty_Sq(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ CreateBiTree_Le_Sq ����...\n");		//5.����CreateBiTree_Le_Sq����
	{
		FILE *fp;
		
		printf("���������д��������� T ...\n");
		fp = fopen("TestData_Le.txt", "r");	
		CreateBiTree_Le_Sq(fp, T);
		fclose(fp); 
		printf("\n");
	}
	PressEnter;
/*
	printf("��6\n������ CreateBiTree_Pre_Sq ����...\n");	//6.����CreateBiTree_Pre_Sq����
	{
		FILE *fp;
		
		printf("���������д��������� T ...\n");
		fp = fopen("TestData_Pre.txt", "r");	
		CreateBiTree_Pre_Sq(fp, T, 0);						//i��0��ʼ 
		fclose(fp); 
		printf("\n");
	}
	PressEnter;
*/
	printf("��29\n������ Print_Sq ����...\n");				//29.����Print_Sq����
	{
		printf("���������Ľṹ��ӡ�� T ...\n");
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;

	printf("��7��8\n������ BiTreeLength_Sq��BiTreeDepth_Sq ����...\n");	//7��8.����BiTreeLength_Sq��BiTreeDepth_Sq����
	{
		printf(" T �ĳ���Ϊ��%d�����Ϊ��%d��\n", BiTreeLength_Sq(T), BiTreeDepth_Sq(T));
		printf("\n");
	}
	PressEnter;	
	
	printf("��17\n������ LevelOrderTraverse_Sq ����...\n");		//17.����LevelOrderTraverse_Sq����
	{
		printf("������������� T = ");
		LevelOrderTraverse_Sq(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��18\n������ PreOrderTraverse_Sq �Ȳ���...\n");		//18.����PreOrderTraverse_Sq����
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;

	printf("��19\n������ InOrderTraverse_Sq �Ȳ���...\n");		//19����InOrderTraverse_Sq����
	{
		printf("������������� T = ");
		InOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;

	printf("��20\n������ PostOrderTraverse_Sq �Ȳ���...\n");	//20.����PostOrderTraverse_Sq����
	{
		printf("������������� T = ");
		PostOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��9\n������ Root_Sq ����...\n");					//9.����Root_Sq����
	{
		TElemType_Sq r;
		
		printf(" T �ĸ����Ϊ %c\n", r);
		Root_Sq(T, &r);
		printf("\n");
	}
	PressEnter;	

	printf("��10\n������ Value_Sq ����...\n");					//10.����Value_Sq����
	{
		Position p = {4, 3};
		
		printf(" T �е� %d �е� %d �е�ֵΪ %c\n", p.level, p.order, Value_Sq(T, p));
		printf("\n");
	}
	PressEnter;

	printf("��11\n������ Assign_Sq ����...\n");					//11.����Assign_Sq����
	{
		Position p = {4, 3};									//4��3��

		printf("���� %d ��� %d �еĽ�㸳ֵΪ 'X' ��T = \n", p.level, p.order);
		Assign_Sq(T, p, 'X');
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;

	printf("��12\n������ Parent_Sq ����...\n");					//12.����Parent_Sq����
	{
		printf(" 'X' ����˫��Ϊ�� %c \n", Parent_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("��13��14\n������ LeftChild_Sq��RightChild_Sq ����...\n");	//13��14.����LeftChild_Sq��RightChild_Sq����
	{
		printf(" 'E' �����ӽ��ֵΪ��%c ���Һ��ӽ��ֵΪ��%c\n", LeftChild_Sq(T, 'E'), RightChild_Sq(T, 'E'));
		printf("\n");
	}
	PressEnter;

	printf("��15\n������ LeftSibling_Sq ����...\n");			//15.����LeftSibling_Sq����
	{
		printf(" 'I' �����ֵ�Ϊ��%c\n", LeftSibling_Sq(T, 'I'));
		printf("\n");
	} 
	PressEnter;	

	printf("��16\n������ RightSibling_Sq ����...\n");			//16.����RightSibling_Sq����
	{
		printf(" 'X' �����ֵ�Ϊ��%c\n", RightSibling_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;

	
	printf("��2\n������ ClearBiTree_Sq ����...\n");				//2.����ClearBiTree_Sq����
	{
		ClearBiTree_Sq(T);
		if(BiTreeEmpty_Sq(T))
			printf(" T �ѱ����!\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
