#include <stdio.h>	
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     //**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
Status Algo_4_12(SString S, SString T, SString V);

int main(int argc, char *argv[])
{
	char *s = "----***--*-**-****-*****-----";
	char *t = "**";
	char *v = "^";
	SString T, S, V;

	printf("替换前...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	StrAssign_Sq(V, v);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n");
	printf("V = ");
	StrPrint_Sq(V);
	printf("\n\n");

	printf("替换后...\n");
	printf("S = ");
	Algo_4_12(S, T, V);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━┓
┃题4.12：字符串替换┃
┗━━━━━━━━━*/
Status Algo_4_12(SString S, SString T, SString V)
{
	if(Replace_Sq(S, T, V))		//已定义 
		return OK;
	else
		return ERROR;
} 
