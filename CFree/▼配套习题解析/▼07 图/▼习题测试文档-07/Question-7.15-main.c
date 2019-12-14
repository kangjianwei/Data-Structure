#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/01 MGraph/MGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status InsertVex_7_15(MGraph *G, VertexType_M v);
Status InsertArc_7_15(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...);
Status DeleteVex_7_15(MGraph *G, VertexType_M v);
Status DeleteArc_7_15(MGraph *G, VertexType_M v, VertexType_M w);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	G.kind = UDG;								//������ͼΪ��
	fp = fopen("Data/Algo_7_15.txt", "r");
	CreateUDG_M(fp, &G);						 
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	printf("���붥�� '%c'...\n", 'H');
	InsertVex_7_15(&G, 'H');
	OutputMGraph(G);		
	printf("\n");

	printf("���뻡 <%c, %c, 1>...\n", 'H', 'C');	
	printf("���뻡 <%c, %c, 1>...\n", 'D', 'H');
	InsertArc_7_15(&G, 'H', 'C', 1);
	InsertArc_7_15(&G, 'D', 'H', 1);
	OutputMGraph(G);	
	printf("\n");

	printf("ɾ���� <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_15(&G, 'H', 'C');
	OutputMGraph(G);
	printf("\n");

	printf("ɾ������ '%c'...\n", 'H');
	DeleteVex_7_15(&G, 'H');
	OutputMGraph(G);	
	printf("\n");
		
	return 0;
}

/*��������������������������
����7.15-1��������v����ͼG��
��������������������������*/
Status InsertVex_7_15(MGraph *G, VertexType_M v)
{
	return InsertVex_M(G, v); 
} 

/*����������������������������
����7.15-2������<v,w>����ͼG��
����������������������������*/
Status InsertArc_7_15(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...)
{
	return InsertArc_M(G, v, w, 1);
}

/*����������������������������
����7.15-3����ͼG��ɾ������v��
����������������������������*/
Status DeleteVex_7_15(MGraph *G, VertexType_M v)
{
	return DeleteVex_M(G, v);
}

/*������������������������������
����7.15-4����ͼG��ɾ����<v,w>��
������������������������������*/
Status DeleteArc_7_15(MGraph *G, VertexType_M v, VertexType_M w)
{
	return DeleteArc_M(G, v, w);
}
