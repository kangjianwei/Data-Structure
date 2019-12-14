/*********************************************************
 *										                 *
 * 文件夹: ▲06 树和二叉树\07 ChildSiblingTree           *
 * 									                     *
 * 文件名: ChildSiblingTree-main.c                       *
 * 										                 *
 * 内  容: 树的二叉链表（孩子-兄弟）存储表示相关函数测试 *
 *                                                       *
 *********************************************************/

#include <stdio.h> 
#include "ChildSiblingTree.c" 											//**▲06 树和二叉树**//

void PrintElem(TElemType_CS e);

int main(int argc, char *argv[])
{
	CSTree T;															//作为输入源
	
	printf("▼1\n▲函数 InitTree_CS 测试...\n");						//1.函数InitTree_CS测试
	{
		printf("初始化一棵空树 T \n");
		InitTree_CS(&T);
		printf("\n");
	}
	PressEnter;

	printf("▼4\n▲函数 TreeEmpty_CS 测试...\n");						//4.函数TreeEmpty_CS测试
	{
		TreeEmpty_CS(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;
		
	printf("▼5\n▲函数 CreateTree_CS 测试...\n");						//5.函数CreateTree_CS测试
	{
		FILE *fp;
		
		printf("按先序序列创建二叉树 T ...\n");
		printf("作为示例，录入先序序列：RAD^E^^B^CFG^H^K^^^^^...\n");
		fp = fopen("TestData_T.txt", "r");								//清除缓存 
		CreateTree_CS(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("▼21\n▲函数 Print_CS 测试...\n");							//21.函数Print_CS测试
	{
		printf("按树的结构打印树 T = \n");
		Print_CS(T);
		printf("\n");
	} 
	PressEnter;
		
	printf("▼18\n▲函数 LevelOrderTraverse_CS 测试...\n");				//18.函数LevelOrderTraverse_CS测试
	{
		printf("层序遍历树 T = ");
		LevelOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼19\n▲函数 PreOrderTraverse_CS 测试...\n");				//19.函数PreOrderTraverse_CS测试
	{
		printf("前序遍历树 T = ");
		PreOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	} 
	PressEnter;

	printf("▼20\n▲函数 InOrderTraverse_CS 测试...\n");				//20.函数InOrderTraverse_CS测试
	{
		printf("中序遍历树 T = ");
		InOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("▼6\n▲函数 TreeDegree_CS 测试...\n");						//6.函数TreeDegree_CS测试
	{
		printf(" T 的度为：%d \n", TreeDegree_CS(T)); 
		printf("\n");
	}
	PressEnter;

	printf("▼7\n▲函数 TreeDepth_CS 测试...\n");						//7.函数TreeDepth_CS测试
	{
		printf(" T 共有 %d 层\n", TreeDepth_CS(T)); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 Root_CS 测试...\n");							//8.函数Root_CS测试
	{
		printf(" T 的根结点为：%c\n", Root_CS(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("▼9\n▲函数 Value_CS 测试...\n");							//9.函数Value_CS测试
	{
		printf(" T 中第 %d 个结点的值为：%c\n", 2, Value_CS(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼10\n▲函数 Order_CS 测试...\n");							//10.函数Order_CS测试
	{
		printf(" T 中元素 %c 的地址为：0x%X \n", 'A', Order_CS(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 Assign_CS 测试...\n");							//11.函数Assign_CS测试
	{
		printf("将结点 'B' 赋值为 'X' 后，T = \n");
		Assign_CS(T, 'B', 'X');
		Print_CS(T);
		printf("\n");
	}
	PressEnter;

	printf("▼12\n▲函数 ChildValue_CS 测试...\n");						//12.函数ChildValue_CS测试
	{
		printf("结点 %c 的第 %d 个孩子为：%c \n", 'A', 2, ChildValue_CS(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("▼13\n▲函数 Sibling_CS 测试...\n");						//13.函数Sibling_CS测试
	{
		printf(" %c 的左兄弟为：%c，", 'E', Sibling_CS(T, 'E', 0));
		printf(" %c 的右兄弟为：%c\n", 'D', Sibling_CS(T, 'D', 1));
		printf("\n");
	}
	PressEnter;
	
	printf("▼14、15、16\n▲函数 InsertTree_CS等 测试...\n");		//14、15、16函数ChildCount_CS、ChildSeat_CS、InsertTree_CS测试
	{
		FILE *fp;
		CSTree T0;
		
		printf("创建并打印树 T0 ...\n");
		InitTree_CS(&T0);
		printf("作为示例，录入先序序列：01^2^34^5^^^^...\n");
		fp = fopen("TestData_T0.txt", "r");
		CreateTree_CS(fp, &T0);
		fclose(fp);
		Print_CS(T0); 
		printf("将 T0嫁接为 %c 的第 %d 棵子树后，T = \n", 'X', 1);
		InsertTree_CS(T, 'X', 1, T0);
		Print_CS(T); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼17\n▲函数 DeleteTree_CS 测试...\n");						//17.函数DeleteTree_CS测试
	{
		printf("删除 T 中结点 %c 的第 %d 棵子树后，T = \n", '0', 3);
		DeleteTree_CS(T, '0', 3); 
		Print_CS(T);	
		printf("\n");
	}
	PressEnter;

	printf("▼2\n▲函数 ClearTree_CS等 测试...\n");						//2.函数ClearTree_CS测试
	{
		ClearTree_CS(&T);
		TreeEmpty_CS(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
	PressEnter;	
}

void PrintElem(TElemType_CS e)
{
	printf("%c ",e);
}
