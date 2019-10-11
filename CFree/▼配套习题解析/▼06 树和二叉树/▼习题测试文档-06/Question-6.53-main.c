#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_53(BiTree T, int way[100]);

int main(int argc, char *argv[])
{
	BiTree T;
	int way[100];
	int i;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABD^^EG^^^CF^HI^^J^^^\n→");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_53.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");
	
	Algo_6_53(T, way);
	printf("输出根结点到叶子结点最长路径中最靠左的一条：");	
	for(i=1; i<=way[0]+1; i++)
		printf("%c ", way[i]);
	printf("\n\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题6.53：寻找根结点到叶子结点最长路径中最靠左的一条┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_6_53(BiTree T, int way[100])
{
	int path[100][100] = {};		//按行存放所有找到的路径，第0列存放路径长度 
	BiTNode node[100];				//临时存放遍历中各结点的复制品 
	int count, max_len;				//count记录路径总数，max_len记录路径最大长度 
	int i, k;
	
	if(!T)
		return ERROR;
	
	i = 0;
	count = max_len = 0;
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].lchild)					//先向左访问到尽头 
		{
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;
			i++;
		}
		
		if(node[i].rchild)						//左子树为空时，遍历右子树 
		{
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		else									//遇到叶子结点 
		{
			count++;							//路径总数增一 
			path[count-1][0] = i;				//存储路径长度 
			for(k=0; k<=i; k++)
				path[count-1][k+1] = node[k].data;
			if(max_len<i)						//记录最大路径长度 
				max_len = i;
			i--;
		}
	}//至此全部路径已找出 
			
	for(k=0; k<count; k++)
	{
		if(path[k][0]==max_len) 
		{
			for(i=0; i<=max_len+1; i++)
				way[i] = path[k][i];
			break;								//找到最左的一条即可 
		}
	}
	
	return OK;
}
