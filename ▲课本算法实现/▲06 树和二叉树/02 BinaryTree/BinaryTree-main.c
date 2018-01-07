/**********************************************
 *							                  *
 * 文件夹: ▲06 树和二叉树\02 BinaryTree      *
 * 							                  *
 * 文件名: BinaryTree-main.c                  *
 * 										      *
 * 内  容: 二叉树（二叉链表存储）相关函数测试 *
 *                                            *
 **********************************************/

#include <stdio.h>
#include "BinaryTree.c" 										//**▲06 树和二叉树**//

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc, char *argv[])
{
	BiTree T;
		
	printf("▼1\n▲函数 InitBiTree 测试...\n");					//1.函数InitBiTree测试
	{
		printf("初始化一个空二叉树 T ...\n");
		InitBiTree(&T);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼4\n▲函数 BiTreeEmpty 测试...\n");				//4.函数BiTreeEmpty测试
	{
		BiTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 CreateBiTree_Sq 测试...\n");			//5.函数CreateBiTree_Sq测试
	{
		FILE *fp;
		
		printf("按先序序列创建二叉树...\n");
		printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");		
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("▼23\n▲函数 PrintTree 测试...\n");					//23.函数PrintTree测试
	{
		printf("按二叉树的结构打印树：T = \n");
		PrintTree(T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼6、7\n▲函数 BiTreeLength、BiTreeDepth 测试...\n");//6、7.函数BiTreeLength、BiTreeDepth测试	
	{
		printf(" T 的长度为：%d，深度为 %d \n", BiTreeLength(T), BiTreeDepth(T));
		printf("\n");
	}
	PressEnter;
	
	printf("▼19\n▲函数 LevelOrderTraverse 测试...\n");		//19.函数LevelOrderTraverse测试
	{
		printf("层序遍历二叉树 T = ");
		LevelOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼20-1\n▲函数 PreOrderTraverse_1 测试...\n");		//20-1.函数PreOrderTraverse_1测试
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("▼20-2\n▲函数 PreOrderTraverse_2 测试...\n");		//20-2.函数PreOrderTraverse_2测试
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼21-1\n▲函数 InOrderTraverse_1 测试...\n");		//21-1.函数InOrderTraverse_1测试
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_1(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("▼21-2\n▲函数 InOrderTraverse_2 测试...\n");		//21-2.函数InOrderTraverse_2测试
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_2(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("▼21-3\n▲函数 InOrderTraverse_3 测试...\n");		//21-3.函数InOrderTraverse_3测试
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_3(T, PrintElement);
		printf("\n\n");
	}
	PressEnter;

	printf("▼22\n▲函数 PostOrderTraverse 测试...\n");			//22.函数PostOrderTraverse测试
	{
		printf("后序遍历二叉树 T = ");
		PostOrderTraverse(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;	
	
	printf("▼8\n▲函数 Root 测试...\n");						//8.函数Root测试
	{
		TElemType e;
		
		Root(T, &e);
		printf(" T 的根结点为：%c \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 Value 测试...\n");						//9.函数Value测试
	{
		BiTree p = T->lchild->rchild->lchild;
		
		printf("指针 p 指向的结点值为 %c \n", Value(p));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼10\n▲函数 Assign 测试...\n");					//10.函数Assign测试
	{
		BiTree p = T->lchild->rchild->lchild;
		
		Assign(p, 'X');
		printf("将 'X' 赋给 p 指向的结点后，T = \n");
		PrintTree(T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 Parent 测试...\n");					//11.函数Parent测试
	{
		printf(" 'X' 结点的双亲为：%c\n", Parent(T, 'X'));
		printf("\n");
	} 
	PressEnter;	
	
	printf("▼12、13\n▲函数 LeftChild、RightChild 测试...\n");	//12、13.函数LeftChild、RightChild测试
	{
		printf(" 'E' 的左孩子结点值为：%c ，右孩子结点值为：%c\n", LeftChild(T, 'E'), RightChild(T, 'E'));
		printf("\n");
	} 
	PressEnter;	
	
	printf("▼14\n▲函数 LeftSibling 测试...\n");				//14.函数LeftSibling测试
	{
		printf(" 'I' 的左兄弟为：%c \n", LeftSibling(T, 'I'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼15\n▲函数 RightSibling 测试...\n");				//15.函数RightSibling测试
	{
		printf(" 'X' 的右兄弟为：%c\n", RightSibling(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼16-1、17\n▲函数 InsertBiTree等 测试...\n");		//16-1、17.函数LocationBiTree_1、InsertBiTree测试 
	{
		FILE *fp;
		BiTree T0;
		
		printf("创建并打印二叉树 T0 = \n");
		InitBiTree(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateBiTree(fp, &T0); 
		fclose(fp);
		PrintTree(T0);
		printf("将 T0 插入到 T 中成为结点‘E’的左子树后，T = \n");
		InsertBiTree(T, 'E', T0, 0);
		PrintTree(T);
		printf("\n");
	}
	PressEnter;

	printf("▼16-2、18\n▲函数 DeleteBiTree等 测试...\n");		//18.函数LocationBiTree_2、函数DeleteBiTree测试
	{
		printf("删除结点 '1' 的右孩子结点后，T = \n");
		DeleteBiTree(T, '1', 1);
		PrintTree(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("▼2\n▲函数 ClearBiTree 测试...\n");				//2.函数ClearBiTree测试
	{
		ClearBiTree(&T);
		if(BiTreeEmpty(T))
			printf(" T 已被清空!\n");
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
