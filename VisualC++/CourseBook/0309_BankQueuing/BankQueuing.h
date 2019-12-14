/*==================
 * ģ�������Ŷ�
 *
 * �����㷨: 3.6��3.7
 ===================*/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include <stdlib.h>         // �ṩmalloc��realloc��free��exitԭ��
#include <time.h>           // �ṩtimeԭ��
#include "Status.h"         //**��01 ����**//
#include "LinkList.h"       //**��02 ���Ա�**//
#include "LinkQueue.h"      //**��03 ջ�Ͷ���**//

/* �궨�� */
#define N 4                 // �ͻ���������
#define SleepTime 1         // SleepTime��������ʱ��
#define DurationTime 20     // ����ҵ�����ʱ���1��DurationTime���Ӳ���
#define IntervalTime  8     // ��һ���ͻ�����ʱ����Ϊ1��IntervalTime���Ӳ���

/* ���Ͷ��� */
typedef LinkList EventList;     //�¼��������ͣ�����Ϊ��������

/* ȫ�ֱ�������������ǰ�涼����g��ǣ� */
int gTotalTime;     // �ۼƿͻ���
int gCustomerNum;   // �ۼƿͻ�����ʱ��

int gCloseTime;     // ����ʱ��,��������ÿ��Ӫҵ8Сʱ��480��

EventList gEv;      // �¼����洢���д������¼�
Event     gEn;      // ��ǰ���ڴ�����¼�

LinkQueue gQ[N+1];  // 4���ͻ�����,0�ŵ�Ԫ����


/*
 * ���������������� �㷨3.6 ����������������
 *
 * ����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ��
 */
void Bank_Simulation_1();

/*
 * ���������������� �㷨3.7 ����������������
 *
 * ����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ��
 * �㷨������3.7�����Ƶ�
 */
void Bank_Simulation_2();

/*
 * ���п��ţ���ʼ�����л���
 */
void OpenForDay();

/*
 * ���й���
 *
 * �ͷ���Դ����ӡͳ����Ϣ
 */
void CloseForDay();

/*
 * �ж��¼����Ƿ�Ϊ�ա�
 * ���Ƿ����δ������¼���
 */
Status MoreEvent();

/*
 * ���������¼����¼������Ƴ����������¼��洢��ȫ�ֱ���gEn�С�
 * event�����洢���¼�������
 */
void EventDrived(char* event);

/*
 * ����ͻ������¼���gEn.NType=0
 */
void CustomerArrived();

/*
 * ����ͻ��뿪�¼���gEn.NType>0
 */
void CustomerDeparture();

/*
 * ������������Ч���¼�
 */
void Invalid();

/*
 * ���¼�en���뵽�¼���ev�У�ev�ǰ�����ʱ����絽�����е��¼���
 * cmp�����Ƚ������¼�����������en����Ϊ�ڶ���ʵ�δ���ȥ
 */
Status OrderInsert(EventList gEv, Event gEn, int(cmp)(Event, Event));

/*
 * �Ƚ����¼���������
 */
int cmp(Event a, Event b);

/*
 * ���������
 *
 * durtime  ����ǰ�ͷ�����ҵ������ʱ��
 * intertime����һ�ͻ���������ʱ��
 */
void Random(int* durtime, int* intertime);

/*
 * ���س�����̵Ķ��е����
 */
int Minimum();

/*
 * ��ʾ���пͻ����е��Ŷ����
 */
void Show();

#endif
