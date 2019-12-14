/**********************************************
 *							                  *
 * �ļ���: ��06 ���Ͷ�����\02 BinaryTree      *
 * 							                  *
 * �ļ���: BinaryTree-main.c                  *
 * 										      *
 * ��  ��: ����������������洢����غ������� *
 *                                            *
 **********************************************/

#include <stdio.h>
#include "BinaryTree.c" 										//**��06 ���Ͷ�����**//

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc, char *argv[])
{
	BiTree T;
		
	printf("��1\n������ InitBiTree ����...\n");					//1.����InitBiTree����
	{
		printf("��ʼ��һ���ն����� T ...\n");
		InitBiTree(&T);
		printf("\n");
	} 
	PressEnter;
	
	printf("��4\n������ BiTreeEmpty ����...\n");				//4.����BiTreeEmpty����
	{
		BiTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��5\n������ CreateBiTree_Sq ����...\n");			//5.����CreateBiTree_Sq����
	{
		FILE *fp;
		
		printf("���������д���������...\n");
		printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");		
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("��23\n������ PrintTree ����...\n");					//23.����PrintTree����
	{
		printf("���������Ľṹ��ӡ����T = \n");
		PrintTree(T);
		printf("\n");
	}
	PressEnter;
	
	printf("��6��7\n������ BiTreeLength��BiTreeDepth ����...\n");//6��7.����BiTreeLength��BiTreeDepth����	
	{
		printf(" T �ĳ���Ϊ��%d�����Ϊ %d \n", BiTreeLength(T), BiTreeDepth(T));
		printf("\n");
	}
	PressEnter;
	
	printf("��19\n������ LevelOrderTraverse ����...\n");		//19.����LevelOrderTraverse����
	{
		printf("������������� T = ");
		LevelOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��20-1\n������ PreOrderTraverse_1 ����...\n");		//20-1.����PreOrderTraverse_1����
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��20-2\n������ PreOrderTraverse_2 ����...\n");		//20-2.����PreOrderTraverse_2����
	{
		printf("ǰ����������� T = ");
		PreOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��21-1\n������ InOrderTraverse_1 ����...\n");		//21-1.����InOrderTraverse_1����
	{
		printf("������������� T = ");
		InOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��21-2\n������ InOrderTraverse_2 ����...\n");		//21-2.����InOrderTraverse_2����
	{
		printf("������������� T = ");
		InOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("��21-3\n������ InOrderTraverse_3 ����...\n");		//21-3.����InOrderTraverse_3����
	{
		printf("������������� T = ");
		InOrderTraverse_3(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("��22\n������ PostOrderTraverse ����...\n");			//22.����PostOrderTraverse����
	{
		printf("������������� T = ");
		PostOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;	
	
	printf("��8\n������ Root ����...\n");						//8.����Root����
	{
		TElemType e;
		
		Root(T, &e);
		printf(" T �ĸ����Ϊ��%c \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ Value ����...\n");						//9.����Value����
	{
		BiTree p = T->lchild->rchild->lchild;
		
		printf("ָ�� p ָ��Ľ��ֵΪ %c \n", Value(p));
		printf("\n");
	}
	PressEnter;	
	
	printf("��10\n������ Assign ����...\n");					//10.����Assign����
	{
		BiTree p = T->lchild->rchild->lchild;
		
		Assign(p, 'X');
		printf("�� 'X' ���� p ָ��Ľ���T = \n");
		PrintTree(T);
		printf("\n");
	}
	PressEnter;
	
	printf("��11\n������ Parent ����...\n");					//11.����Parent����
	{
		printf(" 'X' ����˫��Ϊ��%c\n", Parent(T, 'X'));
		printf("\n");
	} 
	PressEnter;	
	
	printf("��12��13\n������ LeftChild��RightChild ����...\n");	//12��13.����LeftChild��RightChild����
	{
		printf(" 'E' �����ӽ��ֵΪ��%c ���Һ��ӽ��ֵΪ��%c\n", LeftChild(T, 'E'), RightChild(T, 'E'));
		printf("\n");
	} 
	PressEnter;	
	
	printf("��14\n������ LeftSibling ����...\n");				//14.����LeftSibling����
	{
		printf(" 'I' �����ֵ�Ϊ��%c \n", LeftSibling(T, 'I'));
		printf("\n");
	} 
	PressEnter;	

	printf("��15\n������ RightSibling ����...\n");				//15.����RightSibling����
	{
		printf(" 'X' �����ֵ�Ϊ��%c\n", RightSibling(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("��16-1��17\n������ InsertBiTree�� ����...\n");		//16-1��17.����LocationBiTree_1��InsertBiTree���� 
	{
		FILE *fp;
		BiTree T0;
		
		printf("��������ӡ������ T0 = \n");
		InitBiTree(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateBiTree(fp, &T0); 
		fclose(fp);
		PrintTree(T0);
		printf("�� T0 ���뵽 T �г�Ϊ��㡮E������������T = \n");
		InsertBiTree(T, 'E', T0, 0);
		PrintTree(T);
		printf("\n");
	}
	PressEnter;

	printf("��16-2��18\n������ DeleteBiTree�� ����...\n");		//18.����LocationBiTree_2������DeleteBiTree����
	{
		printf("ɾ����� '1' ���Һ��ӽ���T = \n");
		DeleteBiTree(T, '1', 1);
		PrintTree(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("��2\n������ ClearBiTree ����...\n");				//2.����ClearBiTree����
	{
		ClearBiTree(&T);
		if(BiTreeEmpty(T))
			printf(" T �ѱ����!\n");
		printf("\n");
	}
	PressEnter;
			
	return 0;
}

void PrintElem(TElemType e)
{
	printf("%c ",e);
}

Status PrintElement(TElemType e) 
{
	printf("%c ",e);
	return OK;
}
