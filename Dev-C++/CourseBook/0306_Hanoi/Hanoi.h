/*==============
 * ��ŵ��
 *
 * �����㷨: 3.5
 ===============*/

#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define N 5         // ��ŵ������������

// ��ŵ��ͼ����Ϣ
typedef struct {
    int** plates;   // ��ŵ���е�Բ����Ϣ
    int high[3];    // �������ĸ߶ȣ����е�����������
} Tower;

// ��ŵ��
static Tower T;

// ͳ���ƶ�����
static int gStep;


/*
 * ���������������� �㷨3.5 ����������������
 *
 * ��ŵ����⣺��y��Ϊ��������x����ǰn��Բ���ƶ���z��
 */
void hanoi(int n, char x, char y, char z);

/*
 * �ƶ���ŵ��Բ�̣�����n��Բ�̴�x���Ƶ�z����
 */
void move(char x, int n, char z);

/*
 * ��ŵ��ͼ����Ϣ��ʼ��
 *
 *��ע��
 * �̲����޴˲�����
 * ���Ӵ˲�����Ŀ����Ϊ�˱��ڹ۲캺ŵ��Բ�̵��ƶ�����
 */
void init(int n);

/*
 * ��ŵ���ƶ���ͼ�α�ʾ����������μ�move()����
 *
 *��ע��
 * �̲����޴˲�����
 * ���Ӵ˲�����Ŀ����Ϊ�˱��ڹ۲캺ŵ��Բ�̵��ƶ�����
 */
void PrintGraph(char x, int n, char z);

#endif
