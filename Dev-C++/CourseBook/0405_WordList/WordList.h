/*===========================================
 * 索引表
 *
 * 包含算法: 4.9、4.10、4.11、4.12、4.13、4.14
 ============================================*/

#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdio.h>      // 提供fopen、fclose、feof、fgets原型
#include <stdlib.h>     // 提供exit、strtol原型
#include <string.h>     // 提供strlen、strcmpi、strlwr原型
#include "Status.h"     //**▲01 绪论**//
#include "ELinkList.h"  //**▲02 线性表**//
#include "HString.h"    //**▲04 串**//

/* 宏定义 */
#define MaxBookNum 1000     // 允许的最大书目数（假设最多只对1000本书建索引表）
#define MaxKeyNum  2500     // 索引表最大容量(索引项数量的最大值)
#define MaxLineLen 500      // 书目串(行)的最大长度
#define MaxWordNum 100      // 词表的最大容量

/* 类型定义 */

// 布尔类型
typedef Status Boolean;

// 词表类型(顺序表)
typedef struct {
    char* item[MaxWordNum];  // 词表集合
    int last;                // 词表的长度
} WordListType;

// 索引项类型（索引表的行）
typedef struct {
    HString key;        // 关键词
    ELinkList bnolist;  // 存放书号索引的链表
} IdxTermType;

/*
 * 索引表类型
 *
 *【注】
 * 0号单元存储表头信息，这一点与教材有所不同
 */
typedef struct {
    IdxTermType item[MaxKeyNum + 1];    // 索引项的集合
    int last;                           // 索引表中包含的索引项数目
} IdxListType;

/* 全局变量（变量名称前面都加了g标记） */

// 书目缓存区
static char gBuf[MaxLineLen];

// 关键词词表(普通词表)，已经排除了常用词
static WordListType gWdList;


/*
 * ████████ 算法4.9 ████████
 *
 * 从文件bookinfo中读取书目信息，并依此创建相应的关键词索引表，然后将索引表写入文件bookidx。
 */
void Main(char* bookinfo, char* bookidx);

/*
 * 初始化索引表
 *
 *【注】
 * 教材中将索引表表头置为空串，但这里设定了一个有意义的表头
 */
void InitIdxList(IdxListType* idxlist);

/*
 * 从文件f中读取一条书目信息存入书目缓冲区gBuf。
 */
void GetLine(FILE* f);

/*
 * 从缓冲区gBuf中提取书名关键词到词表gWdList，书号存入bno。
 */
void ExtractKeyWord(ElemType* bno);

/*
 * ████████ 算法4.10 ████████
 *
 * 将书号bno对应的书名关键词按词典顺序插入到索引表idxlist。
 */
Status InsIdxList(IdxListType* idxlist, int bno);

/*
 * ████████ 算法4.11 ████████
 *
 * 用wd返回词表gWdList中第i个关键词。
 */
void GetWord(int i, HString* wd);

/*
 * ████████ 算法4.12 ████████
 *
 * 查询在索引表idxlist中是否存在与wd相等的关键词。
 * 若存在，则返回wd在词表中的位置，并置b为TRUE。
 * 若不存在，则返回wd应插入的位置，并置b为FALSE。
 */
int Locate(IdxListType idxlist, HString wd, Boolean* b);

/*
 * ████████ 算法4.13 ████████
 *
 * 在索引表的索引i(>=0)处插入关键词wd，并初始化书号索引的链表为空表。
 */
void InsertNewKey(IdxListType* idxlist, int i, HString wd);

/*
 * ████████ 算法4.14 ████████
 *
 * 为索引表在索引i(>0)处的关键词插入书号。
 */
Status InsertBook(IdxListType* idxlist, int i, int bno);

/*
 * 将生成的索引表idxlist输出到文件g。
 */
void PutText(FILE* g, IdxListType idxlist);

// 判断str是否为常用词
static Status isCommonWords(char* str);

#endif
