/****************************************************
 *						                            *
 * �ļ���: ��05 ����͹����\05 GeneralizedList-H&T *
 * 						                            *
 * �ļ���: GeneralizedList-H-T.c                    *
 * 						                            *
 * ��  ��: 5.5��5.6��5.7��5.8                       * 
 * 						                            *
 ****************************************************/

#ifndef GENERALIZEDLIST_H_T_C
#define GENERALIZEDLIST_H_T_C

#include "GeneralizedList-H-T.h" 						//**��05 ����͹����**//

void InitGList_GL_H_T(GList *L)
{
	*L = NULL;											//��ʼ����һ���ձ�����Ϊ0�����Ϊ1 
}

/*�T�T�T�T�[
�U �㷨5.8�U 
�^�T�T�T�T*/
/* ����������ַ����޿ո���������ȷ */
void sever_GL_H_T_1(SString hstr, SString str)			//str������������� 
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

/*�T�T�T�T�[
�U �㷨5.7�U 
�^�T�T�T�T*/
void CreateGList_GL_H_T_1(GList *L, SString S)
{
	SString emp, hsub, sub;
	GList p, q;
	
	StrAssign_Sq(emp, "()");	
	
	if(!StrCompare_Sq(S, emp))							//S����ձ�
		*L = NULL;										//�����ձ�
	else
	{
		*L = (GList)malloc(sizeof(GLNode));
		if(!*L)
			exit(OVERFLOW);
		
		if(StrLength_Sq(S)==1)							//������ԭ�ӹ����
		{
			(*L)->tag = Atom;
			(*L)->Union.atom = S[1];
			
			(*L)->mark = 0;								//GarbageCollection.c 
		}
		else
		{
			(*L)->tag = List;

			(*L)->mark = 0;								//GarbageCollection.c
			
			p = *L;
			
			SubString_Sq(sub, S, 2, StrLength_Sq(S)-2);	//ȥ����������� 
											
			do											//�ظ���n���ӱ� 
			{	
				sever_GL_H_T_1(hsub, sub);				//�������ͷ��hsub	
				CreateGList_GL_H_T_1(&(p->Union.ptr.hp), hsub);
				q = p;
				if(!StrEmpty_Sq(sub))					//��β��Ϊ�գ������β 
				{									
					p = (GList)malloc(sizeof(GLNode));
					if(!p)
						exit(OVERFLOW);
						
					p->tag = List;

					p->mark = 0;						//GarbageCollection.c 

					q->Union.ptr.tp = p;
				}			
			}while(!StrEmpty_Sq(sub));
			q->Union.ptr.tp = NULL;
		}
	}
}

/* ��һ�ִ����������㷨���������㷨���в�ͬ */
/* ����������ַ����޿ո���������ȷ */
void sever_GL_H_T_2(SString hstr, SString str)			//��str�ֽ�Ϊ��ͷԪ�غͱ�βԪ�������� 
{
	int i = 1;
	int k = 0;
	int n;
	SString tmp;
	
	SubString_Sq(tmp, str, 2, StrLength_Sq(str)-2);
	
	n = StrLength_Sq(tmp);
	
	while(i<n && (tmp[i]!=',' || k!=0))
	{
		if(tmp[i]=='(')
			k++;
		if(tmp[i]==')')
			k--;
		i++;
	}
	
	if(i<n)
		SubString_Sq(hstr, tmp, 1, i-1);
	else
		StrCopy_Sq(hstr, tmp);
	
	StrDelete_Sq(str, 2, i);		
}

void CreateGList_GL_H_T_2(GList *L, SString S)
{
	SString hsub, sub, emp;
	GList p, q;
	
	StrAssign_Sq(emp, "()");
	
	if(!StrCompare_Sq(S, emp))
		*L = NULL;	
	else
	{	
		*L = (GList)malloc(sizeof(GLNode));
		
		if(StrLength_Sq(S)==1)
		{
			(*L)->tag = Atom;
			(*L)->Union.atom = S[1];
		}
		else
		{			
			(*L)->tag = List;
			p = *L;
			
			StrCopy_Sq(sub, S);
			
			do
			{				
				sever_GL_H_T_2(hsub, sub);
				CreateGList_GL_H_T_2(&(p->Union.ptr.hp), hsub);
				
				if(StrCompare_Sq(sub, emp))
				{
					q = p;
					p = (GList)malloc(sizeof(GLNode));
					p->tag = List;
					q->Union.ptr.tp = p;
				}
			}while(StrCompare_Sq(sub, emp));
			p->Union.ptr.tp = NULL;
		}	
	}
}

void ClearGList_GL_H_T(GList *L)
{
	GList p, q;
	
	if(*L)
	{
		if((*L)->tag==Atom)
     	{
			free(*L); 									//ɾ��ԭ�ӽ��
			*L = NULL;      		
     	}
		else											//ɾ������
		{
			p = (*L)->Union.ptr.hp;
			q = (*L)->Union.ptr.tp;
			free(*L);
			*L = NULL;
			ClearGList_GL_H_T(&p);
			ClearGList_GL_H_T(&q);
		}
	}	
}

/*�T�T�T�T�[
�U �㷨5.6�U 
�^�T�T�T�T*/
void CopyGList_GL_H_T(GList *T, GList L)
{
	if(!L)
		*T = NULL;
	else
	{
		*T = (GList)malloc(sizeof(GLNode));				//������			
		if(!*T)
			exit(OVERFLOW);
		
		(*T)->tag = L->tag;
		
		if(L->tag==Atom)								//���Ƶ�ԭ��
			(*T)->Union.atom = L->Union.atom; 
		else											//���Ʊ�ͷ�ͱ�β 
		{
			CopyGList_GL_H_T(&((*T)->Union.ptr.hp), L->Union.ptr.hp);
			CopyGList_GL_H_T(&((*T)->Union.ptr.tp), L->Union.ptr.tp);
		}
	}	
}

int GListLength_GL_H_T(GList L)
{
	int count;
	
	for(count=0; L; count++,L=L->Union.ptr.tp)
		;
	
	return count; 
}

/*�T�T�T�T�[
�U �㷨5.5�U 
�^�T�T�T�T*/
int GListDepth_GL_H_T(GList L)
{
	int max, deep;
	GList p;
	
	if(!L)												//�ձ����Ϊ1 
		return 1;

	if(L->tag==Atom)									//ԭ�����Ϊ0 
		return 0;
	
	for(max=0,p=L; p; p=p->Union.ptr.tp)
	{
		deep = GListDepth_GL_H_T(p->Union.ptr.hp);
		if(deep>max)
			max = deep;
	}
		
	return max + 1;										//�ǿձ������Ǹ�Ԫ�������ȼ�һ 
}

Status GListEmpty_GL_H_T(GList L)
{
	if(!L)
		return TRUE;
	else
		return FALSE;
}

GList GetHead_GL_H_T(GList L)
{
	GList p;
	
	if(!L)
	{
		printf("�����Ϊ�ձ��޷���ȡ��ͷ��\n");
		exit(ERROR);
	}
	
	CopyGList_GL_H_T(&p, L->Union.ptr.hp);
	
	return p;
}

GList GetTail_GL_H_T(GList L)
{
	GList p;
	
	if(!L)
	{
		printf("�����Ϊ�ձ��޷���ȡ��β��\n");
		exit(ERROR);
	}
	
	CopyGList_GL_H_T(&p, L->Union.ptr.tp);
	
	return p;
}

void InsertFirst_GL_H_T(GList *L, GList e)
{
	GList g;
	
	g = (GList)malloc(sizeof(GLNode));
	if(!g)
		exit(OVERFLOW);
			
	g->tag = 1;	
	g->Union.ptr.hp = e;
	g->Union.ptr.tp = *L;
	*L = g;
}

void DeleteFirst_GL_H_T(GList *L, GList *e)
{
	GList p;
	
	if(!(*L))
	{
		printf("�����Ϊ�ձ�ɾ����ͷʧ�ܣ�\n");
		exit(ERROR);
	}
	
	p = *L;
	*L = (*L)->Union.ptr.tp;
	
	CopyGList_GL_H_T(e, p->Union.ptr.hp);
	
	free(p);	
	p = NULL;
}

void Traverse_GL_H_T(GList L, void(Visit)(AtomType))
{
	if(L)
	{
		if(L->tag==Atom)
			Visit(L->Union.atom);
		else
		{
			Traverse_GL_H_T(L->Union.ptr.hp, Visit);
			Traverse_GL_H_T(L->Union.ptr.tp, Visit);
		}
	}
}

void Output_GL_H_T(GList L, Mark mark)
{
	if(!L)												//LΪ�� 
	{
		if(mark==Head)									//mark=0��������ָ�����Ա�ͷ 
			printf("()");
		else											//mark=1��������ָ�����Ա�β 
			printf(")");
	}
	else												//L��Ϊ��ʱ 
	{
		if(L->tag==Atom)								//����ԭ�ӽ�㣬���ԭ�� 
			printf("%c",L->Union.atom);
		else											//���ڱ��㣬Ҫ�Ա�ͷ����β�ֱ����� 
		{
			if(mark==Head)
				printf("(");
			else
				printf(",");

			Output_GL_H_T(L->Union.ptr.hp, Head);
			Output_GL_H_T(L->Union.ptr.tp, Tail);
		}
	}			
}

#endif
