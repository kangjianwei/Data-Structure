#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 宏定义 */
#define MAX_TREE_SIZE 100						//树的最大结点数 

/* 树的双亲存储类型定义 */
typedef struct PTNode							//结点结构 
{
	char data;
	int parent;									//双亲位置域 
}PTNode; 
typedef struct									//树结构 
{
	PTNode nodes[MAX_TREE_SIZE];				//根结点位置默认到0，为了操作方便
	int n;										//树的结点数
}PTree;

/* 函数原型 */
CSTree Algo_6_66(PTree T); 

int main(int argc, char *argv[])
{
	PTree PT;
	CSTree CST;
	
	PT.n = 10;
	
	PT.nodes[0].data = 'R'; PT.nodes[0].parent = -1;
	PT.nodes[1].data = 'A'; PT.nodes[1].parent = 0;
	PT.nodes[2].data = 'B'; PT.nodes[2].parent = 0;
	PT.nodes[3].data = 'C'; PT.nodes[3].parent = 0;
	PT.nodes[4].data = 'D'; PT.nodes[4].parent = 1;
	PT.nodes[5].data = 'E'; PT.nodes[5].parent = 1;
	PT.nodes[6].data = 'F'; PT.nodes[6].parent = 3;
	PT.nodes[7].data = 'G'; PT.nodes[7].parent = 6;
	PT.nodes[8].data = 'H'; PT.nodes[8].parent = 6;
	PT.nodes[9].data = 'K'; PT.nodes[9].parent = 6;
	
	CST = Algo_6_66(PT); 
	
	printf("创建的孩子兄弟二叉树为：\n");
	Print_CS(CST);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━┓
┃ 题6.66：树的双亲表示法→树的孩子-兄弟表示法┃
┗━━━━━━━━━━━━━━━━━━━━━━*/
CSTree Algo_6_66(PTree T) 						//由树的双亲结构创建创建树的孩子-兄弟链表 
{
	int i, j, k;
	CSTree p, q;
	CSTree tmp[100];
	
	for(i=0,j=0; i<T.n; i++)					//双亲表按层序存储
	{
		k = T.nodes[i].parent;
		
		p = (CSTree)malloc(sizeof(CSNode));
		if(!p)
			exit(OVERFLOW);
		p->data = T.nodes[i].data;
		p->firstchild = p->nextsibling = NULL;
		
		if(k!=-1)
		{
			if(tmp[k]->firstchild==NULL)		//作为第一个孩子 
				tmp[k]->firstchild = p;
			else
			{
				q = tmp[k]->firstchild;			//寻找孩子链表的末端 
				while(q->nextsibling)
					q = q->nextsibling;
				q->nextsibling = p;
			}	
		}
		
		tmp[j++] = p;	
	}
	
	if(j)
		return tmp[0];
	else
		return NULL;
}
