#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_33_1(GList L, int d);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	Algo_5_33_1(L, 0);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题5.33-1：输出广义表中所有原子项及其所在层次（头尾链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 
/* 头尾链表存储表示 */ 
void Algo_5_33_1(GList L, int d)
{
	int i = d;								//d的初值赋值为0
	
	if(L)
	{
		if(L->tag==Atom)
			printf("%c -> 第%d层\n", L->Union.atom, i);
		
		if(L->tag==List)					//表头指针指向表的话层数增一
		{
			Algo_5_33_1(L->Union.ptr.hp, i+1);
			Algo_5_33_1(L->Union.ptr.tp, i);
		}
	}
}
