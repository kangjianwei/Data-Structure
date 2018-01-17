#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 函数原型 */
int Algo_4_27(SString S, SString T, int pos);

int main(int argc, char *argv[])
{
	char *s = "aaaaaaaaaaaaaaab";
	char *t = "aaaab";
	SString S, T;
	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");	
	
	printf("T在S中首次出现的位置为：");
	printf("%d\n", Algo_4_27(S, T, 1));
	printf("\n");
		
	return 0;
}

/*━━━━━━━━┓
┃题4.27：子串定位┃
┗━━━━━━━━*/
int Algo_4_27(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	
	if(pos<1)
		return 0;
		
	while(i<=S[0] && j<=T[0])
	{

		if((j!=1&&S[i]==T[j])||(j==1&&S[i]==T[j]&&S[i+T[0]-1]==T[T[0]]))
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;
			j = 1;
		}
	}
	
	if(j>T[0] && T[0])											//T不为空串 
		return i-T[0];											//匹配成功 
	else
		return 0;	 
}
