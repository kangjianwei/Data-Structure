#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"

/* 宏定义 */
#define MAXSIZE 20000

/* 类型定义 */
typedef struct
{
	int row;
	int col;
	int key;
	int tag;					//tag=0:结点为空 
}HNode;
typedef HNode HashTable[MAXSIZE];

/* 函数原型 */
int Algo_9_46(HashTable H, int row, int col);
Status CreateHash_9_46(FILE *fp, HashTable H);//创建哈希表 
int fHash_9_46(int row, int col);//根据行列值生成哈希地址 

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_46.txt","r");
	CreateHash_9_46(fp, H);
	fclose(fp);
	
	printf("查找测试：\n");
	p = Algo_9_46(H, 622,64);
	printf("下标为(%d %d)的关键字在哈希表第 %d 个位置。\n", 622, 64, p);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题9.46：查找指定行列值在哈希表中的位置┃
┗━━━━━━━━━━━━━━━━━━━*/
int Algo_9_46(HashTable H, int row, int col)
{
	int p;
	
	p = fHash_9_46(row, col);						
	
	while(H[p].tag==1&&(H[p].row!=row||H[p].col!=col))
		p = (p+1)%MAXSIZE;		//若出现“无效碰撞”则顺次往下查找 
	
	if(H[p].tag==1&&H[p].row==row&&H[p].col==col)
		return p;
	else
		return -1;				//此行列值下的关键字不存在时返回-1 
}

Status CreateHash_9_46(FILE *fp, HashTable H)
{
	int i, p;
	int row, col, key;
	
	for(i=0; i<MAXSIZE; i++)
		H[i].tag = 0;

	while(Scanf(fp, "%d%d%d", &row, &col, &key)==3) //录入关键字到哈希表 
	{
		p = fHash_9_46(row, col);
		
		while(H[p].tag==1)				//出现冲突
			p = (p+1)%MAXSIZE;
		
		if(H[p].tag==0)
		{
			H[p].tag = 1;
			H[p].row = row;
			H[p].col = col;
			H[p].key = key;
		}
		else							//此处未对失败情况做限制 
			return ERROR;		
	}
	
	return OK;
}

int fHash_9_46(int row, int col)	//哈希函数 
{
	int a, b, c;
	
	a = row%100;					//取行列值的后两位
	b = col%100;
	c = a*100 + b;					//c的范围在0~9999 
	
	return 2*c;
}
