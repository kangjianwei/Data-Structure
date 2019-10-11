/****************************************
 *                                      *
 * 文件夹: ▲03 栈和队列\09 BankQueuing *
 *                                      *
 * 文件名: BankQueuing.h                *
 *                                      *
 * 内  容: 模拟银行排队相关操作列表     *
 *                                      *
 ****************************************/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include <time.h>						//提供time原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 宏定义 */
#define SleepTime 1						//SleepTime代表休眠时间
#define DurationTime 20					//办理业务持续时间从1到DurationTime分钟不等 
#define IntervalTime 10					//下一个客户到来时间间隔为1到IntervalTime分钟不等 

/* 类型定义 */
typedef enum
{
	Arrive,Leave_1,Leave_2,Leave_3,Leave_4
}EventType;								//事件类型，0代表到达事件，1至4表示四个窗口的离开事件
typedef struct         					//事件链表                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
{
	int OccurTime;						//事件发生时刻
	EventType NType;					//事件类型
}Event;
typedef Event LElemType_L;				//事件链表元素 
typedef struct LNode
{
	LElemType_L data;
	struct LNode *next;
}LNode; 
typedef LNode* LinkList;
typedef LinkList EventList;											//事件链表类型，定义为有序链表
#include "../../▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//
typedef struct
{
	int ArrivedTime;					//客户到达时间
	int Duration;						//办理事务所需的时间
	int Count;							//此变量记录来到每个队列的客户是第几个
}QElemType_L;							//队列的数据元素类型 
#include "../07 LinkQueue/LinkQueue.c"	//**▲03 栈和队列**//

/* 全局变量 */
int gTotalTime, gCustomerNum;			//累计客户逗留时间，客户数
int gCloseTime = 480;					//关门时间,假设银行每天营业8小时，480分 
EventList gEv;							//事件表
Event gEn;								//事件
LinkQueue gQ[5];						//4个客户队列,0号单元弃用
QElemType_L gCustomerRcd;				//客户记录 
 
/* 模拟银行排队函数列表 */
void Bank_Simulation_1();
/*━━━━━━━━━━━━━━━━┓
┃(01)算法3.6：模拟银行排队事件。 ┃
┗━━━━━━━━━━━━━━━━*/

void OpenForDay();
/*━━━━━━━━━━━━━━┓
┃(02)银行开门，初始化各变量。┃
┗━━━━━━━━━━━━━━*/

Status MoreEvent();
/*━━━━━━━━━━━━┓
┃(03)判断事件表是否为空。┃
┗━━━━━━━━━━━━*/

void EventDrived(char *event);
/*━━━━━━━━━━━━━━━━┓
┃(04)事件驱动，获取当前事件类型。┃
┗━━━━━━━━━━━━━━━━*/

void CustomerArrived();
/*━━━━━━━━━━━┓
┃(05)处理客户到达事件。┃
┗━━━━━━━━━━━*/

void CustomerDeparture();
/*━━━━━━━━━━━┓
┃(06)处理客户离开事件。┃
┗━━━━━━━━━━━*/

void Invalid();
/*━━━━━━━━━┓
┃(07)事件类型错误。┃
┗━━━━━━━━━*/

void CloseForDay();
/*━━━━━━━┓
┃(08)银行关门。┃
┗━━━━━━━*/

int cmp(Event a, Event b);
/*━━━━━━━━━━━━━━━━┓
┃(09)比较事件a和b发生的先后次序。┃
┗━━━━━━━━━━━━━━━━*/

void Random(int *durtime, int *intertime);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)生成随机数，包括当前客服办理业务所需时间和下一客户到达间隔的时间。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status OrderInsert(EventList gEv, Event gEn, int(cmp)(Event,Event));
/*━━━━━━━━━━━━━━━┓
┃(11)将事件插入事件表正确位置。┃
┗━━━━━━━━━━━━━━━*/

int Minimum();
/*━━━━━━━━━━━━━┓
┃(12)求长度最短队列的序号。┃
┗━━━━━━━━━━━━━*/

void Show();
/*━━━━━━━━━━━━━━━━┓
┃(13)显示当前队列的客户排队情况。┃
┗━━━━━━━━━━━━━━━━*/

void Bank_Simulation_2();
/*━━━━━━━━━━━━━━━━┓
┃(14)算法3.7：模拟银行排队事件。 ┃
┗━━━━━━━━━━━━━━━━*/

#endif
