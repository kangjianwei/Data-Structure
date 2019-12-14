#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_11(SString R, SString S, SString T, int a[]);

int main(int argc, char *argv[])
{
	int a[MAXSTRLEN+1];
	char *s = "amdhcjgfdlpinbefcopgkqikeb";
	char *t = "mhjlpinopkqik";
	SString T, S, R;
	int i;
	
	printf("初始化S和T...\n");
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("\n");
	
	printf("S = ");	
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");	
	StrPrint_Sq(T);
	printf("\n\n");
	
	Algo_4_11(R, S, T, a);
	printf("R = ");	
	StrPrint_Sq(R);
	printf("\n");
	printf("a = ");
	for(i=1; i<=a[0]; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━┓
┃题4.11：r=s-s∩t┃
┗━━━━━━━━*/
void Algo_4_11(SString R, SString S, SString T, int a[])	//数组a的0号存储a中元素个数 
{
	int i, p;
	SString Tmp;
	
	StrAssign_Sq(R, "");
	Tmp[0] = 1;
	
	for(i=1,a[0]=0; i<=S[0]; i++)
	{
		Tmp[1] = S[i];										//把S[i]变为串 
		
		p = Index_Sq_1(T, Tmp, 1);							//判断S[i]是否在T中
		
		if(!p)
			p = Index_Sq_1(R, Tmp, 1);						//判断S[i]是否已出现过 
		
		if(!p)
		{		
			a[0]++;
			a[a[0]] = i;
			StrInsert_Sq(R, a[0], Tmp);		
		}
	}
	
} 
