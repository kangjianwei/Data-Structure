#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/04 ThreadBinaryTree/ThreadBinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_58(ThrBiTree p, ThrBiTree x);
void PrintElem(TElemType_Thr e);

int main(int argc, char *argv[])
{	
	ThrBiTree Thrt_1, T_1;
	ThrBiTree Thrt_2, T_2;
	ThrBiTree p, x;
	FILE *fp;
	char tmp;
	
	printf("预设二叉树先序序列为：ABDG^^^EH^^I^^CF^J^^^...\n");
	printf("预设需要插入的二叉树先序序列为：123^^4^^^...\n");

	fp = fopen("Data/Algo_6_58.txt", "r");
	CreateBiTree_Thr(fp, &T_1);
	Scanf(fp, "%c", &tmp);					//跳过换行符 
	CreateBiTree_Thr(fp, &T_2);

	InOrderThreading_Thr(&Thrt_1, T_1);	 
	InOrderThreading_Thr(&Thrt_2, T_2);	
	printf("\n");
	
	p = T_1->rchild;									//用于测试的p和x 
	x = T_2;
	
	printf("将 %c 及其子树插入到 %c 中...\n", x->data, p->data); 
	Algo_6_58(p, x);
	printf("\n");
	
	printf("中序输出插入完成后的树：");
	InOrderTraverse_Thr(Thrt_1, PrintElem);
	printf("\n\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题6.58：中序线索二叉树的插入┃
┗━━━━━━━━━━━━━━*/
Status Algo_6_58(ThrBiTree p, ThrBiTree x)
{
	ThrBiTree pre_p, x_first, lp_first;
	
	x_first = x;							// 寻找树x中序遍历第一个结点
	while(x_first->lchild && x_first->LTag!=Thread)
		x_first = x_first->lchild;
	
	pre_p = p->lchild;	// 记下p的左结点，可能是左线索，也可能是左子树 
	
	if(p->LTag==Thread)	// 如果p结点无左子树，则将x插入为左子树 
	{
		/* 此时，pre_p为p的前驱线索 */	
		
		p->LTag = Link;	// 修改标记，从线索到子树 
		p->lchild = x;
			
		x_first->lchild = pre_p;	// 修改树x最左结点的前驱 
							 
		x->rchild = p;	// 修改x的后继线索 
	}
	else				// p结点有左子树，则将该子树摘下，并将其插入为x的右子树 
	{
		/* 此时，pre_p为p的左子树 */
		
		x->RTag = Link;
		x->rchild = pre_p;	// 摘下p的左子树，作为x的右子树 
		
		lp_first = p;		// 寻找p的左子树的中序序列中第一个结点
		while(lp_first->LTag==Link)
			lp_first = lp_first->lchild;
		
		x_first->lchild = lp_first->lchild;	// 修改树x最左结点的前驱 
		lp_first->lchild = x;				// lp_first的左线索更新为x 
		
		p->lchild = x;	// 更新p的左子树 
	}
	
	return OK;
}

void PrintElem(TElemType_Thr e)
{
	printf("%c ",e);
}
