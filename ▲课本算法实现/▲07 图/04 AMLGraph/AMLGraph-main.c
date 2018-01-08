/********************************************
 *						                    *
 * 文件夹: ▲07 图\04 AMLGraph              *
 * 						                    *
 * 文件名: AMLGraph-main.c                  *
 * 							                *
 * 内  容: 无向图（邻接多重表）相关函数测试 *
 *                                          *
 ********************************************/

#include <stdio.h> 
#include "AMLGraph.c" 							//**▲07 图**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	AMLGraph G;
	
	printf("▼1\n▲函数 CreateDG_AML等 测试...\n");			//1.函数CreateDG_AML等测试
	{
		FILE *fp;
		
		printf("初始化无向图...\n");
		fp = fopen("TestData_UDG_AML.txt", "r");			//文档中弧的录入为逆序 
		CreateUDG_AML(fp, &G); 
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼15\n▲函数 OutputAMLGraph 测试...\n");		//15.函数OutputAMLGraph测试
	{
		printf("输出无向图的邻接多重表 G = \n");		
		OutputAMLGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("▼3\n▲函数 LocateVex_AML 测试...\n");			//3.函数LocateVex_AML测试
	{
		printf("顶点 '%c' 的位置为 %d \n", 'C', LocateVex_AML(G, 'C'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼4\n▲函数 GetVex_AML 测试...\n");				//4.函数GetVex_AML测试
	{
		printf("第 %d 个顶点的值为 '%c' \n", 3, GetVex_AML(G, 3));
		printf("\n");
	} 
	PressEnter;	

	printf("▼6\n▲函数 FirstAdjVex_AML 测试...\n");		//6.函数FirstAdjVex_AML测试
	{
		printf(" '%c' 的第一个邻接顶点的序号为 %d \n", 'D', FirstAdjVex_AML(G, 'D'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼7\n▲函数 NextAdjVex_AML 测试...\n");			//7.函数NextAdjVex_AML测试
	{
		printf(" '%c' 相对于 '%c' 的下一个邻接顶点序号为 %d \n", 'D', 'A', NextAdjVex_AML(G, 'D', 'A'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼5\n▲函数 PutVex_AML 测试...\n");				//5.函数PutVex_AML测试
	{
		printf("对顶点 '%c' 赋值 '%c'后，G = \n", 'A', 'X');
		PutVex_AML(&G, 'A', 'X');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 InsertVex_AML 测试...\n");			//8.函数InsertVex_AML测试
	{
		printf("插入顶点 '%c' 后，G = \n", 'H');
		InsertVex_AML(&G, 'H');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;	

	printf("▼10\n▲函数 InsertArc_AML 测试...\n");			//10.函数InsertArc_AML测试
	{
		printf("顺次插入弧 <%c, %c>、", 'H', 'X');
		printf("<%c, %c>、", 'H', 'C');
		printf("<%c, %c> 后，G = \n", 'D', 'H');
		InsertArc_AML(&G, 'H', 'X');
		InsertArc_AML(&G, 'H', 'C');
		InsertArc_AML(&G, 'D', 'H');
		OutputAMLGraph(G);
		printf("\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 DeleteArc_AML 测试...\n");			//11.函数DeleteArc_AML测试
	{
		printf("删除弧 <%c, %c> 后，G = \n", 'H', 'X');
		DeleteArc_AML(&G, 'H', 'X');
		OutputAMLGraph(G);	
		printf("\n");
	} 
	PressEnter;
	
	printf("▼09\n▲函数 DeleteVex_AML 测试...\n");			//09.函数DeleteVex_AML测试
	{
		printf("删除顶点 '%c' 后，G = \n", 'H');
		DeleteVex_AML(&G, 'H');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("▼12、13\n▲函数 DFSTraverse_AML等 测试...\n");	//12、13.函数DFSTraverse_AML等测试
	{
		printf("深度优先遍历无向图 G = ");
		DFSTraverse_AML(G, PrintElem);	
		printf("\n\n");
	} 
	PressEnter;

	printf("▼14\n▲函数 BFSTraverse_AML 测试...\n");		//14.函数BFSTraverse_AML测试
	{
		printf("广度优先遍历无向图 G = ");
		BFSTraverse_AML(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 ClearGraph_AML 测试...\n");			//2.函数ClearGraph_AML测试
	{
		printf("清空无向图...\n");
		ClearGraph_AML(&G);
		OutputAMLGraph(G);	
		printf("\n");
	} 
	PressEnter;				
}

void PrintElem(char c)
{
	printf("%c ", c);
}
