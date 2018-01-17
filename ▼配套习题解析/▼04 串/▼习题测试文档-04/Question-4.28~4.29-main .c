#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	         //**▲01 绪论**//

/* 串结构类型定义 */
typedef struct strLNode			//主串是个双向链表（不循环），模式串在未求next值之前与主串类似 
{
	char chdata;
	struct strLNode *succ;		//succ指向后继 
	struct strLNode *next;		//next在主串中，指向前驱 
}strLNode;						//next在模式串中，指向当前结点失配时，下一个应该比较的结点 
typedef strLNode *LString;

/* 函数原型 */
Status Algo_4_28_1(LString T);
Status Algo_4_28_2(LString T) ;
int Algo_4_29(LString S, LString T, int pos);
Status AssignLString(LString *S, char *s);
Status PrintLString(LString S);

int main(int argc, char *argv[])
{
	int pos, i1, i2;
	LString S, T1, T2;
	char *s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
	char *t = "abaabcac";
	LString p;
	AssignLString(&S, s);					//主串 
	AssignLString(&T1, t);					//模式串
	AssignLString(&T2, t);
		
	printf("主  串 ：S  = ");
	PrintLString(S);
	printf("\n");
	printf("模式串 ：T1 = "); 
	PrintLString(T1);
	printf("\n");
	printf("模式串 ：T2 = "); 
	PrintLString(T2);
	printf("\n\n");
	
	printf("███题 4.28 验证...███\n");
	Algo_4_28_1(T1);	
	Algo_4_28_2(T2);
	printf("创建next表...\n");
	printf("\n");

	printf("███题 4.29 验证...███\n");		
	i1 = Algo_4_29(S, T1, 1);
	printf("模式串 T1 从 %d 个字符起第一次匹配成功的位置为i1 = %d\n", 1, i1);

	i2 = Algo_4_29(S, T2, 1);
	printf("模式串 T2 从 %d 个字符起第一次匹配成功的位置为i2 = %d\n", 1, i2);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━┓
┃题4.28-1：求next值┃
┗━━━━━━━━━*/
/* 方案1：求next值 */
Status Algo_4_28_1(LString T)
{
	strLNode *i, *j;
	
	if(!T || !T->succ)
		return ERROR;
		
	i = T->succ;				//i = 1
	j = T;						//j = 0
	
	i->next = T;				//第一个字符处失配
	
	while(i->succ)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ;
			j = j->succ;
			i->next = j;
		}
		else
			j = j->next;
	}
	
	return OK;
} 

/*━━━━━━━━━┓
┃题4.28-2：求next值┃
┗━━━━━━━━━*/
/* 方案2：求nextval值，即改进后的求next方案 */
Status Algo_4_28_2(LString T) 
{
	strLNode *i, *j;
	
	if(!T || !T->succ)
		return ERROR;
		
	i = T->succ;				//i = 1
	j = T;						//j = 0
	
	i->next = T;				//第一个字符处失配
	
	while(i->succ)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ;
			j = j->succ;
			
			if(i->chdata!=j->chdata)	
				i->next = j;
			else
				i->next = j->next;
		}
		else
			j = j->next;
	}
	
	return OK;	
}

/*━━━━━━━━┓
┃题4.29：KMP算法 ┃
┗━━━━━━━━*/
int Algo_4_29(LString S, LString T, int pos)
{
	int count, m;
	strLNode *i, *j;	//i遍历S，j遍历T 
	strLNode *p, *q;
	
	if(pos<1 || !S || !S->succ || !T || !T->succ)
		return 0;
	
	for(count=1,i=S->succ; count<pos; count++,i=i->succ)
		;					//用i指向第pos个结点

	j = T->succ;
	p = i;

	while(i && j)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ; 
			j = j->succ;
		}
		else
		{
			j = j->next;
			if(j==T->succ)
				p = i;		//记下重新开始匹配时i的起点
		}
	}

	if(!j)
	{
		for(count=1,q=S->succ; q!=p; count++,q=q->succ)
			;				//找出第一个结点匹配的位置					 
		return count;	
	}
	else
		return 0;	
}

Status AssignLString(LString *S, char *s)
{
	int i;
	LString pre, p;
	
	*S = (LString)malloc(sizeof(strLNode));
	if(!(*S))
		exit(OVERFLOW);
	(*S)->next = (*S)->succ = NULL;

	for(i=0,pre=*S; i<strlen(s); i++)
	{
		p = (LString)malloc(sizeof(strLNode));
		if(!p)
			exit(OVERFLOW);
		p->chdata = s[i];
		p->next = pre;
		p->succ = pre->succ;
		pre->succ = p;
		pre = pre->succ;
	}
	
	return OK;
}

Status PrintLString(LString S)
{
	LString p;
	
	if(!S)
		return ERROR;
	
	for(p=S->succ; p; p=p->succ)
		printf("%c", p->chdata);
	
	return OK;
}
