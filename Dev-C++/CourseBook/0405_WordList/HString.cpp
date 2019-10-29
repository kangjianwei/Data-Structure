/*=========================
 * 串的堆分配存储表示（堆串）
 *
 * 包含算法: 4.4
 ==========================*/

#include "HString.h"    //**▲04 串**//

/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(HString* T, const char* chars) {
    int i, j;
    
    // 求chars的长度
    i = (int) strlen(chars);
    
    // 没有有效元素
    if(i == 0) {
        (*T).ch = NULL;
        (*T).length = 0;
    
        return OK;
    }
    
    // 存在有效元素时，需要分配存储空间
    (*T).ch = (char*) malloc(i * sizeof(char));
    if(!((*T).ch)) {
        exit(OVERFLOW);
    }
    
    for(j = 0; j < i; j++) {
        (*T).ch[j] = chars[j];
    }
    
    (*T).length = i;
    
    return OK;
}

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrCompare(HString S, HString T) {
    int i;
    
    for(i = 0; i < S.length && i < T.length; i++) {
        // 遇到不同的字符时，比较其大小
        if(S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    
    return S.length - T.length;
}

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy(HString* T, HString S) {
    int i;
    
    if(S.length == 0) {
        (*T).ch = NULL;
        (*T).length = 0;
    } else {
        // 分配空间
        (*T).ch = (char*) malloc(S.length * sizeof(char));
        if(!(*T).ch) {
            exit(OVERFLOW);
        }
        
        // 复制元素
        for(i = 0; i < S.length; i++) {
            (*T).ch[i] = S.ch[i];
        }
        
        // 复制长度信息
        (*T).length = S.length;
    }
    
    return OK;
}
