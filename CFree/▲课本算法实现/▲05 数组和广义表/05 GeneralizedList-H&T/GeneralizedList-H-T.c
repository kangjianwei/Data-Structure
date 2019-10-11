/****************************************************
 *						                            *
 * 文件夹: ▲05 数组和广义表\05 GeneralizedList-H&T *
 * 						                            *
 * 文件名: GeneralizedList-H-T.c                    *
 * 						                            *
 * 算  法: 5.5、5.6、5.7、5.8                       * 
 * 						                            *
 ****************************************************/

#ifndef GENERALIZEDLIST_H_T_C
#define GENERALIZEDLIST_H_T_C

#include "GeneralizedList-H-T.h" 						//**▲05 数组和广义表**//

void InitGList_GL_H_T(GList *L)
{
	*L = NULL;											//初始化了一个空表，长度为0，深度为1 
}

/*════╗
║ 算法5.8║ 
╚════*/
/* 假设广义表各字符间无空格，且输入正确 */
void sever_GL_H_T_1(SString hstr, SString str)			//str最外层已无括号 
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

/*════╗
║ 算法5.7║ 
╚════*/
void CreateGList_GL_H_T_1(GList *L, SString S)
{
	SString emp, hsub, sub;
	GList p, q;
	
	StrAssign_Sq(emp, "()");	
	
	if(!StrCompare_Sq(S, emp))							//S代表空表
		*L = NULL;										//创建空表
	else
	{
		*L = (GList)malloc(sizeof(GLNode));
		if(!*L)
			exit(OVERFLOW);
		
		if(StrLength_Sq(S)==1)							//创建单原子广义表
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
			
			SubString_Sq(sub, S, 2, StrLength_Sq(S)-2);	//去掉最外层括号 
											
			do											//重复建n个子表 
			{	
				sever_GL_H_T_1(hsub, sub);				//分离出表头串hsub	
				CreateGList_GL_H_T_1(&(p->Union.ptr.hp), hsub);
				q = p;
				if(!StrEmpty_Sq(sub))					//表尾不为空，处理表尾 
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

/* 另一种创建广义表的算法，与上述算法略有不同 */
/* 假设广义表各字符间无空格，且输入正确 */
void sever_GL_H_T_2(SString hstr, SString str)			//将str分解为表头元素和表尾元素两部分 
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
			free(*L); 									//删除原子结点
			*L = NULL;      		
     	}
		else											//删除表结点
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

/*════╗
║ 算法5.6║ 
╚════*/
void CopyGList_GL_H_T(GList *T, GList L)
{
	if(!L)
		*T = NULL;
	else
	{
		*T = (GList)malloc(sizeof(GLNode));				//建表结点			
		if(!*T)
			exit(OVERFLOW);
		
		(*T)->tag = L->tag;
		
		if(L->tag==Atom)								//复制单原子
			(*T)->Union.atom = L->Union.atom; 
		else											//复制表头和表尾 
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

/*════╗
║ 算法5.5║ 
╚════*/
int GListDepth_GL_H_T(GList L)
{
	int max, deep;
	GList p;
	
	if(!L)												//空表深度为1 
		return 1;

	if(L->tag==Atom)									//原子深度为0 
		return 0;
	
	for(max=0,p=L; p; p=p->Union.ptr.tp)
	{
		deep = GListDepth_GL_H_T(p->Union.ptr.hp);
		if(deep>max)
			max = deep;
	}
		
	return max + 1;										//非空表的深度是各元素最大深度加一 
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
		printf("广义表为空表，无法获取表头！\n");
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
		printf("广义表为空表，无法获取表尾！\n");
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
		printf("广义表为空表，删除表头失败！\n");
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
	if(!L)												//L为空 
	{
		if(mark==Head)									//mark=0代表广义表指针来自表头 
			printf("()");
		else											//mark=1代表广义表指针来自表尾 
			printf(")");
	}
	else												//L不为空时 
	{
		if(L->tag==Atom)								//对于原子结点，输出原子 
			printf("%c",L->Union.atom);
		else											//对于表结点，要对表头、表尾分别讨论 
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
