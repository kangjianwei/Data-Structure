#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  										//**��01 ����**//

/* ���Ͷ��� */
typedef int LElemType_DC;
typedef struct DuLNode					//˫������ṹ��
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
	int freq;							//����Ƶ���� 
}DuLNode;
typedef DuLNode* DuLinkList;		 	//ָ��˫ѭ������ṹ��ָ�� 

/* ����ԭ�� */
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
	printf("��ʼ����L = \n");
	Output_DuL_2_38(L);
	printf("\n\n");
	
	// ���η���tmp��Ԥ������� 
	for(i=0; i<10; i++)
		Algo_2_38(&L, tmp[i]);
	
	printf("����֮��L = \n");
	Output_DuL_2_38(L);
	printf("\n\n");

	return 0;
}

/*����������������������������������������������������������������������
����2.38����λL��Ԫ��e��λ�򣬲�������Ƶ�������������������Ԫ�ز��ظ���
����������������������������������������������������������������������*/
DuLinkList Algo_2_38(DuLinkList *L, LElemType_DC e)
{	
	DuLinkList p, pre;
	int i;
	
	if(!(*L))				//��������
		return NULL;
	
	// ���ҽ��e������ 
	for(p=*L; p; p=p->next)
	{
		// �ҵ���e 
		if(p->data==e)
		    break;		
        
        // û�ҵ������ǵ����յ� 
	    if(p->next==p)
	    {
		    p = NULL;
		    break;
		}		 
	}
	
	if(p!=NULL)							//�ҵ�����e��ȵĽ�� 
	{
		p->freq++;						//����Ƶ�ȵ��� 
		
		if(p!=*L)						//p������λ�Ļ�����Ҫ�������°ڷ� 
		{
		    for(pre=p->prior; pre->freq<p->freq; pre=pre->prior)
			{
				// �Ѿ��ҵ�ͷ����û���ҵ���p��Ƶ�ȸ���Ľ�� 
			    if(pre==*L)
			    {
				    pre = NULL;
				    break;
				}
			}
			
			p->next->prior= p->prior;	//ժ�½��p 
			p->prior->next = p->next;
			
			if(pre==NULL)	// p��Ϊ�µ�����ͷ��
			{
				p->prior = (*L)->prior;
				p->prior->next = p;
				p->next = *L;
			    (*L)->prior = p;
			    *L = p;
			}
			else			// p�ŵ�pre֮�� 
			{
			    p->prior = pre;
			    p->next = pre->next;
			    p->next->prior = p;
			    pre->next = p;
			}
		}
	}
	
	return p;	// ���ص�ǰ���ָ�� 
}

//���޵��д�����û��ͷ��� 
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
			// β��
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
	
	printf("���ݣ�");
	for(p=L; p; p=p->next)
	{
	    printf("%2d ", p->data);
	    
	    if(p->next==L)
            break;
	}
	
	printf("\nƵ�ȣ�");
	for(p=L; p; p=p->next)
	{
	    printf("%2d ", p->freq);
	    
	    if(p->next==L)
            break;
	}
}
