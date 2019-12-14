/*************************************
 *				     	             *
 * �ļ���: ��02 ���Ա�\11 Polynomial *
 * 					                 *
 * �ļ���: Polynomial.c              *
 * 				                     *
 * ��  ��: 2.22��2.23                * 
 *                                   *
 *************************************/

#ifndef	POLYNOMIAL_C
#define	POLYNOMIAL_C

#include "Polynomial.h"					//**��02 ���Ա�**//

/*�T�T�T�T�T�[
�U �㷨2.22 �U 
�^�T�T�T�T�T*/
void CreatPolyn_P(FILE *fp, Polynomial *P, int m)
{
	PositionPtr h;
	ElemType_P e;
	int i;
	Link p;

	InitList_E(P);						//��ʼ��һ����չ�ĵ������Ŷ���ʽ 
	h = GetHead_E(*P);					//��ȡ����ʽͷָ�� 

	e.coef = 0.0;
	e.expn = -1;
	SetCurElem_E(h, e);			    	//����ͷ��������Ԫ�� 
	h->next = NULL;
	
	for(i=1; i<=m; i++)					//����¼��n����0�� 
	{
		Scanf(fp, "%f%d", &(e.coef), &(e.expn));
		MakeNode_E(&p, e);
		p->next = NULL;
		InsFirst_E(P, h, p);
		h = h->next;
	} 
} 

void DestroyPolyn_P(Polynomial *P)
{
	DestroyList_E(P);
}

int PolynLength_P(Polynomial P)
{
	return ListLength_E(P);
}

/*�T�T�T�T�T�[
�U �㷨2.23 �U 
�^�T�T�T�T�T*/
void AddPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha, hb;
	PositionPtr qa, qb;
	ElemType_P a, b;
	float sum;
	 
	ha = GetHead_E(*Pa);					//ha��hb�ֱ�ָ��Pa��Pbͷ��� 
	hb = GetHead_E(*Pb);	
	qa = NextPos_E(ha);						//qa��qb�ֱ�ָ��Pa��Pb�ĵ�ǰ���
	qb = NextPos_E(hb);

	while(qa && qb)							//qa��qb���ǿ�
	{
		a = GetCurElem_E(qa);				//a��bΪ�����е�ǰ�Ƚ�Ԫ�� 
		b = GetCurElem_E(qb);

		switch(Cmp_exp(a,b))				//�Ƚϵ�ǰԪ�ص�ָ����С 
		{
			case -1:						//����ʽPa�е�ǰ����ָ��ֵ��С
				ha = qa;
				qa = NextPos_E(ha);
				break;
			case 0:							//������ֵ��� 
				sum = a.coef + b.coef;
				if(sum != 0.0)				//��Ӳ��ܵ���ʱ����Pa����ϵ��ֵ 
				{
					qa->data.coef = sum;
					SetCurElem_E(qa, qa->data);
					ha = qa;				//��ʱha����� 
				}
				else						//��ӵ���ʱ��ɾ��Pa�е�ǰ���
				{
					DelFirst_E(Pa, ha, &qa);
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb, hb, &qb);	//ɾ��Pb��ɨ����Ľ�� 
				FreeNode_E(&qb);
				qb = NextPos_E(hb);			//qa��qb������ 
				qa = NextPos_E(ha);
				break;
			case 1:							//����ʽPb�е�ǰ����ָ��ֵ��С
				DelFirst_E(Pb, hb, &qb);	//ժ��Pb��ǰ���
				InsFirst_E(Pa, ha, qb); 	//��ժ�½������Pa��
				qb = NextPos_E(hb);
				ha = NextPos_E(ha); 
				break; 
		}//switch
	}//while
	
	if(qb)									//��Pb��δɨ���꣬��ʣ�������ӵ�Pa�� 
		Append_E(Pa, qb);

	FreeNode_E(&hb);						//�ͷ�Pbͷ���
	(*Pb).head = (*Pb).tail = NULL;			//����PbΪ����״̬ 
	(*Pb).len = 0;		 
}

void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha, hb;
	PositionPtr qa, qb;
	PositionPtr r;
	ElemType_P a, b;
	float sum;
	 
	ha = GetHead_E(*Pa);					//ha��hb�ֱ�ָ��Pa��Pbͷ��� 
	hb = GetHead_E(*Pb);	
	qa = NextPos_E(ha);						//qa��qb�ֱ�ָ��Pa��Pb�ĵ�ǰ���
	qb = NextPos_E(hb);
	
	while(qa && qb)							//qa��qb���ǿ�
	{
		a = GetCurElem_E(qa);				//a��bΪ�����е�ǰ�Ƚ�Ԫ�� 
		b = GetCurElem_E(qb);

		switch(Cmp_exp(a,b))				//�Ƚϵ�ǰԪ�ص�ָ����С 
		{
			case -1:						//����ʽPa�е�ǰ����ָ��ֵ��С
				ha = qa;
				qa = NextPos_E(ha);
				break;
			case 0:							//������ֵ��� 
				sum = a.coef - b.coef;
				if(sum != 0.0)				//������ܵ���ʱ����Pa����ϵ��ֵ 
				{
					qa->data.coef = sum;
					SetCurElem_E(qa, qa->data);
					ha = qa;				//��ʱha����� 
				}
				else						//��ӵ���ʱ��ɾ��Pa�е�ǰ���
				{
					DelFirst_E(Pa, ha, &qa);
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb, hb, &qb);	//ɾ��Pb��ɨ����Ľ�� 
				FreeNode_E(&qb);
				qb = NextPos_E(hb);			//qa��qb������ 
				qa = NextPos_E(ha);
				break;
			case 1:							//����ʽPb�е�ǰ����ָ��ֵ��С
				DelFirst_E(Pb, hb, &qb);	//ժ��Pb��ǰ���
				qb->data.coef = - qb->data.coef;	//�ı䵱ǰ������ 
				InsFirst_E(Pa, ha, qb); 	//��ժ�½������Pa��
				qb = NextPos_E(hb);
				ha = NextPos_E(ha); 
				break; 
		}//switch
	}//while

	if(qb)									//Pb��δɨ����
	{
		r = qb;
		while(r)							
		{
			r->data.coef = - r->data.coef;	//�ı�ʣ������� 
			r = r->next;
		}
		Append_E(Pa, qb);	
	} 

	FreeNode_E(&hb);						//�ͷ�Pbͷ���
	(*Pb).head = (*Pb).tail = NULL;
	(*Pb).len = 0;
}

void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	Polynomial Pc, Ptmp;
	int i, j, la, lb;
	PositionPtr ha;
	PositionPtr qa, qb;
	Link s;
	
	la = PolynLength_P(*Pa);
	lb = PolynLength_P(*Pb);
	ha = (*Pa).head;

	InitList_E(&Pc);
	
	for(i=1; i<=la; i++)
	{
		InitList_E(&Ptmp);

		DelFirst_E(Pa, ha, &qa);
		qb = (*Pb).head->next;

		for(j=1; j<=lb; j++)
		{
			s = (Link)malloc(sizeof(ELNode));				//����ռ� 	
			if(!s)
				exit(OVERFLOW);
			
			s->data.coef = qa->data.coef * qb->data.coef;	//ϵ����� 
			s->data.expn = qa->data.expn + qb->data.expn;	//ָ����� 
			s->next = NULL;
			
			Append_E(&Ptmp, s);
			 
			qb = qb->next;
		}
		
		AddPolyn_P(&Pc, &Ptmp);		
	}
	
	AddPolyn_P(Pa, &Pc);
	
	DestroyPolyn_P(Pb);
}

int Cmp_exp(ElemType_P c1, ElemType_P c2)
{
	int i = c1.expn - c2.expn; 
	
	if(i<0)
		return -1;
	else if(i==0)
		return 0;
	else
		return 1;
} 

void PrintPolyn_P(Polynomial P)
{
	int i;
	Link p;
	
	p = P.head->next;
	for(i=1; i<=P.len; i++)
	{
		if(i==1)
			printf("%g", p->data.coef);
		else
		{
			if(p->data.coef>0)
			{
				printf(" + ");
				printf("%g", p->data.coef);
			}
			else
			{
				printf(" - ");
				printf("%g", -p->data.coef);
			}				
		}
		
		if(p->data.expn)
		{
			printf("x");
			
			if(p->data.expn!=1)
				printf("^%d", p->data.expn);
		}
		
		p = p->next;
	}
}

#endif
