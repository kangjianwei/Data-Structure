#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/04 AMLGraph/AMLGraph.c"	//**▲07 图**//

/* 函数原型 */
Status InsertVex_7_18(AMLGraph *G, VertexType_AML v);
Status InsertArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...);
Status DeleteVex_7_18(AMLGraph *G, VertexType_AML v);
Status DeleteArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w);
Status Algo_7_19(FILE *fp, AMLGraph *G);

int main(int argc, char *argv[])
{
	AMLGraph G;
	FILE *fp;									//作为输入源
	
	printf("███题 7.19 验证...███\n");
	printf("创建并输出无向图...\n");					
	fp = fopen("Data/Algo_7_18-7_19.txt", "r");
	Algo_7_19(fp, &G);							//以无向图为例				 
	fclose(fp);
	OutputAMLGraph(G);
	printf("\n");

	printf("███题 7.18 验证...███\n");	
	printf("插入顶点 '%c'...\n", 'H');
	InsertVex_7_18(&G, 'H');
	OutputAMLGraph(G);		
	printf("\n");

	printf("插入弧 <%c, %c>...\n", 'H', 'C');	
	printf("插入弧 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_18(&G, 'H', 'C');
	InsertArc_7_18(&G, 'D', 'H');
	OutputAMLGraph(G);	
	printf("\n");

	printf("删除弧 <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_18(&G, 'H', 'C');
	OutputAMLGraph(G);
	printf("\n");

	printf("删除顶点 '%c'...\n", 'H');
	DeleteVex_7_18(&G, 'H');
	OutputAMLGraph(G);	
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题7.18-1：将顶点v插入图G┃
┗━━━━━━━━━━━━*/
Status InsertVex_7_18(AMLGraph *G, VertexType_AML v)
{
	return InsertVex_AML(G, v); 
} 

/*━━━━━━━━━━━━━┓
┃题7.18-2：将弧<v,w>插入图G┃
┗━━━━━━━━━━━━━*/
Status InsertArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...)
{
	return InsertArc_AML(G, v, w);
}

/*━━━━━━━━━━━━━┓
┃题7.18-3：从图G中删除顶点v┃
┗━━━━━━━━━━━━━*/
Status DeleteVex_7_18(AMLGraph *G, VertexType_AML v)
{
	return DeleteVex_AML(G, v);
}

/*━━━━━━━━━━━━━━┓
┃题7.18-4：从图G中删除弧<v,w>┃
┗━━━━━━━━━━━━━━*/
Status DeleteArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w)
{
	return DeleteArc_AML(G, v, w);
}

/*━━━━━━━━━━━━━━━┓
┃题7.19：创建无向图的邻接多重表┃
┗━━━━━━━━━━━━━━━*/
Status Algo_7_19(FILE *fp, AMLGraph *G)
{
	return CreateUDG_AML(fp, G);
} 
