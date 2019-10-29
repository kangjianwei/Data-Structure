/*===========================================
 * 索引表
 *
 * 包含算法: 4.9、4.10、4.11、4.12、4.13、4.14
 ============================================*/

#include "WordList.h"   //**▲04 串**//

/*
 * ████████ 算法4.9 ████████
 *
 * 从文件bookinfo中读取书目信息，并依此创建相应的关键词索引表，然后将索引表写入文件bookidx。
 */
void Main(char* bookinfo, char* bookidx) {
    FILE* f, * g;
    char head[MaxLineLen];      // 书目的表头信息（未使用）
    IdxListType idxlist;        // 关键词索引表
    ElemType bno;               // 书号
    int count;
    
    // 以“只读”模式打开书目文件
    if((f = fopen(bookinfo, "r")) != NULL) {
        
        // 以“只写”模式打开索引文件
        if((g = fopen(bookidx, "w")) != NULL) {
            
            // 初始化索引表
            InitIdxList(&idxlist);
            
            // 跳过文件第一行
            fgets(head, MaxLineLen, f);
            
            count = 0;
            
            // 如果未到文件结尾，则一直读文件
            while(feof(f) == FALSE && count < MaxBookNum) {
                
                // 从文件f读入一个书目信息到书目缓冲区gBuf
                GetLine(f);
                
                // 从gBuf提取关键词到词表gWdList，书号存入bno
                ExtractKeyWord(&bno);
                
                // 将书号及对应的关键词插入索引表idxlist
                InsIdxList(&idxlist, bno);
                
                count++;
            }
            
            // 向文件g中写入索引表数据
            PutText(g, idxlist);
            
            fclose(g);
        }
        
        fclose(f);
    }
}

/*
 * 初始化索引表
 *
 *【注】
 * 教材中将索引表表头置为空串，但这里设定了一个有意义的表头
 */
void InitIdxList(IdxListType* idxlist) {
    // 索引表的表头信息
    char* chars = "关键词            书号索引";
    IdxTermType e;
    
    // 初始化表头信息
    StrAssign(&(e.key), chars);
    
    // 初始化书号索引链表
    InitList(&(e.bnolist));
    
    (*idxlist).item[0] = e;
    
    // 表头为第0条信息
    (*idxlist).last = 0;
}

/*
 * 从文件f中读取一条书目信息存入书目缓冲区gBuf。
 */
void GetLine(FILE* f) {
    // 读取一行数据，存入缓冲区gBuf
    fgets(gBuf, MaxLineLen, f);
}

/*
 * 从缓冲区gBuf中提取书名关键词到词表gWdList，书号存入bno。
 */
void ExtractKeyWord(ElemType* bno) {
    char delim[] = {'-', ' ', '\r', '\n', '\t'};  // 分隔符
    char* title;    // 书名
    char* token;    // 从书名中分解出的关键词
    
    // 分解书目字符串，将书号存入bno(十进制)，并用title指向剩下的字符串(书名)
    *bno = (int) strtol(gBuf, &title, 10);
    
    // 将书名的由大写变小写
    strlwr(title);
    
    // 清空关键词词表
    gWdList.last = 0;
    
    // 分解关键词
    for(token = strtok(title, delim); token != NULL; token = strtok(NULL, delim)) {
        // 如果该关键词是常用词，则忽略它
        if(isCommonWords(token) == TRUE) {
            continue;
        }
        
        // 记下从书名中提取的关键词
        gWdList.item[gWdList.last++] = token;
    }
}

/*
 * ████████ 算法4.10 ████████
 *
 * 将书号bno对应的书名中的关键词按词典顺序插入到索引表idxlist。
 */
Status InsIdxList(IdxListType* idxlist, int bno) {
    int i, j;
    Boolean boo;
    HString wd;
    
    if(gWdList.last <= 0) {
        return ERROR;
    }
    
    // 遍历书号bno对应的书名中的所有关键词
    for(i = 0; i < gWdList.last; i++) {
        // 获取待插入的关键词
        GetWord(i, &wd);
        
        // 判断该关键词是否已经位于索引表中
        j = Locate(*idxlist, wd, &boo);
        
        // 如果该关键词不在索引表中，则需要插入关键词
        if(boo == FALSE) {
            // 将关键词wd插入到索引表
            InsertNewKey(idxlist, j, wd);
        }
        
        // 在关键词已存在的情形下，插入书号
        if(!InsertBook(idxlist, j, bno)) {
            return ERROR;
        }
    }
    
    return OK;
}

/*
 * ████████ 算法4.11 ████████
 *
 * 用wd返回词表gWdList中第i个关键词。
 */
void GetWord(int i, HString* wd) {
    if(i < 0 || i > gWdList.last - 1) {
        StrAssign(wd, "");
    } else {
        StrAssign(wd, gWdList.item[i]);
    }
}

/*
 * ████████ 算法4.12 ████████
 *
 * 查询在索引表idxlist中是否存在与wd相等的关键词。
 * 若存在，则返回wd在词表中的位置，并置b为TRUE。
 * 若不存在，则返回wd应插入的位置，并置b为FALSE。
 */
int Locate(IdxListType idxlist, HString wd, Boolean* b) {
    int i, m = -1;
    
    /*
     * 在索引表idxlist中查找关键词wd是否存在
     * 注：0号单元存储了表头信息
     */
    for(i = idxlist.last; i > 0 && (m = StrCompare(idxlist.item[i].key, wd)) > 0; i--) {
    }
    
    // 如果找到了关键词wd
    if(m == 0) {
        *b = TRUE;
        return i;
    } else {
        *b = FALSE;
        return i + 1;
    }
}

/*
 * ████████ 算法4.13 ████████
 *
 * 在索引表的索引i(>=0)处插入关键词wd，并初始化书号索引的链表为空表。
 */
void InsertNewKey(IdxListType* idxlist, int i, HString wd) {
    int j;
    
    /*
     * 索引项后移
     * 注：0号单元存储了表头信息
     */
    for(j = (*idxlist).last; j >= i; j--) {
        (*idxlist).item[j + 1] = (*idxlist).item[j];
    }
    
    // 插入索引项
    StrCopy(&((*idxlist).item[i].key), wd);
    
    // 初始化书号索引链表
    InitList(&((*idxlist).item[i].bnolist));
    
    // 索引数目增一
    (*idxlist).last++;
}

/*
 * ████████ 算法4.14 ████████
 *
 * 为索引表在索引i(>0)处的关键词插入书号。
 */
Status InsertBook(IdxListType* idxlist, int i, ElemType bno) {
    Link p;
    
    // 内存分配失败
    if(MakeNode(&p, bno) == FALSE) {
        return ERROR;
    }
    
    // 插入新的书号索引
    Append(&((*idxlist).item[i].bnolist), p);
    
    return OK;
}

/*
 * 将生成的索引表idxlist输出到文件g。
 */
void PutText(FILE* g, IdxListType idxlist) {
    int i, j, m, n;
    Link p;
    HString S;
    ELinkList L;
    
    if(idxlist.last <= 0) {
        return;
    }
    
    // 先输出表头信息
    S = idxlist.item[0].key;
    for(m = 0; m < S.length; m++) {
        fprintf(g, "%c", S.ch[m]);
    }
    fprintf(g, "\n");
    
    // 输出索引信息
    for(i = 1; i <= idxlist.last; i++) {
        // 1.输出关键词
        S = idxlist.item[i].key;
        for(m = 0; m < S.length; m++) {
            fprintf(g, "%c", S.ch[m]);
        }
        
        // 2.输出空格
        for(j = 1; j <= 18 - idxlist.item[i].key.length; j++) {
            fprintf(g, " ");
        }
        
        // 3.输出书号索引
        L = idxlist.item[i].bnolist;
        for(n = 1, p = L.head->next; n <= L.len; n++) {
            fprintf(g, "%03d", p->data);
            p = p->next;
            if(p) {
                fprintf(g, "，");
            }
        }
        
        // 4.输出换行
        fprintf(g, "\n");
    }
    
}

// 判断str是否为常用词
static Status isCommonWords(char* str) {
    int i;
    
    // 常用词词表，这些词汇会被排除在关键词之外
    WordListType words = {{"a", "an", "the", "of", "and", "is", "to", "as", "in", "for"}, 10};
    
    // 查询常用词词表
    for(i = 0; i < words.last; i++) {
        // 对两字符串进行忽略大小写的比较
        if(strcasecmp(str, words.item[i]) == 0) {
            // 如果该字符串是常用词，则返回TRUE
            return TRUE;
        }
    }
    
    return FALSE;
}
