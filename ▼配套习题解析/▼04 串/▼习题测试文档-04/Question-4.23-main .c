#include <stdio.h>
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"//**▲03 栈和队列**//
#include "../../../▲课本算法实现/▲04 串/03 BlockChainString/BlockChainString.c"//**▲04 串**//

/* 函数原型 */
Status Algo_4_23(LString T);

int main(int argc, char *argv[])
{
	char *t = "abcdefgfedcba";
	LString T;
	
	StrAssign_L(&T, t);
	printf("T = ");
	StrPrint_L(T);
	printf("\n\n");

	Algo_4_23(T) ? printf("T是对称串！") : printf("T是非对称串！！");
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━┓
┃题4.23：判断串是否对称┃
┗━━━━━━━━━━━*/
/* 借助于栈的操作来实现此函数，栈中数据元素定义为char */
Status Algo_4_23(LString T)
{
	int i, j, m;
	SqStack S;
	SElemType_Sq e;
	Chunk *p;
	
	if(!(T.curlen))
		return OK;
		
	InitStack_Sq(&S);
	m = T.curlen/2;

	for(i=1,p=T.head,j=0; i<=m; i++)
	{
		Push_Sq(&S, p->ch[j]);
		j = (j+1) % CHUNKSIZE;
		if(!j)
			p = p->next;
	}
	
	if(T.curlen % 2)					//长度为奇数则跳过一个字符
	{
		i++;
		j = (j+1) % CHUNKSIZE;
		if(!j)
			p = p->next;		
	}
	
	while(!StackEmpty_Sq(S) && i<=T.curlen)
	{
		Pop_Sq(&S, &e);
		if(e!=p->ch[j])
			return ERROR;
		i++;
		j = (j+1) % CHUNKSIZE;
		if(!j)
			p = p->next;		
	}
	
	if(StackEmpty_Sq(S) && i>T.curlen)
		return OK;
} 
