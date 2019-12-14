/***************************************
 *                                     *
 * 文件夹: ▲04 串\03 BlockChainString *
 *                                     *
 * 文件名: BlockChainString.h          *
 *                                     *
 * 内  容: 块链串相关操作列表          *
 *                                     *
 ***************************************/

#ifndef BLOCKCHAINSTRING_H
#define BLOCKCHAINSTRING_H

#include <stdio.h> 
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include <string.h>						//提供strlen原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 宏定义 */
#define CHUNKSIZE 3						//块大小（自定义） 

/* 串的块链存储类型定义 */
typedef struct Chunk 
{
	char ch[CHUNKSIZE];					
	struct Chunk *next;
}Chunk;
typedef struct
{
	Chunk *head, *tail;					//串的头和尾指针 
	int curlen;							//串的当前长度 
}LString;								

/* 块链串函数列表 */
void InitString_L(LString *T);
/*━━━━━━━━━━┓
┃(01)初始化块链串T。 ┃
┗━━━━━━━━━━*/

Status StrAssign_L(LString *T, char *chars);
/*━━━━━━━━━━━━━━━━━━┓
┃(02)生成一个其值等于常量chars的串T。┃
┗━━━━━━━━━━━━━━━━━━*/

Status StrCopy_L(LString *T, LString S); 
/*━━━━━━━━━━━┓
┃(03)由串S复制得到串T。┃
┗━━━━━━━━━━━*/ 
 
Status StrEmpty_L(LString S);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(04)若S为空串，返回TRUE,否则返回FALSE。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

int StrCompare_L(LString S, LString T); 
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(05)若S>T，返回值>0；若S<T，返回值<0；否则，返回值=0。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int StrLength_L(LString S); 
/*━━━━━━┓
┃(06)求串长。┃
┗━━━━━━*/
 
void ClearString_L(LString *S);
/*━━━━━━┓
┃(07)清空S。 ┃
┗━━━━━━*/

void Concat_L(LString *T, LString S1, LString S2);
/*━━━━━━━━━━━━━━━━━━┓
┃(08)用T返回由S1和S2联接而成的新串。 ┃
┗━━━━━━━━━━━━━━━━━━*/

Status SubString_L(LString *Sub, LString S, int pos, int len);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(09)用Sub返回串S的第pos个字符起长度为len的子串。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

int Index_L(LString S, LString T, int pos);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)返回T在S中第pos个字符后第一次出现的位置，不存在则返回0。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status Replace_L(LString *S, LString T, LString V);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)用V替换主串S中出现的所有与T相等的不重叠的子串。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status StrInsert_L(LString *S, int pos, LString T);
/*━━━━━━━━━━━━━━━━━━┓
┃(12)在串S的第pos个字符之前插入串T。 ┃
┗━━━━━━━━━━━━━━━━━━*/

Status StrDelete_L(LString *S, int pos, int len);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(13)从串S中删除第pos个字符起长度为len的子串。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void DestroyString_L(LString *S);
/*━━━━━━━┓
┃(14)销毁串S。 ┃
┗━━━━━━━*/

void StrPrint_L(LString S);
/*━━━━━━━┓
┃(15)输出串S。 ┃
┗━━━━━━━*/

Status GetChar_L(LString S, char *c, int i);
/*━━━━━━━━━━━┓
┃用*c返回串S中第i个字符┃
┗━━━━━━━━━━━*/

#endif
