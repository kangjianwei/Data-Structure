/*==============
 * �Թ�Ѱ·����
 *
 * �����㷨: 3.3
 ===============*/

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>         // �ṩsystem��rand��srandԭ��
#include <time.h>           // �ṩtimeԭ��
#include "Status.h"         //**��01 ����**//
#include "SqStack.h"        //**��03 ջ�Ͷ���**//

/* �궨�� */
#define M 15    // �Թ�������
#define N 15    // �Թ�������

#define X 4     // Xָʾ�Թ��ϰ����ֵĸ��ʡ����磬X=4����ζ�ű����Թ�ʱ�����ϰ��ĸ�����1/4=25%

#define SleepTime 3     //SleepTime�����ӡ��ͼʱ��ʱ����

/* �Թ����Ͷ��� */
typedef enum {
    Wall,                       // ��ǽ
    Obstacle,                   // �Թ��ڲ����ϰ�
    Way,                        // ͨ·
    Impasse,                    // ������ͬ��
    East, South, West, North    // ��ǰ̽�����򣺶�������
} MazeNode;

typedef int MazeType[M][N];      // �Թ�����


/*
 * ���������������� �㷨3.3 ����������������
 *
 * �Թ�Ѱ·
 *
 * ʹ����ٷ����ҵ�һ������ͨ·������
 */
Status MazePath(MazeType maze, PosType start, PosType end);

/*
 * ��ʼ��һ����ģΪN��N�Թ�
 * start��end�ֱ�Ϊ�Թ����������ͳ�������
 *
 *��ע��
 * �̲����޴˲��������ò����Ǳ�����ڵ�
 */
void InitMaze(MazeType maze, PosType* start, PosType* end);

/*
 * �жϵ�ǰλ���Ƿ��ͨ����Ҫ���λ���Ǵ�δ��̽����ͨ����
 *
 *��ע��
 * �����Ϊ�жϵ�ǰλ���Ƿ�Ϊ�״�̽��
 */
Status Pass(MazeType maze, PosType seat);

/*
 * ��ȡ��һ��Ӧ��̽����λ��
 * diָʾ��ǰ����λ�õ�̽�����򣬰���East, South, West, North
 */
PosType NextPos(PosType seat, int di);

/*
 * ���³�ʼ�����㼣
 *
 * ��ʼ�����㼣���򶫷���
 */
void FootPrint(MazeType maze, PosType seat);

/*
 * ���Թ���seat������mark���
 *
 *��ע��
 * �ú�����̲��ϵĺ���������
 * �̲���ֻ���ô˺�������"����̽��"�ı��
 * ���˴��ĺ����Ľ�Ϊ�������������ǣ�����̽������ı��
 */
void MarkPrint(MazeType maze, PosType seat, int mark);

/*
 * ����һ��ͨ������Ϣ������
 *
 *��ע��
 * �̲����д˲��������޴˺���
 */
SElemType Construct(int ord, PosType seat, int di);

/*
 * �ж����������Ƿ����
 *
 *��ע��
 * �̲����д˲��������޴˺���
 * ��Ϊ������Ҫ�Ƚ������ṹ�壬���Բ���ֱ����"=="����
 */
Status Equals(PosType a, PosType b);

/*
 * �����Թ�
 * ��ͼ�εķ�ʽ�����Թ���ǰ��״̬
 *
 *��ע��
 * �̲����޴˲���
 * �˴����Ӹò�����Ŀ���ǹ۲�Ѱ·���̵�ÿһ��
 */
void PaintMaze(MazeType maze);

#endif
