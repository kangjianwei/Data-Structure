/***************************
 *                         *
 * �ļ���: ��09 ����       *
 *                         *
 * �ļ���: SequnceSearch.c *
 *                         *
 * ��  ��: 9.1             *
 *                         *
 ***************************/

#ifndef SEQUNCESEARCH_C
#define SEQUNCESEARCH_C

#include "SequnceSearch.h" 					//**��09 ����**//

/*�T�T�T�T�[
�U �㷨9.1�U 
�^�T�T�T�T*/
int Search_Seq(Table T, KeyType key)
{
	int i;
	
	T.elem[0].key = key;
	
	for(i=T.length; !EQ(T.elem[i].key, key); --i)
		;
	
	return i;
}

#endif
