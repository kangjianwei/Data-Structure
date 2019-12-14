#include <stdio.h>
#include <limits.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"  	//**▲01 绪论**//

/* 宏定义 */
#define MAXKEY INT_MAX									//关键字可能的最大值 
#define W 6												//工作区缓存

/* 类型定义 */
typedef int KeyType;									//定义关键字类型为整数类型
typedef int LoserTree[W];								//败者树叶节点存储结构
typedef KeyType WorkArea[W];							//内存工作区，容量为W 

/* 全局变量 */
KeyType cache[W+1];										//辅助存储区，容量为W 
int output[11][101];									//存储归并后的序列

/* 函数原型 */
void Algo_11_13(FILE *fi, LoserTree ls, WorkArea wa);
void GetRun_11_13(FILE *fi, LoserTree ls, WorkArea wa);
	//求得一个初始归并段
void MiniMax_11_13(LoserTree ls, WorkArea wa, int q);
void BuildLoser_11_13(KeyType cache[W+1], LoserTree ls, WorkArea wa);
	//从辅助存取区读取记录创建败者树

int main(int argc, char *argv[])
{	
	FILE *fi;									//输入文件 
	LoserTree ls;								//败者树 
	WorkArea wa;								//工作空间
	int i,j,k;
		
	printf("自然选择排序...\n");
	fi = fopen("Data/Algo_11_13.txt", "r");		//读取输入文件	
	Algo_11_13(fi, ls, wa);						//分割fi
	printf("\n");	
	
	printf("排序前的序列...\n");
	fi = fopen("Data/Algo_11_13.txt", "r");		//读取输入文件
	while(!feof(fi))
	{
		Scanf(fi,"%d",&k);
		printf("%d ", k);
	}
	printf("\n\n");
	fclose(fi);	

	printf("排序后的序列...\n");		
	for(i=1; i<=output[0][0]; i++)
	{
		printf("RUN%2d：", i);
		for(j=1; j<=output[i][0]; j++)
			printf("%d ", output[i][j]);
		printf("\n");
	}
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题11.13：自然选择排序 ┃
┗━━━━━━━━━━━*/
void Algo_11_13(FILE *fi, LoserTree ls, WorkArea wa)
{
	int i;
	FILE *fo;
	
	for(i=1; i<=W; i++)
		Scanf(fi, "%d", &cache[i]),cache[0]++;	
	BuildLoser_11_13(cache, ls, wa);				//从辅助存取区读取记录创建败者树
											
	output[0][0] = 0;
	
	while(!feof(fi) || cache[0])					//无任何缓存内存 
	{
		output[0][0]++;
		output[output[0][0]][0] = 0;
		
		if(cache[0]==W || (cache[0]>0&&feof(fi)))
			BuildLoser_11_13(cache, ls, wa);		//从辅助存取区读取记录创建败者树
			
		GetRun_11_13(fi, ls, wa);					//求得一个初始归并段
	}
	
	fclose(fi);
}

void GetRun_11_13(FILE *fi, LoserTree ls, WorkArea wa)
{
	int q, minimax, tag;
	int m, n;
	
	m = output[0][0];
	n = output[m][0];
	
	if(wa[ls[0]]!=MAXKEY)	
	{
		q = ls[0];								//q指示MINIMAX记录在wa中的位置 
		minimax = wa[q];
		n++;
		output[m][n] = wa[q];
	}
	
	while(cache[0]!=W && wa[ls[0]]!=MAXKEY)
	{
		tag=Scanf(fi, "%d", &wa[q]);
		
		if(tag!=1)								//读取失败，则输入文件结束
		{
			wa[q] = MAXKEY;
			break;
		}			 
		else
		{			
			if(wa[q]<minimax)					//新读入的记录属于下一段
			{
				cache[0]++;
				cache[cache[0]] = wa[q];
				if(cache[0]==W)
				{
					wa[q] = MAXKEY;	
					break;
				}
			}
			else
			{
				MiniMax_11_13(ls, wa, q); 		//选择新的MINIMAX记录			
				q = ls[0];						//q指示MINIMAX记录在wa中的位置 
				minimax = wa[q];
				n++;
				output[m][n] = wa[q];
			}
		}		 
	}
	
 
	while(minimax!=MAXKEY)
	{		
		MiniMax_11_13(ls, wa, q); 				//选择新的MINIMAX记录
		
		if(wa[ls[0]]!=MAXKEY)
		{
			q = ls[0];
			minimax = wa[q];
			n++;
			output[m][n] = wa[q];
			wa[q] = MAXKEY;
		}
		else
			minimax = MAXKEY;
	}
	
	output[m][0] = n;
}

void MiniMax_11_13(LoserTree ls, WorkArea wa, int q)
{
	int p, t, tmp;
	 
	for(t=(W+q)/2,p=ls[t]; t>0; t=t/2,p=ls[t])
	{
		if(wa[p]<wa[q])
		{
			tmp = q;						//q指向新的胜利者 
			q = ls[t];
			ls[t] = tmp;
		}
	}
	
	ls[0] = q;
}

void BuildLoser_11_13(KeyType cache[W+1], LoserTree ls, WorkArea wa)	//工作区wa是一棵败者树 
{
	int i;
	 
	for(i=0; i<W; i++)
		wa[i] = ls[i] = 0;					//工作区初始化
		
	for(i=W-1; i>=0; i--)
	{		
		if(cache[0]>0)
		{
			cache[0]--;
			wa[i] = cache[W-i];				//读入一个记录
		}			
		else
			wa[i] = MAXKEY;

		MiniMax_11_13(ls, wa, i);			//调整败者 
	}
}
