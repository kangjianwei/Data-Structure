#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_50(FILE *fp, BiTree *T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp; 

	printf("创建二叉树（层序序列）...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_50.txt", "r");
	Algo_6_50(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);	
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题6.50：按层序创建二叉树（输入形式如题）┃
┗━━━━━━━━━━━━━━━━━━━━*/
void Algo_6_50(FILE *fp, BiTree *T)
{
	char input[4];
	BiTree tmp[100];								//顺序存储遇到的每个结点 
	int m, n;
	BiTree p;
	
	m = n = 0;
	printf("读到的序列→\n");
	while(1)
	{			
		Scanf(fp, "%s", input);
		printf("%s\n", input);
		
		if(input[1]=='^')							//退出标志 
			break;
		else
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			if(!p)
				exit(OVERFLOW);
			p->data = input[1];
			p->lchild = p->rchild = NULL;
			
			if(input[0]=='^')						//根结点   
				*T = p;
			else
			{
				while(tmp[m]->data!=input[0])		//寻找子树结点 
					m++;
					
				if(input[2]=='L')
					tmp[m]->lchild = p;
				else
					tmp[m]->rchild = p;				
			}
			
			tmp[n++] = p;
		}
	}
}
