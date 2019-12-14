/*=============================
 * 串的定长顺序存储表示（顺序串）
 *
 * 包含算法: 4.1、4.2、4.3、4.5
 ==============================*/

#include "SString.h"    //**▲04 串**//

/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(SString T, const char* chars) {
    int i, len;
    
    len = (int) strlen(chars);
    
    // chars过长
    if(len > MAXSTRLEN) {
        return ERROR;
    }
    
    T[0] = len;
    for(i = 1; i <= len; i++) {
        T[i] = chars[i - 1];
    }
    
    return OK;
}
