#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
void Algo_3_16(char *En, char Con[]);
Status Dispatch_3_16(char *En, char Ex[], char Con[]);

int main(int argc, char *argv[])
{
	char *En = "HSHHSHHHSSHSSSHS"; 
	char Ex[100], Con[100];
	
	printf("假设入口在右边→，出口在左边←..\n");
	printf("调度前入口处的车厢排列为（H代表硬席，S代表软席）：\nEn（从左到右） = ");
	printf("%s\n", En);
	printf("\n");
	
	printf("生成调度序列...\n");
	Algo_3_16(En, Con);
	printf("调度序列为（I代表入栈，O代表出栈）：\nCon = ");
	printf("%s\n", Con);
	printf("\n");	

	printf("根据调度序列进行车厢调度...\n");
	Dispatch_3_16(En, Ex, Con);
	printf("调度完成后出口出的车厢排列为：\nEx（从左到右） = ");
	printf("%s\n", Ex);
	printf("\n");

	return 0;
}

/*━━━━━━━━━━━━┓
┃题3.16：生成车厢调度序列┃
┗━━━━━━━━━━━━*/
/* 假设入口在右边，出口在左边，车厢读取顺序从左到右 */
void Algo_3_16(char *En, char Con[])		//En存储车厢序列，Con存储调度序列 
{
	int i, j; 
	SqStack S; 
	SElemType_Sq e;
		
	InitStack_Sq(&S);						//初始化一个字符栈 
	i = j = 0;
	
	while(En[i])
	{
		if(En[i]=='H')						//硬席先入栈 
		{
			Push_Sq(&S, En[i]);
			Con[j++] = 'I';
		}
		
		if(En[i]=='S')						//软席入栈出栈，用栈做中转 
		{
			Push_Sq(&S, En[i]);
			Pop_Sq(&S, &e);
			Con[j++] = 'I';
			Con[j++] = 'O';
		}	
		
		i++;
	}
	
	while(!StackEmpty_Sq(S))				//将栈中硬席出栈 
	{
		Pop_Sq(&S, &e);
		Con[j++] = 'O';
	}
	
	Con[j] = '\0';
}

/* 将入口的车厢调度到出口 */ 
Status Dispatch_3_16(char *En, char Ex[], char Con[])
{
	int i, j, k;
	SqStack S; 
	SElemType_Sq e;
		
	InitStack_Sq(&S);						//初始化一个字符栈 
	
	i = j = k = 0;

	while(Con[k])
	{
		if(Con[k]=='I')
			Push_Sq(&S, En[i++]);
		
		if(Con[k]=='O')
		{
			Pop_Sq(&S, &e);
			Ex[j++] = e;
		}
		
		k++;
	}
	
	if(!Con[k] && (En[i] || StackEmpty_Sq(S)))
		return ERROR;
	
	Ex[j] = '\0';
	
	return OK;
}
