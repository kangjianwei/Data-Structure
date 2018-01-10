/*************************************
 *                                   *
 * 文件夹: ▲09 查找                 *
 *                                   *
 * 文件名: NearlyOptimalSearchTree.c *
 *                                   *
 * 算  法: 9.3、9.4                  *
 *                                   *
 *************************************/

#ifndef NEARLYOPTIMALSEARCHTREE_C
#define NEARLYOPTIMALSEARCHTREE_C

#include "NearlyOptimalSearchTree.h" 			//**▲09 查找**//

void FindSW(float sw[], Table T)
{
	int i;
	
	sw[0] = 0.0;
	
	for(i=1; i<=T.length; i++)
		sw[i] = sw[i-1] + T.elem[i].weight;
}

int MinSW(float sw[], int low, int high)
{
	int i,j;
	float min, tmp, dw;
	
	dw = sw[high] + sw[low-1];
	min = fabs(sw[high]-sw[low]);
	
	for(i=j=low; i<=high; i++)
	{
		tmp = fabs(dw - sw[i] - sw[i-1]);
		
		if(tmp<min)
		{
			j = i;
			min = tmp;
		}
	}
	
	return j;
}

/*════╗
║ 算法9.3║ 
╚════*/
void SecondOptimal(BiTree *BT, ElemType_Search R[], float sw[], int low, int high)
{
	int i;
	
	i = MinSW(sw, low, high);
	
	*BT = (BiTree)malloc(sizeof(BiTNode));
	(*BT)->data = ch[R[i].key];
	
	if(i==low)
		(*BT)->lchild = NULL;
	else
		SecondOptimal(&((*BT)->lchild), R, sw, low, i-1);
		
	if(i==high)
		(*BT)->rchild = NULL;
	else
		SecondOptimal(&((*BT)->rchild), R, sw, i+1, high);	 
}

/*════╗
║ 算法9.4║ 
╚════*/
Status CreateSOSTree(SOSTree *BT, Table T)
{
	float sw[T.length+1];
	
	if(T.length==0)
		*BT = NULL;
	else
	{
		FindSW(sw, T);
		SecondOptimal(BT, T.elem, sw, 1, T.length);
	}
	
	return OK;
}

Status Search_SOST(SOSTree BT, KeyType key)
{
	if(BT)
	{
		if(ch[key]==BT->data)
			return OK;
		else if(ch[key]<BT->data)
			return Search_SOST(BT->lchild, key);
		else
			return Search_SOST(BT->rchild, key);
	}
	
	return FALSE;
} 

#endif
