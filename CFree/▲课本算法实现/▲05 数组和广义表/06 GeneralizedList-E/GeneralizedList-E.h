/******************************************************
 *						                              *
 * 文件夹: ▲05 数组和广义表\06 GeneralizedList-E     *
 * 						                              *
 * 文件名: GeneralizedList-E.h                        *
 * 							                          *
 * 内  容: 广义表（扩展线性链表存储表示）相关操作列表 *
 *                                                    *
 ******************************************************/

#ifndef GENERALIZEDLIST_E_H
#define GENERALIZEDLIST_E_H

#include <stdio.h>
#include <stdlib.h>								            //提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"				            //**▲01 绪论**//
#include "../../▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 广义表（扩展线性链表存储表示）类型定义 */
typedef enum { Atom, List }ElemTag;			//Atom==0：原子结点，List==1：表结点
typedef char AtomType;						//原子类型
typedef struct GLNode
{
	ElemTag tag;							//公共部分，用于区分原子结点和表结点
	union									//原子结点和表结点的联合部分
	{
		AtomType atom;						//原子结点值域 
		struct GLNode *hp;					//表结点的表头指针 
	}Union;
	struct GLNode *tp;						//相当于线性链表的next，指向下一个元素结点 
}GLNode;
typedef GLNode* GList;						//广义表类型

/* 广义表（扩展线性链表存储）基础操作 */
/* ★每一层带上括号考察★ */
void InitGList_GL_E(GList *L);
/*━━━━━━━━━━━━━━━━━━━┓
┃(01)初始化广义链表（创建空的广义表）。┃
┗━━━━━━━━━━━━━━━━━━━*/

void sever_GL_E(SString hstr, SString str);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)将非空串str分割成两部分:hstr为第一个','之前的子串,str为之后的子串。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void CreateGList_GL_E(GList *L, SString S);
/*━━━━━━━━━━┓
┃(03)由S创建广义表。 ┃
┗━━━━━━━━━━*/

void DestroyGList_GL_E(GList *L);
/*━━━━━━━━┓
┃(04)销毁广义表。┃
┗━━━━━━━━*/

void CopyGList_GL_E(GList *T, GList L);
/*━━━━━━━━┓
┃(05)复制广义表。┃
┗━━━━━━━━*/

int GListLength_GL_E(GList L);
/*━━━━━━━━━┓
┃(06)求广义表长度。┃
┗━━━━━━━━━*/

int GListDepth_GL_E_1(GList L);
/*━━━━━━━━━━┓
┃(07-1)求广义表深度。┃
┗━━━━━━━━━━*/

int GListDepth_GL_E_2(GList L);
/*━━━━━━━━━━┓
┃(07-2)求广义表深度。┃
┗━━━━━━━━━━*/

Status GListEmpty_GL_E(GList L);
/*━━━━━━━━━━━━┓
┃(08)判断广义表是否为空。┃
┗━━━━━━━━━━━━*/

GList GetHead_GL_E(GList L);
/*━━━━━━━┓
┃(09)获取表头。┃
┗━━━━━━━*/

GList GetTail_GL_E(GList L);
/*━━━━━━━┓
┃(10)获取表尾。┃
┗━━━━━━━*/

void InsertFirst_GL_E(GList *L, GList e);
/*━━━━━━━━━━━━━━━┓
┃(11)插入e作为广义表第一元素。 ┃
┗━━━━━━━━━━━━━━━*/

void DeleteFirst_GL_E(GList *L, GList *e);
/*━━━━━━━━━━━━━━━━━┓
┃(12)删除广义表第一元素并用e返回。 ┃
┗━━━━━━━━━━━━━━━━━*/

void Traverse_GL_E(GList L, void(Visit)(AtomType));
/*━━━━━━━━┓
┃(13)遍历广义表。┃
┗━━━━━━━━*/

void Output_GL_E(GList L);
/*━━━━━━━━━━━━┓
┃(14)带括号输出广义表L。 ┃
┗━━━━━━━━━━━━*/

#endif
