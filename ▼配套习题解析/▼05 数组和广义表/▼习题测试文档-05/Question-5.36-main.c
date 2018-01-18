#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//

/* 函数原型 */
void Algo_5_36_1(GList L, Mark mark);
void Algo_5_36_2(GList L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("\n");	
	
	printf("第 1 种输出形式('_'代表空表)...\n");	
	printf("L = ");
	Algo_5_36_1(L, 0);
	printf("\n\n");

	printf("第 2 种输出形式...\n");
	printf("L = ");
	Algo_5_36_2(L);
	printf("\n\n");
			
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题5.36：输出广义表（头尾链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━*/ 
/* 形式1：输出广义表元素('_'代表空表) */ 
void Algo_5_36_1(GList L, Mark mark)
{
	if(L)
	{
		if(L->tag==Atom)
			printf("%c ", L->Union.atom);
		else
		{
			Algo_5_36_1(L->Union.ptr.hp, Head);
			Algo_5_36_1(L->Union.ptr.tp, Tail);
		}
	}
	
	if(!L && mark==Head)
		printf("_ ");
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题5.36：输出广义表（头尾链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━*/ 
/* 形式2：按广义表书写形式输出 */ 
void Algo_5_36_2(GList L)
{
	Output_GL_H_T(L, Head);					//已定义 
}
