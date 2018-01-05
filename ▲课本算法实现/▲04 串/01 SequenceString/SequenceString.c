/*************************************
 *                                   *
 * 文件夹: ▲04 串\01 SequenceString *
 *                                   *
 * 文件名: SequenceString.c          *
 *                                   *
 * 算  法: 4.1、4.2、4.3、4.5        * 
 *                                   *
 *************************************/

#ifndef SEQUENCESTRING_C
#define SEQUENCESTRING_C

#include "SequenceString.h" 						//**▲04 串**//

Status StrAssign_Sq(SString T, const char *chars)	//属于最小操作子集 
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

void StrCopy_Sq(SString T, SString S)
{
	int i;
	
	for(i=0; i<=S[0]; i++)
		T[i] = S[i];
}

Status StrEmpty_Sq(SString S)
{
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

int StrCompare_Sq(SString S, SString T)				//属于最小操作子集
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

int StrLength_Sq(SString S)							//属于最小操作子集
{
	return S[0];
}

void ClearString_Sq(SString S)
{
	S[0] = 0;
}

void DestroyString_Sq(SString S)
{
	//顺序串不能被销毁 
}

/*════╗
║ 算法4.2║ 
╚════*/
Status Concat_Sq(SString T, SString S1, SString S2)	//属于最小操作子集
{
	int i;

	for(i=1; i<=S1[0]; i++)
		T[i] = S1[i];
	
	if(S1[0]+S2[0]<=MAXSTRLEN)
	{
		for(i=1; i<=S2[0]; i++)
			T[S1[0]+i] = S2[i];

		T[0] = S1[0]+S2[0];		

		return OK;
	}
	else
	{
		for(i=1; S1[0]+i<=MAXSTRLEN; i++)
			T[S1[0]+i] = S2[i];

		T[0]=MAXSTRLEN;

		return ERROR;
	}
}

/*════╗
║ 算法4.3║ 
╚════*/
Status SubString_Sq(SString Sub, SString S, int pos, int len)//属于最小操作子集
{
	int i;
	
	if(pos<1 || pos>S[0] || len<0 || pos+len-1>S[0])
		return ERROR;

	for(i=1; i<=len; i++)
		Sub[i] = S[pos+i-1];

	Sub[0] = len;

	return OK;
}

/*════╗
║ 算法4.1║ 
╚════*/
int Index_Sq_1(SString S, SString T, int pos)				//用到串类型的最小操作子集 
{
	int s, t;
	SString Sub;
	
	if(pos>0)
	{
		s = StrLength_Sq(S);
		t = StrLength_Sq(T);
		
		if(s && t)
		{
			while(pos+t-1<=s)
			{
				SubString_Sq(Sub, S, pos, t);
	
				if(!StrCompare_Sq(Sub, T))
					return pos;
			
				pos++;
			}		
		}
	}

	return 0;
}

/*════╗
║ 算法4.5║ 
╚════*/
/* 串的模式匹配算法 */
int Index_Sq_2(SString S, SString T, int pos)			//不依赖其他串操作的匹配算法 
{
	int i = pos;
	int j = 1;
	
	if(pos<1)
		return 0;
	
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - (j-1) +1;							//j-1代表徒劳地前进了j-1个位置 
			j = 1;
		}
	}

	if(j>T[0] && T[0])									//T不为空串 
		return i-T[0];									//匹配成功 
	else
		return 0;
}

Status Replace_Sq(SString S, SString T, SString V)
{
	int i;
		
	i = Index_Sq_2(S, T, 1);							//寻找第一个匹配的位置 

	while(S[0]-T[0]+V[0]<=MAXSTRLEN && i)				//有匹配的字符串且可以被完全替换
	{

		StrDelete_Sq(S, i, T[0]);						//删除T 
		StrInsert_Sq(S, i, V);							//插入V 

		i += V[0];										//i切换到下一个位置 

		i = Index_Sq_2(S, T, i);						//定位下一个匹配的字符串 
	}

	if(i==0)											//S中的T已全部被替换 
		return OK;
	else												//S中尚有T，但是V已经插不进去了 
		return ERROR;
}

Status StrInsert_Sq(SString S, int pos, SString T)
{
	int i;
	
	if(pos<1 || pos>S[0]+1 || S[0]+T[0]>MAXSTRLEN)
		return ERROR;

	for(i=S[0]; i>=pos; i--)
		S[i+T[0]] = S[i];

	for(i=pos; i<=pos+T[0]-1; i++)
		S[i] = T[i-pos+1];

	S[0] += T[0];

	return OK;
}

Status StrDelete_Sq(SString S, int pos, int len)
{
	int i;     
	
	if(pos<1 || pos+len-1>S[0] || len<0)
		return ERROR;

	for(i=pos+len; i<=S[0]; i++)
		S[i-len] = S[i];

	S[0] -= len;

	return OK;
}

void StrPrint_Sq(SString S)
{
	int i;
	
	for(i=1; i<=S[0]; i++)
		printf("%c", S[i]);
}

#endif
