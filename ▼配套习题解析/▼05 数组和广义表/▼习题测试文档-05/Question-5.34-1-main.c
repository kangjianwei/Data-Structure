#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_34_1(GList *L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "(a,((b,c),()),(((d),e),f))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	printf("逆置广义表...\n");
	Algo_5_34_1(&L);
	printf("L = ");
	Output_GL_H_T(L, Head);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━┓
┃题5.34-1：逆置广义表┃
┗━━━━━━━━━━*/ 
/* 头尾链表存储表示 */ 
void Algo_5_34_1(GList *L)
{
	GList head, tail;
	
	if(*L)								//从后向前，从里到外逆置 
	{
		head = *L;
		tail = (*L)->Union.ptr.tp;
					
										//对表头进行逆置 
		if(head->Union.ptr.hp && head->Union.ptr.hp->tag==List)
			Algo_5_34_1(&(head->Union.ptr.hp));
					 
		if(tail)						//对表尾进行逆置
		{	
			Algo_5_34_1(&((*L)->Union.ptr.tp));
		
			*L = (*L)->Union.ptr.tp;	//头尾交换
			tail->Union.ptr.tp = head;
			head->Union.ptr.tp = NULL;
		}
	}
}
