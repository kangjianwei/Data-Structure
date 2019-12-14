#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ�� 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* ���Ͷ��� */
typedef char XElemType;
typedef struct XorNode			//���ָ��������ṹ		
{
	XElemType data;
	struct XorNode *LRPtr;
}XorNode;
typedef XorNode* XorPointer;	//ָ����ṹ��ָ�� 
typedef struct					//��ͷ�������ָ��˫�������ͷβָ�� 
{
	XorPointer Left;			//�ֱ�ָ�����������ˣ�ͷָ�룩�����Ҷˣ�βָ�룩 
	XorPointer Right;
}XorLinkedList;
typedef XorLinkedList* Xor;

/* ���ָ��������ԭ�� */
Status Algo_2_34_1(Xor L, int mark);
Status Algo_2_34_2(Xor L, int mark);
Status Algo_2_35(Xor L, int i, XElemType e);
Status Algo_2_36(Xor L, int i, char *e);
XorPointer XorP_XorL(XorPointer p, XorPointer q);
Status Init_XorL(Xor *L);
Status Create_XorL(Xor L, int n, XElemType Data[]);
XorPointer Prior_Next_Ptr_XorL(Xor L, XorPointer cur, int mark);
int Length_XorL(Xor L);
XorPointer GetElemPtr_XorL(Xor L, int i);

int main(int argc, char **argv)
{
	Xor L;
	XElemType e;
	int n = 9;
	XElemType *data = "123456789";
	
	Init_XorL(&L);			//�ȳ�ʼ�� 
	 
	Create_XorL(L, n, data);		
	printf("�������� 2.34 ��֤...������\n");
	printf("˳�����L = ");
	Algo_2_34_1(L, 0);
	printf("\n");
	printf("�������L = ");
	Algo_2_34_1(L, 1);
	printf("\n\n");

	printf("�������� 2.35 ��֤...������\n");		
	Algo_2_35(L, 5, '*');
	printf("���� '*' ΪL�ĵ�5������˳�����...\n");
	Algo_2_34_2(L, 0);
	printf("\n\n");

	printf("�������� 2.36 ��֤...������\n");			
	Algo_2_36(L, 5, &e);
	printf("ɾ��L�ĵ�5����� '%c' ���������...\n", e);
	Algo_2_34_2(L, 1);
	printf("\n\n");
		
	return 0;
}

/*����������������������������������������
��(01)ָ�������������ָ��p��q�����ֵ��
����������������������������������������*/
XorPointer XorP_XorL(XorPointer p, XorPointer q)
{					 
	unsigned long x, y, z;
	
	x = (unsigned long)p;
	y = (unsigned long)q;
	
	z = x^y;					//����� 
	
	return (XorPointer)z;
}

/*��������������������������
��(02)��ʼ�����ָ������L ��
��������������������������*/
Status Init_XorL(Xor *L)
{
	*L = (Xor)malloc(sizeof(XorLinkedList));
	if(!(*L))
		exit(OVERFLOW);
		
	(*L)->Left = NULL;
	(*L)->Right = NULL;

	return OK; 
}

/*������������������������
��(03)�������ָ������L ��
������������������������*/
Status Create_XorL(Xor L, int n, XElemType Data[])
{
	int i;
	XorPointer pre_l, pre_m, pre_r; 

	pre_l = pre_m = NULL;
	
	for(i=1; i<=n; i++)
	{
		pre_r = (XorPointer) malloc (sizeof(XorNode));
		if(!pre_r)
			exit(OVERFLOW);
		
		pre_r->data = Data[i-1];
		
		if(i==1)					//��ָ�루�����׽��ʱ������ 
			L->Left = pre_r;
 			
		if(pre_m)					//pre_m��Ϊ��ʱִ��,�Ӵ����ڶ������ʱִ�� 
			pre_m->LRPtr = XorP_XorL(pre_l, pre_r);				

		L->Right = pre_r;			//��ָ��					
		pre_r->LRPtr = XorP_XorL(pre_m, NULL);
		pre_l = pre_m;
		pre_m = pre_r;	
	}
	
	return OK;
}

/*����������������������������������������������������
��(04)��ȡ��ǰ���(cur)��ǰ��(mark=0)����(mark=1) ��
����������������������������������������������������*/
XorPointer Prior_Next_Ptr_XorL(Xor L, XorPointer cur, int mark) 
{
	XorPointer p_l, p_m, p_r;

	if(mark!=1 && mark!=0)
		return NULL;
	
	if(!L || !L->Left || !cur)					//�������ڻ�����Ϊ�ջ�curΪ�����޷����ַ
		return NULL;

	if(mark==1)									//���̣��������� 
	{
		p_l = NULL;
		p_m = L->Left;
		
		while(p_m!=cur)
		{
			p_r = XorP_XorL(p_l, p_m->LRPtr);	//�����Ҳ��һ������ַ
			p_l = p_m;							//ָ�벻�������ƽ� 
			p_m = p_r;
		}
		
		p_r = XorP_XorL(p_l, p_m->LRPtr);
		
		return p_r;
	}
	
	if(mark==0)									//��ǰ������������ 
	{
		p_m = L->Right;
		p_r = NULL;
		while(p_m!=cur)
		{
			p_l = XorP_XorL(p_m->LRPtr, p_r);	//��������һ������ַ
			p_r = p_m;							//ָ�벻�������ƽ�
			p_m = p_l;
		}
		
		p_l = XorP_XorL(p_m->LRPtr, p_r);
		
		return p_l;
	}
}

/*����������������
��(05)��ȡL���� ��
����������������*/
int Length_XorL(Xor L)
{
	int count;	
	XorPointer p, pre, psuc;
	
	if(!L)
		exit(OVERFLOW);					//�����������˳� 
	
	count = 0;	
	pre = NULL;
	p = L->Left;						//�������ұ���
	
	while(p)
	{
		count++;
		psuc = XorP_XorL(pre, p->LRPtr);
		pre = p;
		p = psuc;
	}
	
	return count; 
}

/*������������������������������
��(06)����ָ���i������ָ�� ��
������������������������������*/ 
XorPointer GetElemPtr_XorL(Xor L, int i)	//iΪԪ��λ�� 
{
	int count;
	XorPointer p, pre, psuc;

	if(!L || !L->Left)						//�������ڻ�����Ϊ���޷����ַ 
		return ERROR;

	if(i<1)
		return ERROR;
	
	count = 1;
	pre = NULL;
	p = L->Left;
	
	while(count<i && p)
	{
		psuc = XorP_XorL(pre, p->LRPtr);
		pre = p;
		p = psuc;
		count++;
	}
	
	return p;
}

/*��������������������������������
��(07-1)���L��mark��ʾ������� ��
��������������������������������*/
/* ����1������Prior_Next_Ptr_XorL������������ */ 
Status Algo_2_34_1(Xor L, int mark)
{
	XorPointer cur;
	
	if(mark!=1 && mark!=0)
		return ERROR;
		
	if(!L || !L->Left)				//�������ڻ�����Ϊ�����޷���� 
		return ERROR;
		
	if(mark==0)
	{
		cur = L->Left;
		do
		{
			printf("%c ",cur->data);
			cur = Prior_Next_Ptr_XorL(L, cur, !mark);
		}while(cur);
	}
	
	if(mark==1)
	{
		cur = L->Right;
		do
		{
			printf("%c ",cur->data);
			cur = Prior_Next_Ptr_XorL(L, cur, !mark);
		}while(cur);
	}

	return OK;
}

/*��������������������������������
��(07-2)���L��mark��ʾ������� ��
��������������������������������*/
/* ����2��������ǰ��_��̺����������� */
Status Algo_2_34_2(Xor L, int mark)		//i����0����������������1�������������� 
{
	XorPointer p_l, p_m, p_r;
	
	if(mark!=1 && mark!=0)
		return ERROR;
		
	if(!L && !L->Left)					//�������ڻ�����Ϊ�����޷���� 
		return ERROR;

	if(mark==0)							//��������
	{
		p_l = NULL;
		p_m = L->Left;
		
		while(p_m)						//p_mΪ��ʱ˵���������� 
		{
			printf("%c ",p_m->data);
			p_r = XorP_XorL(p_l, p_m->LRPtr);//�����Ҳ��һ������ַ
			p_l = p_m;					//ָ�벻���ƽ� 
			p_m = p_r;			
		}
	}
	
	if(mark==1)
	{
		p_m = L->Right;
		p_r = NULL;

		while(p_m)
		{
			printf("%c ",p_m->data);
			p_l = XorP_XorL(p_m->LRPtr, p_r);
			p_r = p_m;
			p_m = p_l;			      
		} 
	}

	return OK;
}

/*��������������������������������
��(08)��Ԫ��e���뵽��i�����֮ǰ��
��������������������������������*/
Status Algo_2_35(Xor L, int i, XElemType e)
{
	XorPointer s, i_pre_pre, i_pre, i_cur, i_suc;
	
	if(!L)										//L������� 
		return ERROR;
		 
	if(i<1 || i>Length_XorL(L)+1)				//i��������ȷ�ķ�Χ��					
		return ERROR;
		
	s = (XorPointer)malloc(sizeof(XorNode));
	if(!s)
		return OVERFLOW;
	s->data = e;

	i_cur = GetElemPtr_XorL(L, i);				//ָ���i����� 	
	i_pre = GetElemPtr_XorL(L, i-1);			//ָ���i-1�����
	i_pre_pre = GetElemPtr_XorL(L, i-2);		//ָ���i-2�����
	
	if(!i_cur)									//��i����㲻���� 
	{
		if(!i_pre)								//����Ϊ�գ�����Ϊ�׽��						
		{
			s->LRPtr = NULL;
			L->Left =s;
		}
		else									//�����գ�����Ϊβ���
		{
			s->LRPtr = i_pre;
			i_pre->LRPtr = XorP_XorL(i_pre_pre, s);		
		}
		
		L->Right = s;
	}
	else										//��i�������� 
	{
		i_suc = XorP_XorL(i_pre, i_cur->LRPtr);	//ָ���i+1����� 
		
		s->LRPtr = XorP_XorL(i_pre, i_cur);		//�趨s�ĺ��ָ�� 
		i_cur->LRPtr = XorP_XorL(s, i_suc);		//��ǰ���ĺ��ָ��ҲҪ�ı� 
		
		if(!i_pre)								//�����գ�����Ϊ�׽�� 
			L->Left = s;		
		else
			i_pre->LRPtr = XorP_XorL(i_pre_pre, s);
	}	

	return OK;
}


/*������������������������������������������
��(09)ɾ����i����㣬����e���ܽ����Ԫ��ֵ��
������������������������������������������*/
Status Algo_2_36(Xor L, int i, char *e)
{
	XorPointer i_pre_pre, i_pre, i_cur, i_suc, i_suc_suc;
	
	if(i<1 || i>Length_XorL(L))
		return ERROR;
		
	if(!L || !L->Left)
		return ERROR;
		
	i_cur = GetElemPtr_XorL(L, i);					//ָ���i����� 
	*e = i_cur->data;
	
	i_pre = GetElemPtr_XorL(L, i-1);				//ָ���i-1����� 	
	i_suc = XorP_XorL(i_pre, i_cur->LRPtr);			//ָ���i+1����� 	
	
		
	if(!i_suc)										//ɾ��β��� 
	{
		L->Right = i_pre;
		
		if(!i_pre)									//ֻ��һ���������
			L->Left = NULL;
		else
			i_pre->LRPtr = XorP_XorL(i_pre->LRPtr, i_cur);	
	}
	else
	{
		if(!i_pre)									//ɾ���׽��
		{
			L->Left = i_suc;
			i_suc->LRPtr = 	XorP_XorL(i_cur, i_suc->LRPtr);
		}
		else
		{
			i_pre_pre = XorP_XorL(i_pre->LRPtr, i_cur);		//ָ���i-2����� 	
			i_suc_suc = XorP_XorL(i_cur, i_suc->LRPtr);		//ָ���i+2�����
			i_pre->LRPtr = XorP_XorL(i_pre_pre, i_suc);
			i_suc->LRPtr = XorP_XorL(i_pre, i_suc_suc);
		}
	}
	
	free(i_cur);
	i_cur = NULL;
	
	return OK;
}
