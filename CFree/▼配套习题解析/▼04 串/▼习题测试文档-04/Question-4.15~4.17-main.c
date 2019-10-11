#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 函数原型 */
Status Algo_4_15(SString T, char *chars);
int Algo_4_16(SString S, SString T);
Status Algo_4_17(SString S, SString T, SString V);

int main(int argc, char *argv[])
{
	char *t = "ab**c*de***fg";
	char *s = "ab**c*de***fh";
	int i;
	SString T, S, M1, M2;
	
	printf("███题 4.15 验证...███\n");
	Algo_4_15(T, t);
	Algo_4_15(S, s);
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n");
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	printf("███题 4.16 验证...███\n");
	i = Algo_4_16(S, T);
	if(i>0)
		printf("S > T\n");
	else if(i<0)
		printf("S < T\n");
	else
		printf("S == T\n");
	printf("\n");
	
	printf("███题 4.17 验证...███\n");
	Algo_4_15(M1, "**");
	Algo_4_15(M2, "^");
	Algo_4_17(S, M1, M2);
	printf("用 \"^\" 替换 \"**\" 后：S = ");
	StrPrint_Sq(S);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━┓
┃题4.15：字符串赋值┃
┗━━━━━━━━━*/
Status Algo_4_15(SString T, char *chars)
{
	int i, len;
	
	len = strlen(chars);
	
	if(len>MAXSTRLEN)								//chars过长 
		return ERROR;
	else
	{
		T[0] = len;
		for(i=1; i<=len; i++)
			T[i] = chars[i-1];						//chars为常量 

		return OK;
	}
}

/*━━━━━━━━━┓
┃题4.16：字符串比较┃
┗━━━━━━━━━*/
int Algo_4_16(SString S, SString T)
{
	int i = 1;
	
	while(i<=S[0] && i<=T[0])
	{
		if(S[i]==T[i])
			i++;
		else
			return S[i] - T[i];	
	}
	
	return S[0] - T[0];	
}

/*━━━━━━━━━┓
┃题4.17：字符串替换┃
┗━━━━━━━━━*/
Status Algo_4_17(SString S, SString T, SString V)
{
	int count = 1;									//count遍历S 
	int i, j, k;
	SString Tmp_beh;
	
	i = count;
	j = 1;	
	while(i>=1 && i<=S[0] && j<=T[0])				//寻找第一个匹配的位置 
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;						//j-1代表徒劳地前进了j-1个位置 
			j = 1;
		}
	}
	if(j>T[0] && T[0]!=0)							//T不为空串 
		count = i-T[0];								//匹配成功 
	else
		count = 0;
										
	while(S[0]-T[0]+V[0]<=MAXSTRLEN && count!=0)	//有匹配的字符串且可以被完全替换
	{			
		Tmp_beh[0] = S[0]-i+1;						//摘取S中匹配字符串之后的字符到Tmp_beh
		for(k=1; k<=S[0]-i+1; k++)
			Tmp_beh[k] = S[k+i-1];
		
		S[0] = S[0]-T[0]+V[0];
		for(k=1; k<=V[0]; k++)						//联接V到S上 
			S[k+count-1] = V[k];
		
		for(k=count+V[0]; k<=S[0]; k++)				//联接取自S中的后半部分到S上 
			S[k] = Tmp_beh[k-count-V[0]+1];
				
		count += V[0];								//i切换到下一个位置 
				
		i = count;
		j = 1;	
		while(i>=1 && i<=S[0] && j<=T[0])			//定位下一个匹配的字符串 
		{
			if(S[i]==T[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - (j-1) +1;					//j-1代表徒劳地前进了j-1个位置 
				j = 1;
			}
		}
		if(j>T[0] && T[0]!=0)						//T不为空串 
			count = i-T[0];							//匹配成功 
		else
			count = 0;
	}
	
	if(count==0)									//S中的T已全部被替换 
		return OK;
	else											//S中尚有T，但是V已经插不进去了 
		return ERROR;
}
