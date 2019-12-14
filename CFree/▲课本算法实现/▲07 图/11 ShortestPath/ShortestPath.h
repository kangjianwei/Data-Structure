/***********************************
 *						           *
 * �ļ���: ��07 ͼ\11 ShortestPath *
 * 						           *
 * �ļ���: ShortestPath.h          *
 *                                 *
 * ��  ��: ���·����ز����б�    *
 *                                 *
 ***********************************/

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <stdio.h>
#include "../../��01 ����/Status.h"							//**��01 ����**//
#include "../01 MGraph/MGraph.c" 							//**��07 ͼ**//

/* ���·�����Ͷ��� */
typedef int PathMatrix;
typedef int ShortPathTable;

/* ���·�������б� */
void ShortestPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[]);
/*������������������������������������������������������������������������������������������
��(01)�㷨7.15����Dijkstra�㷨������ͼG��v0���㵽���ඥ��v�����·��P[v]�����Ȩ����D[v]����
������������������������������������������������������������������������������������������*/

void OutputPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[]);
/*������������������������������������������
��(02)�����Dijkstra�㷨���������ͼ·������
������������������������������������������*/

void Dijkstra(MGraph G1, int v0, PathMatrix path1[], ShortPathTable dist1[]);
/*������������������������������������������������������������
��(03)��һ��д�������㲢�����Dijkstra�㷨���������ͼ·������
������������������������������������������������������������*/

void ShortestPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1]);
/*��������������������������������������������������������������������������������������������
��(04)�㷨7.16����Floyd�㷨������ͼG�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]����
��������������������������������������������������������������������������������������������*/

void OutputPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1]);
/*����������������������������������������
��(05)�����Floyd�㷨���������ͼ·���� ��
����������������������������������������*/

void Floyd(MGraph G2, PathMatrix path2[][MAX_VERTEX_NUM+1], ShortPathTable dist2[][MAX_VERTEX_NUM+1]);
/*����������������������������������������������������������
��(06)��һ��д�������㲢�����Floyd�㷨���������ͼ·���� ��
����������������������������������������������������������*/

#endif
