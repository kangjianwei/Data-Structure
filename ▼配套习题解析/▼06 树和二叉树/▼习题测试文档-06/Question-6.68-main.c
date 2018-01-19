#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 类型定义 */
typedef	struct 
{
	TElemType_CS e;						//结点的值 
	int d;								//结点的度 
}TreeNode;

/* 函数原型 */
void Algo_6_68(CSTree *T, TreeNode node[]);

int main(int argc, char *argv[])
{
	CSTree T;
	TreeNode node[100];
	
	node[0].e = '\0'; node[0].d = 10;		//0号单元d存储结点个数 
	node[1].e = 'R';  node[1].d = 3;
	node[2].e = 'A';  node[2].d = 2;
	node[3].e = 'B';  node[3].d = 0;
	node[4].e = 'C';  node[4].d = 1;
	node[5].e = 'D';  node[5].d = 0;
	node[6].e = 'E';  node[6].d = 0;
	node[7].e = 'F';  node[7].d = 3;
	node[8].e = 'G';  node[8].d = 0;
	node[9].e = 'H';  node[9].d = 0;
	node[10].e = 'K'; node[10].d = 0;
	
	Algo_6_68(&T, node); 
	
	printf("创建的孩子兄弟二叉树为：\n");
	Print_CS(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃ 题6.68：创建树的孩子-兄弟结构┃
┗━━━━━━━━━━━━━━━*/
void Algo_6_68(CSTree *T, TreeNode node[])				//node中存储各结点及其度的信息			
{
	int i, j, count;
	int m;
	CSTree p, q;
	CSTree tmp[100];
	
	*T = NULL;
	
	if(node[0].d)										//树不为空 
	{
		i = j = 1;
		
		*T = (CSTree)malloc(sizeof(CSNode));			//根结点 
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = node[j].e;
		(*T)->firstchild = (*T)->nextsibling = NULL;
			
		tmp[j] = (*T);
		
		count = 0;
		while(j+1<=node[0].d)							//j遍历速度较快 
		{
			if(count<node[i].d)							//统计i结点的孩子 
			{
				++count;
				++j;			
		
				p = (CSTree)malloc(sizeof(CSNode));	
				if(!p)
					exit(OVERFLOW);
				p->data = node[j].e;
				p->firstchild = p->nextsibling = NULL;
					
				tmp[j] = p;			
				
				if(tmp[i]->firstchild==NULL)			//作为第一个孩子 
					tmp[i]->firstchild = p;
				else
				{
					q = tmp[i]->firstchild;				//寻找孩子链表的末端 
					while(q->nextsibling)
						q = q->nextsibling;
					q->nextsibling = p;
				}
			}
			
			if(count==node[i].d)						//i结点的孩子已遍历完 
			{
				i++;									//开始新的结点 
				count = 0;
			}
		}
	}
}
