/**************************************************
 *						                          *
 * 文件夹: ▲05 数组和广义表\06 GeneralizedList-E *
 * 						                          *
 * 文件名: GeneralizedList-E.c                    *
 *						                          *
 *************************************************/

#ifndef GENERALIZEDLIST_E_C
#define GENERALIZEDLIST_E_C

#include "GeneralizedList-E.h" 			//**▲05 数组和广义表**//

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
		
	StrCopy_Sq(sub, S);								//复制是为了不破坏S 
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
		if((*L)->tag==List)							//处理表结点 
		{
			p = (*L)->Union.hp;
			q = (*L)->tp;					
			free(*L);
			*L = NULL;
			if(p)
				DestroyGList_GL_E(&p);				//递归处理表头 
			if(q)
				DestroyGList_GL_E(&q);				//递归处理表尾	
		}
		else										//处理原子结点 
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
		printf("广义表不存在！！\n");
		exit(OVERFLOW);
	}
}

int GListLength_GL_E(GList L)
{
	int i = 0;
	GList p;
	
	if(!L)
	{
		printf("广义表不存在！！\n");
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
		printf("广义表不存在！！\n");
		exit(OVERFLOW);
	}
   	
	if(L->tag==List && !L->Union.hp)			//空表深度为1 
		return 1;
	else if(L->tag==Atom)						//单原子表深度为0，只会出现在递归调用中 
		return 0;
	else										//求一般表的深度 
	{
		for(p=L->Union.hp; p; p=p->tp)
		{
			deep = GListDepth_GL_E_1(p);		//求以p为头指针的子表深度 
			if(deep>max)
				max = deep;
		}
	}
	    
	return max + 1;
}

// 对于表结点，分横向深度和纵向深度讨论。跳过原子结点
int GListDepth_GL_E_2(GList L)
{
	int max, deep;
	GList p = L;
	
	max = deep = 0;
	
	if(!L)
	{
		printf("广义表L不存在！！\n");
		exit(OVERFLOW);
	}
	else
	{		
		if(L->tag==List)								//处理表结点 
		{
			max++;										//一个表结点代表一个深度 
			
			if(L->Union.hp)
			{
				deep = GListDepth_GL_E_2(L->Union.hp);
				max += deep;							//纵向深度不断累加 
			}
			
			do											//跳过同一层原子结点 
			{
				p = p->tp;
			}while(p && p->tag!=List);					
		}
		else											//处理原子结点 
		{
			while(p && p->tag!=List)					//跳过同一层原子结点 
				p = p->tp;
		}
		
		if(p)												
		{
			deep = GListDepth_GL_E_2(p);
			if(deep>max)								//max保存同一层各结点的最大深度 
				max = deep;								//横向深度取最大的一个 
		}			
	}
	
	return max;
}

Status GListEmpty_GL_E(GList L)
{
	if(!L)
	{
		printf("广义表不存在！！\n");
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
		printf("广义表不存在！！\n");
		exit(OVERFLOW);
	}
	if(!L->Union.hp)
	{
		printf("广义表为空表，无法获取表头！\n");
		exit(OVERFLOW);
	}
	
	q = L->Union.hp->tp;								//q保存L的表尾
	L->Union.hp->tp = NULL; 							//截去L的表尾部分
	CopyGList_GL_E(&p, L->Union.hp); 					//将表头元素复制给h
	L->Union.hp->tp = q;								//恢复L的表尾 
	
	return p;
}

GList GetTail_GL_E(GList L)
{
	GList p, q;
	
	if(!L)
	{
		printf("广义表不存在！！\n");
		exit(OVERFLOW);
	}
	if(!L->Union.hp)
	{
		printf("广义表为空表，无法获取表尾！\n");
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
		printf("广义表不存在！！\n");
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
		printf("广义表不存在！！\n");
		exit(OVERFLOW);
	}
	if(!(*L)->Union.hp)
	{
		printf("广义表为空表，删除表头失败！\n");
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
		if(L->tag==List)								//处理表结点 
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
		else											//处理原子结点 
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
