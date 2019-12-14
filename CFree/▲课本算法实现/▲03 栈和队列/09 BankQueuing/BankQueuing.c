/****************************************
 *                                      *
 * 文件夹: ▲03 栈和队列\09 BankQueuing *
 *                                      *
 * 文件名: BankQueuing.c                *
 *                                      *
 * 算  法: 3.6、3.7                     * 
 *                                      *
 ****************************************/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h" 				//**▲03 栈和队列**//

/*════╗
║ 算法3.6║ 
╚════*/
void Bank_Simulation_1()				//银行业务模拟，统计一天内客户在银行逗留的平均时间 
{
	char eventType;
	
	OpenForDay();						//初始化

	while(MoreEvent())
	{
		EventDrived(&eventType);		//事件驱动
		
		switch(eventType)
		{
			case 'A': 
				CustomerArrived();
				break;
			case 'D': 
				CustomerDeparture();
				break;
			default : 
				Invalid();
		}
	}
	
	CloseForDay();
}
 
void OpenForDay() 
{	
	int i;
	
	gTotalTime = 0;					//初始化累计时间和客户数为0 
	gCustomerNum = 0;
			
	InitList_L(&gEv);				//初始化事件链表为空表

	gEn.OccurTime = 0;				//设定第一个客户到达事件 
	gEn.NType = Arrive;
	 
	OrderInsert(gEv, gEn, cmp);		//插入事件表
	
	for(i=1; i<=4; ++i) 
		InitQueue_L(&gQ[i]);		//置空队列

	Show();
}

Status MoreEvent()
{
	if(!ListEmpty_L(gEv))
		return TRUE;
	else
		return FALSE;
}

void EventDrived(char *event)
{
	ListDelete_L(gEv, 1, &gEn);
	
	if(gEn.NType==Arrive)
		*event = 'A';
	else
		*event = 'D';
}

void CustomerArrived()							//处理客户到达事件，gEn.NType=0 
{	
	int durtime, intertime; 
	int cur_LeftTime, suc_ArrivalTime;
	int i;
	
	++gCustomerNum;								//总客户数增一 
	
	Random(&durtime, &intertime);				//生成当前客户办理业务需要的时间和下一个客户达到时间间隔
	cur_LeftTime    = gEn.OccurTime + durtime;	//当前客户的离开时间 
	suc_ArrivalTime = gEn.OccurTime + intertime;//下一个客户到达时间 
			
	gCustomerRcd.ArrivedTime = gEn.OccurTime;	//记录当前客户信息 
	gCustomerRcd.Duration    = durtime;
	gCustomerRcd.Count       = gCustomerNum;

	i = Minimum(gQ);							//求长度最短队列
	EnQueue_L(&gQ[i], gCustomerRcd); 			//当前客户进入最短队列
	Show();
	
	if(suc_ArrivalTime<gCloseTime)				//银行尚未关门，将下一客户到达事件插入事件表
	{
		gEn.OccurTime = suc_ArrivalTime;		//gEn的参数已经改变 
		gEn.NType = Arrive;
		OrderInsert(gEv, gEn, cmp);
	}

	if(QueueLength_L(gQ[i])==1)					//设定第i队列的队头客户的离开事件并插入事件表
	{
		gEn.OccurTime = cur_LeftTime;
		gEn.NType = i;		
		OrderInsert(gEv, gEn, cmp);					
	}
}

void CustomerDeparture()						//处理客户离开事件,gEn.NType>0
{
	int i = gEn.NType;
	
	DeQueue_L(&gQ[i], &gCustomerRcd);			//删除第i队列的排头客户
	Show();
		
	gTotalTime += gEn.OccurTime - gCustomerRcd.ArrivedTime;	//累计客户逗留时间
	
	if(!QueueEmpty_L(gQ[i]))					//设定第i队列的第一个离开事件并插入事件表 
	{
		GetHead_L(gQ[i], &gCustomerRcd);
		gEn.OccurTime += gCustomerRcd.Duration;
		gEn.NType = i;
		OrderInsert(gEv,gEn,cmp);
	} 
}

void Invalid()
{
	printf("运行错误！");
		exit(OVERFLOW);
}

void CloseForDay()
{
	printf("当天总共有%d个客户，平均逗留时间为%d分钟。\n",gCustomerNum,gTotalTime/gCustomerNum);
}

int cmp(Event a, Event b)					//比较两事件发生次序 
{
	if(a.OccurTime<b.OccurTime)				//a晚于b发生 
		return -1;
	if(a.OccurTime==b.OccurTime)			//a、b同时发生 
		return 0;
	if(a.OccurTime>b.OccurTime)				//a早于b发生 
		return 1;
}

void Random(int *durtime, int *intertime)
{
	srand((unsigned)time(NULL));
	*durtime = rand()%DurationTime+1;		//办业务时间持续1到20分钟
	*intertime = rand()%IntervalTime+1; 	//下一个顾客来的时间为间隔1到10分钟 
}

Status OrderInsert(EventList gEv, Event gEn, int (cmp)(Event,Event))
{
	int i;
	EventList p, pre, s;
	
	pre = gEv;
	p = gEv->next;							//p指向第一个事件 
	
	while(p && cmp(gEn, p->data)==1)		//查找gEn在事件表中应该插入的位置
	{
		pre = p;
		p = p->next;
	}
	
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	
	s->data = gEn;							//将gEn插入事件表
	s->next = pre->next;
	pre->next = s;
	
	return OK;
}

int Minimum()
{
	int i1 = QueueLength_L(gQ[1]);
	int i2 = QueueLength_L(gQ[2]);
	int i3 = QueueLength_L(gQ[3]);
	int i4 = QueueLength_L(gQ[4]);
	
	if(i1<=i2 && i1<=i3 && i1<=i4)
		return 1;
	if(i2<i1  && i2<=i3 && i2<=i4)
		return 2;
	if(i3<i1  && i3<i2  && i3<=i4)
		return 3;
	if(i4<i1  && i4<i2  && i4<i3 )
		return 4;
}

void Show()
{
	int i;
	QueuePtr p;								//记录到来的客户是第几个 
	
	system("cls");
	
	for(i=1; i<=4; i++)
	{
		for(p=gQ[i].front; p; p=p->next)
		{
			if(p==gQ[i].front)
			{
				if(i==1)
					printf("柜台①●");
				if(i==2)
					printf("柜台②●");
				if(i==3)
					printf("柜台③●");
				if(i==4)
					printf("柜台④●");
			}
			else
				printf("（%03d）",p->data.Count);			

	
			if(p==gQ[i].rear)
				printf("\n"); 
		}
	}
	
	Wait(SleepTime);
}

/*════╗
║ 算法3.7║ 
╚════*/
void Bank_Simulation_2()
{
	OpenForDay();							//初始化
	
	while(!ListEmpty_L(gEv))
	{
		ListDelete_L(gEv, 1, &gEn);
		
		if(gEn.NType==Arrive)
			CustomerArrived();				//处理客户到达事件 
		else
			CustomerDeparture();			//处理客户离开事件 
	}
	
	printf("当天总共有%d个客户，平均逗留时间为%d分钟。\n",gCustomerNum,gTotalTime/gCustomerNum);//计算平均逗留时间	
}

#endif
