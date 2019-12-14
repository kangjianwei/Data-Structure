/***************************
 *                         *
 * �ļ���: ��09 ����       *
 *                         *
 * �ļ���: Binsearch.c     *
 *                         *
 * ��  ��: 9.2             *
 *                         *
 ***************************/

#ifndef BINSEARCH_C
#define BINSEARCH_C

#include "Binsearch.h" 				//**��09 ����**//

/*�T�T�T�T�[
�U �㷨9.2�U 
�^�T�T�T�T*/
int Search_Bin(Table T, KeyType key)
{
	int low, high, mid;
	
	low = 1;
	high = T.length;
	
	while(low<=high)
	{
		mid = (low + high) / 2;
		
		if(EQ(key, T.elem[mid].key))
			return mid;
		else if(LT(key, T.elem[mid].key))
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return 0;
}

#endif
