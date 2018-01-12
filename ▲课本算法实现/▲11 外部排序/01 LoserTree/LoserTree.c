/****************************
 *                          *
 * 文件夹: ▲11 外部排序    *
 *                          *
 * 文件名: LoserTree.c      *
 *                          *
 * 算  法: 11.1、11.2、11.3 *
 *                          *
 ****************************/

#ifndef LOSERTREE_C
#define LOSERTREE_C

#include "LoserTree.h"			//**▲11 外部排序**//

/*════╗
║算法11.1║ 
╚════*/
void K_Merge(FILE *fp_out, LoserTree ls, External b)
{
	int i, q;
	FILE *fp_in[K] = {};				//k个输入归并段 
		
	for(i=0; i<K; i++)					//分别从k个归并输入段读入该段当前首个记录的关键字到外结点
		input(fp_in, &(b[i].key), i);	//b[0..k-1]为败者树上的k个叶子结点，分别存放k个输入归并段中当前记录的关键字
	
	CreateLoserTree(ls, b);				//建败者树ls，选得最小关键字为b[ls[0]].key 
	
	while(b[ls[0]].key!=MAXKEY)
	{
		q = ls[0];						//q指示当前最小关键字所在归并段 
		output(fp_out, b[q].key);		//将编号为q的归并段中当前(关键字为b[q].key)的记录写至输出归并段
		input(fp_in, &(b[q].key), q);	//从编号为q的输入归并段中读入下一个记录的关键字 
		Adjust(ls, b, q);				//调整败者树，选择新的最小关键字 
	}
	
	output(fp_out, b[ls[0]].key);		//将含最大关键字MAXKEY的记录写至输出归并段
	
	fclose(fp_out);
}

/*════╗
║算法11.2║ 
╚════*/
void Adjust(LoserTree ls, External b, int s)
{
	int t, tmp;
	
	t = (s+K)/2;						//ls[t]是b[s]的双亲结点 
	
	while(t>0)							//沿从叶子结点b[s]到根结点ls[0]的路径调整败者树 
	{
		if(b[s].key>b[ls[t]].key)		//s指示新的胜利者（小为胜，向上比较，大为败，留在双亲结点） 
		{
			tmp = s;
			s = ls[t];
			ls[t] = tmp;
		}
		
		t = t/2;
	}
	
	ls[0] = s;							//顶部结点为最小值 
}

/*════╗
║算法11.3║ 
╚════*/
void CreateLoserTree(LoserTree ls, External b)
{										//b[0..k-1]为完全二叉树ls的叶子结点存有k个关键字
	int i;
	 
	b[K].key = MINKEY;					//设MINKEY为关键字可能的最小值		 
	
	for(i=0; i<K; i++)
		ls[i] = K;						//设置ls中“败者”的初值 
	
	for(i=K-1; i>=0; i--)				//依次从b[k-1..0]出发调整败者 
		Adjust(ls, b, i);
}

void Cut_Sort(FILE *fp)					//分段归并排序 
{
	FILE *fptr;							//fptr指向[0..n-1].txt 
	SqList_sort L;	
	int i, j;
	KeyType tmp;
	int len, m, n;
	char str1[100], str2[100], str3[100] = ".txt";
	
	Scanf(fp, "%d", &len);				//关键字总个数 
		
	m = len/K;							//m为一次可以处理的最大数字个数					
	n = K+(len%m!=0);					//n为归并段个数 

	system("md tmpfile");				//创建临时文件夹tmp 
	
	for(i=0; i<n; i++)					//分n批读取
	{
		strcpy(str1, "tmpfile/");		
		itoa(i, str2, 10);				//[0..k-1]
	 	strcat(str1, strcat(str2, str3));//tmpfile/[0..k-1].txt
		
		fptr = fopen(str1, "w+");		//存储局部有序关键字(归并排序)，[0..n-1].txt 
		
		L.length = 0;		
		for(j=1; j<=m; j++)				 
		{
			if(Scanf(fp, "%d", &tmp)==1)
			{
				L.length++;
				L.r[L.length].key = tmp;
			}
			else
				break;
		}
		
		MergeSort(&L);

		for(j=1; j<=L.length; j++)
			fprintf(fptr, "%d，", L.r[j].key);
		fprintf(fptr, "%d", MAXKEY);		//写入结束标志 
		fclose(fptr);
	}
	
	fclose(fp);	
}

void input(FILE *fp[K], int *x, int i)		//i=0..k-1
{
	int tmp;
	char str1[100], str2[100], str3[100] = ".txt";
		
	if(!fp[i])								//打开新文件读取 
	{
		strcpy(str1, "tmpfile/");		
		itoa(i, str2, 10);					//[0..k-1]
	 	strcat(str1, strcat(str2, str3));	//tmpfile/[0..k-1].txt

		fp[i] = fopen(str1, "r");			//从fp[i]中开始读取 
	}
			
	if(Scanf(fp[i], "%d", &tmp)==1)
	{
		*x = tmp;

		if(tmp==MAXKEY)
			fclose(fp[i]);
	}
}

void output(FILE *fp, int x)
{
	fprintf(fp, "%d，", x);
}

void RandomNum(FILE *fp)
{
	int i, j, number, tag;
	int x[MAX+1]={0};						//生成MAX个随机数 

	srand((unsigned)time(NULL)); 
	
	for(i=1; i<=MAX; i++)
	{		
		do
		{		
			number = rand()%(4*MAX-1) + 1;	//随机数范围1..4*MAX-1 

			tag = 0;			
			for(j=1; j<=x[0]; j++)			//保证随机数不重复 
			{
				if(number==x[j])
				{
					tag = 1;
					break;
				}		
			}
			
			if(tag==0)
			{
				x[0]++;
				x[x[0]] = number;
			}
		}while(tag==1);
	}
 
	fprintf(fp, "（%d），", MAX);
	for(i=1; i<=x[0]; i++)
		fprintf(fp, "%d，", x[i]);

	fclose(fp);
}

#endif
