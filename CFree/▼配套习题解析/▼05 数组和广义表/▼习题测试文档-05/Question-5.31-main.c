#include <stdio.h>
#include "../../../▲课本算法实现/▲05 数组和广义表/06 GeneralizedList-E/GeneralizedList-E.c" //**▲05 数组和广义表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c" 	//**▲04 串**//

/* 函数原型 */
void Algo_5_31(GList *T, GList L);

int main(int argc, char *argv[])
{
	GList L, T;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("创建广义表 L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");	
	
	printf("复制广义表到 L 到 T...\n");
	Algo_5_31(&T, L);
	printf("T = ");
	Output_GL_E(T);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题5.31：广义表复制（扩展线性链表存储表示）┃
┗━━━━━━━━━━━━━━━━━━━━━*/
void Algo_5_31(GList *T, GList L)
{
	CopyGList_GL_E(T, L); 			//已定义 
}
