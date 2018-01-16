#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/07 LinkQueue/LinkQueue.c"  //**▲03 栈和队列**//

/* 函数原型 */
void Algo_3_34(char *En, char Con[]);
Status EnQueue_3_34(LinkQueue *Q, QElemType_L e, int di);
Status Dispatch_3_34(char *En, char Ex[], char Con[]);

int main(int argc, char *argv[])
{
	char *En = "HPSHHSHPPHHSPSHSPSSHSP"; 
	char Ex[100], Con[100];

	printf("假设入口在左边←，出口在右边→..\n");
	printf("调度前入口处的车厢排列为（P代表硬座席，S代表软卧，H代表硬卧）：\nEn（从右到左） = ");
	printf("%s\n", En);
	printf("\n");
	
	printf("生成调度序列...\n");
	Algo_3_34(En, Con);
	printf("调度序列为（E代表队头入队，A代表队尾入队，D代表队头出队）：\nCon = ");
	printf("%s\n", Con);
	printf("\n");	

	printf("根据调度序列进行车厢调度...\n");
	Dispatch_3_34(En, Ex, Con);
	printf("调度完成后出口出的车厢排列为：\nEx（从右到左） = ");
	printf("%s\n", Ex);
	printf("\n");

	return 0;
}

/*━━━━━━━━━━━━┓
┃题3.34：生成车厢调度序列┃
┗━━━━━━━━━━━━*/
/* 假设入口在左边，出口在右边，车厢读取顺序从右到左 */
void Algo_3_34(char *En, char Con[])
{
	int i, j; 
	LinkQueue Q; 
	QElemType_L e;
		
	InitQueue_L(&Q);						//初始化一个字符队列 
	i = j = 0;
	
	while(En[i])
	{
		if(En[i]=='P')						//硬座直接开到合适的位置 
		{
			Con[j++] = 'L';					//L代表从入口直接开到出口 
		}
		
		if(En[i]=='S')						//软卧从队头入队 
		{
			EnQueue_3_34(&Q, En[i], 0);
			Con[j++] = 'E';
		}	
		
		if(En[i]=='H')						//硬卧从队尾入队
		{
			EnQueue_3_34(&Q, En[i], 1);
			Con[j++] = 'A';
		}
				
		i++;
	}
	
	while(!QueueEmpty_L(Q))					//将队列中中软卧和硬卧出队 
	{
		DeQueue_L(&Q, &e);;
		Con[j++] = 'D';
	}
	
	Con[j] = '\0';
}

/* 输出受限的队列入队算法*/ 
Status EnQueue_3_34(LinkQueue *Q, QElemType_L e, int di)	//di代表入队方向 
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));					//队列满则无法入队 
	if(!p)
		exit(OVERFLOW);
	
	p->data = e;
	
	if(di==0)												//di=0从队头入队
	{
		p->next = (*Q).front->next;
		(*Q).front->next = p;
	}
	
	if(di==1) 												//di=1从队尾入队
	{
		p->next = (*Q).rear->next;
		(*Q).rear->next = p;
		(*Q).rear = p;
	}
	
	return OK;	 
} 

/* 将入口的车厢调度到出口 */ 
Status Dispatch_3_34(char *En, char Ex[], char Con[])
{
	int i, j, k;
	LinkQueue Q; 
	QElemType_L e;
		
	InitQueue_L(&Q);						//初始化一个字符队列 	
	i = j = k = 0;

	while(Con[k])
	{
		if(Con[k]=='L')						//硬座从入口直接开到出口 
			Ex[j++] = En[i++];
		
		if(Con[k]=='E')						//软卧从队头入队 
			EnQueue_3_34(&Q, En[i++], 0);
		
		if(Con[k]=='A')
			EnQueue_3_34(&Q, En[i++], 1);
			
		if(Con[k]=='D')
		{
			DeQueue_L(&Q, &e);
			Ex[j++] = e;		
		}
		
		k++;
	}
	
	if(!Con[k] && (En[i] || QueueEmpty_L(Q)))
		return ERROR;
	
	Ex[j] = '\0';
	
	return OK;
}
