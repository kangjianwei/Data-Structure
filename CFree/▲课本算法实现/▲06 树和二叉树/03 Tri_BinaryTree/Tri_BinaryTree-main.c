/**********************************************
 *										      *
 * �ļ���: ��06 ���Ͷ�����\03 Tri_BinaryTree  *
 * 									          *
 * �ļ���: Tri_BinaryTree-main.c              *
 * 										      *
 * ��  ��: ����������������洢����غ������� *
 *                                            *
 *********************************************/

#include <stdio.h>
#include "Tri_BinaryTree.c" 						//**��06 ���Ͷ�����**//

void PrintElem(TElemType_Tri e);

int main(int argc, char *argv[])
{
	TBiTree T;
	
	printf("��1\n������ InitBiTree_Tri ����...\n");				//1.����InitBiTree_Tri����
	{
		printf("��ʼ��һ���ն����� T ...\n");
		InitBiTree_Tri(&T);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ BiTreeEmpty_Tri ����...\n");			//4.����BiTreeEmpty_Tri����
	{
		BiTreeEmpty_Tri(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��5��6\n������ CreateBiTree_Tri�� ����...\n");		//5��6.����Create_Tri��CreateBiTree_Tri����
	{
		FILE *fp;
		
		printf("���������д��������� T ...\n");
		printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree_Tri(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("��24\n������ Print_Tri ����...\n");					//24.����Print_Tri����
	{
		printf("���������Ľṹ��ӡ����T = \n");
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;
	
	printf("��7��8\n������ BiTreeLength_Tri��BiTreeDepth_Tri ����...\n");//7��8.����BiTreeLength_Tri��BiTreeDepth_Tri����	
	{
		printf(" T �ĳ���Ϊ��%d�����Ϊ %d \n", BiTreeLength_Tri(T), BiTreeDepth_Tri(T));
		printf("\n");
	}
	PressEnter;
	
	printf("��20\n������ LevelOrderTraverse_Tri ����...\n");	//20.����LevelOrderTraverse_Tri����
	{
		printf("������������� T = ");
		LevelOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��21\n������ PreOrderTraverse_Tri ����...\n");		//21.����PreOrderTraverse_Tri����
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��22\n������ InOrderTraverse_Tri ����...\n");		//22.����InOrderTraverse_Tri����
	{
		printf("������������� T = ");
		InOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��23\n������ PostOrderTraverse_Tri ����...\n");		//23.����PostOrderTraverse_Tri����
	{
		printf("������������� T = ");
		PostOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;	
	
	printf("��9\n������ Root_Tri ����...\n");					//9.����Root_Tri����
	{
		TElemType_Tri e;
		
		Root_Tri(T, &e);
		printf(" T �ĸ����Ϊ %c \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��10\n������ Value_Tri ����...\n");					//10.����Value_Tri����
	{
		TBiTree p;
		
		p = T->lchild->rchild->lchild;
		printf("ָ�� p ָ��Ľ��ֵΪ %c \n", Value_Tri(p));
		printf("\n");
	}
	PressEnter;	
	
	printf("��11\n������ Assign_Tri ����...\n");				//11.����Assign_Tri����
	{
		TBiTree p;
		
		p = T->lchild->rchild->lchild;
		Assign_Tri(p, 'X');
		printf("�� 'X' ���� p ָ��Ľ���T = \n");
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("��12��13\n������ Point��Parent ����...\n");			//12��13.����Point��Parent_Tri����
	{
		printf(" 'X' ��˫��Ϊ��%c \n", Parent_Tri(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("��14��15\n������ LeftChild_Tri��RightChild_Tri ����...\n");	//14��15.����LeftChild_Tri��RightChild_Tri����
	{
		printf(" 'E' �����ӽ��ֵΪ��%c ���Һ��ӽ��ֵΪ��%c \n", LeftChild_Tri(T, 'E'), RightChild_Tri(T, 'E'));
		printf("\n");
	}
	PressEnter;	
	
	printf("��16\n������ LeftSibling_Tri ����...\n");			//16.����LeftSibling_Tri����
	{
		printf(" 'I' �����ֵ�Ϊ��%c \n", LeftSibling_Tri(T, 'I'));
		printf("\n");
	}
	PressEnter;	

	printf("��17\n������ RightSibling_Tri ����...\n");			//17.����RightSibling_Tri����
	{
		printf(" 'X' �����ֵ�Ϊ��%c \n", RightSibling_Tri(T, 'X'));
		printf("\n");
	}
	PressEnter;	
		
	printf("��18\n������ InsertBiTree_Tri ����...\n");			//18.����InsertBiTree_Tri���� 
	{
		FILE *fp;
		TBiTree T0;
		
		printf("��������ӡ������ T0 = \n");
		InitBiTree_Tri(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateBiTree_Tri(fp, &T0); 
		fclose(fp);
		Print_Tri(T0);
		printf("�� T0 ���뵽 T �г�Ϊ��㡮E������������T = \n");
		InsertBiTree_Tri(T, 'E', &T0, 0);
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;

	printf("��19\n������ DeleteBiTree_Tri ����...\n");			//19.����DeleteBiTree_Tri����
	{
		printf("ɾ����� '1' ���Һ��ӽ���T = \n");
		DeleteBiTree_Tri(T, '1', 1);
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("��2\n������ ClearBiTree_Tri ����...\n");			//2.����ClearBiTree_Tri����
	{
		ClearBiTree_Tri(&T);
		if(BiTreeEmpty_Tri(T))
			printf(" T �ѱ����!\n");
		printf("\n");
	}
	PressEnter;
				
	return 0;
}

void PrintElem(TElemType_Tri e)
{
	printf("%c ",e);
}
