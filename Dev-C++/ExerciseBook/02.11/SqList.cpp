/*=============================
 * 线性表的顺序存储结构（顺序表）
 *
 * 包含算法: 2.3、2.4、2.5、2.6
 =============================*/

#include "SqList.h"

/*
 * ████████ 算法2.3 ████████
 *
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(SqList* L) {
    // 分配指定容量的内存，如果分配失败，则返回NULL
    (*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if((*L).elem == NULL) {
        // 存储内存失败
        exit(OVERFLOW);
    }
    
    (*L).length = 0;                    // 初始化顺序表长度为0
    (*L).listsize = LIST_INIT_SIZE;     // 顺序表初始内存分配量
    
    return OK;                          // 初始化成功
}

/*
 * ████████ 算法2.6 ████████
 *
 * 查找
 *
 * 返回顺序表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是Compare函数第二个形参
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    ElemType* p;
    
    // 确保顺序表结构存在
    if(L.elem == NULL) {
        return ERROR;
    }
    
    /*
     * i的初值为第1个元素的位序
     *
     * 其实，更自然的写法是将i初始化为第1个元素的索引
     * 但由于教材中是按位序计数的，所以这里仍写作位序
     */
    i = 1;
    
    // p的初值为第1个元素的存储位置
    p = L.elem;
    
    // 遍历顺序表
    while(i <= L.length && !Compare(*p++, e)) {
        ++i;
    }
    
    if(i <= L.length) {
        return i;
    } else {
        return 0;
    }
}

/*
 * ████████ 算法2.4 ████████
 *
 * 插入
 *
 * 向顺序表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SqList* L, int i, ElemType e) {
    ElemType* newbase;
    ElemType* p, * q;
    
    // 确保顺序表结构存在
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }
    
    // i值越界
    if(i < 1 || i > (*L).length + 1) {
        return ERROR;
    }
    
    // 若存储空间已满，则增加新空间
    if((*L).length >= (*L).listsize) {
        // 基于现有空间扩容
        newbase = (ElemType*) realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL) {
            // 存储内存失败
            exit(OVERFLOW);
        }
        
        // 新基址
        (*L).elem = newbase;
        // 存的存储空间
        (*L).listsize += LISTINCREMENT;
    }
    
    // q为插入位置
    q = &(*L).elem[i - 1];
    
    // 1.右移元素，腾出位置
    for(p = &(*L).elem[(*L).length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    
    // 2.插入e
    *q = e;
    
    // 3.表长增1
    (*L).length++;
    
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    
    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
    
    printf("\n");
}
