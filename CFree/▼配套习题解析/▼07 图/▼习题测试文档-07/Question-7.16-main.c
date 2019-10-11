#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//

/* 函数原型 */
Status InsertVex_7_16(ALGraph *G, VertexType_AL v);
Status InsertArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w, ...);
Status DeleteVex_7_16(ALGraph *G, VertexType_AL v);
Status DeleteArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出无向图...\n");
	G.kind = UDG;								//以无向图为例
	fp = fopen("Data/Algo_7_16.txt", "r");
	CreateUDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	printf("插入顶点 '%c'...\n", 'H');
	InsertVex_7_16(&G, 'H');
	OutputALGraph(G);		
	printf("\n");

	printf("插入弧 <%c, %c>...\n", 'H', 'C');	
	printf("插入弧 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_16(&G, 'H', 'C');
	InsertArc_7_16(&G, 'D', 'H');
	OutputALGraph(G);	
	printf("\n");

	printf("删除弧 <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_16(&G, 'H', 'C');
	OutputALGraph(G);
	printf("\n");

	printf("删除顶点 '%c'...\n", 'H');
	DeleteVex_7_16(&G, 'H');
	OutputALGraph(G);	
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题7.16-1：将顶点v插入图G┃
┗━━━━━━━━━━━━*/
Status InsertVex_7_16(ALGraph *G, VertexType_AL v)
{
	return InsertVex_AL(G, v); 
} 

/*━━━━━━━━━━━━━┓
┃题7.16-2：将弧<v,w>插入图G┃
┗━━━━━━━━━━━━━*/
Status InsertArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w, ...)
{
	return InsertArc_AL(G, v, w);
}

/*━━━━━━━━━━━━━┓
┃题7.16-3：从图G中删除顶点v┃
┗━━━━━━━━━━━━━*/
Status DeleteVex_7_16(ALGraph *G, VertexType_AL v)
{
	return DeleteVex_AL(G, v);
}

/*━━━━━━━━━━━━━━┓
┃题7.16-4：从图G中删除弧<v,w>┃
┗━━━━━━━━━━━━━━*/
Status DeleteArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w)
{
	return DeleteArc_AL(G, v, w);
}
