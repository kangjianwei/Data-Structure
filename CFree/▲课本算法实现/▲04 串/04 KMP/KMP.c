/**************************
 *						  *
 * 文件夹: ▲04 串\04 KMP *
 * 						  *
 * 文件名: KMP.c          *
 * 				     	  *
 * 算  法: 4.6、4.7、4.8  * 
 *                        *
 **************************/

#ifndef KMP_C
#define KMP_C

#include "KMP.h"						//**▲04 串**//

/*════╗
║ 算法4.6║ 
╚════*/
int Index_KMP(SString S, SString T, int pos, int next[])
{
	int i = pos;
	int j = 1;

	if(pos<1)
		return 0;

	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j] || j==0)
		{
			i++;
			j++;
		}
		else							//失配时回到前一个适当的位置 
			j = next[j];
	}

	if(j>T[0])							//匹配成功 
		return i - T[0];
	else								//匹配失败 
		return 0;
} 

/*════╗
║ 算法4.7║ 
╚════*/
void get_next(SString T, int next[])
{
	int i = 1;
	int j = 0;

	next[1] = 0;						//第一个字符处失配
	
	while(i<T[0])
	{
		if(T[i]==T[j] || !j)
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
} 

/*════╗
║ 算法4.8║ 
╚════*/
void get_nextval(SString T, int nextval[])
{
	int i = 1;
	int j = 0;
	
	nextval[1] = 0;
	
	while(i<T[0])
	{
		if(T[i]==T[j] || !j)
		{
			i++;
			j++;
			if(T[i]!=T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
} 

#endif
