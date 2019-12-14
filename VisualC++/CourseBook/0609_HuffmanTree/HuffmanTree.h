/*====================
 * �շ�����
 *
 * �����㷨: 6.12��6.13
 ====================*/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩstrcpyԭ��
#include <limits.h>     // �ṩһЩ����ֵ�ĺ궨��
#include "Status.h"     //**��01 ����**//

/*
 * �������� ��ʾ ��������
 *
 * �շ�������������������
 */


/* �շ�������㶨�壬��һ��˫�״洢�ṹ */
typedef struct {
    unsigned int weight;    // Ȩֵ
    unsigned int parent;    // ˫��λ��
    unsigned int lchild;    // ����λ��
    unsigned int rchild;    // �Һ���λ��
} HTNode;

/*
 * �շ��������Ͷ���
 *
 *��ע��
 * 1.0�ŵ�Ԫ��weight��ָʾ�շ������Ľ������
 * 2.��洢�ռ�ᶯ̬����
 */
typedef HTNode* HuffmanTree;

/*
 * �շ������������Ͷ��壬�����˶���ַ��ĺշ�������
 *
 *��ע��
 * 1.0�ŵ�Ԫ�����õ�
 * 2.�洢�ռ���Ҫ��̬����
 */
typedef char** HuffmanCode;


/*
 * ��ʼ������
 *
 * ��Ҫ������ʼ��Ȩֵ��Ϣ��
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status InitEnvironment(int** w, int* n, char* path);

/*
 * ���������������� �㷨6.12 ����������������
 *
 * ����
 * 1.����ָ����n��Ȩֵ��Ϣw�������շ�����HT��
 * 2.�ɺշ�����HT�������շ�������ֵHC��
 *
 *��ע��
 * ���㷨�롾�㷨6.13������һ�¡�
 */
Status HuffmanCodeing_1(HuffmanTree* HT, HuffmanCode* HC, int* w, int n);

/*
 * ���������������� �㷨6.13 ����������������
 *
 * ����
 * 1.����ָ����n��Ȩֵ��Ϣw�������շ�����HT��
 * 2.��������շ�����HT����շ�������ֵHC��
 *
 *��ע��
 * ���㷨�롾�㷨6.12������һ�¡�
 */
Status HuffmanCodeing_2(HuffmanTree* HT, HuffmanCode* HC, int* w, int n);

/*
 * ����
 * ���ݸ�����n���շ�������HC������������Ȩֵ��
 */
Status HuffmanDecoding(HuffmanTree HT, HuffmanCode HC, int** w, int n);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ��ʼ���������ڲ�ʵ��
static Status Init(int** w, int* n, FILE* fp);

// �ںշ��������[1...end]������ѡ��Ȩֵ��С��δ�������������������s1��s2��
static void Select(HuffmanTree HT, int end, int* s1, int* s2);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ӡ�շ������ṹ��
void PrintHuffmanTree(HuffmanTree HT);

// ��ӡ�շ������롣
void PrintHuffmanCode(HuffmanTree HT, HuffmanCode HC);

// ��ӡ�շ��������Ӧ��Ȩֵ��Ϣ��
void PrintWeight(HuffmanCode HC, int *w, int n);

#endif
