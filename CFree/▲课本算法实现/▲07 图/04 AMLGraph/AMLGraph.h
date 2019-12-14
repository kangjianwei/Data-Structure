/********************************************
 *						                    *
 * �ļ���: ��07 ͼ\04 AMLGraph              *
 * 						                    *
 * �ļ���: AMLGraph.h                       *
 *                                          *
 * ��  ��: ����ͼ���ڽӶ��ر���ز����б� *
 *                                          *
 ********************************************/

#ifndef AMLGRAPH_H
#define AMLGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//�ṩmalloc��realloc��free��exitԭ��
#include <stdarg.h>											//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"							//**��01 ����**//
#include "../../��01 ����/Scanf.c"							//**��01 ����**//
#include "../../��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c" 	//**��03 ջ�Ͷ���**//

/* �궨�� */
#define MAX_VERTEX_NUM 20						//��󶥵���� 
#define MAX_EDGE_NUM 190						//����ͼ������� 

/* ����ͼ���ڽӶ��ر����Ͷ��� */
typedef enum{ unvisit, visit }VisitIf;
typedef struct
{
	//���ĵ����軡��Ϣ
}InfoType;
typedef struct EBox								//���� 
{
	VisitIf mark;								//���ʱ�� 
	int ivex, jvex;								//�ñ����������������λ��
	struct EBox *ilink, *jlink;					//�ֱ�ָ�������������������һ����
	InfoType info;								//�û������Ϣ
}EBox;
typedef char VertexType_AML;					//����ͼ�������� 
typedef struct VexBox
{
	VertexType_AML data;						//������Ϣ 
	EBox *firstedge;
}VexBox;
typedef struct									//����ͼ���ڽӶ��ر��洢�ṹ
{
	VexBox adjmulist[MAX_VERTEX_NUM+1];			//��ͷ����
	int vexnum, edgenum;						//����ͼ��ǰ�������ͻ��� 
	int IncInfo;								//IncInfoΪ0���������������Ϣ  
}AMLGraph;

/* ȫ�ֱ��� */
Status visited[MAX_VERTEX_NUM+1];				//�����־����
EBox *edgePtr[MAX_EDGE_NUM+1];					//��ָ������
void (*VisitFunc)(VertexType_AML e);			//����ָ����� 

/* ����ͼ���ڽӶ��ر������б� */
Status CreateUDG_AML(FILE *fp, AMLGraph *G);
/*����������������������������
��(01)�㷨7.3����������ͼ�� ��
����������������������������*/

void ClearGraph_AML(AMLGraph *G);
/*��������������
��(02)���ͼ����
��������������*/

int LocateVex_AML(AMLGraph G, VertexType_AML u);
/*������������������������
��(03)Ѱ�Ҷ���u��λ�á� ��
������������������������*/

VertexType_AML GetVex_M(AMLGraph G, int order);
/*��������������������������
��(04)���ص�v������ֵ�� ��
��������������������������*/

Status PutVex_AML(AMLGraph *G, VertexType_AML v, VertexType_AML value);
/*������������������������
��(05)�Զ���v��ֵvalue����
������������������������*/

int FirstAdjVex_AML(AMLGraph G, VertexType_AML v);
/*����������������������������������
��(06)����v�ĵ�һ���ڽӶ�����š� ��
����������������������������������*/

int NextAdjVex_AML(AMLGraph G, VertexType_AML v, VertexType_AML w);
/*����������������������������������������
��(07)����v�����w����һ���ڽӶ�����š���
����������������������������������������*/

Status InsertVex_AML(AMLGraph *G, VertexType_AML v);
/*����������������������
��(08)���붥��v��ͼ�� ��
����������������������*/

Status DeleteVex_AML(AMLGraph *G, VertexType_AML v);
/*������������������������
��(09)��ͼ��ɾ������v�� ��
������������������������*/

Status InsertArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...);
/*������������������������
��(10)���뻡<v,w>��ͼ�� ��
������������������������*/

Status DeleteArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w);
/*��������������������
��(11)ɾ����<v,w> ����
��������������������*/

void DFSTraverse_AML(AMLGraph G, void(Visit)(VertexType_AML));
/*��������������������
��(12)������ȱ�������
��������������������*/

void DFS_AML(AMLGraph G, int v);
/*����������������������������
��(13)������ȱ������ĺ�������
����������������������������*/

void BFSTraverse_AML(AMLGraph G, void(Visit)(VertexType_AML));
/*��������������������
��(14)������ȱ�������
��������������������*/

void OutputAMLGraph(AMLGraph G);
/*��������������
��(15)���ͼ����
��������������*/

void ClearMark(AMLGraph G);
/*����������������
��(16)��ձ�־����
����������������*/

void Input(FILE *fp, InfoType *info);
/*������������������������
��(17)¼�뻡�������Ϣ����
������������������������*/

#endif
