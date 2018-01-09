/*******************************
 *						       *
 * 文件夹: ▲08 动态存储管理   *
 * 						       *
 * 文件名: GarbageCollection.c *
 *    	    			       *
 * 算  法: 8.3                 * 
 *    	    				   *
 ******************************/

#ifndef GARBAGECOLLECTION_C
#define GARBAGECOLLECTION_C

#include "GarbageCollection.h" 						//**▲08 动态存储管理**//

/*════╗
║ 算法8.3║ 
╚════*/
void MakeList(GList G)
{
	GList t, p, q;
	
	Status finished;
	
	if(G && G->mark==0)
	{
		t = NULL;								//t为p的母表 
		p = G;
		finished = FALSE;
		
		while(!finished)
		{
			while(p->mark==0)
			{
				p->mark = 1;					//MakeHead(p)的细化 
				q = p->Union.ptr.hp;			//q指向p的表头
				
				if(q!=NULL && q->mark==0) 
				{
					if(q->tag==Atom)			//表头为原子结点
						q->mark = 1;		
					else						//继续遍历子表 
					{
						p->Union.ptr.hp = t;
						p->tag = Atom;
						t = p;
						p = q;
					}
				}						 
			}									//完成对表头的标记
		
			q = p->Union.ptr.tp;
		
			if(q!=NULL && q->mark==0)			//继续遍历表尾 
			{
				p->Union.ptr.tp = t;
				t = p;
				p = q;
			}
			else								//BackTrack(finished)的细化 
			{
				while(t && t->tag==List)		//表结点，从表尾回溯 
				{
					q = t;
					t = q->Union.ptr.tp;
					q->Union.ptr.tp = p;
					p = q;
				}
				
				if(t==NULL)						//结束 
					finished = TRUE;
				else							//从表头回溯 
				{
					q = t;
					t = q->Union.ptr.hp;
					q->Union.ptr.hp = p;
					p = q;
					p->tag = List;
				}								//继续遍历表尾 
			}
		}
	}	
}

#endif
