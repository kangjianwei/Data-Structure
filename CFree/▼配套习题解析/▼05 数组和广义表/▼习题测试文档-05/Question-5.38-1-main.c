#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_38_1(GList L, int d, int l);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	printf("广义表第 2 层的原子项为：");
	Algo_5_38_1(L, 0, 2);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题5.38-1：输出广义表中第l层的原子项(头尾链表存储表示) ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 
/* 头尾链表存储表示 */ 
void Algo_5_38_1(GList L, int d, int l)
{
	int i = d;							//d的初值赋值为0
	
	if(L && l>=i)
	{
		if(L->tag==Atom)
		{
			if(l==i)					//层数符合 
				printf("%c ", L->Union.atom);
		}
		else							//表头指针指向表的话层数增一
		{
			Algo_5_38_1(L->Union.ptr.hp, i+1, l);
			Algo_5_38_1(L->Union.ptr.tp, i, l);
		}
	}
}
