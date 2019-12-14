#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/04 AMLGraph/AMLGraph.c"	//**��07 ͼ**//

/* ����ԭ�� */
Status InsertVex_7_18(AMLGraph *G, VertexType_AML v);
Status InsertArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...);
Status DeleteVex_7_18(AMLGraph *G, VertexType_AML v);
Status DeleteArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w);
Status Algo_7_19(FILE *fp, AMLGraph *G);

int main(int argc, char *argv[])
{
	AMLGraph G;
	FILE *fp;									//��Ϊ����Դ
	
	printf("�������� 7.19 ��֤...������\n");
	printf("�������������ͼ...\n");					
	fp = fopen("Data/Algo_7_18-7_19.txt", "r");
	Algo_7_19(fp, &G);							//������ͼΪ��				 
	fclose(fp);
	OutputAMLGraph(G);
	printf("\n");

	printf("�������� 7.18 ��֤...������\n");	
	printf("���붥�� '%c'...\n", 'H');
	InsertVex_7_18(&G, 'H');
	OutputAMLGraph(G);		
	printf("\n");

	printf("���뻡 <%c, %c>...\n", 'H', 'C');	
	printf("���뻡 <%c, %c>...\n", 'D', 'H');
	InsertArc_7_18(&G, 'H', 'C');
	InsertArc_7_18(&G, 'D', 'H');
	OutputAMLGraph(G);	
	printf("\n");

	printf("ɾ���� <%c, %c>...\n", 'H', 'C');
	DeleteArc_7_18(&G, 'H', 'C');
	OutputAMLGraph(G);
	printf("\n");

	printf("ɾ������ '%c'...\n", 'H');
	DeleteVex_7_18(&G, 'H');
	OutputAMLGraph(G);	
	printf("\n");
		
	return 0;
}

/*��������������������������
����7.18-1��������v����ͼG��
��������������������������*/
Status InsertVex_7_18(AMLGraph *G, VertexType_AML v)
{
	return InsertVex_AML(G, v); 
} 

/*����������������������������
����7.18-2������<v,w>����ͼG��
����������������������������*/
Status InsertArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...)
{
	return InsertArc_AML(G, v, w);
}

/*����������������������������
����7.18-3����ͼG��ɾ������v��
����������������������������*/
Status DeleteVex_7_18(AMLGraph *G, VertexType_AML v)
{
	return DeleteVex_AML(G, v);
}

/*������������������������������
����7.18-4����ͼG��ɾ����<v,w>��
������������������������������*/
Status DeleteArc_7_18(AMLGraph *G, VertexType_AML v, VertexType_AML w)
{
	return DeleteArc_AML(G, v, w);
}

/*��������������������������������
����7.19����������ͼ���ڽӶ��ر�
��������������������������������*/
Status Algo_7_19(FILE *fp, AMLGraph *G)
{
	return CreateUDG_AML(fp, G);
} 
