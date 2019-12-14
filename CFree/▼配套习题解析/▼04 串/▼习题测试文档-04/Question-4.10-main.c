#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_10(SString T, SString S);

int main(int argc, char *argv[])
{
	char *s = "0123456789";
	SString T, S;
	
	printf("逆置前，T = ");
	StrAssign_Sq(T, s);
	StrPrint_Sq(T);
	printf("\n\n");

	printf("逆置后，S = ");
	Algo_4_10(T, S);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━┓
┃题4.10：将T逆置为S┃
┗━━━━━━━━━*/
void Algo_4_10(SString T, SString S)
{
	int i;
	
	for(i=T[0]; i>=1; i--)
		S[T[0]-i+1] = T[i];
	
	S[0] = T[0];
} 
