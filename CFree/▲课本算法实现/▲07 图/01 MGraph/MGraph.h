/******************************************************
 *                                                    *
 * �ļ���: ��07 ͼ\01 MGraph                          *
 *                                                    *
 * �ļ���: MGraph.h                                   *
 *                                                    *
 * ��  ��: ͼ��������飨�ڽӾ��󣩱�ʾ����ز����б� *
 *                                                    *
 ******************************************************/

#ifndef MGRAPH_H
#define MGRAPH_H

#include <stdio.h>
#include <limits.h>											//�ṩ��INT_MAX
#include <stdlib.h> 										//�ṩrand��srandԭ�� 
#include <stdarg.h>											//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"							//**��01 ����**//
#include "../../��01 ����/Scanf.c"							//**��01 ����**//
#include "../../��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c" 	//**��03 ջ�Ͷ���**//

/* �궨�� */
#define INFINITY INT_MAX						//���ֵ��
#define MAX_VERTEX_NUM 20						//��󶥵���� 

/* ͼ��������飨�ڽӾ��󣩱�ʾ�����Ͷ��� */
typedef enum{ DG, DN, UDG, UDN }GraphKind;		//0-����ͼ��1-����������Ȩֵ����2-����ͼ��3-����������Ȩֵ��
typedef struct{ }InfoType;						//�������Ϣ
typedef int VRType;								//ͼ�������ϵ���� 
typedef struct ArcCell
{
	VRType adj;									//��Ȩͼ�б�ʾȨֵ����Ȩͼ����0��1��ʾ�Ƿ�����
	InfoType info;								//�û������Ϣ�����Ժ��� 
}ArcCell;
typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1]; //�ڽӾ��� 

/* ͼ���������ʾ�����Ĵ洢��ʾ */
typedef char VertexType_M;				//ͼ���������� 
typedef struct
{
	VertexType_M vexs[MAX_VERTEX_NUM+1];//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum,	arcnum;					//ͼ����ĵ�ǰ�������ͻ���
	int IncInfo;						//IncInfoΪ0���������������Ϣ 
	GraphKind kind;						//ͼ����������־ 
}MGraph;

/* ȫ�ֱ��� */
Status visited[MAX_VERTEX_NUM+1];		//��־����
void (*VisitFunc)(VertexType_M e);		//����ָ����� 

/* ͼ���������ʾ���������б� */
Status CreateGraph_M(FILE *fp, MGraph *G);
/*����������������������������
��(01)�㷨7.1������ͼ���� ��
����������������������������*/

Status CreateDG_M(FILE *fp, MGraph *G);
/*������������������
��(02)��������ͼ����
������������������*/

Status CreateDN_M(FILE *fp, MGraph *G);
/*������������������
��(03)��������������
������������������*/ 

Status CreateUDG_M(FILE *fp, MGraph *G);
/*������������������
��(04)��������ͼ����
������������������*/

Status CreateUDN_M(FILE *fp, MGraph *G);
/*����������������������������
��(05)�㷨7.2�������������� ��
����������������������������*/

void ClearGraph_M(MGraph *G);
/*��������������������
��(06)���ͼ����������
��������������������*/

int LocateVex_M(MGraph G, VertexType_M u);
/*������������������������
��(07)Ѱ�Ҷ���u��λ�á� ��
������������������������*/

VertexType_M GetVex_M(MGraph G, int order);
/*��������������������������
��(08)���ص�v������ֵ�� ��
��������������������������*/

Status PutVex_M(MGraph *G, VertexType_M v, VertexType_M value);
/*������������������������
��(09)�Զ���v��ֵvalue����
������������������������*/

int FirstAdjVex_M(MGraph G, VertexType_M v);
/*����������������������������������
��(10)����v�ĵ�һ���ڽӶ�����š� ��
����������������������������������*/

int NextAdjVex_M(MGraph G, VertexType_M v, VertexType_M w);
/*����������������������������������������
��(11)����v�����w����һ���ڽӶ�����š���
����������������������������������������*/

Status InsertVex_M(MGraph *G, VertexType_M v);
/*����������������������
��(12)���붥��v��ͼ�� ��
����������������������*/

Status DeleteVex_M(MGraph *G, VertexType_M v);
/*������������������������
��(13)��ͼ��ɾ������v�� ��
������������������������*/

Status InsertArc_M(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...);
/*������������������������������������������������
��(14)���뻡<v,w>��ͼ,���������ϢInfoType��ѡ����
������������������������������������������������*/

Status DeleteArc_M(MGraph *G, VertexType_M v, VertexType_M w);
/*��������������������
��(15)ɾ����<v,w>�� ��
��������������������*/

void DFSTraverse_M(MGraph G, void(Visit)(VertexType_M));
/*������������������������������
��(16)�㷨7.4��������ȱ����� ��
������������������������������*/

void DFS_M(MGraph G, int v);
/*��������������������������������������
��(17)�㷨7.5��������ȱ������ĺ����� ��
��������������������������������������*/

void BFSTraverse_M(MGraph G, void(Visit)(VertexType_M));
/*������������������������������
��(18)�㷨7.6��������ȱ����� ��
������������������������������*/

void OutputMGraph(MGraph G);
/*��������������������
��(19)���ͼ��������
��������������������*/

void Input(FILE *fp, InfoType *info);
/*������������������������
��(20)¼�뻡�������Ϣ����
������������������������*/

#endif
