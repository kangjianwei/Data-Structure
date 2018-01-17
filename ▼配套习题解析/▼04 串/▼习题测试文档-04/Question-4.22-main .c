#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/03 BlockChainString/BlockChainString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_22(LString S, LString *T, char ch);

int main(int argc, char *argv[])
{
	char *t = "----***--*-**-**^**-*****-----";
	char *s = "12345";
	char ch = '^';
	LString T, S;
	
	StrAssign_L(&T, t);
	StrAssign_L(&S, s);
	printf("T = ");
	StrPrint_L(T);
	printf("\n");
	printf("S = ");
	StrPrint_L(S);
	printf("\n\n");

	Algo_4_22(S, &T, ch);
	printf("T = ");
	StrPrint_L(T);
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题4.22：将S插入到T的某个字符之后，若不存在则插在T的末位 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
void Algo_4_22(LString S, LString *T, char ch)
{
	int i;
	char tmp[2];
	LString Tmp;
	
	tmp[0] = ch;
	tmp[1] = '\0';
	StrAssign_L(&Tmp, tmp);
	
	i = Index_L((*T), Tmp, 1);					//寻找字符ch在T中的位置
	
	if(i)
		StrInsert_L(T, i+1, S); 			//S插入在T的第i+1个字符前 
	else
		StrInsert_L(T, (*T).curlen+1, S); 	//S插入在T的最后	
} 
