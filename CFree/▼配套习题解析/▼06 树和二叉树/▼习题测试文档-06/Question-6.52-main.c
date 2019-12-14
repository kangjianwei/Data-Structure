#include <stdio.h>
#include <math.h>								//提供pow、log原型 
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
int Algo_6_52(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_52.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");
		
	printf("树的繁茂度为： %d", Algo_6_52(T));		
	printf("\n\n");
	
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.52：计算二叉树的繁茂度┃
┗━━━━━━━━━━━━━*/
int Algo_6_52(BiTree T)
{
	int i, j, level, v;
	float f;
	int max_row, max_col;				//记录最大层数与树最宽处结点个数 
	BiTree p[100] = {};					//树指针数组，模拟队列 
	int order[100] = {}; 				//存放各结点序号（按满二叉树计算） 
	int count[100] = {};				//下标代表层，数组内容为各层结点个数 

	v = 0;
	i = j = 0;
	max_row = max_col = 0;

	if(T)								//遍历的同时为各结点编号 
	{
		p[j] = T;	
		order[j] = 1;
		j++;
		
		while(i<j)
		{
			f = log(order[i])/log(2);
			level = (int)f + 1;			//计算当前结点所在层数
			if(max_row<level)
				max_row = level;
		
			count[level]++;				//递增当前层结点个数 
			if(max_col<count[level])
				max_col = count[level];
			
			if(p[i]->lchild)
			{
				p[j] = p[i]->lchild;
				order[j] = 2*order[i];
				j++;			
			}

			if(p[i]->rchild)
			{
				p[j] = p[i]->rchild;
				order[j] = 2*order[i]+1;
				j++;
			}
			
			i++;		
		}
	}
	
	v = max_row * max_col;				//计算繁茂度 
	
	return v;
}
