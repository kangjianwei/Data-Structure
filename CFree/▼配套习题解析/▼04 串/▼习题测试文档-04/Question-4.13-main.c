#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_13(SString S, SString T);

int main(int argc, char *argv[])
{
	char *s = "----***--*-**-****-*****-----";
	char *t = "**";
	SString T, S;

	printf("删除前...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");

	printf("删除后...\n");
	printf("S = ");
	Algo_4_13(S, T);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━━━┓
┃题4.13：删除S中包含的T┃
┗━━━━━━━━━━━*/
void Algo_4_13(SString S, SString T)
{
	int i;
	
	for(i=1; i=Index_Sq_1(S, T, 1); i++)
		StrDelete_Sq(S, i, T[0]);	
} 
