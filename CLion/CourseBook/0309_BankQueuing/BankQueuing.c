/*==================
 * 模拟银行排队
 *
 * 包含算法: 3.6、3.7
 ===================*/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h"                //**▲03 栈和队列**//

/* 全局变量（变量名称前面都加了g标记） */
int gTotalTime;     // 累计客户数
int gCustomerNum;   // 累计客户逗留时间

int gCloseTime;     // 关门时间,假设银行每天营业8小时，480分

EventList gEv;      // 事件表，存储所有待处理事件
Event     gEn;      // 当前正在处理的事件

LinkQueue gQ[N+1];  // 4个客户队列,0号单元弃用


/*
 * ████████ 算法3.6 ████████
 *
 * 银行业务模拟，统计一天内客户在银行逗留的平均时间
 */
void Bank_Simulation_1() {
    char eventType;
    
    OpenForDay();                       // 银行开门
    
    // 如果事件表不为空
    while(MoreEvent()) {
        EventDrived(&eventType);        // 事件驱动
        
        switch(eventType) {
            case 'A':
                CustomerArrived();      // 处理客户到达事件
                break;
            case 'D':
                CustomerDeparture();    // 处理客户离开事件
                break;
            default :
                Invalid();
        }
    }
    
    CloseForDay();
}

/*
 * ████████ 算法3.7 ████████
 *
 * 银行业务模拟，统计一天内客户在银行逗留的平均时间
 * 算法内容与3.7是类似的
 */
void Bank_Simulation_2() {
    OpenForDay();                       // 银行开门
    
    while(!ListEmpty(gEv)) {
        ListDelete(gEv, 1, &gEn);
        
        if(gEn.NType == Arrive) {
            CustomerArrived();          // 处理客户到达事件
        } else {
            CustomerDeparture();        // 处理客户离开事件
        }
    }
    
    CloseForDay();                      // 银行关门
}

/*
 * 银行开门，初始化运行环境
 */
void OpenForDay() {
    int i;
    
    // 关门时间,假设银行每天营业8小时，480分
    gCloseTime = 480;
    
    // 初始化累计时间和客户数为0
    gTotalTime = 0;
    gCustomerNum = 0;
    
    // 初始化事件链表为空表
    InitList(&gEv);
    
    // 设定第一个客户到达事件
    gEn.OccurTime = 0;
    gEn.NType = Arrive;
    
    // 插入事件表
    OrderInsert(gEv, gEn, cmp);
    
    // 初始化4个空队列
    for(i = 1; i <= N; ++i) {
        InitQueue(&gQ[i]);
    }
    
    Show();
}

/*
 * 银行关门
 *
 * 释放资源，打印统计信息
 */
void CloseForDay() {
    printf("当天总共有%d个客户，平均逗留时间为%d分钟。\n", gCustomerNum, gTotalTime / gCustomerNum);
}

/*
 * 判断事件表是否为空。
 * 即是否存在未处理的事件。
 */
Status MoreEvent() {
    return !ListEmpty(gEv);
}

/*
 * 将待处理事件从事件表中移除，并将该事件存储到全局变量gEn中。
 * event用来存储该事件的类型
 */
void EventDrived(char* eventType) {
    // 从事件表中获取待处理事件
    ListDelete(gEv, 1, &gEn);
    
    // 识别事件类型
    if(gEn.NType == Arrive) {
        *eventType = 'A';
    } else {
        *eventType = 'D';
    }
}

/*
 * 处理客户到达事件，gEn.NType=0
 */
void CustomerArrived() {
    Event en;               // 事件
    QElemType customer;     // 客户记录
    
    int durtime;    // 当前客户办理业务需要的时间
    
    int intertime;  // 下一个客户达到时间间隔
    int t;          // 下一个客户到达时间
    
    int i;          // 队列编号
    
    // 总客户数增一
    ++gCustomerNum;
    
    // 生成当前客户办理业务需要的时间和下一个客户达到时间间隔
    Random(&durtime, &intertime);
    
    // 下一个客户到达时间
    t = gEn.OccurTime + intertime;
    
    // 如果银行尚未关门，将下一客户"到达"事件插入事件表
    if(t < gCloseTime) {
        en.OccurTime = t;   // 下一客户的到达时间
        en.NType = Arrive;  // "到达"事件类型
        OrderInsert(gEv, en, cmp);  // "到达"事件插入事件表
    }
    
    // 获取当前长度最短的队列编号
    i = Minimum(gQ);
    
    // 记录当前客户信息
    customer.ArrivedTime = gEn.OccurTime;   // 到达时间
    customer.Duration = durtime;            // 办理业务所需时间
    customer.Count = gCustomerNum;          // 客户编号
    
    // 当前客户进入最短队列排队
    EnQueue(&gQ[i], customer);
    printf("第%3d个客户到柜台 %d 中排队...\n", customer.Count, i);
    Show();
    
    /*
     * 如果当前队列中只有这一个客户排队，则需要计算其离开时间，
     * 并构造一个"离开"事件插入到事件表中
     */
    if(QueueLength(gQ[i]) == 1) {
        en.OccurTime = gEn.OccurTime + durtime; // 当前客户的离开时间
        en.NType     = i;                       // "离开"事件类型，值为1-4，指示从第几个队列中离开
        OrderInsert(gEv, en, cmp);  // "离开"事件插入事件表
    }
}

/*
 * 处理客户离开事件，gEn.NType>0
 */
void CustomerDeparture() {
    Event en;               // 事件
    QElemType customer;     // 客户记录
    int i = gEn.NType;      // 队列编号
    
    // 第i个队列的队头客户完成业务并出队
    DeQueue(&gQ[i], &customer);
    printf("第%3d个客户从柜台 %d 中离开...\n", customer.Count, i);
    Show();
    
    // 累计客户逗留时间
    gTotalTime += gEn.OccurTime - customer.ArrivedTime;
    
    /*
     * 如果当前队列中仍然存在排队的客户，则需要计算该队列中队头客户的离开时间
     * 注：之所以在这里计算，是因为只有上一个客户离开了，下一个客户的离开时间才会有意义
     */
    if(!QueueEmpty(gQ[i])) {
        // 获取队头客户
        GetHead(gQ[i], &customer);
        en.OccurTime = gEn.OccurTime + customer.Duration;   // "离开"事件发生的时间
        en.NType     = i;                                   // "离开"事件类型
        OrderInsert(gEv, en, cmp);  // "离开"事件插入事件表
    }
}

/*
 * 代表遇到了无效的事件
 */
void Invalid() {
    printf("运行错误！");
    exit(OVERFLOW);
}

/*
 * 将事件en插入到事件表ev中（ev是按发生时间从早到晚排列的事件表）
 * cmp用来比较两个事件发生的早晚，en会作为第二个实参传进去
 */
Status OrderInsert(EventList ev, Event en, int(cmp)(Event, Event)) {
    EventList p, pre, s;
    
    if(ev == NULL) {
        return ERROR;
    }
    
    for(pre = ev; pre->next != NULL && cmp(pre->next->data, en) < 0; pre = pre->next) {
        // 查找
    }
    
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = en;
    
    s->next = pre->next;
    pre->next = s;
    
    return OK;
}

/*
 * 比较两事件发生次序
 */
int cmp(Event a, Event b) {
    if(a.OccurTime < b.OccurTime) {
        return -1;      // a发生比较早
    } else if(a.OccurTime > b.OccurTime) {
        return 1;       // a发生比较晚
    } else {
        return 0;       // 同时发生
    }
}

/*
 * 生成随机数
 *
 * durtime  ：当前客服办理业务所需时间
 * intertime：下一客户到达间隔的时间
 */
void Random(int* durtime, int* intertime) {
    srand((unsigned) time(NULL));
    *durtime = rand() % DurationTime + 1;       // 办业务时间持续1到20分钟
    *intertime = rand() % IntervalTime + 1;     // 下一个顾客到来的时间为间隔1到10分钟
}

/*
 * 返回长度最短的队列的序号
 */
int Minimum() {
    int i1 = QueueLength(gQ[1]);
    int i2 = QueueLength(gQ[2]);
    int i3 = QueueLength(gQ[3]);
    int i4 = QueueLength(gQ[4]);
    
    if(i1 <= i2 && i1 <= i3 && i1 <= i4) {
        return 1;
    }
    
    if(i2 < i1 && i2 <= i3 && i2 <= i4) {
        return 2;
    }
    
    if(i3 < i1 && i3 < i2 && i3 <= i4) {
        return 3;
    }
    
    if(i4 < i1 && i4 < i2 && i4 < i3) {
        return 4;
    }
    
    return 0;
}

/*
 * 显示所有客户队列的排队情况
 */
void Show() {
    int i;
    QueuePtr p;     // 记录到来的客户是第几个
    
    // 遍历所有客户队列
    for(i = 1; i <= N; i++) {
        for(p = gQ[i].front; p; p = p->next) {
            if(p == gQ[i].front) {
                if(i == 1) {
                    printf("柜台⑴●");
                }
                if(i == 2) {
                    printf("柜台⑵●");
                }
                if(i == 3) {
                    printf("柜台⑶●");
                }
                if(i == 4) {
                    printf("柜台⑷●");
                }
            } else {
                printf("（%03d）", p->data.Count);
            }
            
            
            if(p == gQ[i].rear) {
                printf("\n");
            }
        }
    }
    
    printf("\n");
    
    Wait(SleepTime);
}

#endif
