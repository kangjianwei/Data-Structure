#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_33_2(GList L, int d);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	Algo_5_33_2(L, 0);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题5.33-2：输出广义表中所有原子项及其所在层次（扩展线性链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 扩展线性链表存储表示 */ 
void Algo_5_33_2(GList L, int d)
{
	int i = d;										//d初值赋为0
	
	if(L)
	{
		if(L->tag==Atom)
			printf("%c -> 第%d层\n", L->Union.atom, i);
		
		if(L->tag==List)
			Algo_5_33_2(L->Union.hp, i+1);		//表头指针指向表的话层数增一
		
		Algo_5_33_2(L->tp, i);
	}
}
