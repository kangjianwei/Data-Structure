#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  										//**▲01 绪论**//

/* 类型定义 */
typedef int LElemType_DC;
typedef struct DuLNode					//双向链表结构体
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
	int freq;							//访问频度域 
}DuLNode;
typedef DuLNode* DuLinkList;		 	//指向双循环链表结构的指针 

/* 函数原型 */
DuLinkList Algo_2_38(DuLinkList *L, LElemType_DC e);
Status CreatList_DuL_2_38(DuLinkList *L, int n, LElemType_DC Data[]);
void Output_DuL_2_38(DuLinkList L);

int main(int argc, char *argv[])
{
	DuLinkList L, p;
	int i;
	LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
	LElemType_DC tmp[10] = {1,2,2,2,3,4,4,5,5,9}; 
	
	CreatList_DuL_2_38(&L, 10, data);
	printf("初始化：L = \n");
	Output_DuL_2_38(L);
	printf("\n\n");
	
	// 依次访问tmp中预设的数字 
	for(i=0; i<10; i++)
		Algo_2_38(&L, tmp[i]);
	
	printf("访问之后：L = \n");
	Output_DuL_2_38(L);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.38：定位L中元素e的位序，并按访问频度重排链表假设链表中元素不重复┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
DuLinkList Algo_2_38(DuLinkList *L, LElemType_DC e)
{	
	DuLinkList p, pre;
	int i;
	
	if(!(*L))				//链表不存在
		return NULL;
	
	// 查找结点e的所在 
	for(p=*L; p; p=p->next)
	{
		// 找到了e 
		if(p->data==e)
		    break;		
        
        // 没找到，但是到了终点 
	    if(p->next==p)
	    {
		    p = NULL;
		    break;
		}		 
	}
	
	if(p!=NULL)							//找到了与e相等的结点 
	{
		p->freq++;						//访问频度递增 
		
		if(p!=*L)						//p不在首位的话，需要考虑重新摆放 
		{
		    for(pre=p->prior; pre->freq<p->freq; pre=pre->prior)
			{
				// 已经找到头，但没有找到比p的频度更大的结点 
			    if(pre==*L)
			    {
				    pre = NULL;
				    break;
				}
			}
			
			p->next->prior= p->prior;	//摘下结点p 
			p->prior->next = p->next;
			
			if(pre==NULL)	// p做为新的链表头部
			{
				p->prior = (*L)->prior;
				p->prior->next = p;
				p->next = *L;
			    (*L)->prior = p;
			    *L = p;
			}
			else			// p放到pre之后 
			{
			    p->prior = pre;
			    p->next = pre->next;
			    p->next->prior = p;
			    pre->next = p;
			}
		}
	}
	
	return p;	// 返回当前结点指针 
}

//从无到有创建，没有头结点 
Status CreatList_DuL_2_38(DuLinkList *L, int n, LElemType_DC Data[])	
{
	DuLinkList s, h;
	int i;
	
	*L = NULL;
	
	for(i=0; i<n; i++)
	{
	    s = (DuLinkList)malloc(sizeof(DuLNode));
		if(!s)
			exit(OVERFLOW);
		s->data = Data[i];
		s->freq = 0;
		
		if(*L==NULL)
		{
		    h = *L = s;
		    s->next = s->prior = s;
		}
		else
		{
			// 尾插
			s->next = *L;
			s->prior = h; 
		    h->next = s;
			(*L)->prior = s;
			
			h = h->next;
		} 
	}
	
	s = NULL;
}

void Output_DuL_2_38(DuLinkList L)
{
	DuLinkList p = L;
	
	printf("数据：");
	for(p=L; p; p=p->next)
	{
	    printf("%2d ", p->data);
	    
	    if(p->next==L)
            break;
	}
	
	printf("\n频度：");
	for(p=L; p; p=p->next)
	{
	    printf("%2d ", p->freq);
	    
	    if(p->next==L)
            break;
	}
}
