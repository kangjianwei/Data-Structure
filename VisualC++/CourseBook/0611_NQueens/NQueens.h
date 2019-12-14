/*==============
 * N�ʺ�����
 *
 * �����㷨: 6.16
 ===============*/

#ifndef NQUEENS_H
#define NQUEENS_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp��abs ԭ��
#include "Status.h"     //**��01 ����**//

/* �������ΧN*N����ֵ����>=4 */
#define N 8

/* �������Ͷ��� */
typedef int ChessBoard;

/* ȫ�ֱ��� */
int order;          // ����ÿһ�ֽⷨ
ChessBoard** CB;    // ����

/*
 * ��ʼ��N*N��ģ������CB��
 *
 *��ע��
 * 0�ŵ�Ԫ������
 */
void InitChessBoard();

/*
 * ���������������� �㷨6.16 ����������������
 *
 * ��ָ����С���������N�ʺ�����ĸ��⡣
 */
void Trial(int i, int n);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

/*
 * �ж���x��y�з������Ӻ����̲����Ƿ����
 */
static Status AllowLayout(int i, int j);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

/*
 * չʾ�����еĻʺ󲼾֡�
 */
void ShowChessBoard();

#endif
