/****************************************
 *    	    		                    *
 * 文件夹: ▲07 图\08 ArticulationPoint *
 * 					                    *
 * 文件名: ArticulationPoint-main.c     *
 * 							            *
 * 内  容: 无向图关节点相关函数测试     *
 *                                      *
 ****************************************/

#include <stdio.h>
#include "ArticulationPoint.c" 									//**▲07 图**//													

int main(int argc, char *argv[])
{
	ALGraph G;	
	
	printf("创建并输出无向图...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;	

	printf("▼1、2、3、4\n▲函数 FindArticul等 测试...\n");		//1、2、3、4.函数FindArticul、OutputAPoint等测试	
	{
		printf("寻找并输出关节点...\n");
		FindArticul(G);
		OutputAPoint(G);
		printf("\n");
	}
	PressEnter;
		
	return 0;
}
