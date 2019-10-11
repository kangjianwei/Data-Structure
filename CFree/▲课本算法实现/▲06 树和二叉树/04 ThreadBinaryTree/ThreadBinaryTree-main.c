/***********************************************
 *							                   *
 * 文件夹: ▲06 树和二叉树\04 ThreadBinaryTree *
 *							                   *
 * 文件名: ThreadBinaryTree-main.c             *
 * 								               *
 * 内  容: 线索二叉树相关操作列表              *
 *                                             *
 ***********************************************/

#include <stdio.h>
#include "ThreadBinaryTree.c" 									//**▲06 树和二叉树**//

void PrintElem(TElemType_Thr e);

int main(int argc, char *argv[])
{
	ThrBiTree Thrt1, Thrt2, Thrt3;
	ThrBiTree T1, T2, T3; 
	int mark;
			
	printf("▼1\n▲函数 CreateBiTree_Thr 测试...\n");				//1.函数CreateBiTree_Thr测试
	{
		FILE *fp;
		
		printf("按先序序列创建二叉树...\n");
		printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree_Thr(fp, &T1);
		fseek(fp, 0, SEEK_SET);										//退回到文档开头 
		CreateBiTree_Thr(fp, &T2);
		fseek(fp, 0, SEEK_SET);										//退回到文档开头 
		CreateBiTree_Thr(fp, &T3);
		fclose(fp);
		printf("\n");
	} 
	PressEnter; 
	
	printf("★\n★测试先序后继线索二叉树...\n★\n");
	{
		printf("▼5、6\n▲函数 PreTheading_Thr、PreOrderThreading_Thr 测试...\n");//5、6.函数PreTheading_Thr、PreOrderThreading_Thr测试
		printf("将 T1 先序后继线索化为 Thrt1 ...\n");
		PreOrderThreading_Thr(&Thrt1, T1);
		printf("\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 PreOrderTraverse_Thr 测试...\n");		//4.函数PreOrderTraverse_Thr测试
	{
		printf("先序遍历 Thrt1 = ");
		PreOrderTraverse_Thr(Thrt1, PrintElem);
		printf("\n\n");
	}
	PressEnter;		
	
	printf("★\n★测试中序全线索二叉树...\n★\n");
	printf("▼2、3\n▲函数 InTheading_Thr、InOrderThreading_Thr 测试...\n");	//2、3.函数InTheading_Thr、InOrderThreading_Thr测试
	{
		printf("将 T2 中序全线索化为 Thrt2 ...\n");
		InOrderThreading_Thr(&Thrt2, T2);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 InOrderTraverse_Thr 测试...\n");		//4.函数InOrderTraverse_Thr测试
	{
		printf("中序遍历 Thrt2 = ");
		InOrderTraverse_Thr(Thrt2, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("★\n★测试后序后继线索二叉树...\n★\n");
	printf("▼11\n▲函数 ParentPtr_Thr等 测试...\n");								//11.函数ParentPtr_Thr测试
	{
		printf("为各结点寻找双亲结点...\n");
		ParentPtr_Thr(T3);
		printf("\n");
	}
	PressEnter;
				
	printf("▼8、9\n▲函数 PosTheading_Thr、PosOrderThreading_Thr 测试...\n");	//8、9.函数PosTheading_Thr、PosOrderThreading_Thr测试
	{
		printf("将 T3 后序后继线索化为 Thrt3 ...\n");
		PosOrderThreading_Thr(&Thrt3, T3);
		printf("\n");
	}
	PressEnter;

	printf("▼10、12\n▲函数 PosOrderTraverse_Thr等 测试...\n");					//10、12.函数PosOrderTraverse_Thr、Pos_NextPtr_Thr测试
	{
		printf("后序遍历 Thrt3 = ");
		PosOrderTraverse_Thr(Thrt3, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(TElemType_Thr e)
{
	printf("%c ",e);
}
