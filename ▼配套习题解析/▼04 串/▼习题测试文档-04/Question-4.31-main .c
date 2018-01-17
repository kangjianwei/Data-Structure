#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     //**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"//**▲04 串**//

/* 宏定义 */
#define Sl 2000

/* 类型定义 */
typedef struct
{
	SString String;			//某个最长的公共 
	int start;				//字符串起点 
}PString;
typedef struct
{
	PString Sub[MAXSTRLEN+1];
	int count;
}StringSet;					//满足条件的子串集合 

/* 函数原型 */
Status Algo_4_31(SString S, SString T, StringSet *Set_s, StringSet *Set_t);
Status StringSetPrint(StringSet Set);

int main(int argc, char *argv[])
{
	char *s = "abcd*lokis***hyuij**vfgh*lokis****yu*mklng***u****wy*c*vdgry*pklnh";
	char *t = "-vdgry--vfgh-hyuij---abcd-pklnh---yu----lokis-----uio-u--wy---mklng-c ";
	SString S, T;
	StringSet Set_s, Set_t;
	
	printf("初始化...\n");	
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");
	StrPrint_Sq(T);
	printf("\n\n");
	
	printf("求取公共子串的集合...\n");
	Algo_4_31(S, T, &Set_s, &Set_t);
	printf("\n");
	
	printf("输出 S 中公共子串信息...\n");
	StringSetPrint(Set_s);
	printf("\n");

	printf("输出 T 中公共子串信息...\n");
	StringSetPrint(Set_t);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━┓
┃题4.31：最长公共子串┃
┗━━━━━━━━━━*/
/* 结构StringSet保存串S和串T所有的最长公共子串及其起始位置和数量 */
Status Algo_4_31(SString S, SString T, StringSet *Set_s, StringSet *Set_t)
{
	int i, j;					//i标记S，j标记T 
	int m, n;
	int k, flag;
	int len[MAXSTRLEN+1][MAXSTRLEN+1];
	
	if(!S[0] || !T[0])			//有字符串为空 
		return ERROR;
		
	for(m=0; m<=T[0]; m++)		//初始化首列为0 
		len[m][0] = 0;
	for(n=0; n<=S[0]; n++)		//初始化首行为0 
		len[0][n] = 0;
	
	m = T[0]+1;
	n = 1;
	while(n<=S[0])
	{
		m>1 ? m-- : n++;
		
		for(i=m,j=n; i<=T[0]&&j<=S[0]; i++,j++)
		{
			if(T[i]==S[j])
				len[i][j] = len[i-1][j-1] + 1;
			else
				len[i][j] = 0;	
		
			if(len[i][j]>len[m-1][n-1])
				len[m-1][n-1] = len[i][j];
			
			if(len[i][j]>len[0][S[0]])
				len[T[0]][0] = len[0][S[0]] = len[i][j];			
		}
	}
	
	if(!len[0][S[0]])//两字符串无最长公共子串 
		return ERROR; 
	
	m = T[0]+1;
	n = 1;
	(*Set_s).count = (*Set_t).count = 0;

	while(n<=S[0])
	{
		m>1 ? m-- : n++;

		if(len[m-1][n-1]==len[0][S[0]])//存在最长公共子串 
		{
			for(i=m,j=n; i+len[0][S[0]]-1<=T[0]&&j+len[0][S[0]]-1<=S[0]; i++,j++)
			{
				if(len[i+len[0][S[0]]-1][j+len[0][S[0]]-1]==len[0][S[0]])//满足条件的字符串起点 
				{
					for(k=1,flag=0; k<=(*Set_t).count; k++)//是否已加入T中
					{
						if((*Set_t).Sub[k].start==i)
						{
							flag = 1;
							break;
						}
					}
					
					if(!flag)//收集T中出现的最长公共字符串									
					{
						(*Set_t).count++;
						(*Set_t).Sub[(*Set_t).count].start = i;
						SubString_Sq((*Set_t).Sub[(*Set_t).count].String, T, i, len[T[0]][0]);					
					}

					for(k=1,flag=0; k<=(*Set_s).count; k++)//是否已加入S中
					{
						if((*Set_s).Sub[k].start==j)
						{
							flag = 1;
							break;
						}
					}
					
					if(!flag)//收集S中出现的最长公共字符串	
					{
						(*Set_s).count++;
						(*Set_s).Sub[(*Set_s).count].start = j;
						SubString_Sq((*Set_s).Sub[(*Set_s).count].String, S, j, len[0][S[0]]);					
					}
				}
			}		
		}
	}
	
	return OK;	
}

Status StringSetPrint(StringSet Set)
{
	int i, j, k;
	
	for(k=1; k<=Set.count; k++)
	{
		printf("第 %2d 个位置：", Set.Sub[k].start);
		StrPrint_Sq(Set.Sub[k].String);
		printf("\n");
	}
}
