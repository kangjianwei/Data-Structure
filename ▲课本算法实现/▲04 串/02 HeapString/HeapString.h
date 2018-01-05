/*********************************
 *                               *
 * 文件夹: ▲04 串\02 HeapString *
 *                               *
 * 文件名: HeapString.h          *
 *                               *
 * 内  容: 堆串相关操作列表      *
 *                               *
 *********************************/

#ifndef HEAPSTRING_H
#define HEAPSTRING_H

#include <stdio.h> 
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include <string.h>						//提供strlen原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 串的堆存储表示 */
typedef struct
{
	char *ch;							//若是非空串，则按串长分配存储区，否则ch为NULL 
	int length;
}HString;							

/* 堆串函数列表 */
void InitString_H(HString *S);
/*━━━━━━━━━━┓
┃(01)初始化S为空串。 ┃
┗━━━━━━━━━━*/

Status StrAssign_H(HString *T, char *chars);
/*━━━━━━━━━━━━━━━━━━┓
┃(02)生成一个其值等于常量chars的串T。┃
┗━━━━━━━━━━━━━━━━━━*/

Status StrCopy_H(HString *T, HString S); 
/*━━━━━━━━━━━┓
┃(03)由串S复制得到串T。┃
┗━━━━━━━━━━━*/ 
 
Status StrEmpty_H(HString S);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(04)若S为空串，返回TRUE,否则返回FALSE。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

Status StrCompare_H(HString S, HString T); 
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(05)若S>T，返回值>0；若S<T，返回值<0；否则，返回值=0。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int StrLength_H(HString S); 
/*━━━━━━┓
┃(06)求串长。┃
┗━━━━━━*/
 
Status ClearString_H(HString *S);
/*━━━━━━┓
┃(07)清空S。 ┃
┗━━━━━━*/

Status Concat_H(HString *T, HString S1, HString S2);
/*━━━━━━━━━━━━━━━━━━┓
┃(08)用T返回由S1和S2联接而成的新串。 ┃
┗━━━━━━━━━━━━━━━━━━*/

Status SubString_H(HString *Sub, HString S, int pos, int len);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(09)用Sub返回串S的第pos个字符起长度为len的子串。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

int Index_H(HString S, HString T, int pos);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)返回T在S中第pos个字符后第一次出现的位置，不存在则返回0。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status Replace_H(HString *S, HString T, HString V);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)用V替换主串S中出现的所有与T相等的不重叠的子串。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status StrInsert_H(HString *S, int pos, HString T);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(12)算法4.4：在串S的第pos个字符之前插入串T。┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

Status StrDelete_H(HString *S, int pos, int len);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(13)从串S中删除第pos个字符起长度为len的子串。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void DestroyString_H(HString *S);
/*━━━━━━━┓
┃(14)销毁串S。 ┃
┗━━━━━━━*/

void StrPrint_H(HString S);
/*━━━━━━━┓
┃(15)输出串S。 ┃
┗━━━━━━━*/

#endif
