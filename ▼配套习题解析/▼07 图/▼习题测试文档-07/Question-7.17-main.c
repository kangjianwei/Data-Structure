#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/03 OLGraph/OLGraph.c"		//**▲07 图**//

/* 函数原型 */
Status InsertVex_7_17(OLGraph *G, VertexType_OL v);
Status InsertArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w, ...);
Status DeleteVex_7_17(OLGraph *G, VertexType_OL v);
Status DeleteArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w);

int main(int argc, char *argv[])
{
	OLGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出有向图...\n");							
	fp = fopen("Data/Algo_7_17.txt", "r");
	CreateDG_OL(fp, &G);						//以有向图为例
	fclose(fp);
	OutputOLGraph(G);
	printf("\n");
	
	printf("插入顶点 '%c'...\n", 'H');
	InsertVex_7_17(&G, 'H');
	OutputOLGraph(G);		
	printf("\n");

	printf("插入弧 <%c, %c>...\n", 'H', 'C');	
	printf("插入弧 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_17(&G, 'H', 'C');
	InsertArc_7_17(&G, 'D', 'H');
	OutputOLGraph(G);	
	printf("\n");

	printf("删除弧 <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_17(&G, 'H', 'C');
	OutputOLGraph(G);
	printf("\n");

	printf("删除顶点 '%c'...\n", 'H');
	DeleteVex_7_17(&G, 'H');
	OutputOLGraph(G);	
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题7.17-1：将顶点v插入图G┃
┗━━━━━━━━━━━━*/
Status InsertVex_7_17(OLGraph *G, VertexType_OL v)
{
	return InsertVex_OL(G, v); 
} 

/*━━━━━━━━━━━━━┓
┃题7.17-2：将弧<v,w>插入图G┃
┗━━━━━━━━━━━━━*/
Status InsertArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w, ...)
{
	return InsertArc_OL(G, v, w);
}

/*━━━━━━━━━━━━━┓
┃题7.17-3：从图G中删除顶点v┃
┗━━━━━━━━━━━━━*/
Status DeleteVex_7_17(OLGraph *G, VertexType_OL v)
{
	return DeleteVex_OL(G, v);
}

/*━━━━━━━━━━━━━━┓
┃题7.17-4：从图G中删除弧<v,w>┃
┗━━━━━━━━━━━━━━*/
Status DeleteArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w)
{
	return DeleteArc_OL(G, v, w);
}
