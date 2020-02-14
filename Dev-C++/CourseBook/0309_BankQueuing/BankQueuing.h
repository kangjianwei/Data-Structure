/*==================
 * 模拟银行排队
 *
 * 包含算法: 3.6、3.7
 ===================*/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include <stdlib.h>         // 提供malloc、realloc、free、exit原型
#include <time.h>           // 提供time原型
#include "Status.h"         //**▲01 绪论**//
#include "LinkList.h"       //**▲02 线性表**//
#include "LinkQueue.h"      //**▲03 栈和队列**//

/* 宏定义 */
#define N 4                 // 客户队列数量
#define SleepTime 1         // SleepTime代表休眠时间
#define DurationTime 20     // 办理业务持续时间从1到DurationTime分钟不等
#define IntervalTime  8     // 下一个客户到来时间间隔为1到IntervalTime分钟不等

/* 类型定义 */
typedef LinkList EventList;     //事件链表类型，定义为有序链表


/*
 * ████████ 算法3.6 ████████
 *
 * 银行业务模拟，统计一天内客户在银行逗留的平均时间
 */
void Bank_Simulation_1();

/*
 * ████████ 算法3.7 ████████
 *
 * 银行业务模拟，统计一天内客户在银行逗留的平均时间
 * 算法内容与3.7是类似的
 */
void Bank_Simulation_2();

/*
 * 银行开门，初始化运行环境
 */
void OpenForDay();

/*
 * 银行关门
 *
 * 释放资源，打印统计信息
 */
void CloseForDay();

/*
 * 判断事件表是否为空。
 * 即是否存在未处理的事件。
 */
Status MoreEvent();

/*
 * 将待处理事件从事件表中移除，并将该事件存储到全局变量gEn中。
 * event用来存储该事件的类型
 */
void EventDrived(char* event);

/*
 * 处理客户到达事件，gEn.NType=0
 */
void CustomerArrived();

/*
 * 处理客户离开事件，gEn.NType>0
 */
void CustomerDeparture();

/*
 * 代表遇到了无效的事件
 */
void Invalid();

/*
 * 将事件en插入到事件表ev中（ev是按发生时间从早到晚排列的事件表）
 * cmp用来比较两个事件发生的早晚，en会作为第二个实参传进去
 */
Status OrderInsert(EventList gEv, Event gEn, int(cmp)(Event, Event));

/*
 * 比较两事件发生次序
 */
int cmp(Event a, Event b);

/*
 * 生成随机数
 *
 * durtime  ：当前客服办理业务所需时间
 * intertime：下一客户到达间隔的时间
 */
void Random(int* durtime, int* intertime);

/*
 * 返回长度最短的队列的序号
 */
int Minimum();

/*
 * 显示所有客户队列的排队情况
 */
void Show();

#endif
