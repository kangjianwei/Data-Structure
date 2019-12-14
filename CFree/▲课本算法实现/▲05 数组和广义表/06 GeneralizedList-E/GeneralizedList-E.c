/**************************************************
 *						                          *
 * �ļ���: ��05 ����͹����\06 GeneralizedList-E *
 * 						                          *
 * �ļ���: GeneralizedList-E.c                    *
 *						                          *
 *************************************************/

#ifndef GENERALIZEDLIST_E_C
#define GENERALIZEDLIST_E_C

#include "GeneralizedList-E.h" 			//**��05 ����͹����**//

void InitGList_GL_E(GList *L)
{
	*L = (GList)malloc(sizeof(GLNode));
	if(!*L)
		exit(OVERFLOW);
	
	(*L)->tag = List;	
	(*L)->Union.hp = NULL;
	(*L)->tp = NULL;
}

void sever_GL_E(SString hstr, SString str)
{
	int i, k, n;
	SString ch;
	
	n = StrLength_Sq(str);
	
	i = k = 0;
	do
	{
		++i;
		SubString_Sq(ch, str, i, 1);
		if(ch[1]=='(')
			++k;
		if(ch[1]==')')
			--k;
	}while(i<n && (ch[1]!=',' || k!=0));
	
	if(i<n)
	{
		SubString_Sq(hstr, str, 1, i-1);
		SubString_Sq(str, str, i+1, n-i);
	}
	else
	{
		StrCopy_Sq(hstr, str);
		ClearString_Sq(str);
	}
}

void CreateGList_GL_E(GList *L, SString S)
{
	SString emp, hsub, sub, tmp;
	GList p, q;

	StrAssign_Sq(emp, "()");
		
	StrCopy_Sq(sub, S);								//������Ϊ�˲��ƻ�S 
	sever_GL_E(hsub, sub);
	
	*L = (GList) malloc (sizeof(GLNode));
	if(!*L)
		exit(OVERFLOW);
	
	if(!StrCompare_Sq(hsub, emp))
	{
		(*L)->tag = List;
		(*L)->Union.hp = NULL;
	}
	else
	{
		if(StrLength_Sq(hsub)==1)
		{
			(*L)->tag = Atom;
			(*L)->Union.atom = hsub[1];
		}
		else
		{
			(*L)->tag = List;
			
			SubString_Sq(tmp, hsub, 2, StrLength_Sq(hsub)-2);
			
			CreateGList_GL_E(&((*L)->Union.hp), tmp);			
		}
	}
	
	if(StrEmpty_Sq(sub))
		(*L)->tp = NULL;
	else
		CreateGList_GL_E(&((*L)->tp), sub);
}

void DestroyGList_GL_E(GList *L)
{
	GList p, q;
	
	if(*L)
	{		
		if((*L)->tag==List)							//������� 
		{
			p = (*L)->Union.hp;
			q = (*L)->tp;					
			free(*L);
			*L = NULL;
			if(p)
				DestroyGList_GL_E(&p);				//�ݹ鴦���ͷ 
			if(q)
				DestroyGList_GL_E(&q);				//�ݹ鴦���β	
		}
		else										//����ԭ�ӽ�� 
		{	
			q = (*L)->tp;		
			free(*L);
			*L = NULL;
			if(q)
				DestroyGList_GL_E(&q);
		}		
	}	
}

void CopyGList_GL_E(GList *T, GList L)
{
	if(L)
	{
		*T = (GList) malloc (sizeof(GLNode));
		if(!*T)
			exit(OVERFLOW);
		
		if(L->tag==Atom)
		{
			(*T)->tag = Atom;
			(*T)->Union.atom = L->Union.atom;
		}
		else
		{
			(*T)->tag = List;
			if(L->Union.hp)
				CopyGList_GL_E(&((*T)->Union.hp), L->Union.hp);
			else
				(*T)->Union.hp = NULL;
		}
		
		if(L->tp)
			CopyGList_GL_E(&((*T)->tp), L->tp);
		else
			(*T)->tp = NULL;	
	}
	else
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
}

int GListLength_GL_E(GList L)
{
	int i = 0;
	GList p;
	
	if(!L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	
	p = L->Union.hp;
	while(p)
	{
		++i;
		p = p->tp;
	}
	
	return i;
}

int GListDepth_GL_E_1(GList L)
{
	int max, deep;   
	GList p;
   
   	max = 0;
   	
   	if(!L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
   	
	if(L->tag==List && !L->Union.hp)			//�ձ����Ϊ1 
		return 1;
	else if(L->tag==Atom)						//��ԭ�ӱ����Ϊ0��ֻ������ڵݹ������ 
		return 0;
	else										//��һ������� 
	{
		for(p=L->Union.hp; p; p=p->tp)
		{
			deep = GListDepth_GL_E_1(p);		//����pΪͷָ����ӱ���� 
			if(deep>max)
				max = deep;
		}
	}
	    
	return max + 1;
}

// ���ڱ��㣬�ֺ�����Ⱥ�����������ۡ�����ԭ�ӽ��
int GListDepth_GL_E_2(GList L)
{
	int max, deep;
	GList p = L;
	
	max = deep = 0;
	
	if(!L)
	{
		printf("�����L�����ڣ���\n");
		exit(OVERFLOW);
	}
	else
	{		
		if(L->tag==List)								//������� 
		{
			max++;										//һ���������һ����� 
			
			if(L->Union.hp)
			{
				deep = GListDepth_GL_E_2(L->Union.hp);
				max += deep;							//������Ȳ����ۼ� 
			}
			
			do											//����ͬһ��ԭ�ӽ�� 
			{
				p = p->tp;
			}while(p && p->tag!=List);					
		}
		else											//����ԭ�ӽ�� 
		{
			while(p && p->tag!=List)					//����ͬһ��ԭ�ӽ�� 
				p = p->tp;
		}
		
		if(p)												
		{
			deep = GListDepth_GL_E_2(p);
			if(deep>max)								//max����ͬһ������������� 
				max = deep;								//�������ȡ����һ�� 
		}			
	}
	
	return max;
}

Status GListEmpty_GL_E(GList L)
{
	if(!L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	
	if(L->tag==List && !(L->Union.hp) && !(L->tp))
		return TRUE;
	else
		return ERROR;
}

GList GetHead_GL_E(GList L)
{
	GList p, q;
	
	if(!L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	if(!L->Union.hp)
	{
		printf("�����Ϊ�ձ��޷���ȡ��ͷ��\n");
		exit(OVERFLOW);
	}
	
	q = L->Union.hp->tp;								//q����L�ı�β
	L->Union.hp->tp = NULL; 							//��ȥL�ı�β����
	CopyGList_GL_E(&p, L->Union.hp); 					//����ͷԪ�ظ��Ƹ�h
	L->Union.hp->tp = q;								//�ָ�L�ı�β 
	
	return p;
}

GList GetTail_GL_E(GList L)
{
	GList p, q;
	
	if(!L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	if(!L->Union.hp)
	{
		printf("�����Ϊ�ձ��޷���ȡ��β��\n");
		exit(OVERFLOW);
	}
	
	InitGList_GL_E(&p);
	q = L->Union.hp;
	do
	{
		q = q->tp;
	}while(q && q->tp);
		
	p->Union.hp = q;
	
	return p;
}

void InsertFirst_GL_E(GList *L, GList e)
{
	GList g;
	
	if(!*L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	
	CopyGList_GL_E(&g, e);
	
	g->tp = (*L)->Union.hp;
	(*L)->Union.hp = g;
}

void DeleteFirst_GL_E(GList *L, GList *e)
{
	GList p;
	
	if(!*L)
	{
		printf("��������ڣ���\n");
		exit(OVERFLOW);
	}
	if(!(*L)->Union.hp)
	{
		printf("�����Ϊ�ձ�ɾ����ͷʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	
	p = (*L)->Union.hp;	
	(*L)->Union.hp = p->tp;
	p->tp = NULL;

	*e = p;
}

void Traverse_GL_E(GList L, void(Visit)(AtomType))
{
	if(L)
	{
		if(L->tag==List)
			Traverse_GL_E(L->Union.hp, Visit);
		else
			Visit(L->Union.atom);
			
		Traverse_GL_E(L->tp, Visit);
	}
}

void Output_GL_E(GList L)
{
	if(L)
	{
		if(L->tag==List)								//������� 
		{
			printf("(");
			
			if(L->Union.hp)
				Output_GL_E(L->Union.hp);
			
			if(L->tp)
			{
				printf("),");
				Output_GL_E(L->tp);
			}
			else
				printf(")");
		}
		else											//����ԭ�ӽ�� 
		{
			printf("%c",L->Union.atom);
			if(L->tp)
			{
				printf(",");
				Output_GL_E(L->tp);
			}				
		}		
	}
}

#endif
