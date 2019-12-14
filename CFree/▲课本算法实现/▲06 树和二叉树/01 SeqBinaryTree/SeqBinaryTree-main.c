/********************************************
 *										    *
 * 文件夹: ▲06 树和二叉树\01 SeqBinaryTree *
 * 									        *
 * 文件名: SeqBinaryTree-main.c             *
 * 										    *
 * 内  容: 二叉树（顺序存储）相关函数测试   *
 *                                          *
 ********************************************/

#include <stdio.h> 
#include "SeqBinaryTree.c" 									//**▲06 树和二叉树**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	SqBiTree T;

	printf("▼1\n▲函数 InitBiTree_Sq 测试...\n");			//1.函数InitBiTree_Sq测试
	{
		printf("初始化空二叉树 T ...\n");
		InitBiTree_Sq(T);
		printf("\n");
	}
	PressEnter; 
	
	printf("▼4\n▲函数 BiTreeEmpty_Sq 测试...\n");			//4.函数BiTreeEmpty_Sq测试
	{
		BiTreeEmpty_Sq(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 CreateBiTree_Le_Sq 测试...\n");		//5.函数CreateBiTree_Le_Sq测试
	{
		FILE *fp;
		
		printf("按层序序列创建二叉树 T ...\n");
		fp = fopen("TestData_Le.txt", "r");	
		CreateBiTree_Le_Sq(fp, T);
		fclose(fp); 
		printf("\n");
	}
	PressEnter;
/*
	printf("▼6\n▲函数 CreateBiTree_Pre_Sq 测试...\n");	//6.函数CreateBiTree_Pre_Sq测试
	{
		FILE *fp;
		
		printf("按先序序列创建二叉树 T ...\n");
		fp = fopen("TestData_Pre.txt", "r");	
		CreateBiTree_Pre_Sq(fp, T, 0);						//i从0开始 
		fclose(fp); 
		printf("\n");
	}
	PressEnter;
*/
	printf("▼29\n▲函数 Print_Sq 测试...\n");				//29.函数Print_Sq测试
	{
		printf("按二叉树的结构打印树 T ...\n");
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;

	printf("▼7、8\n▲函数 BiTreeLength_Sq、BiTreeDepth_Sq 测试...\n");	//7、8.函数BiTreeLength_Sq、BiTreeDepth_Sq测试
	{
		printf(" T 的长度为：%d，深度为：%d。\n", BiTreeLength_Sq(T), BiTreeDepth_Sq(T));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼17\n▲函数 LevelOrderTraverse_Sq 测试...\n");		//17.函数LevelOrderTraverse_Sq测试
	{
		printf("层序遍历二叉树 T = ");
		LevelOrderTraverse_Sq(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼18\n▲函数 PreOrderTraverse_Sq 等测试...\n");		//18.函数PreOrderTraverse_Sq测试
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;

	printf("▼19\n▲函数 InOrderTraverse_Sq 等测试...\n");		//19函数InOrderTraverse_Sq测试
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;

	printf("▼20\n▲函数 PostOrderTraverse_Sq 等测试...\n");	//20.函数PostOrderTraverse_Sq测试
	{
		printf("后序遍历二叉树 T = ");
		PostOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 Root_Sq 测试...\n");					//9.函数Root_Sq测试
	{
		TElemType_Sq r;
		
		printf(" T 的根结点为 %c\n", r);
		Root_Sq(T, &r);
		printf("\n");
	}
	PressEnter;	

	printf("▼10\n▲函数 Value_Sq 测试...\n");					//10.函数Value_Sq测试
	{
		Position p = {4, 3};
		
		printf(" T 中第 %d 行第 %d 列的值为 %c\n", p.level, p.order, Value_Sq(T, p));
		printf("\n");
	}
	PressEnter;

	printf("▼11\n▲函数 Assign_Sq 测试...\n");					//11.函数Assign_Sq测试
	{
		Position p = {4, 3};									//4行3列

		printf("将第 %d 层第 %d 列的结点赋值为 'X' 后，T = \n", p.level, p.order);
		Assign_Sq(T, p, 'X');
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;

	printf("▼12\n▲函数 Parent_Sq 测试...\n");					//12.函数Parent_Sq测试
	{
		printf(" 'X' 结点的双亲为： %c \n", Parent_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼13、14\n▲函数 LeftChild_Sq、RightChild_Sq 测试...\n");	//13、14.函数LeftChild_Sq、RightChild_Sq测试
	{
		printf(" 'E' 的左孩子结点值为：%c ，右孩子结点值为：%c\n", LeftChild_Sq(T, 'E'), RightChild_Sq(T, 'E'));
		printf("\n");
	}
	PressEnter;

	printf("▼15\n▲函数 LeftSibling_Sq 测试...\n");			//15.函数LeftSibling_Sq测试
	{
		printf(" 'I' 的左兄弟为：%c\n", LeftSibling_Sq(T, 'I'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼16\n▲函数 RightSibling_Sq 测试...\n");			//16.函数RightSibling_Sq测试
	{
		printf(" 'X' 的右兄弟为：%c\n", RightSibling_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;

	
	printf("▼2\n▲函数 ClearBiTree_Sq 测试...\n");				//2.函数ClearBiTree_Sq测试
	{
		ClearBiTree_Sq(T);
		if(BiTreeEmpty_Sq(T))
			printf(" T 已被清空!\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
