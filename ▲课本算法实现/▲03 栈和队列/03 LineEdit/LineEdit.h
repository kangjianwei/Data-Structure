/*************************************
 *							      	 *
 * 文件夹: ▲03 栈和队列\03 LineEdit *
 * 							      	 *
 * 文件名: LineEdit.h             	 *
 * 							      	 *
 * 内  容: 行编辑程序相关操作列表  	 *
 *                                	 *
 *************************************/

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <stdio.h> 
#include "../01 SequenceStack/SequenceStack.c" 		//**▲03 栈和队列**//

/* 行编辑程序函数列表 */
void LineEdit(char Buffer[]);
/*━━━━━━━━━━━━━┓
┃(01)算法3.2：行编辑程序。 ┃
┗━━━━━━━━━━━━━*/

void Print(SElemType_Sq e);
/*━━━━━━━━┓
┃(02)打印元素e。 ┃
┗━━━━━━━━*/

#endif
