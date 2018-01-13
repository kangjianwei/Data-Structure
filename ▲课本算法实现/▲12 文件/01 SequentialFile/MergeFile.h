/********************************
 *                              *
 * 文件夹: ▲12 文件            *
 *                              *
 * 文件名: MergeFile.h          *
 *                              *
 * 内  容: 文件归并相关操作列表 *
 *                              *
 ********************************/

#ifndef MERGEFILE_H
#define MERGEFILE_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//

/* 文件类型定义 */
typedef struct				//主文件
{
	int key;				//账号
	int balance;			//余额 
}MainFile;
typedef struct				//事务文件
{
	char code;				//操作：I-插入，D删去，U更改
	int key;				//账号
	int money;				//金额变动，存"+"，取"-" 
}AffairFile;

/* 文件归并函数列表 */
void InitFile(FILE *f, FILE *g);
/*━━━━━━━━━━━━━━━━━┓
┃(01)初始化一个主文件f和事务文件g。┃
┗━━━━━━━━━━━━━━━━━*/

int Situation(MainFile fr, AffairFile gr);
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)根据读到的主文件记录与事务记录，判断当前情形。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/

MainFile P(AffairFile gr);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(03)将事务记录类型转换为主文件记录类型。┃
┗━━━━━━━━━━━━━━━━━━━━*/

MainFile Q(MainFile fr, AffairFile gr);
/*━━━━━━━━━━━━━━━━┓
┃(04)根据事务记录修改主文件记录。┃
┗━━━━━━━━━━━━━━━━*/

void Error(AffairFile gr, FILE *log);
/*━━━━━━━━━━━━━━━━━━━┓
┃(05)将发生错误的事务记录写入日志文件。┃
┗━━━━━━━━━━━━━━━━━━━*/

void MergeFile(FILE *f, FILE *g, FILE *h, FILE *log); 
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(06)算法12.1：归并主文件f和事务记录g到新的文件h。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Print(FILE *fp, int mark);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)输出记录，mark=0表示输出文件记录，mark=1表示输出事务记录。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
