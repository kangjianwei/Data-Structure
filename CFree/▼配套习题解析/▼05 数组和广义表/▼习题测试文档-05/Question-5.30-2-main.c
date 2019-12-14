#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
int Algo_5_30_2(GList L);

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
	
	printf("广义表深度为： %d\n", Algo_5_30_2(L));
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃题5.30-2：求广义表深度（扩展线性链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/
/* 扩展线性链表存储表示 */ 
int Algo_5_30_2(GList L)
{
	int m, n;
	
	if(!L)							//空表深度为1 
		return 1;
	
	if(L->tag==Atom)				//原子深度为0 
		return 0;
	
	m = Algo_5_30_2(L->Union.hp) + 1;
	n = Algo_5_30_2(L->tp);
	
	return m>n ? m : n;
}
