#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/01 MGraph/MGraph.c"		//**▲07 图**//

/* 函数原型 */
Status InsertVex_7_15(MGraph *G, VertexType_M v);
Status InsertArc_7_15(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...);
Status DeleteVex_7_15(MGraph *G, VertexType_M v);
Status DeleteArc_7_15(MGraph *G, VertexType_M v, VertexType_M w);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出无向图...\n");
	G.kind = UDG;								//以无向图为例
	fp = fopen("Data/Algo_7_15.txt", "r");
	CreateUDG_M(fp, &G);						 
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	printf("插入顶点 '%c'...\n", 'H');
	InsertVex_7_15(&G, 'H');
	OutputMGraph(G);		
	printf("\n");

	printf("插入弧 <%c, %c, 1>...\n", 'H', 'C');	
	printf("插入弧 <%c, %c, 1>...\n", 'D', 'H');
	InsertArc_7_15(&G, 'H', 'C', 1);
	InsertArc_7_15(&G, 'D', 'H', 1);
	OutputMGraph(G);	
	printf("\n");

	printf("删除弧 <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_15(&G, 'H', 'C');
	OutputMGraph(G);
	printf("\n");

	printf("删除顶点 '%c'...\n", 'H');
	DeleteVex_7_15(&G, 'H');
	OutputMGraph(G);	
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题7.15-1：将顶点v插入图G┃
┗━━━━━━━━━━━━*/
Status InsertVex_7_15(MGraph *G, VertexType_M v)
{
	return InsertVex_M(G, v); 
} 

/*━━━━━━━━━━━━━┓
┃题7.15-2：将弧<v,w>插入图G┃
┗━━━━━━━━━━━━━*/
Status InsertArc_7_15(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...)
{
	return InsertArc_M(G, v, w, 1);
}

/*━━━━━━━━━━━━━┓
┃题7.15-3：从图G中删除顶点v┃
┗━━━━━━━━━━━━━*/
Status DeleteVex_7_15(MGraph *G, VertexType_M v)
{
	return DeleteVex_M(G, v);
}

/*━━━━━━━━━━━━━━┓
┃题7.15-4：从图G中删除弧<v,w>┃
┗━━━━━━━━━━━━━━*/
Status DeleteArc_7_15(MGraph *G, VertexType_M v, VertexType_M w)
{
	return DeleteArc_M(G, v, w);
}
