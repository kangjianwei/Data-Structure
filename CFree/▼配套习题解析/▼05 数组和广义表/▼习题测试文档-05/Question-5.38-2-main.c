#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_38_2(GList L, int d, int l);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("广义表第 2 层的原子项为：");
	Algo_5_38_2(L, 0, 2);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题5.38-2：输出广义表中第l层的原子项(扩展线性链表存储表示) ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 扩展线性链表存储表示 */ 
void Algo_5_38_2(GList L, int d, int l)
{
	int i = d;									//d初值赋为0
	
	if(L && l>=i)
	{
		if(L->tag==Atom)
		{
			if(l==i)
				printf("%c ", L->Union.atom);
		}
		else
			Algo_5_38_2(L->Union.hp, i+1, l); //表头指针指向表的话层数增一
		
		Algo_5_38_2(L->tp, i, l);		
	}
}
