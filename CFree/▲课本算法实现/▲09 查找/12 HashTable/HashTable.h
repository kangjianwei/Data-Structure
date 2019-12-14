/**********************************
 *                                *
 * 文件夹: ▲09 查找              *
 *                                *
 * 文件名: HashTable.h            *
 *                                *
 * 内  容: 哈希查找表相关操作列表 *
 *                                *
 **********************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "../00 Base/Base.c" 				//**▲09 查找**//

/*全局变量*/
int hashsize[] = {7,13,17,101,211,307,401,503,601,701,809,907,997};	//哈希表容量递增表，一个合适的素数序列 

/* 宏定义 */
#define DUPLICATE -1						//表中已存在关键字
#define NULLKEY   -2						//标记此处无关键字 
#define FULL      -3						//表已满（冲突次数达上限就认为表满） 
#define EQ(a,b) ((a)==(b))

/* 类型定义 */
typedef struct								//开放定址哈希表存储表示
{
	KeyType *elem;							//数据元素存储基址，动态分配数组 
	int count;								//当前哈希表包含的关键字个数 
	int sizeindex;							//hashsize[sizeindex]为当前容量 
}HashTable; 

void InitHash(HashTable *H);
/*━━━━━━━━━━━━━┓
┃(01)初始化一个空的哈希表。┃
┗━━━━━━━━━━━━━*/

/* 哈希查找表函数列表 */
Status CreateHash(HashTable *H, Table T); 
/*━━━━━━━━┓
┃(02)创建哈希表。┃
┗━━━━━━━━*/

Status SearchHash(HashTable H, KeyType K, int *p);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法9.17：哈希表关键字搜索，p指向查找成功后的元素位置，*c记录发生冲突的次数 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertHash(HashTable *H, KeyType K);
/*━━━━━━━━━━━━━━━━┓
┃(04)算法9.18：哈希表关键字插入。┃
┗━━━━━━━━━━━━━━━━*/

Status RecreateHashTable(HashTable *H);
/*━━━━━━━━┓
┃(05)重建哈希表。┃
┗━━━━━━━━*/

int fHash(HashTable H, KeyType K);
/*━━━━━━━┓
┃(06)哈希函数。┃
┗━━━━━━━*/

void collision(HashTable H, int *p);
/*━━━━━━━━━━━━━━━━┓
┃(07)开放定址法寻找下一探查位置。┃
┗━━━━━━━━━━━━━━━━*/

void PrintHash(HashTable H);
/*━━━━━━━━━━━━┓
┃(08)输出哈希表中关键字。┃
┗━━━━━━━━━━━━*/

#endif 
