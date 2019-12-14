/*********************************
 *                               *
 * 文件夹: ▲09 查找             *
 *                               *
 * 文件名: InterpolationSearch.c *
 *                               *
 *********************************/

#ifndef INTERPOLATIONSEARCH_C
#define INTERPOLATIONSEARCH_C

#include "InterpolationSearch.h" 					//**▲09 查找**//

int Search_Int(Table T, KeyType key)
{
	int low, high, m;
	float j;
	
	low = 1;
	high = T.length;
	
	while(low<=high)
	{
		m = (1.0*(key-T.elem[low].key)/(T.elem[high].key-T.elem[low].key))*(high-low) + low;	//注意浮点数转整型	
	
		if(key<T.elem[m].key)
			high = m - 1;
		else if(key>T.elem[m].key)
			low = m + 1;
		else
			return m;		
	}

}

#endif
