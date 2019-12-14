/******************************************
 *                                        *
 * �ļ���: ��07 ͼ\03 OLGraph             *
 *                                        *
 * �ļ���: OLGraph.h                      *
 *                                        *
 * ��  ��: ����ͼ��ʮ��������ز����б� *
 *                                        *
 ******************************************/

#ifndef OLGRAPH_H
#define OLGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//�ṩmalloc��realloc��free��exitԭ��
#include <stdarg.h>											//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"							//**��01 ����**//
#include "../../��01 ����/Scanf.c"							//**��01 ����**//
#include "../../��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c" 	//**��03 ջ�Ͷ���**//

/* �궨�� */
#define MAX_VERTEX_NUM 20						//��󶥵���� 

/* ����ͼ��ʮ���������Ͷ��� */
typedef struct									//�������Ϣ
{
	//���ĵ����軡��Ϣ 
}InfoType;
typedef struct ArcBox							//�����
{
	int tailvex, headvex;						//�û���β��ͷ�����λ��
	struct ArcBox *hlink, *tLink;				//�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ������� 
	InfoType info;								//�û������Ϣ
}ArcBox;
typedef char VertexType_OL;						//����ͼ��������
typedef struct VexNode
{
	VertexType_OL data;
	ArcBox *firstin, *firstout;					//�ֱ�ָ��ö����һ���뻡�ͳ��� 
}VexNode;
typedef struct									//����ͼ��ʮ�������洢�ṹ 
{
	VexNode xlist[MAX_VERTEX_NUM+1];			//��ͷ����
	int vexnum, arcnum;							//����ͼ��ǰ�������ͻ��� 
	int IncInfo;								//IncInfoΪ0���������������Ϣ  
}OLGraph;

/* ȫ�ֱ��� */
Status visited[MAX_VERTEX_NUM+1];		//��־����
void (*VisitFunc)(VertexType_OL e);		//����ָ����� 

/* ����ͼ��ʮ�����������б� */
Status CreateDG_OL(FILE *fp, OLGraph *G);
/*����������������������������
��(01)�㷨7.3����������ͼ�� ��
����������������������������*/

void ClearGraph_OL(OLGraph *G);
/*��������������
��(02)���ͼ����
��������������*/

int LocateVex_OL(OLGraph G, VertexType_OL u);
/*������������������������
��(03)Ѱ�Ҷ���u��λ�á� ��
������������������������*/

VertexType_OL GetVex_M(OLGraph G, int order);
/*��������������������������
��(04)���ص�v������ֵ�� ��
��������������������������*/

Status PutVex_OL(OLGraph *G, VertexType_OL v, VertexType_OL value);
/*������������������������
��(05)�Զ���v��ֵvalue����
������������������������*/

int FirstAdjVex_OL(OLGraph G, VertexType_OL v);
/*����������������������������������
��(06)����v�ĵ�һ���ڽӶ�����š� ��
����������������������������������*/

int NextAdjVex_OL(OLGraph G, VertexType_OL v, VertexType_OL w);
/*����������������������������������������
��(07)����v�����w����һ���ڽӶ�����š���
����������������������������������������*/

Status InsertVex_OL(OLGraph *G, VertexType_OL v);
/*����������������������
��(08)���붥��v��ͼ�� ��
����������������������*/

Status DeleteVex_OL(OLGraph *G, VertexType_OL v);
/*������������������������
��(09)��ͼ��ɾ������v�� ��
������������������������*/

Status InsertArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w, ...);
/*������������������������
��(10)���뻡<v,w>��ͼ�� ��
������������������������*/

Status DeleteArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w);
/*��������������������
��(11)ɾ����<v,w>�� ��
��������������������*/

void DFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL));
/*��������������������
��(12)������ȱ�������
��������������������*/

void DFS_OL(OLGraph G, int v);
/*����������������������������
��(13)������ȱ������ĺ�������
����������������������������*/

void BFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL));
/*��������������������
��(14)������ȱ�������
��������������������*/

void OutputOLGraph(OLGraph G);
/*��������������
��(15)���ͼ����
��������������*/

void Input(FILE *fp, InfoType *info);
/*������������������������
��(16)¼�뻡�������Ϣ����
������������������������*/

#endif
