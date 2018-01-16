#include <stdio.h>	
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 宏定义 */
#define N 100								//栈的容量

/* 类型定义 */
typedef int SElemType;
typedef enum{ Left, Right } StackName;
typedef struct
{
	SElemType s[N];							//用一个容量足够大的数组做栈 
	int t[2];								//存放栈顶指针 
}TWStack;

/* 函数原型 */
void Inistack_TWS_3_15(TWStack *S);
Status Push_TWS_3_15(TWStack *S, StackName name, SElemType x);
Status Pop_TWS_3_15(TWStack *S, StackName name, SElemType *x);
void OutputStack_3_15(TWStack S, StackName name);

int main(int argc, char *argv[])
{
	TWStack S;
	int i, x;
	
	printf("初始化栈...\n");
	Inistack_TWS_3_15(&S);
	printf("\n");
	
	printf("向两个栈中压入元素...\n");
	for(i=1; i<=5; i++)
	{
		Push_TWS_3_15(&S, Left, i);
		Push_TWS_3_15(&S, Right, 2*i);
	}	
	printf("左栈中的元素（从栈底到栈顶）：");
	OutputStack_3_15(S, Left);
	printf("\n");
	printf("右栈中的元素（从栈底到栈顶）：");	
	OutputStack_3_15(S, Right);
	printf("\n\n");
	
	printf("分别弹出两个栈的栈顶元素...\n");
	Pop_TWS_3_15(&S, Left, &x);
	printf("左栈的栈顶元素为：%d\n", x);
	Pop_TWS_3_15(&S, Right, &x);
	printf("右栈的栈顶元素为：%d\n", x);
	printf("左栈中的元素（从栈底到栈顶）：");
	OutputStack_3_15(S, Left);
	printf("\n");
	printf("右栈中的元素（从栈底到栈顶）：");	
	OutputStack_3_15(S, Right);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题3.15-(1)：初始化双向栈┃
┗━━━━━━━━━━━━*/
void Inistack_TWS_3_15(TWStack *S) 
{									
	(*S).t[Left] = -1;						//栈0的栈顶指针 
	(*S).t[Right] = N;						//栈1的栈顶指针
}

/*━━━━━━━━━━┓
┃题3.15-(2)：入栈操作┃
┗━━━━━━━━━━*/
Status Push_TWS_3_15(TWStack *S, StackName name, SElemType x)//将元素x入i栈 
{
	if((*S).t[Left]+1==(*S).t[Right])		//注意栈满条件，数组全被填充完才算栈满，不浪费空间 
		return ERROR;

	switch(name)
	{
		case Left: 
			(*S).t[name]++;		
			break;

		case Right: 
			(*S).t[name]--;
			break;
	}
	
	(*S).s[(*S).t[name]] = x;

	return OK;
}

/*━━━━━━━━━━┓
┃题3.15-(3)：出栈操作┃
┗━━━━━━━━━━*/
Status Pop_TWS_3_15(TWStack *S, StackName name, SElemType *x)	//将i栈的栈顶元素出栈 
{	
	switch(name)
	{
		case Left:
			if((*S).t[name]==-1)					//判定栈空 
				return ERROR;
			*x = (*S).s[(*S).t[name]];
			(*S).t[name]--;
			break;

		case Right:
			if((*S).t[name]==N)
				return ERROR;
			*x = (*S).s[(*S).t[name]];
			(*S).t[name]++;
			break;
	} 
}

/* 输出栈 */ 
void OutputStack_3_15(TWStack S, StackName name)
{
	int i;
	
	switch(name)
	{
		case Left:
			for(i=0; i<=S.t[name]; i++)
				printf("%d ", S.s[i]);
			break;

		case Right:
			for(i=N-1; i>=S.t[name]; i--)
				printf("%d ", S.s[i]);
			break;
	}
}
