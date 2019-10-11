/**********************************************
 *										      *
 * 文件夹: ▲06 树和二叉树\03 Tri_BinaryTree  *
 * 									          *
 * 文件名: Tri_BinaryTree-main.c              *
 * 										      *
 * 内  容: 二叉树（三叉链表存储）相关函数测试 *
 *                                            *
 *********************************************/

#include <stdio.h>
#include "Tri_BinaryTree.c" 						//**▲06 树和二叉树**//

void PrintElem(TElemType_Tri e);

int main(int argc, char *argv[])
{
	TBiTree T;
	
	printf("▼1\n▲函数 InitBiTree_Tri 测试...\n");				//1.函数InitBiTree_Tri测试
	{
		printf("初始化一个空二叉树 T ...\n");
		InitBiTree_Tri(&T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 BiTreeEmpty_Tri 测试...\n");			//4.函数BiTreeEmpty_Tri测试
	{
		BiTreeEmpty_Tri(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼5、6\n▲函数 CreateBiTree_Tri等 测试...\n");		//5、6.函数Create_Tri、CreateBiTree_Tri测试
	{
		FILE *fp;
		
		printf("按先序序列创建二叉树 T ...\n");
		printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree_Tri(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("▼24\n▲函数 Print_Tri 测试...\n");					//24.函数Print_Tri测试
	{
		printf("按二叉树的结构打印树：T = \n");
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼7、8\n▲函数 BiTreeLength_Tri、BiTreeDepth_Tri 测试...\n");//7、8.函数BiTreeLength_Tri、BiTreeDepth_Tri测试	
	{
		printf(" T 的长度为：%d，深度为 %d \n", BiTreeLength_Tri(T), BiTreeDepth_Tri(T));
		printf("\n");
	}
	PressEnter;
	
	printf("▼20\n▲函数 LevelOrderTraverse_Tri 测试...\n");	//20.函数LevelOrderTraverse_Tri测试
	{
		printf("层序遍历二叉树 T = ");
		LevelOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼21\n▲函数 PreOrderTraverse_Tri 测试...\n");		//21.函数PreOrderTraverse_Tri测试
	{
		printf("前序遍历二叉树 T = ");
		PreOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼22\n▲函数 InOrderTraverse_Tri 测试...\n");		//22.函数InOrderTraverse_Tri测试
	{
		printf("中序遍历二叉树 T = ");
		InOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("▼23\n▲函数 PostOrderTraverse_Tri 测试...\n");		//23.函数PostOrderTraverse_Tri测试
	{
		printf("后序遍历二叉树 T = ");
		PostOrderTraverse_Tri(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;	
	
	printf("▼9\n▲函数 Root_Tri 测试...\n");					//9.函数Root_Tri测试
	{
		TElemType_Tri e;
		
		Root_Tri(T, &e);
		printf(" T 的根结点为 %c \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("▼10\n▲函数 Value_Tri 测试...\n");					//10.函数Value_Tri测试
	{
		TBiTree p;
		
		p = T->lchild->rchild->lchild;
		printf("指针 p 指向的结点值为 %c \n", Value_Tri(p));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼11\n▲函数 Assign_Tri 测试...\n");				//11.函数Assign_Tri测试
	{
		TBiTree p;
		
		p = T->lchild->rchild->lchild;
		Assign_Tri(p, 'X');
		printf("将 'X' 赋给 p 指向的结点后，T = \n");
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("▼12、13\n▲函数 Point、Parent 测试...\n");			//12、13.函数Point、Parent_Tri测试
	{
		printf(" 'X' 的双亲为：%c \n", Parent_Tri(T, 'X'));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼14、15\n▲函数 LeftChild_Tri、RightChild_Tri 测试...\n");	//14、15.函数LeftChild_Tri、RightChild_Tri测试
	{
		printf(" 'E' 的左孩子结点值为：%c ，右孩子结点值为：%c \n", LeftChild_Tri(T, 'E'), RightChild_Tri(T, 'E'));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼16\n▲函数 LeftSibling_Tri 测试...\n");			//16.函数LeftSibling_Tri测试
	{
		printf(" 'I' 的左兄弟为：%c \n", LeftSibling_Tri(T, 'I'));
		printf("\n");
	}
	PressEnter;	

	printf("▼17\n▲函数 RightSibling_Tri 测试...\n");			//17.函数RightSibling_Tri测试
	{
		printf(" 'X' 的右兄弟为：%c \n", RightSibling_Tri(T, 'X'));
		printf("\n");
	}
	PressEnter;	
		
	printf("▼18\n▲函数 InsertBiTree_Tri 测试...\n");			//18.函数InsertBiTree_Tri测试 
	{
		FILE *fp;
		TBiTree T0;
		
		printf("创建并打印二叉树 T0 = \n");
		InitBiTree_Tri(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateBiTree_Tri(fp, &T0); 
		fclose(fp);
		Print_Tri(T0);
		printf("将 T0 插入到 T 中成为结点‘E’的左子树后，T = \n");
		InsertBiTree_Tri(T, 'E', &T0, 0);
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;

	printf("▼19\n▲函数 DeleteBiTree_Tri 测试...\n");			//19.函数DeleteBiTree_Tri测试
	{
		printf("删除结点 '1' 的右孩子结点后，T = \n");
		DeleteBiTree_Tri(T, '1', 1);
		Print_Tri(T);
		printf("\n");
	}
	PressEnter;	
	
	printf("▼2\n▲函数 ClearBiTree_Tri 测试...\n");			//2.函数ClearBiTree_Tri测试
	{
		ClearBiTree_Tri(&T);
		if(BiTreeEmpty_Tri(T))
			printf(" T 已被清空!\n");
		printf("\n");
	}
	PressEnter;
				
	return 0;
}

void PrintElem(TElemType_Tri e)
{
	printf("%c ",e);
}
