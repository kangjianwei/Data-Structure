/*******************************
 *						       *
 * 文件夹: ▲08 动态存储管理   *
 * 						       *
 * 文件名: StorageCompacting.c *
 *    	    				   *
 *******************************/

#ifndef STORAGECOMPACTING_C
#define STORAGECOMPACTING_C

#include "StorageCompacting.h" 						//**▲08 动态存储管理**//

void InitMemory(int n)
{
	void *p = malloc(n);

	start = (int)p;
	end = start + n - 1;
	cur = start;
}

void* MallocMemory(int n)
{
	void *p;
	
	if(cur+n-1>end)									//空间不够，进行压缩 
		cur = CompressMemory();
	
	if(cur+n-1>end)									//压缩后空间依然不够用 
	{
		printf("内存已满，无法继续分配空间！\n");
		return NULL;
	}
	else
	{
		p = (void*)cur;
		
		Record[0].length++;							//内存地址表中添加此记录 
		Record[Record[0].length].stadr = cur;
		Record[Record[0].length].length = n;
		
		cur += n;
	}

	return p;
}

void FreeMemory(void* ptr)
{
	int i, j;

	for(i=1; i<=Record[0].length; i++)
	{
		if(Record[i].stadr==(int)ptr)			//内存地址表压缩 
		{		
			for(j=i; j<Record[0].length; j++)
				Record[j] = Record[j+1];
			
			Record[0].length--;
			
			return;
		}
	}	
}

int CompressMemory()
{
	int p, q, k;
	
	for(k=1,p=start; k<=Record[0].length&&Record[k].length; k++)
	{
		q = Record[k].stadr;
		memmove((void*)p, (void*)q, Record[k].length);		//移动数据 
		Record[k].stadr = p;								//更新起点 
		
		p += Record[k].length;
	}
	
	return p;	
}

void PrintLayout()
{
	int k, count;
	
	printf("已占用的内存块范围：┃");
	for(k=1,count=0; k<=Record[0].length; k++)
	{
		printf("%3d←→%3d┃", Record[k].stadr-start, Record[k].stadr+Record[k].length-start-1);
		count += Record[k].length;	
	}	
	printf("\n");
	
	printf("内存已占用块数：%4d，空闲块数：%4d。\n", count, MAX-count);		
}

#endif
