/*****************************************
 *						                 *
 * 文件夹: ▲06 树和二叉树\05 ParentTree *
 *						                 *
 * 文件名: ParentTree-main.c             *
 * 									     *
 * 内  容: 树的双亲表示法相关函数测试    *
 *                                       *
 *****************************************/

#include <stdio.h>
#include "ParentTree.c" 									//**▲06 树和二叉树**/

void PrintElem(TElemType_P e);

int main(int argc, char *argv[])
{
	PTree T, T0;

	printf("▼1\n▲函数 InitTree_P 测试...\n");				//1.函数InitTree_P测试
	{
		InitTree_P(&T); 
		printf("初始化空树 T ，根结点位置默认设为 0 ...\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 TreeEmpty_P 测试...\n");				//4.函数TreeEmpty_P测试
	{
		TreeEmpty_P(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter; 
	
	printf("▼5\n▲函数 CreateTree_P 测试...\n");				//5.函数CreateTree_P测试
	{
		FILE *fp;
		
		fp = fopen("TestData_T.txt", "r");
		CreateTree_P(fp, &T);
		fclose(fp);
		printf("\n");
	}
	PressEnter;	

	printf("▼19\n▲函数 LevelOrderTraverse_P 测试...\n");	//19.函数LevelOrderTraverse_P测试
	{
		printf("层序遍历树 T = ");
		LevelOrderTraverse_P(T, PrintElem); 
		printf("\n\n");
	}
	PressEnter;

	printf("▼20\n▲函数 Print_P 测试...\n");					//20.函数Print_P测试
	{
		printf("打印树 T = \n");
		Print_P(T); 
		printf("\n");
	}
	PressEnter;

	printf("▼6\n▲函数 TreeDegree_P 测试...\n");				//6.函数TreeDegree_P测试
	{
		printf(" T 的度为：%d\n", TreeDegree_P(T)); 
		printf("\n");
	}
	PressEnter;

	printf("▼7\n▲函数 TreeDepth_P 测试...\n");				//7.函数TreeDepth_P测试
	{
		printf(" T 共有 %d 层\n", TreeDepth_P(T)); 
		printf("\n");
	}
	PressEnter;

	printf("▼8\n▲函数 Root_P 测试...\n");					//8.函数Root_P测试
	{
		printf(" T 的根结点为：%c \n", Root_P(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("▼9\n▲函数 Value_P 测试...\n");					//9.函数Value_P测试
	{
		printf(" T 中第 %d 个结点值为：%c \n", 2, Value_P(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼10\n▲函数 Order_P 测试...\n");					//10.函数Order_P测试
	{
		printf(" T 中元素 %c 的位置为：%d\n", 'A', Order_P(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 Assign_P 测试...\n");				//11.函数Assign_P测试
	{
		printf("将结点 'B' 赋值为 'X' 后，T = \n");
		Assign_P(&T, 'B', 'X');
		Print_P(T);
		printf("\n");
	}
	PressEnter;

	printf("▼12\n▲函数 ChildValue_P 测试...\n");			//12.函数ChildValue_P测试
	{
		printf(" %c 的第 %d 个孩子为：%c \n", 'A', 2, ChildValue_P(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼13\n▲函数 Sibling_P 测试...\n");				//13.函数Sibling_P测试
	{
		printf(" %c 的左兄弟为：%c，%c 的右兄弟为：%c \n", 'E', Sibling_P(T, 'E', 0), 'D', Sibling_P(T, 'D', 1));
		printf("\n");
	}
	PressEnter;	
	
	printf("▼14、15、16、17\n▲函数 InsertTree_P 等测试...\n");		//14、15、16、17.函数ChildCount_P、ChildSeat_P、InsertChild_P、InsertTree_P测试
	{
		FILE *fp;
		
		printf("创建并打印树 T0 ...\n");
		InitTree_P(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateTree_P(fp, &T0);
		fclose(fp);	
		Print_P(T0);
		printf("将树 T0 插入为树 T 中结点 %c 的第 %d 棵子树后，T = \n", 'X', 1);
		InsertTree_P(&T, 'X', 1, T0);
		Print_P(T);
		printf("\n");
	}
	PressEnter;
	
	printf("▼18\n▲函数 DeleteTree_P 测试...\n");				//18.函数DeleteTree_P测试
	{
		printf("删除 T 中结点 %c 的第 %d 棵子树后，T = \n", '0', 3);
		DeleteTree_P(&T, '0', 3);
		Print_P(T);	
		printf("\n");
	}
	PressEnter;	

	printf("▼2\n▲函数 ClearTree_P 测试...\n");					//2.函数ClearTree_P测试
	{
		ClearTree_P(&T);
		TreeEmpty_P(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	} 
	PressEnter;
}

void PrintElem(TElemType_P e)
{
	printf("%c ",e);
}
