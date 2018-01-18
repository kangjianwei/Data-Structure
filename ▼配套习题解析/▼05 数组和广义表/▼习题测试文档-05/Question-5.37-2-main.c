#include <stdio.h>
#include <stdlib.h>								                //提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_37_2(GList *L, AtomType x);
	
int main(int argc, char *argv[])
{
	GList L;
	char *s = "((b),(e),(a,(b,c,d)),(b,((b),b)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("删除 L 中的元素 'b' ...\n");
	Algo_5_37_2(&L, 'b');
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题5.37-2：删除广义表中值为x的原子项 ┃
┗━━━━━━━━━━━━━━━━━━*/ 
/* 扩展线性链表存储表示 */ 
void Algo_5_37_2(GList *L, AtomType x)
{
	GList p;
	
	if(*L)
	{
		if((*L)->tag==List)
		{				
			Algo_5_37_2(&((*L)->Union.hp), x);
			Algo_5_37_2(&((*L)->tp), x);	
		}
		else
		{
			if((*L)->Union.atom==x)
			{	
				p = *L;
				*L = (*L)->tp;
				free(p);
				p = NULL;
				
				Algo_5_37_2(L, x);
			}
			else
				Algo_5_37_2(&((*L)->tp), x);
		}
	}
}
