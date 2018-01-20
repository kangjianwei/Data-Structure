#include <stdio.h>
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_7_39(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;												//输入源 
	char tmp;
		
	InitBiTree(&T); 

	printf("创建二叉树（先序序列）B1→/+*+a^^b^^*b^^-c^^d^^*-c^^d^^e^^*-c^^d^^e^^...\n");
	fp = fopen("Data/Algo_7_39.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树为：\n");
	PrintTree(T);
	printf("\n"); 

	printf("此表达式的逆波兰式为：");	
	Algo_7_39(T);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题7.39： 表达式的二叉链表存储结构 ┃
┗━━━━━━━━━━━━━━━━━*/
void Algo_7_39(BiTree T)			//用二叉树存储			
{
	if(T)							//本质是后序遍历 
	{
		Algo_7_39(T->lchild);
		Algo_7_39(T->rchild);
		printf("%c", T->data);
	}	
}
