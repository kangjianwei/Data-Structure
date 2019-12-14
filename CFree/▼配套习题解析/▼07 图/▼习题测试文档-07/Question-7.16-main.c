#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status InsertVex_7_16(ALGraph *G, VertexType_AL v);
Status InsertArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w, ...);
Status DeleteVex_7_16(ALGraph *G, VertexType_AL v);
Status DeleteArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	G.kind = UDG;								//������ͼΪ��
	fp = fopen("Data/Algo_7_16.txt", "r");
	CreateUDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	printf("���붥�� '%c'...\n", 'H');
	InsertVex_7_16(&G, 'H');
	OutputALGraph(G);		
	printf("\n");

	printf("���뻡 <%c, %c>...\n", 'H', 'C');	
	printf("���뻡 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_16(&G, 'H', 'C');
	InsertArc_7_16(&G, 'D', 'H');
	OutputALGraph(G);	
	printf("\n");

	printf("ɾ���� <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_16(&G, 'H', 'C');
	OutputALGraph(G);
	printf("\n");

	printf("ɾ������ '%c'...\n", 'H');
	DeleteVex_7_16(&G, 'H');
	OutputALGraph(G);	
	printf("\n");
		
	return 0;
}

/*��������������������������
����7.16-1��������v����ͼG��
��������������������������*/
Status InsertVex_7_16(ALGraph *G, VertexType_AL v)
{
	return InsertVex_AL(G, v); 
} 

/*����������������������������
����7.16-2������<v,w>����ͼG��
����������������������������*/
Status InsertArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w, ...)
{
	return InsertArc_AL(G, v, w);
}

/*����������������������������
����7.16-3����ͼG��ɾ������v��
����������������������������*/
Status DeleteVex_7_16(ALGraph *G, VertexType_AL v)
{
	return DeleteVex_AL(G, v);
}

/*������������������������������
����7.16-4����ͼG��ɾ����<v,w>��
������������������������������*/
Status DeleteArc_7_16(ALGraph *G, VertexType_AL v, VertexType_AL w)
{
	return DeleteArc_AL(G, v, w);
}
