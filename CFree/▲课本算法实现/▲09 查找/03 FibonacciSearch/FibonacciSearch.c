/*****************************
 *                           *
 * �ļ���: ��09 ����         *
 *                           *
 * �ļ���: FibonacciSearch.c *
 *                           *
 *****************************/

#ifndef FIBONACCISEARCH_C
#define FIBONACCISEARCH_C

#include "FibonacciSearch.h" 			//**��09 ����**//

int Search_Fib(Table T, KeyType key)
{
	int low, high, mid;
	int Fib[MaxSize+1];
	int i, k;
	int *table;
	
	Fib[1] = Fib[2] = 1;
	for(i=3; i<=MaxSize; i++)
		Fib[i] = Fib[i-1] + Fib[i-2];
	
	table = (int *)malloc((Fib[MaxSize])*sizeof(int));
	
	for(i=1; i<=T.length; i++)
		table[i] = T.elem[i].key;
	
	for(i=T.length+1; i<=Fib[MaxSize]-1; i++)
		table[i] = T.elem[T.length].key;
	
	k = MaxSize;
	low = 1;
	high = Fib[k];
	
	while(low<=high)
	{
		mid = low + Fib[k-1] - 1;	//�е��ȷ�� 
		
		if(key<table[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if(key>table[mid])
		{
			if(mid<T.length)
			{
				low = mid + 1;
				k = k - 2;			
			}
			else
				return 0;			//δ�ҵ� 
		}
		else
		{
			if(mid<T.length)
				return mid;
			else
				return T.length;	//�����һ��λ�� 
		}
	}
	
	return 0; 
}

#endif
