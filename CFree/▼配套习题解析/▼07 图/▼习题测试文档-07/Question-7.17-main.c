#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/03 OLGraph/OLGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status InsertVex_7_17(OLGraph *G, VertexType_OL v);
Status InsertArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w, ...);
Status DeleteVex_7_17(OLGraph *G, VertexType_OL v);
Status DeleteArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w);

int main(int argc, char *argv[])
{
	OLGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");							
	fp = fopen("Data/Algo_7_17.txt", "r");
	CreateDG_OL(fp, &G);						//������ͼΪ��
	fclose(fp);
	OutputOLGraph(G);
	printf("\n");
	
	printf("���붥�� '%c'...\n", 'H');
	InsertVex_7_17(&G, 'H');
	OutputOLGraph(G);		
	printf("\n");

	printf("���뻡 <%c, %c>...\n", 'H', 'C');	
	printf("���뻡 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_17(&G, 'H', 'C');
	InsertArc_7_17(&G, 'D', 'H');
	OutputOLGraph(G);	
	printf("\n");

	printf("ɾ���� <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_17(&G, 'H', 'C');
	OutputOLGraph(G);
	printf("\n");

	printf("ɾ������ '%c'...\n", 'H');
	DeleteVex_7_17(&G, 'H');
	OutputOLGraph(G);	
	printf("\n");
		
	return 0;
}

/*��������������������������
����7.17-1��������v����ͼG��
��������������������������*/
Status InsertVex_7_17(OLGraph *G, VertexType_OL v)
{
	return InsertVex_OL(G, v); 
} 

/*����������������������������
����7.17-2������<v,w>����ͼG��
����������������������������*/
Status InsertArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w, ...)
{
	return InsertArc_OL(G, v, w);
}

/*����������������������������
����7.17-3����ͼG��ɾ������v��
����������������������������*/
Status DeleteVex_7_17(OLGraph *G, VertexType_OL v)
{
	return DeleteVex_OL(G, v);
}

/*������������������������������
����7.17-4����ͼG��ɾ����<v,w>��
������������������������������*/
Status DeleteArc_7_17(OLGraph *G, VertexType_OL v, VertexType_OL w)
{
	return DeleteArc_OL(G, v, w);
}
