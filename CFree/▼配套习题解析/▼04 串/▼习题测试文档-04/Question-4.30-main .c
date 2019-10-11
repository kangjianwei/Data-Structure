#include <stdio.h>	
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 函数原型 */
Status Algo_4_30(SString S, SString Sub, int *pos);

int main(int argc, char *argv[])
{
	char *s = "abcdeabcabcbcdefbcdefefghefgh";
	SString Sub, S;
	int pos;
	
	StrAssign_Sq(S, s);
	printf("主串...\n");
	printf("S   = ");
	StrPrint_Sq(S);
	printf("\n\n");

	printf("首个最长不重复子串...\n");
	printf("Sub = ");
	Algo_4_30(S, Sub, &pos);
	StrPrint_Sq(Sub);
	printf("\n");
	printf("Sub 在 S中首次出现的位置为 %d\n", pos);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题4.30：求首次出现的最长重复子串及其位置┃
┗━━━━━━━━━━━━━━━━━━━━*/
/*
**此处的最长重复子串有三层含义：
**第一：此子串在所有重复子串中是首个出现且最长的；
**第二：子串间可以重叠，比如求取abcabca的结果为abca； 
**第三：子串内可以重复，如求取aaaa的结果为aaa。 
*/
Status Algo_4_30(SString S, SString Sub, int *pos)	//0号单元 
{
	int i, j, k, len, start, end;
	
	if(S[0]<2)								//主串元素个数不能少于2 
		return ERROR;
	
	Sub[0] = 0;
	
	for(k=1; k<S[0]; k++)				//范围从1到S[0]-1 
	{
		i = k;
		j = k+1;
		
		while(j<=S[0] && S[i]!=S[j])
			j++;						//找到首个潜在的循环起点 
		
		if(j<=S[0])
		{
			start = i;
			end = j;
			len = 0;
			while(j<=S[0] && S[i]==S[j])
			{
				i++;
				j++;
				len++;
			}
			
			if(len>Sub[0] && start+len-1>=end-1 )		//保证连续性和最长这两个特性 
			{
				*pos = start;
				SubString_Sq(Sub, S, start, len);			
			}
		}
	}
	
	if(Sub[0])
		return OK;
	else
		return ERROR;
} 
