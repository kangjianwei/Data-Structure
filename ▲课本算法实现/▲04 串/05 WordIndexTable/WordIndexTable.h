/*************************************
 *                                   *
 * 文件夹: ▲04 串\05 WordIndexTable *
 * 							         *
 * 文件名: WordIndexTable.h          *
 * 							         *
 * 内  容: 创建索引表相关操作列表    *
 *                                   *
 *************************************/

#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include <stdio.h> 						//提供fopen、fclose、feof、fgets原型 
#include <stdlib.h> 					//提供exit、strtol原型
#include <string.h>						//提供strlen、strcmpi、strlwr原型
#include "../../▲01 绪论/Status.h"									//**▲01 绪论**//
#include "../../▲02 线性表/09 ExtenLinkedList/ExtenLinkedList.c"	//**▲02 线性表**//
#include "../02 HeapString/HeapString.c" 							//**▲04 串**//

/* 宏定义 */ 
#define MaxBookNum 1000					//允许的最大书目数 
#define MaxKeyNum  2500					//关键词索引表最大容量 
#define MaxLineLen 500					//书目串的最大长度 
#define MaxWordNum 10					//词表的最大容量

/* 类型定义 */
typedef Status Bool;
typedef struct							//词表类型(顺序表) 
{
	char *str[MaxWordNum];				//字符串数组 
	int last;							//词表的长度 
}WordListType;
typedef struct							//索引项类型 
{
	HString key;						//索引关键词 
	ELinkList bnolist;					//存放书号索引的链表 
}IdxTermType;
typedef struct							//索引表类型(有序表)
{
	IdxTermType item[MaxKeyNum+1];		//索引表 
	int num;							//索引表中包含的索引项数目 
}IdxListType;

/* 全局变量 */
char gBuf[MaxLineLen]; 					//书目缓存区 
WordListType gWordList = {{"a","an","the","of","and","is","to","as","in","for"},10};//常用词词表
WordListType gWdList;					//关键词词表(普通词表)

/* 创建索引表函数列表 */
void Main(char *bookinfo, char *bookidx);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法4.9：读取书目文件，并创建相应的关键词索引表到另一文件。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void InitIdxList(IdxListType *idxlist);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法4.10：初始化索引表，且在idxlist.item[0]设置一表头。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void GetLine(FILE *f);
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)从文件f中读取一条书目信息存入书目缓冲区gBuf。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

void ExtractKeyWord(int *bno);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)从gBuf中提取书名关键词到词表gWdList，书号存入bno。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsIdxList(IdxListType *idxlist, int bno);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(05)将书号bno对应的书名关键词按词典顺序插入索引表idxlist。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void PutText(FILE *g, IdxListType idxlist);
/*━━━━━━━━━━━━━━━━━━━┓
┃(06)将生成的索引表idxlist输出到文件g。┃
┗━━━━━━━━━━━━━━━━━━━*/

void GetWord(int i, HString *wd);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)算法4.11：用wd返回词表gWdList中第i个关键词。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

int Locate(IdxListType idxlist, HString wd, Bool *b);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(08)算法4.12：查询在索引表idxlist中是否存在与wd相等的关键词。                       ┃
┃	  若存在，则返回wd在词表中的位置并置b为TRUE，否则返回wd应插入的位置并置b为FALSE。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void InsertNewKey(IdxListType *idxlist, int i, HString wd);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(09)算法4.13：在索引表第i项上插入关键词wd，并初始化书号索引的链表为空表。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertBook(IdxListType *idxlist, int i, int bno);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)算法4.14：在索引表的第i项中插入书号为bno的索引。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status isCommonWords(HString S);
/*━━━━━━━━━━━━━━━━━━┓
┃(11)判断S包含的关键词是否为常用词。 ┃
┗━━━━━━━━━━━━━━━━━━*/

#endif
