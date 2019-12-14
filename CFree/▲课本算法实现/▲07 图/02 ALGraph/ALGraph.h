/************************************
 *					                *
 * �ļ���: ��07 ͼ\02 ALGraph       *
 * 					                *
 * �ļ���: ALGraph.h                *
 *    	    		                *
 * ��  ��: ͼ���ڽӱ���ز����б� *
 *                                  *
 ************************************/

#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//�ṩmalloc��realloc��free��exit��rand��srandԭ�� 
#include <stdarg.h>											//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"							//**��01 ����**//
#include "../../��01 ����/Scanf.c"							//**��01 ����**//
#include "../../��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c" 	//**��03 ջ�Ͷ���**//

/* �궨�� */
#define MAX_VERTEX_NUM 20						//��󶥵���� 

/* ͼ�����Ͷ��� */
typedef enum{ DG, UDG }GraphKind;				//0-����ͼ��1-����ͼ
typedef struct
{
	int in;
}InfoType;

/* ���� */
typedef struct ArcNode
{
	int adjvex;							//������� 
	struct ArcNode *nextarc;			//ָ����һ������ָ�� 
	InfoType info;						//�û������Ϣ
}ArcNode;

/* ͷ��� */
typedef char VertexType_AL;				//ͼ�������� 
typedef struct VNode
{
	VertexType_AL data;					//������Ϣ
	ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAX_VERTEX_NUM+1];

/* ͼ���ڽӱ��Ĵ洢��ʾ */
typedef struct
{
	AdjList vertices;					//�ڽӱ�
	int vexnum,	arcnum;					//ͼ�ĵ�ǰ�������ͻ���
	int IncInfo;						//IncInfoΪ0���������������Ϣ 
	GraphKind kind;						//ͼ�������־ 
}ALGraph;

/* ȫ�ֱ��� */
Status visited[MAX_VERTEX_NUM+1];		//��־����
void (*VisitFunc)(VertexType_AL e);		//����ָ����� 

/* ͼ���ڽӱ������б� */
Status CreateGraph_AL(FILE *fp, ALGraph *G);
/*�������������� 
��(01)����ͼ����
��������������*/

Status CreateDG_AL(FILE *fp, ALGraph *G);
/*������������������
��(02)��������ͼ����
������������������*/

Status CreateUDG_AL(FILE *fp, ALGraph *G);
/*������������������
��(03)��������ͼ����
������������������*/

void ClearGraph_AL(ALGraph *G);
/*��������������
��(04)���ͼ����
��������������*/

int LocateVex_AL(ALGraph G, VertexType_AL u);
/*������������������������
��(05)Ѱ�Ҷ���u��λ�á� ��
������������������������*/

VertexType_AL GetVex_M(ALGraph G, int order);
/*��������������������������
��(06)���ص�v������ֵ�� ��
��������������������������*/

Status PutVex_AL(ALGraph *G, VertexType_AL v, VertexType_AL value);
/*������������������������
��(07)�Զ���v��ֵvalue����
������������������������*/

int FirstAdjVex_AL(ALGraph G, VertexType_AL v);
/*����������������������������������
��(08)����v�ĵ�һ���ڽӶ�����š� ��
����������������������������������*/

int NextAdjVex_AL(ALGraph G, VertexType_AL v, VertexType_AL w);
/*����������������������������������������
��(09)����v�����w����һ���ڽӶ�����š���
����������������������������������������*/

Status InsertVex_AL(ALGraph *G, VertexType_AL v);
/*����������������������
��(10)���붥��v��ͼ�� ��
����������������������*/

Status DeleteVex_AL(ALGraph *G, VertexType_AL v);
/*������������������������
��(11)��ͼ��ɾ������v�� ��
������������������������*/

Status InsertArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w, ...);
/*������������������������
��(12)���뻡<v,w>��ͼ�� ��
������������������������*/

Status DeleteArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w);
/*��������������������
��(13)ɾ����<v,w>�� ��
��������������������*/

void DFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL));
/*��������������������
��(14)������ȱ�������
��������������������*/

void DFS_AL(ALGraph G, int v);
/*����������������������������
��(15)������ȱ������ĺ�������
����������������������������*/

void BFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL));
/*��������������������
��(16)������ȱ�������
��������������������*/

void OutputALGraph(ALGraph G);
/*��������������
��(17)���ͼ����
��������������*/

void Input(FILE *fp, InfoType *info);
/*������������������������
��(18)¼�뻡�������Ϣ����
������������������������*/

#endif
