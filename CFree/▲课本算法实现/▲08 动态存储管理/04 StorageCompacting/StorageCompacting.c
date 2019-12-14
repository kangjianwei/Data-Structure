/*******************************
 *						       *
 * �ļ���: ��08 ��̬�洢����   *
 * 						       *
 * �ļ���: StorageCompacting.c *
 *    	    				   *
 *******************************/

#ifndef STORAGECOMPACTING_C
#define STORAGECOMPACTING_C

#include "StorageCompacting.h" 						//**��08 ��̬�洢����**//

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
	
	if(cur+n-1>end)									//�ռ䲻��������ѹ�� 
		cur = CompressMemory();
	
	if(cur+n-1>end)									//ѹ����ռ���Ȼ������ 
	{
		printf("�ڴ��������޷���������ռ䣡\n");
		return NULL;
	}
	else
	{
		p = (void*)cur;
		
		Record[0].length++;							//�ڴ��ַ������Ӵ˼�¼ 
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
		if(Record[i].stadr==(int)ptr)			//�ڴ��ַ��ѹ�� 
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
		memmove((void*)p, (void*)q, Record[k].length);		//�ƶ����� 
		Record[k].stadr = p;								//������� 
		
		p += Record[k].length;
	}
	
	return p;	
}

void PrintLayout()
{
	int k, count;
	
	printf("��ռ�õ��ڴ�鷶Χ����");
	for(k=1,count=0; k<=Record[0].length; k++)
	{
		printf("%3d����%3d��", Record[k].stadr-start, Record[k].stadr+Record[k].length-start-1);
		count += Record[k].length;	
	}	
	printf("\n");
	
	printf("�ڴ���ռ�ÿ�����%4d�����п�����%4d��\n", count, MAX-count);		
}

#endif
