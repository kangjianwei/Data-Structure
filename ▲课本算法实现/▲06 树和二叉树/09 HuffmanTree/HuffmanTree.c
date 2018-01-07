/******************************************
 *								          *
 * 文件夹: ▲06 树和二叉树\09 HuffmanTree *
 * 								          *
 * 文件名: HuffmanTree.c                  *
 * 								          *
 * 算  法: 6.12、6.13                     * 
 *    	    			                  * 
 ******************************************/

#ifndef HUFFMANTREE_C
#define HUFFMANTREE_C

#include "HuffmanTree.h" 								//**▲06 树和二叉树**//

void InitTree_HT(HuffmanTree *HT)
{
	*HT = NULL;
}

Status CreateHuffmanTree_HT(FILE *fp, HuffmanTree *HT)
{
	int m, n;
	int w[MAX_TREE_SIZE];
	HuffmanTree p;
	int i;
	int s1, s2;

	Scanf(fp, "%d", &n); 	
	printf("录入哈夫曼树叶子结点个数→ %d\n", n);
	
	printf("依次录入各叶子结点的权值→ ");
	for(i=1; i<=n; i++)									//0号单元弃用
	{
		Scanf(fp, "%d", &w[i]);
		printf("%d ", w[i]);
	}
	printf("\n");
	
	m = 2*n - 1;										//哈夫曼树有效结点个数
		
	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0号单元弃用
	if(!(*HT))
		exit(OVERFLOW);
	
	(*HT)[0].weight = n;								//利用0号单元的权值存储哈夫曼树叶子个数
 		
	for(i=1; i<=m; i++)									//初始化结点[1...2*n+1]，存储叶子结点及双亲结点 
	{		
		if(i<=n)										 
			(*HT)[i].weight = w[i];						//[1...n]，叶子结点
		else											 
			(*HT)[i].weight = 0;						//[n+1...2*n+1]，双亲结点

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0; 
	} 
	
	for(i=n+1; i<=m; i++)								//建立哈夫曼树
	{
		Select_HT(*HT, i-1, &s1, &s2);
	
		(*HT)[s1].parent = (*HT)[s2].parent = i;

		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	
	return OK;
} 

Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2)
{
	HuffmanTree p;
	int i, count;
	int m, n, tmp;
	
	if(end<2)
		return ERROR;
	
	for(i=1,count=1; i<=end; i++)						//遍历找出前两个未编入树的结点 
	{
		if(HT[i].parent==0)
		{
			if(count==1)
				m = i;
			if(count==2)
				n = i;
			count++;
		}
		
		if(count>2)
			break;
	}
	
	if(HT[m].weight>HT[n].weight)						//令m结点的权重小于等于n结点的权重 
	{
		tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m>n ? m : n) + 1;
	while(i<=end)										//继续遍历，寻找更小更靠前的结点
	{	
		if(HT[i].parent==0)
		{
			if(HT[i].weight<HT[m].weight)
			{
				n = m;
				m = i;
			}
			else
			{
				if(HT[i].weight>=HT[m].weight && HT[i].weight<HT[n].weight)
					n = i;
			}		
		}
		
		i++;
	}
	
	*order_1 = HT[m].weight<=HT[n].weight ? m : n;
	*order_2 = HT[m].weight>HT[n].weight ? m : n;
	
	return OK;
}

/*═════╗
║ 算法6.12 ║ 
╚═════*/
Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC)
{
	char* code;
	int n, i;
	int start, c, f;
	
	n = HT[0].weight;									//叶子结点个数 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))
		exit(OVERFLOW);
	
	code = (char*)malloc(n*sizeof(char));
	if(!code)
		exit(OVERFLOW);	
	
	code[n-1] = '\0';									//字符串结尾 
	for(i=1; i<=n; i++)									//逐次求每个叶子结点的哈夫曼编码 
	{
		start = n - 1;									//赋值起点 
		for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		
		(*HC)[i] = (char*)malloc((n-start)*sizeof(char));
		
		strcpy((*HC)[i], &code[start]);					//从start开始复制 
	}
	
	free(code);
}

/*═════╗
║ 算法6.13 ║ 
╚═════*/
Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC)
{
	int m, n, i;
	int cdlen;
	int p, mark[MAX_TREE_SIZE];
	char* code;
		 
	n = HT[0].weight;									//哈夫曼树叶子结点个数
	m = 2 * n - 1;										//哈夫曼树结点个数 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))
		exit(OVERFLOW);	

	code = (char*)malloc(n*sizeof(char));
	if(!code)
		exit(OVERFLOW);	

	for(i=1; i<=n; i++)
		code[i] = '\0';
		
	for(i=1; i<=m; i++)									//初始化访问标记 
		mark[i] = 0;									//0、1、2分别表示访问过0次、1次、2次
	
	p = m;
	cdlen = 0;
	
	while(p)
	{
		if(mark[p]==0)									//第一次访问此结点
		{
			mark[p] = 1;
			if(HT[p].lchild!=0)							//向左访问 
			{
				p = HT[p].lchild;						//p向左走一步							
				code[cdlen] = '0';
				cdlen++;
			}
			else
			{
				if(HT[p].rchild==0)						//找到叶子结点 
				{
					(*HC)[p] = (char*)malloc((cdlen+1)*sizeof(char));
					strcpy((*HC)[p], code);				//复制编码串 
				}
			}
		}
		else
		{
			if(mark[p]==1)								//第二次访问此结点
			{
				mark[p] = 2;
				if(HT[p].rchild!=0)
				{
					p = HT[p].rchild;
					code[cdlen] = '1';
					cdlen++;
				}
			}
			else	//mark[p]==2						//第三次访问 
			{
				p = HT[p].parent;						//退回到父结点
				cdlen--;								//编码长度减1
				code[cdlen] = '\0'; 
			}
		}	
	}
	
	free(code);
} 

void ShowHuffmanTree_HT(HuffmanTree HT)
{
	int i;
	
	printf("┏━━━┳━━━┳━━━┳━━━┳━━━┓\n");
	printf("┃*order┃weight┃parent┃lchild┃rchild┃\n");
	for(i=0; i<=2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("┃  %2d  ┃ %4d ┃  ×  ┃  ×  ┃  ×  ┃\n", i, HT[i].weight);
		else
			printf("┃  %2d  ┃ %4d ┃  %2d  ┃  %2d  ┃  %2d  ┃\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC)
{
	int i;
	
	printf("┏━━━┳━━━┳━━━┳━━━━━━━┓\n");
	printf("┃*order┃weight┃      ┃  哈夫曼编码  ┃\n");
	for(i=1; i<=HT[0].weight; i++)
		printf("┃  %2d  ┃ %4d ┃──→  %-14s┃\n", i, HT[i].weight, HC[i]);	
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

#endif 
