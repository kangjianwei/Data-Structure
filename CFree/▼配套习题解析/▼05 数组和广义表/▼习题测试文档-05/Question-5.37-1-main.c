#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_37_1(GList *L, AtomType x);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((b),(e),(a,(b,c,d)),(b,((b),b)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	printf("删除 L 中的元素 'b' ...\n");
	Algo_5_37_1(&L, 'b');
	printf("L = ");
	Output_GL_H_T(L, Head);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题5.37-1：删除广义表中值为x的原子项 ┃
┗━━━━━━━━━━━━━━━━━━*/ 
/* 头尾链表存储表示 */ 
void Algo_5_37_1(GList *L, AtomType x)
{
	GList h, p;
	
	if(*L && (*L)->tag==List)
	{		
		h = (*L)->Union.ptr.hp;
		if(h)
		{
			if(h->tag==List)
			{
				Algo_5_37_1(&((*L)->Union.ptr.hp), x);
				Algo_5_37_1(&((*L)->Union.ptr.tp), x);			
			}			
			else
			{
				if(h->Union.atom==x)
				{				
					p = *L;
					*L = (*L)->Union.ptr.tp;
					p->Union.ptr.tp = NULL;
					ClearGList_GL_H_T(&p);
					Algo_5_37_1(L, x);				
				}
				else
					Algo_5_37_1(&((*L)->Union.ptr.tp), x);
			}			
		}
		else
		{
			if((*L)->Union.ptr.tp)
				Algo_5_37_1(&((*L)->Union.ptr.tp), x);
		}
	}
}
