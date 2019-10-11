/****************************************************
 *										            *
 * 文件夹: ▲06 树和二叉树\06 ChildTree             *
 * 									                *
 * 文件名: ChildTree-main.c                         *
 * 										            *
 * 内  容: 树的孩子链表(带双亲)存储表示相关函数测试 *
 *                                                  *
 ****************************************************/

#include <stdio.h>
#include "ChildTree.c" 													//**▲06 树和二叉树**//															

void PrintElem(TElemType_C e);

int main(int argc, char *argv[])
{
	CTree T, T0;
	FILE *fp;															//作为输入源

	printf("▼1\n▲函数 InitTree_C 测试...\n");							//1.函数InitTree_C测试
	{
		printf("初始化一棵空树 T ...\n");
		fp = fopen("TestData_T.txt", "r");
		InitTree_C(fp, &T);
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 TreeEmpty_C 测试...\n");						//5.函数TreeEmpty_C测试
	{
		TreeEmpty_C(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;
		
	printf("▼6\n▲函数 CreateTree_C 测试...\n");						//6.函数CreateTree_C测试
	{
		CreateTree_C(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("▼22\n▲函数 LevelOrderTraverse_C 测试...\n");				//22.函数LevelOrderTraverse_C测试
	{
		printf("层序遍历树 T = ");
		LevelOrderTraverse_C(T, PrintElem); 
		printf("\n\n");
	}
	PressEnter;

	printf("▼8-2、9、23-1\n▲函数 Print_C等 测试...\n");				//8-2、9、23-1.函数Print_C_1、TreeDepth_C_2、Depth_C测试
	{
		printf("打印树 T = \n");
		Print_C_1(T); 
		printf("\n");
	}
	PressEnter;

	printf("▼24\n▲函数 ShowTree_T 测试...\n");						//24.函数ShowTree_T测试
	{
		printf("展示树结构 T = \n");
		ShowTree_C(T); 
		printf("\n");
	}
	PressEnter;

	printf("▼7\n▲函数 TreeDegree_C 测试...\n");						//7.函数TreeDegree_P测试
	{
		printf(" T 的度为：%d \n", TreeDegree_C(T)); 
		printf("\n");
	}
	PressEnter;

	printf("▼8-1\n▲函数 TreeDepth_C_1 测试...\n");					//8-1.函数TreeDepth_C_1测试
	{
		printf(" T 共有 %d 层 \n", TreeDepth_C_1(T)); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼10\n▲函数 Root_C 测试...\n");							//10.函数Root_C测试
	{
		printf(" T 的根结点为：%c\n", Root_C(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("▼11\n▲函数 Value_C 测试...\n");							//11.函数Value_C测试
	{
		printf(" T 中第 %d 个结点的值为：%c \n", 2, Value_C(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼12\n▲函数 Order_C 测试...\n");							//12.函数Order_C测试
	{
		printf(" T 中元素 %c 的位置为：%d \n", 'A', Order_C(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼13、23-2\n▲函数 Assign_C等 测试...\n");					//13、23-2.函数Assign_C、Print_C_2测试
	{
		printf("将结点 'B' 赋值为 'X' 后，T = \n");
		Assign_C(&T, 'B', 'X'); 
		Print_C_2(T, T.r, 0);
		printf("\n");
	}
	PressEnter;

	printf("▼14\n▲函数 ChildValue_C 测试...\n");						//14.函数ChildValue_C测试
	{
		printf("结点 %c 第 %d 个孩子为：%c \n", 'A', 2, ChildValue_C(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼15-1、15-2\n▲函数 Sibling_C_1、Sibling_C_2 测试...\n");	//15-1、15-2.函数Sibling_C_1、Sibling_C_2测试
	{
		printf(" %c 的左兄弟为：%c，%c 的右兄弟为：%c \n", 'E', Sibling_C_1(T, 'E', 0), 'D', T.nodes[Sibling_C_2(T, 3, 1)].data);
		printf("\n");
	}
	PressEnter;

	printf("▼16、17、18、19、20\n▲函数 InsertTree_C等 测试...\n");	//16、17、18、19、20.函数ChildCount_C、ChildSeat_C、SiblingSeat_C、InsertChild_C、InsertTree_C测试
	{
		printf("创建并打印 T0 ...\n");
		fp = fopen("TestData_T0.txt", "r");
		InitTree_C(fp, &T0);
		CreateTree_C(fp, &T0);
		fclose(fp);
		Print_C_1(T0);
		printf("\n"); 
		printf("将树 T0 嫁接为 %c 的第 %d 棵子树后，T = ...\n", 'X', 1);
		InsertTree_C(&T, 'X', 1, T0);
		Print_C_1(T); 
		printf("\n");
		ShowTree_C(T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼21\n▲函数 DeleteTree_C 测试...\n");						//21.函数DeleteTree_C测试
	{
		printf("删除 T 中结点 %c 的第 %d 棵子树后，T = \n", '0', 3);
		DeleteTree_C(&T, '0', 3); 
		Print_C_1(T);
		printf("\n");
		ShowTree_C(T);
		printf("\n");
	}
	PressEnter;

	printf("▼2、3\n▲函数 ClearTree_C等 测试...\n");					//2、3.函数ClearTree_C测试
	{
		ClearTree_C(&T);
		TreeEmpty_C(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;	
}

void PrintElem(TElemType_C e)
{
	printf("%c ",e);
}
