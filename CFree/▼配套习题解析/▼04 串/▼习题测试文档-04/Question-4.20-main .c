#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
void Algo_4_20(SString S, SString T);

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
	Algo_4_20(S, T);
	StrPrint_Sq(S);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━━━┓
┃题4.20：删除S中包含的T┃
┗━━━━━━━━━━━*/
void Algo_4_20(SString S, SString T)
{
	int i, j, k;
	
	i = 1;
	j = 1;	
	while(i<=S[0] && j<=T[0])				//寻找第一个匹配的位置 
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;				//j-1代表徒劳地前进了j-1个位置 
			j = 1;
		}
	}
	if(j>T[0] && T[0])						//T不为空串 
		i = i-T[0];							//匹配成功 
	else
		i = 0;
										
	while(i!=0)								//有匹配的字符串
	{	
		for(k=i+T[0]; k<=S[0]; k++)
			S[k-T[0]] = S[k];
		S[0] = S[0] - T[0];					//改变S长度 
				
		j = 1;	
		while(i<=S[0] && j<=T[0])			//定位下一个匹配的字符串 
		{
			if(S[i]==T[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - (j-1) +1;			//j-1代表徒劳地前进了j-1个位置 
				j = 1;
			}
		}
		
		if(j>T[0] && T[0]!=0)				//T不为空串 
			i = i-T[0];						//匹配成功 
		else
			i = 0;
	}
} 
