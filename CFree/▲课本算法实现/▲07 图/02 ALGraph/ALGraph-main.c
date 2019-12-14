/************************************
 *					                *
 * 文件夹: ▲07 图\02 ALGraph       *
 * 					                *
 * 文件名: ALGraph-main.c           *
 * 							        *
 * 内  容: 图（邻接表）相关函数测试 *
 *                                  *
 ************************************/

#include <stdio.h> 
#include "ALGraph.c" 										//**▲07 图**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	ALGraph G;

	printf("▼1、2、3\n▲函数 CreateGraph_AL等 测试...\n");	//1、2、3.函数CreateGraph_AL等测试
	{
		FILE *fp;
		int r;
		
		srand((unsigned)time(NULL));						//用系统时间做随机数种子 
		r = rand()%2;										//生成随机数
	
		switch(r)
		{
			case DG:
				printf("初始化有向图...\n");
				fp = fopen("TestData_DG_AL.txt", "r");
				break;
			case UDG:
				printf("初始化无向图...\n");
				fp = fopen("TestData_UDG_AL.txt", "r");
				break;			
		}
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼17\n▲函数 OutputALGraph 测试...\n");			//17.函数OutputALGraph测试
	{
		printf("输出图的邻接表 G = \n");		
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 LocateVex_AL 测试...\n");			//5.函数LocateVex_AL测试
	{
		printf("顶点 '%c' 的位置为 %d \n", 'C', LocateVex_AL(G, 'C'));
		printf("\n");
	}
	PressEnter;	

	printf("▼6\n▲函数 GetVex_AL 测试...\n");				//6.函数GetVex_AL测试
	{
		printf("第 %d 个顶点的值为 '%c'\n", 3, GetVex_AL(G, 3));
		printf("\n");
	}
	PressEnter;	

	printf("▼8\n▲函数 FirstAdjVex_AL 测试...\n");			//8.函数FirstAdjVex_AL测试
	{
		printf(" '%c' 的第一个邻接顶点的序号为 %d \n", 'B', FirstAdjVex_AL(G, 'B'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼9\n▲函数 NextAdjVex_AL 测试...\n");			//9.函数NextAdjVex_AL测试
	{
		printf(" '%c' 相对于 '%c' 的下一个邻接顶点序号为 %d \n", 'A', 'B', NextAdjVex_AL(G, 'A', 'B'));
		printf("\n");
	} 
	PressEnter;	

	printf("▼7\n▲函数 PutVex_AL 测试...\n");				//7.函数PutVex_AL测试
	{
		printf("对顶点 '%c' 赋值 '%c' 后，G = \n", 'A', 'X');
		PutVex_AL(&G, 'A', 'X');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;
	
	printf("▼10\n▲函数 InsertVex_AL 测试...\n");			//10.函数InsertVex_AL测试
	{
		printf("插入顶点 '%c' 后，G = \n", 'H');
		InsertVex_AL(&G, 'H');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;	

	printf("▼12\n▲函数 InsertArc_AL 测试...\n");			//12.函数InsertArc_AL测试
	{
		printf("顺次插入弧 <%c, %c>、", 'H', 'X');
		printf("<%c, %c>、", 'H', 'C');
		printf("<%c, %c> 后，G = \n", 'D', 'H');
		InsertArc_AL(&G, 'H', 'X');
		InsertArc_AL(&G, 'H', 'C');
		InsertArc_AL(&G, 'D', 'H');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;

	printf("▼13\n▲函数 DeleteArc_AL 测试...\n");			//13.函数DeleteArc_AL测试
	{
		printf("删除弧 <%c, %c> 后，G = \n", 'H', 'X');
		DeleteArc_AL(&G, 'H', 'X');
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;
		
	printf("▼11\n▲函数 DeleteVex_AL 测试...\n");			//11.函数DeleteVex_AL测试
	{
		printf("删除顶点 '%c' 后，G = \n", 'H');
		DeleteVex_AL(&G, 'H');
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("▼14、15\n▲函数 DFSTraverse_AL等 测试...\n");	//14、15.函数DFSTraverse_AL等测试
	{
		printf("深度优先遍历图 G = ");
		DFSTraverse_AL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;

	printf("▼16\n▲函数 BFSTraverse_AL 测试...\n");		//16.函数BFSTraverse_AL测试
	{
		printf("广度优先遍历图 G = ");
		BFSTraverse_AL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 ClearGraph_AL 测试...\n");			//4.函数ClearGraph_AL测试
	{
		printf("清空图...\n");
		ClearGraph_AL(&G);
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;					
}

void PrintElem(char c)
{
	printf("%c ", c);
}
