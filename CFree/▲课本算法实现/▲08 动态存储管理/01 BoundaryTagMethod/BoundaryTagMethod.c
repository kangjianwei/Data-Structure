/*******************************
 *						       *
 * 文件夹: ▲08 动态存储管理   *
 * 						       *
 * 文件名: BoundaryTagMethod.c *
 *    	    			       *
 * 算  法: 8.1                 * 
 *    	    				   *
 *******************************/

#ifndef BOUNDARYTAGMETHOD_C
#define BOUNDARYTAGMETHOD_C

#include "BoundaryTagMethod.h" 						//**▲08 动态存储管理**//

void InitSpace_a(WORD_a memory[MAX+2])
{
	Space pav;
	
	pav = &memory[0];

	memory[0].Ptr.llink = pav;	
	memory[0].tag = 0;
	memory[0].size = MAX;
	memory[0].rlink = pav;

	memory[MAX-1].Ptr.uplink = pav;
	memory[MAX-1].tag = 0;
	
	av = pav;
}

/*════╗
║ 算法8.1║ 
╚════*/
Space AllocBoundTag(Space *pav, int n)	//请求分配n个字 
{
	Space p, f;
	
	for(p=*pav; p && p->size<n && p->rlink!=*pav; p=p->rlink)
		;								//查找不小于n的空闲块
	
	if(!p || p->size<n)
		return NULL;					//找不到合适的空闲块
	else
	{									//寻找到不小于n的空闲块 
		f = FootLoc(p);					//指向此空闲块的底部
		*pav = p->rlink;				//pav指向p结点的后继结点 
		
		if(p->size-n<=E)				//整块分配，忽略<=E的剩余量
		{
			if(*pav==p)					//只有一个块 
				*pav = NULL;			//被占用后可利用表变为空表 
			else						//在表中删除分配的结点 
			{
				(*pav)->Ptr.llink = p->Ptr.llink; 
				p->Ptr.llink->rlink = *pav;
			}
			
			p->tag = f->tag = 1;		//设占用块标志为1 
		}
		else							//从中间切割，占用后面的部分 
		{
			f->tag = 1;					//修改分配块的底部标志
			p->size -= n;				//置剩余块大小
			
			f = FootLoc(p);				//指向剩余块底部 
			f->tag = 0;					//设置剩余块底部标志 
			f->Ptr.uplink = p;			
			
			p = f + 1;					//指向分配块头部 
			p->tag = 1;					//设置分配块头部 
			p->size = n; 
		}
		
		return p;						//p结点的llink和rlink域并未改变，这对回收空间有用 
	}	
}

void Reclaim_a(Space *pav, Space *p)
{
	Space f, s, t, q;
	int l, r;
	
	l = (*p - 1)->tag;								//l，r为指示释放块的左右邻块是否空闲 
	r = (*p + (*p)->size)->tag;
		
	if(!(*pav))										//可利用空间表为空 
	{
		*pav = (*p)->Ptr.llink = (*p)->rlink = *p;	//修改空闲表指针 
		(*p)->tag = (FootLoc(*p))->tag = 0;			//修改头尾标志 
		(FootLoc(*p))->Ptr.uplink = *p;				//修改尾部域 
	}
	else											//可利用空间表不为空 
	{
		if(l && r)									//左右邻区均不为空 
		{
			(*p)->tag = 0;
			(FootLoc(*p))->Ptr.uplink = *p;
			(FootLoc(*p))->tag = 0;
			
			q = (*pav)->Ptr.llink;
			(*p)->rlink = *pav;
			(*p)->Ptr.llink = q;
			q->rlink = (*pav)->Ptr.llink = *p;
			*pav = *p;								//令刚释放的结点为下次分配时的最先查询的结点 
		}
		else if(!l && r)							//左邻区为空，右邻区不为空 
		{
			s = (*p - 1)->Ptr.uplink;				//s指向左邻区（空闲时）的首地址
			s->size += (*p)->size;					//设置新空闲块大小 
			(FootLoc(*p))->Ptr.uplink = s;			//设置新的空闲块底部 
			(FootLoc(*p))->tag = 0;			
		}
		else if(l && !r)							//左邻区不为空，右邻区为空 
		{
			t = *p + (*p)->size;					//t指向右邻区（空闲时）的首地址
			(*p)->tag = 0;							//p为合并后的结点头部地址 

			q = t->Ptr.llink;						//此处q为右邻区的前驱结点首地址 
			(*p)->Ptr.llink = q;					//链接q与p 
			q->rlink = *p;
			
			q = t->rlink;							//此处q为右邻区的后继结点首地址 
			(*p)->rlink = q;						//链接q与p 
			q->Ptr.llink = *p;
			
			(*p)->size += t->size;					//新空闲块大小 
			(FootLoc(t))->Ptr.uplink = *p;			//底部指针指向新结点的头部	

			if(*pav==t)
				*pav = s;
		}
		else										//左右邻区均为空 
		{
			s = (*p - 1)->Ptr.uplink;				//s指向左邻区（空闲时）的首地址
			t = *p + (*p)->size;					//t指向右邻区（空闲时）的首地址
			
			s->size += (*p)->size + t->size;		//设置新结点大小
			t->Ptr.llink->rlink = t->rlink;			//跨过t链接 
			t->rlink->Ptr.llink = t->Ptr.llink;
			(FootLoc(t))->Ptr.uplink = s;			//新结点底部指针指向其头部
			
			if(*pav==t)
				*pav = s;
		} 
	}
	
	*p = NULL;	
}

void PrintLayout_a(Space av, Space pav)
{
	Space r;
	
	r = pav;
	printf("空闲块起止范围：┃");
	printf("%4d←→%4d┃", r-av+1, r+r->size-av);
	while(r->rlink!=pav)
	{
		r = r->rlink;
		printf("%4d←→%4d┃", r-av+1, r+r->size-av);
	}
	printf("\n");
}

#endif
