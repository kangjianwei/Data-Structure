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

/*
 * 清空
 *
 * 将串S清空。
 */
Status ClearString(SString S) {
    // 只需要将长度置为0就可以
    S[0] = 0;
    return OK;
}

/*
 * 判空
 *
 * 判断串S中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 串S为空
 * FALSE: 串S不为空
 */
Status StrEmpty(SString S) {
    return S[0] == 0 ? TRUE : FALSE;
}

/*
 * 计数
 *
 * 返回串S中元素的个数。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(SString S) {
    return S[0];
}

/*
 * ████████ 算法4.3 ████████
 *
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(SString Sub, SString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos > S[0] || len < 0 || pos + len - 1 > S[0]) {
        return ERROR;
    }
    
    // 复制元素
    for(i = 1; i <= len; i++) {
        Sub[i] = S[pos + i - 1];
    }
    
    // 确定新长度
    Sub[0] = len;
    
    return OK;
}

/*
 * 删除
 *
 * 删除S[pos, pos+len-1]。
 */
Status StrDelete(SString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos + len - 1 > S[0] || len < 0) {
        return ERROR;
    }
    
    // 如果待删除的长度为0，则提前返回
    if(len == 0) {
        return OK;
    }
    
    // 把后面的元素挪到前面，覆盖掉被删除的元素
    for(i = pos + len; i <= S[0]; i++) {
        S[i - len] = S[i];
    }
    
    // 长度减少
    S[0] -= len;
    
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
int StrCompare(SString S, SString T) {
    int i = 1;
    
    while(i <= S[0] && i <= T[0]) {
        // 遇到不同的字符时，比较其大小
        if(S[i] != T[i]) {
            return S[i] - T[i];
        }
        
        i++;
    }
    
    return S[0] - T[0];
}

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy(SString T, SString S) {
    int i;
    
    // 连同长度信息一起复制
    for(i = 0; i <= S[0]; i++) {
        T[i] = S[i];
    }
    
    return OK;
}

/*
 * 清理字符串S中的不可打印字符，【不清理】空格
 *
 *【注】
 * 该函数是在本章中新增的。
 */
Status ClearBlank(SString S) {
    int i, j;
    
    // 如果是空串
    if(S[0] == 0) {
        return ERROR;
    }
    
    for(i = 1, j = 0; i <= S[0]; i++) {
        // 如果遇到空白，则略过
        if(!isprint(S[i])) {
            continue;
        }
        
        j++;
        
        S[j] = S[i];
    }
    
    S[0] = j;
    
    return OK;
}
