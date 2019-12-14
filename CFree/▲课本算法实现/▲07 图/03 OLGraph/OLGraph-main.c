/******************************************
 *                                        *
 * 文件夹: ▲07 图\03 OLGraph             *
 *                                        *
 * 文件名: OLGraph-main.c                 *
 * 							              *
 * 内  容: 有向图（十字链表）相关函数测试 *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "OLGraph.c" 											//**▲07 图**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	OLGraph G;
	
	printf("▼1\n▲函数 CreateDG_OL等 测试...\n");				//1.函数CreateDG_OL等测试
	{
		FILE *fp;
		
		printf("初始化有向图 G ...\n");
		fp = fopen("TestData_DG_OL.txt", "r");					//文档中弧的录入为逆序 
		CreateDG_OL(fp, &G); 
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼15\n▲函数 OutputOLGraph 测试...\n");				//15.函数OutputOLGraph测试
	{
		printf("输出有向图的十字链表 G = \n");		
		OutputOLGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("▼3\n▲函数 LocateVex_OL 测试...\n");				//3.函数LocateVex_OL测试
	{
		printf("顶点 '%c' 的位置为 %d \n", 'C', LocateVex_OL(G, 'C'));
		printf("\n");
	}
	PressEnter;	

	printf("▼4\n▲函数 GetVex_OL 测试...\n");					//4.函数GetVex_OL测试
	{
		printf("第 %d 个顶点的值为 '%c' \n", 3, GetVex_OL(G, 3));
		printf("\n");
	}
	PressEnter;	

	printf("▼6\n▲函数 FirstAdjVex_OL 测试...\n");				//6.函数FirstAdjVex_OL测试
	{
		printf("' %c' 的第一个邻接顶点的序号为 %d \n", 'D', FirstAdjVex_OL(G, 'D'));
		printf("\n");
	}
	PressEnter;	

	printf("▼7\n▲函数 NextAdjVex_OL 测试...\n");				//7.函数NextAdjVex_OL测试
	{
		printf(" '%c' 相对于 '%c' 的下一个邻接顶点序号为 %d\n", 'D', 'A', NextAdjVex_OL(G, 'D', 'A'));
		printf("\n");
	}
	PressEnter;	

	printf("▼5\n▲函数 PutVex_OL 测试...\n");					//5.函数PutVex_OL测试
	{
		printf("对顶点 '%c' 赋值 '%c'后，G = \n", 'A', 'X');
		PutVex_OL(&G, 'A', 'X');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 InsertVex_OL 测试...\n");					//8.函数InsertVex_OL测试
	{
		printf("插入顶点 '%c'后，G = \n", 'H');
		InsertVex_OL(&G, 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;	

	printf("▼10\n▲函数 InsertArc_OL 测试...\n");				//10.函数InsertArc_OL测试
	{
		printf("顺次插入弧 <%c, %c>、", 'H', 'X');
		printf("<%c, %c>、", 'H', 'C');
		printf("<%c, %c>后，G = \n", 'D', 'H');
		InsertArc_OL(&G, 'H', 'X');
		InsertArc_OL(&G, 'H', 'C');
		InsertArc_OL(&G, 'D', 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("▼11\n▲函数 DeleteArc_OL 测试...\n");				//11.函数DeleteArc_OL测试
	{
		printf("删除弧 <%c, %c>后，G = \n", 'H', 'X');
		DeleteArc_OL(&G, 'H', 'X');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;
		
	printf("▼09\n▲函数 DeleteVex_OL 测试...\n");				//09.函数DeleteVex_OL测试
	{
		printf("删除顶点 '%c'后，G = \n", 'H');
		DeleteVex_OL(&G, 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("▼12、13\n▲函数 DFSTraverse_OL等 测试...\n");		//12、13.函数DFSTraverse_OL等测试
	{
		printf("深度优先遍历有向图 G = ");
		DFSTraverse_OL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;

	printf("▼14\n▲函数 BFSTraverse_OL 测试...\n");				//14.函数BFSTraverse_OL测试
	{
		printf("广度优先遍历有向图 G = ");
		BFSTraverse_OL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 ClearGraph_OL 测试...\n");				//2.函数ClearGraph_OL测试
	{
		printf("清空有向图...\n");
		ClearGraph_OL(&G);
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;					
}

void PrintElem(char c)
{
	printf("%c ", c);
}
