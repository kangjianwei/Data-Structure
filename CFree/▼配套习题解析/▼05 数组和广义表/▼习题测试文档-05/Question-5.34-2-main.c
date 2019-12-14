#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_34_2(GList *L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "(a,((b,c),()),(((d),e),f))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("逆置广义表...\n");
	Algo_5_34_2(&L);
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━┓
┃题5.34-2：逆置广义表┃
┗━━━━━━━━━━*/ 
/* 扩展线性链表存储表示 */ 
void Algo_5_34_2(GList *L)
{
	GList head, tail;
	
	if(*L)
	{
		head = *L;
		tail = (*L)->tp;
		
		if(head->tag==List && head->Union.hp)
			Algo_5_34_2(&(head->Union.hp));
		
		if(tail)						//对表尾进行逆置
		{	
			Algo_5_34_2(&((*L)->tp));
		
			*L = (*L)->tp;				//头尾交换
			tail->tp = head;
			head->tp = NULL;
		}
	}
}
