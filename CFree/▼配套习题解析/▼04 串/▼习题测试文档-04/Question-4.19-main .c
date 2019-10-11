#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_19(SString R, SString S, SString T, int a[]);

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
	
	Algo_4_19(R, S, T, a);
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
┃题4.19：r=s-s∩t┃
┗━━━━━━━━*/
void Algo_4_19(SString R, SString S, SString T, int a[])	//数组a的0号存储a中元素个数 
{
	int i, j, k;
	int flag;
	
	a[0] = 0;
	R[0] = 0;												//初始化R
			
	for(i=1; i<=S[0]; i++)
	{
		flag = 0;

		for(j=1; j<=T[0]; j++)
		{
			if(S[i]==T[j])
			{
				flag = 1;
				break;
			}
		}
		
		if(!flag)											//S[i]中的元素不在T中 
		{
			for(k=1; k<=R[0]; k++)
			{
				if(S[i]==R[k])
				{
					flag = 1;
					break;				
				}
			}
		}
			
		if(!flag)											//S[i]不在R中 
		{
			R[0]++;
			a[0]++;
			R[R[0]] = S[i];
			a[a[0]] = i;
		}
	}
} 
