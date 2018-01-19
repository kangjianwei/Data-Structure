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
	ThrBiTree pre_p, suc_p, x_first;
	if(p->LTag==Link && p->RTag==Link)
		return ERROR;
		
	if(p->LTag!=Link)							//p结点无左子树，x插入为左子树 
	{
		pre_p = p->lchild;						//pre_p标记为p的前驱		
		p->LTag = Link;							//修改标记
		p->lchild = x;
		
		x_first = x;							//寻找树x中序遍历第一个结点
		while(x_first->lchild && x_first->LTag!=Thread)
			x_first = x_first->lchild;
		x_first->lchild = pre_p;				//修改树x最左结点前驱 
							 
		x->rchild = p;							//修改x的后继
	}
	else										//p结点有左子树，x插入为右子树 
	{
		suc_p = p->rchild;
		p->RTag = Link;
		p->rchild = x;
		
		x_first = x;							//寻找树x中序遍历第一个结点
		while(x_first->lchild && x_first->LTag!=Thread)
			x_first = x_first->lchild;
		x_first->lchild = p;
		
		x->rchild = suc_p;						//修改x的后继	
	}
	
	return OK;
}

void PrintElem(TElemType_Thr e)
{
	printf("%c ",e);
}
