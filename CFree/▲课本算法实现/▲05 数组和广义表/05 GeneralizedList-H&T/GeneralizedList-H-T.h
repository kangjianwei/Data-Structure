/****************************************************
 *						                            *
 * 文件夹: ▲05 数组和广义表\05 GeneralizedList-H&T *
 * 						                            *
 * 文件名: GeneralizedList-H-T.h                    *
 * 						                            *
 * 内  容: 广义表（头尾链表存储表示）相关操作列表   *
 * 						                            *
 ****************************************************/

#ifndef GENERALIZEDLIST_H_T_H
#define GENERALIZEDLIST_H_T_H

#include <stdio.h>
#include <stdlib.h>											//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 广义表（头尾链表存储表示）类型定义 */
typedef enum{ Head, Tail }Mark;
typedef enum{ Atom, List }ElemTag;			//Atom==0：原子结点，List==1：表结点
typedef char AtomType;						//原子类型
typedef struct GLNode
{
	union{ int mark; };						//匿名联合，仅在第8章广义表遍历算法中使用 
	
	ElemTag tag;							//公共部分，用于区分原子结点和表结点 
	union									//原子结点和表结点的联合部分 
	{
		AtomType atom;						//atom是原子结点的值域，AtomType由用户定义 
		struct
		{
			struct GLNode *hp;				//指向表头
			struct GLNode *tp;				//指向表尾 
		}ptr;								//表结点的指针域 
	}Union;
}GLNode;
typedef GLNode* GList;						//广义表类型 

/* 广义表（头尾链表存储）函数列表 */
/* ★每一层去掉括号考察★ */
void InitGList_GL_H_T(GList *L);
/*━━━━━━━━━━━━━━━━━━━┓
┃(01)初始化广义链表（创建空的广义表）。┃
┗━━━━━━━━━━━━━━━━━━━*/

void sever_GL_H_T_1(SString hstr, SString str);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02-1)算法5.8：将非空串str分割成两部分:hsub为第一个','之前的子串,str为之后的子串。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void CreateGList_GL_H_T_1(GList *L, SString S);
/*━━━━━━━━━━━━━━━┓
┃(03-1)算法5.7：由S创建广义表。┃
┗━━━━━━━━━━━━━━━*/

void sever_GL_H_T_2(SString hstr, SString str);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02-2)将非空串str分割成两部分:hsub做表头,str做表尾。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void CreateGList_GL_H_T_2(GList *L, SString S);
/*━━━━━━━━━━━┓
┃(03-2)由S创建广义表。 ┃
┗━━━━━━━━━━━*/

void ClearGList_GL_H_T(GList *L);
/*━━━━━━━━━━━━━━┓
┃(04)清空广义表（无法销毁）。┃
┗━━━━━━━━━━━━━━*/

void CopyGList_GL_H_T(GList *T, GList L);
/*━━━━━━━━━━━━━┓
┃(05)算法5.6：复制广义表。 ┃
┗━━━━━━━━━━━━━*/

int GListLength_GL_H_T(GList L);
/*━━━━━━━━━┓
┃(06)求广义表长度。┃
┗━━━━━━━━━*/

int GListDepth_GL_H_T(GList L);
/*━━━━━━━━━━━━━━┓
┃(07)算法5.5：求广义表深度。 ┃
┗━━━━━━━━━━━━━━*/

Status GListEmpty_GL_H_T(GList L);
/*━━━━━━━━━━━━┓
┃(08)判断广义表是否为空。┃
┗━━━━━━━━━━━━*/

GList GetHead_GL_H_T(GList L);
/*━━━━━━━┓
┃(09)获取表头。┃
┗━━━━━━━*/

GList GetTail_GL_H_T(GList L);
/*━━━━━━━┓
┃(10)获取表尾。┃
┗━━━━━━━*/

void InsertFirst_GL_H_T(GList *L, GList e);
/*━━━━━━━━━━━━━━━┓
┃(11)插入e为广义表第一个元素。 ┃
┗━━━━━━━━━━━━━━━*/

void DeleteFirst_GL_H_T(GList *L, GList *e);
/*━━━━━━━━━━━━━━━┓
┃(12)删除广义表表头并用e返回。 ┃
┗━━━━━━━━━━━━━━━*/

void Traverse_GL_H_T(GList L, void(Visit)(AtomType));
/*━━━━━━━━┓
┃(13)遍历广义表。┃
┗━━━━━━━━*/

void Output_GL_H_T(GList L, Mark mark);
/*━━━━━━━━━━━━━━━━━━┓
┃(14)带括号输出广义表L，mark为标记。 ┃
┗━━━━━━━━━━━━━━━━━━*/

#endif
