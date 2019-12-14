/*******************************
 *						       *
 * �ļ���: ��08 ��̬�洢����   *
 * 						       *
 * �ļ���: GarbageCollection.c *
 *    	    			       *
 * ��  ��: 8.3                 * 
 *    	    				   *
 ******************************/

#ifndef GARBAGECOLLECTION_C
#define GARBAGECOLLECTION_C

#include "GarbageCollection.h" 						//**��08 ��̬�洢����**//

/*�T�T�T�T�[
�U �㷨8.3�U 
�^�T�T�T�T*/
void MakeList(GList G)
{
	GList t, p, q;
	
	Status finished;
	
	if(G && G->mark==0)
	{
		t = NULL;								//tΪp��ĸ�� 
		p = G;
		finished = FALSE;
		
		while(!finished)
		{
			while(p->mark==0)
			{
				p->mark = 1;					//MakeHead(p)��ϸ�� 
				q = p->Union.ptr.hp;			//qָ��p�ı�ͷ
				
				if(q!=NULL && q->mark==0) 
				{
					if(q->tag==Atom)			//��ͷΪԭ�ӽ��
						q->mark = 1;		
					else						//���������ӱ� 
					{
						p->Union.ptr.hp = t;
						p->tag = Atom;
						t = p;
						p = q;
					}
				}						 
			}									//��ɶԱ�ͷ�ı��
		
			q = p->Union.ptr.tp;
		
			if(q!=NULL && q->mark==0)			//����������β 
			{
				p->Union.ptr.tp = t;
				t = p;
				p = q;
			}
			else								//BackTrack(finished)��ϸ�� 
			{
				while(t && t->tag==List)		//���㣬�ӱ�β���� 
				{
					q = t;
					t = q->Union.ptr.tp;
					q->Union.ptr.tp = p;
					p = q;
				}
				
				if(t==NULL)						//���� 
					finished = TRUE;
				else							//�ӱ�ͷ���� 
				{
					q = t;
					t = q->Union.ptr.hp;
					q->Union.ptr.hp = p;
					p = q;
					p->tag = List;
				}								//����������β 
			}
		}
	}	
}

#endif
