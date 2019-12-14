#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_59(CSTree T);
int Algo_6_60(CSTree T);
int Algo_6_61(CSTree T);
int Algo_6_62(CSTree T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp;

	 
	printf("录入先序序列：RAD^E^^B^CFG^H^K^^^^^...\n");
	InitTree_CS(&T);
	fp = fopen("Data/Algo_6_59-6.62.txt", "r");	 
	CreateTree_CS(fp, &T); 
	fclose(fp);
	printf("\n");
	
	printf("███题 6.59 验证...███\n");
	{
		printf("输出所有边...\n→");
		Algo_6_59(T);
		printf("\n\n");	
	}
	
	printf("███题 6.60 验证...███\n");
	{
		int count;
		
		count = Algo_6_60(T);
		printf("叶子结点个数为：count = %d\n", count);
		printf("\n");	
	}

	printf("███题 6.61 验证...███\n");
	{
		int degree;
		
		degree = Algo_6_61(T);
		printf("树的度为：degree = %d\n", degree);
		printf("\n");	
	}	

	printf("███题 6.62 验证...███\n");
	{
		int depth;
		
		depth = Algo_6_62(T);
		printf("树的深度为：depth = %d\n", depth);
		printf("\n");	
	}
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题6.59：输出树的各条边┃
┗━━━━━━━━━━━*/
void Algo_6_59(CSTree T)
{
	CSTree p, q;
	
	if(T)
	{
		p = T;
		q = T->firstchild;
		
		while(q)
		{
			printf("(%c, %c) ", p->data, q->data);
			q = q->nextsibling;
		}
		
		Algo_6_59(T->firstchild);
		Algo_6_59(T->nextsibling);
	}
} 

/*━━━━━━━━━━━━━┓
┃题6.59：求树的叶子结点个数┃
┗━━━━━━━━━━━━━*/
int Algo_6_60(CSTree T)
{	
	if(T)
	{
		if(!T->firstchild)
			return 1 + Algo_6_60(T->nextsibling);
		else
			return Algo_6_60(T->firstchild) + Algo_6_60(T->nextsibling);
	}
	else
		return 0;
}

/*━━━━━━━━┓
┃题6.61：求树的度┃
┗━━━━━━━━*/
int Algo_6_61(CSTree T)
{
	return TreeDegree_CS(T);						//已定义 
}

/*━━━━━━━━━┓
┃题6.62：求树的深度┃
┗━━━━━━━━━*/
int Algo_6_62(CSTree T)
{
	return TreeDepth_CS(T);							//已定义 
}
