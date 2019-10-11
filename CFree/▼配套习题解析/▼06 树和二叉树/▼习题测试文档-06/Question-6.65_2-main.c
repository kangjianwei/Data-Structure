#include <stdio.h>
#include <string.h>											//提供strlen原型 
#include <stdlib.h>											//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 全局变量 */
char Pre[] = "ABDGEHICFJ";
char In[] =  "GDBHEIAFJC";

/* 函数原型 */
BiTree Algo_6_65_2();
BiTree BuildTree_pre_in(int pre_start, int pre_end, int in_start, int in_end);	//递归创建二叉树 

int main(int argc, char *argv[])
{
	BiTree T;

	printf("二叉树先序序列为：%s\n", Pre);
	printf("二叉树中序序列为：%s\n", In);
	printf("\n");
			
	T = Algo_6_65_2(Pre, In);
	printf("由此构造的二叉树为：\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题6.65：根据前序序列和中序序列创建二叉树┃
┗━━━━━━━━━━━━━━━━━━━━*/
/* 方法2：递归遍历前序存储的结点创建二叉树 */
BiTree Algo_6_65_2()							//Pre与In设为全局变量 
{
	int len_pre, len_in;
	BiTree T;
	
	len_pre = strlen(Pre);
	len_in = strlen(In);
	
	T = BuildTree_pre_in(0, len_pre-1, 0, len_in-1);
	
	return T;
}

BiTree BuildTree_pre_in(int pre_start, int pre_end, int in_start, int in_end)
{
	BiTree T;
	int i, LTreeLen, RTreeLen;
	
	T = (BiTree)malloc(sizeof(BiTNode));		//建立根结点 
	if(!T)
		exit(OVERFLOW);
	T->data = Pre[pre_start];					//遍历前序存储的结点 
	T->lchild = T->rchild = NULL;				//初始化时置空左右孩子指针 
		
	i=in_start;
	while(In[i]!=T->data)						//在中序序列中寻找根结点位置
		i++;	 
	
	LTreeLen = i-in_start;						//左子树长度 
	RTreeLen = in_end - i;						//右子树长度
		
	if(LTreeLen) 								//左子树存在
		T->lchild = BuildTree_pre_in(pre_start+1, pre_start+LTreeLen, in_start, i-1);
	
	if(RTreeLen) 								//右子树存在
		T->rchild = BuildTree_pre_in(pre_start+LTreeLen+1, pre_end, i+1, in_end);

	return T;
}
