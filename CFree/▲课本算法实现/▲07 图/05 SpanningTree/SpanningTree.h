/************************************
 *                                  *
 * �ļ���: ��07 ͼ\05 SpanningTree  *
 *                                  *
 * �ļ���: SpanningTree.h           *
 *                                  *
 * ��  ��: ����ͼ��������ز����б� *
 *                                  *
 ************************************/
 
#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include <stdlib.h>											//�ṩmalloc��realloc��free��exitԭ��
#include "../01 MGraph/MGraph.c"										//**��07 ͼ**//
#include "../../��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c"	//**��06 ���Ͷ�����**//

/* ����ͼ�����������б� */
void DFSForest(MGraph G, CSTree *T);
/*������������������������������������������
��(01)�㷨7.7����������ͼ����������ɭ�֣� ��
������������������������������������������*/

void DFSTree(MGraph G, int v, CSTree *T);
/*����������������������������������������
��(02)�㷨7.8�����ɽ��v��ʼ������ɭ�֣���
����������������������������������������*/

#endif
