/*================
 * 字符串操作工具类
 =================*/

#include "StringUtil.h"

/*
 * 删除
 *
 * 删除s[pos, pos+len-1]，pos从1开始计数。
 */
Status StrDelete(char** s, int pos, int n) {
    int len;
    char* ss;
    
    len = (int) strlen(*s);
    
    if(pos < 1 || pos + n - 1 > len || n < 0) {
        return ERROR;
    }
    
    // 如果待删除的长度为0，则提前返回
    if(n == 0) {
        return ERROR;
    }
    
    ss = (char*) malloc((len - n + 1) * sizeof(char));
    
    strncpy(ss, *s, pos - 1);
    strncpy(ss, *s + pos + n - 1, len - pos - n + 1);
    
    ss[len - n] = '\0';
    
    *s = ss;
    
    return OK;
}

/*
 * 求子串
 *
 * 用sub返回s[pos, pos+len-1]，pos从1开始计数。
 */
Status SubString(char** sub, char* s, int pos, int n) {
    int len, i;
    
    len = (int) strlen(s);
    
    if(pos < 1 || pos > len || n < 0 || pos + n - 1 > len) {
        *sub = NULL;
        return ERROR;
    }
    
    *sub = (char*) malloc((n + 1) * sizeof(char));
    
    for(i = 0; i < n; i++) {
        (*sub)[i] = s[pos + i - 1];
    }
    
    // 确定新长度
    (*sub)[n] = '\0';
    
    return OK;
}

/*
 * 判空
 *
 * 判断串s中是否包含有效数据。
 */
Status StrEmpty(char* s) {
    return strlen(s) == 0 ? TRUE : FALSE;
}

/*
 * 整理
 *
 * 清理字符串s中的空白，包括清理不可打印字符和清理空格。
 */
Status ClearBlank(char** s) {
    int len;
    int i, j;
    char* ss;
    
    len = (int) strlen(*s);
    if(len == 0) {
        return ERROR;
    }
    
    ss = (char*) malloc((len + 1) * sizeof(char));
    
    for(i = 0, j = 0; i < len; i++) {
        // 如果遇到空白，则略过
        if((*s)[i] == ' ' || !isprint((*s)[i])) {
            continue;
        }
        
        ss[j++] = (*s)[i];
    }
    
    ss[j] = '\0';
    
    *s = ss;
    
    return OK;
}

/*
 * 计数
 *
 * 统计字符串s中的元素个数。
 * 这里的特殊之处在于：对于数字，会将其当成一个元素。
 */
int ElemCount(const char* s) {
    int count;
    float f;
    char c;
    char* sub;
    
    if(s==NULL || strlen(s) == 0) {
        return 0;
    }
    
    sub = (char*) malloc((strlen(s) + 1) * sizeof(char));
    sub[0] = '\0';
    
    // 如果遇到了数字
    if(sscanf(s, "%f", &f) == 1) {
        sscanf(s, "%f%s", &f, sub);
    } else {
        sscanf(s, "%c%s", &c, sub);
    }
    
    count = ElemCount(sub);
    
    return 1 + count;
}

/*
 * 取值
 *
 * 获取字符串s中第pos个元素(pos从1开始计数)，并用f接收。
 * 这里的特殊之处在于：对于数字，会将其当成一个元素。
 */
Status GetElem(char* s, int pos, float* f) {
    int len;
    
    len = (int) strlen(s);
    
    if(pos < 1 || pos > len) {
        return ERROR;
    }
    
    // 先尝试读数字，读取失败的话，再尝试读字符
    if(sscanf(s + pos - 1, "%f", f) < 1) {
        *f = s[pos - 1];
    }
    
    return OK;
}
