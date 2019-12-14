/*******************************
 *						       *
 * �ļ���: ��08 ��̬�洢����   *
 * 						       *
 * �ļ���: BoundaryTagMethod.c *
 *    	    			       *
 * ��  ��: 8.1                 * 
 *    	    				   *
 *******************************/

#ifndef BOUNDARYTAGMETHOD_C
#define BOUNDARYTAGMETHOD_C

#include "BoundaryTagMethod.h" 						//**��08 ��̬�洢����**//

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

/*�T�T�T�T�[
�U �㷨8.1�U 
�^�T�T�T�T*/
Space AllocBoundTag(Space *pav, int n)	//�������n���� 
{
	Space p, f;
	
	for(p=*pav; p && p->size<n && p->rlink!=*pav; p=p->rlink)
		;								//���Ҳ�С��n�Ŀ��п�
	
	if(!p || p->size<n)
		return NULL;					//�Ҳ������ʵĿ��п�
	else
	{									//Ѱ�ҵ���С��n�Ŀ��п� 
		f = FootLoc(p);					//ָ��˿��п�ĵײ�
		*pav = p->rlink;				//pavָ��p���ĺ�̽�� 
		
		if(p->size-n<=E)				//������䣬����<=E��ʣ����
		{
			if(*pav==p)					//ֻ��һ���� 
				*pav = NULL;			//��ռ�ú�����ñ��Ϊ�ձ� 
			else						//�ڱ���ɾ������Ľ�� 
			{
				(*pav)->Ptr.llink = p->Ptr.llink; 
				p->Ptr.llink->rlink = *pav;
			}
			
			p->tag = f->tag = 1;		//��ռ�ÿ��־Ϊ1 
		}
		else							//���м��иռ�ú���Ĳ��� 
		{
			f->tag = 1;					//�޸ķ����ĵײ���־
			p->size -= n;				//��ʣ����С
			
			f = FootLoc(p);				//ָ��ʣ���ײ� 
			f->tag = 0;					//����ʣ���ײ���־ 
			f->Ptr.uplink = p;			
			
			p = f + 1;					//ָ������ͷ�� 
			p->tag = 1;					//���÷����ͷ�� 
			p->size = n; 
		}
		
		return p;						//p����llink��rlink��δ�ı䣬��Ի��տռ����� 
	}	
}

void Reclaim_a(Space *pav, Space *p)
{
	Space f, s, t, q;
	int l, r;
	
	l = (*p - 1)->tag;								//l��rΪָʾ�ͷſ�������ڿ��Ƿ���� 
	r = (*p + (*p)->size)->tag;
		
	if(!(*pav))										//�����ÿռ��Ϊ�� 
	{
		*pav = (*p)->Ptr.llink = (*p)->rlink = *p;	//�޸Ŀ��б�ָ�� 
		(*p)->tag = (FootLoc(*p))->tag = 0;			//�޸�ͷβ��־ 
		(FootLoc(*p))->Ptr.uplink = *p;				//�޸�β���� 
	}
	else											//�����ÿռ��Ϊ�� 
	{
		if(l && r)									//������������Ϊ�� 
		{
			(*p)->tag = 0;
			(FootLoc(*p))->Ptr.uplink = *p;
			(FootLoc(*p))->tag = 0;
			
			q = (*pav)->Ptr.llink;
			(*p)->rlink = *pav;
			(*p)->Ptr.llink = q;
			q->rlink = (*pav)->Ptr.llink = *p;
			*pav = *p;								//����ͷŵĽ��Ϊ�´η���ʱ�����Ȳ�ѯ�Ľ�� 
		}
		else if(!l && r)							//������Ϊ�գ���������Ϊ�� 
		{
			s = (*p - 1)->Ptr.uplink;				//sָ��������������ʱ�����׵�ַ
			s->size += (*p)->size;					//�����¿��п��С 
			(FootLoc(*p))->Ptr.uplink = s;			//�����µĿ��п�ײ� 
			(FootLoc(*p))->tag = 0;			
		}
		else if(l && !r)							//��������Ϊ�գ�������Ϊ�� 
		{
			t = *p + (*p)->size;					//tָ��������������ʱ�����׵�ַ
			(*p)->tag = 0;							//pΪ�ϲ���Ľ��ͷ����ַ 

			q = t->Ptr.llink;						//�˴�qΪ��������ǰ������׵�ַ 
			(*p)->Ptr.llink = q;					//����q��p 
			q->rlink = *p;
			
			q = t->rlink;							//�˴�qΪ�������ĺ�̽���׵�ַ 
			(*p)->rlink = q;						//����q��p 
			q->Ptr.llink = *p;
			
			(*p)->size += t->size;					//�¿��п��С 
			(FootLoc(t))->Ptr.uplink = *p;			//�ײ�ָ��ָ���½���ͷ��	

			if(*pav==t)
				*pav = s;
		}
		else										//����������Ϊ�� 
		{
			s = (*p - 1)->Ptr.uplink;				//sָ��������������ʱ�����׵�ַ
			t = *p + (*p)->size;					//tָ��������������ʱ�����׵�ַ
			
			s->size += (*p)->size + t->size;		//�����½���С
			t->Ptr.llink->rlink = t->rlink;			//���t���� 
			t->rlink->Ptr.llink = t->Ptr.llink;
			(FootLoc(t))->Ptr.uplink = s;			//�½��ײ�ָ��ָ����ͷ��
			
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
	printf("���п���ֹ��Χ����");
	printf("%4d����%4d��", r-av+1, r+r->size-av);
	while(r->rlink!=pav)
	{
		r = r->rlink;
		printf("%4d����%4d��", r-av+1, r+r->size-av);
	}
	printf("\n");
}

#endif
