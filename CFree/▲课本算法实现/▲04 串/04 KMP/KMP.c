/**************************
 *						  *
 * �ļ���: ��04 ��\04 KMP *
 * 						  *
 * �ļ���: KMP.c          *
 * 				     	  *
 * ��  ��: 4.6��4.7��4.8  * 
 *                        *
 **************************/

#ifndef KMP_C
#define KMP_C

#include "KMP.h"						//**��04 ��**//

/*�T�T�T�T�[
�U �㷨4.6�U 
�^�T�T�T�T*/
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
		else							//ʧ��ʱ�ص�ǰһ���ʵ���λ�� 
			j = next[j];
	}

	if(j>T[0])							//ƥ��ɹ� 
		return i - T[0];
	else								//ƥ��ʧ�� 
		return 0;
} 

/*�T�T�T�T�[
�U �㷨4.7�U 
�^�T�T�T�T*/
void get_next(SString T, int next[])
{
	int i = 1;
	int j = 0;

	next[1] = 0;						//��һ���ַ���ʧ��
	
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

/*�T�T�T�T�[
�U �㷨4.8�U 
�^�T�T�T�T*/
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
