/**********************************
 *							      *
 * �ļ���: ��02 ���Ա�            *
 * 							      *
 * �ļ���: StaticLinkedList.c     *
 * 				     		      *
 * ��  ��: 2.13��2.14��2.15��2.16 * 
 *                                *
 **********************************/

#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C
 
#include "StaticLinkedList.h" 			//**��02 ���Ա�**//

/*�T�T�T�T�T�[
�U �㷨2.14 �U 
�^�T�T�T�T�T*/
void InitSpace_SL()						//���ȳ�ʼ�����ÿռ� 
{
	int i;								//0�ŵ�Ԫ�����ÿռ����ʼ��� 

	for(i=0; i<MAXSIZE-1; i++)			//���ռ�����β��� 
		SPACE[i].cur = i + 1;

	SPACE[MAXSIZE-1].cur = 0;	
}

/*�T�T�T�T�T�[
�U �㷨2.15 �U 
�^�T�T�T�T�T*/
int Malloc_SL()							//�ӱ��ÿռ�������ռ�
{
	int i;
	
	i = SPACE[0].cur;					 

	if(SPACE[0].cur)				 
	{ 
		SPACE[0].cur = SPACE[i].cur;	//�����뵽�Ŀռ�ӱ��ÿռ���ɾȥ 
		return i;						//�������������±�
	}
	else
		return 0;						//����ʧ�ܷ���0 
}

/*�T�T�T�T�T�[
�U �㷨2.16 �U 
�^�T�T�T�T�T*/
void Free_SL(int k) 					//����k���ռ� 
{
	SPACE[k].cur = SPACE[0].cur;		
	SPACE[0].cur = k;
}

Status InitList_SL(SLinkList *H)		//HΪͷ���ָ�� 
{
	*H = Malloc_SL();					//����ͷ��� 	
	if(!(*H))
		exit(OVERFLOW);					//���ڴ桱���� 

	SPACE[*H].cur = 0; 					//ͷ����α���Ϊ0 

	return OK;
}

Status ClearList_SL(SLinkList H)
{
	int p, q;
	
	if(!H)
		return ERROR;

	p = SPACE[H].cur;					//pָ���һ����� 
	
	while(p)							//�������׽�㿪ʼɾ�� 
	{
		SPACE[H].cur = SPACE[p].cur;
		Free_SL(p);
		p = SPACE[H].cur;
	}

	return OK;
}

void DestroyList_SL(SLinkList *H)
{	
	ClearList_SL(*H);					//��վ�̬���� 
	
	Free_SL(*H);							//�ͷ�ͷ���	
	*H = 0; 
}

Status ListEmpty_SL(SLinkList H)
{
	if(H && !SPACE[H].cur)				//ֻ��ͷ��� 
		return TRUE;
	else
		return FALSE;
} 

int ListLength_SL(SLinkList H)
{
	int count;							//������
	int p;
	
	if(!H)
		exit(OVERFLOW);

	count = 0;
	p = SPACE[H].cur;
	
	while(p)
	{
		count++;
		p = SPACE[p].cur;
	}

	return count;
} 

Status GetElem_SL(SLinkList H, int i, LElemType_S *e)
{
	int count, p;
	
	if(!H || i<1 || i>MAXSIZE-2)
		return ERROR;
	
	count = 0;
	p = SPACE[H].cur;
	
	while(p)
	{
		count++;
		
		if(count==i)
		{
			*e = SPACE[p].data;		
			return OK;
		}

		p = SPACE[p].cur;
	}
} 

/*�T�T�T�T�T�[
�U �㷨2.13 �U 
�^�T�T�T�T�T*/
int LocateElem_SL(SLinkList H, LElemType_S e)
{
	int k, count;
	
	count = 1;
	if(H && SPACE[H].cur)
	{
		k = SPACE[H].cur;
		
		while(k && SPACE[k].data!=e)
		{
			count++;
			k = SPACE[k].cur;	
		}
		
		if(k)
			return count;
	}
	
	return 0;			
} 

Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e)
{
	int p, q;

	if(H)
	{
		p = SPACE[H].cur;
		
		if(p && SPACE[p].data!=cur_e)
		{
			q = SPACE[p].cur;
			
			while(q && SPACE[q].data!=cur_e)
			{
				p = q;
				q= SPACE[q].cur;
			}
			
			if(q)								//�ҵ���cur_e
			{
				*pre_e = SPACE[p].data;
				return OK;			
			}
		}
	}
	
	return ERROR;
} 

Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e)
{
	int p;
	
	if(H)
	{
		p = SPACE[H].cur;
		
		while(p && SPACE[p].data!=cur_e)
			p = SPACE[p].cur;
		
		if(p && SPACE[p].cur)					//�ҵ���cur_e�Ҳ������һ����� 
		{
			p = SPACE[p].cur;
			*next_e = SPACE[p].data;
			return OK;
		}	
	}
	
	return ERROR;
} 

Status ListInsert_SL(SLinkList H, int i, LElemType_S e)
{
	int count, k, p;
	
	if(!H)								//�������� 
		return ERROR;
	
	if(i>0)
	{
		count = 0;
		k = H;							//kָ��ͷ��� 
		
		while(k && count<i-1)			//Ѱ�Ҳ���λ�õ�ǰһ��λ�� 
		{
			count++;
			k = SPACE[k].cur;
		}
		
		if(k)							//�ҵ��˵�i-1��Ԫ�ص�λ�� 
		{
			p = Malloc_SL();
			if(!p)						//����ռ�ʧ�� 
				return ERROR;

			SPACE[p].data = e;			//����Ԫ��e 
			SPACE[p].cur = SPACE[k].cur;
			SPACE[k].cur = p;
			
			return OK;			
		}		
	}

	return ERROR;	
} 

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e)
{
	int count, k, p;
	
	if(!H)								//�������� 
		return ERROR;
	
	if(i>0)
	{
		count = 0;
		k = H;							//kָ��ͷ��� 
		
		while(k && count<i-1)			//Ѱ�Ҳ���λ�õ�ǰһ��λ�� 
		{
			count++;
			k = SPACE[k].cur;
		}
		
		if(k && SPACE[k].cur)			//�ҵ��˵�i-1��Ԫ�ص�λ���Ҳ������һ��Ԫ�� 
		{
			p = SPACE[k].cur;			//pָ��Ҫ��ɾ���Ľ�� 
			*e = SPACE[p].data;
			SPACE[k].cur = SPACE[p].cur;
			Free_SL(p);			

			return OK;			
		}		
	}

	return ERROR; 
} 

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S))
{
	int p;
	
	if(!H)
		return ERROR;					//��̬�������ڻ�Ϊ��
		
	p = SPACE[H].cur;
	
	while(p)
	{
		Visit(SPACE[p].data);
		p = SPACE[p].cur;
	}

	return OK;
}

#endif 
