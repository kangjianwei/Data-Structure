/*===========================
 * 习题4.10~4.14中使用的字符串
 ============================*/

#include "String.h"

// 初始化：构造一个值为s的串t
void StrAssign(StringType* t, const char* s) {
    if(s == NULL) {
        *t = "";
    }
    
    *t = (char*) malloc((strlen(s) + 1) * sizeof(char));
    
    strcpy(*t, s);
}

// 比较：返回s与t的大小，如果大小一致，返回0
int StrCompare(StringType s, StringType t) {
    return strcmp(s, t);
}

// 计数：返回字符串s的长度
int StrLength(StringType s) {
    return (int) strlen(s);
}

// 联接：返回由s与t联接后的串
StringType Concat(StringType s, StringType t) {
    StringType r;
    
    if(s == NULL) {
        s = "";
    }
    
    if(t == NULL) {
        t = "";
    }
    
    r = (char*) malloc((strlen(s) + strlen(t) + 1) * sizeof(char));
    r[0] = '\0';
    
    strcat(r, s);
    strcat(r, t);
    
    return r;
}

// 求子串：从s的start位置起，截取len个字符后返回
StringType SubString(StringType s, int start, int len) {
    int n;
    char* sub;
    
    n = (int) strlen(s);
    
    if(start < 1 || start > n || start + len - 1 > n || len < 0) {
        return "";
    }
    
    sub = (char*) malloc((len + 1) * sizeof(char));
    strncpy(sub, s + start - 1, len);
    sub[len] = '\0';
    
    return sub;
}

// 查找：从s的pos位置起查找t，如果找到，返回其位置
int Index(StringType s, StringType t, int pos) {
    int m, n, i;
    StringType sub;
    
    // 失败情形提前处理
    if(pos < 1 || pos > StrLength(s) || StrLength(t) == 0) {
        return 0;
    }
    
    n = StrLength(s);
    m = StrLength(t);
    i = pos;
    
    // 保证长度不越界
    while(i <= n - m + 1) {
        // 获取S[i, i+m-1]
        sub = SubString(s, i, m);
        
        // 如果子串与模式串不匹配，则需要继续推进
        if(StrCompare(sub, t) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    
    return 0;
}

// 插入：在s的pos处插入t
Status StrInsert(StringType* s, int pos, StringType t) {
    StringType r;
    StringType s1, s2;
    
    if(pos < 1 || pos > StrLength(*s) + 1) {
        return ERROR;
    }
    
    r = (StringType) malloc((strlen(*s) + strlen(t) + 1) * sizeof(char));
    r[0] = '\0';
    
    // 如果待插入的串为空，则提前返回
    if(StrLength(t) == 0) {
        return OK;
    }
    
    s1 = SubString(*s, 1, pos - 1);
    s2 = SubString(*s, pos, (int) strlen(*s) - pos + 1);
    
    strcat(r, s1);
    strcat(r, t);
    strcat(r, s2);
    
    *s = r;
    
    return OK;
}

// 删除：从s的pos位置起，删除len个字符
Status StrDelete(StringType* s, int pos, int len) {
    StringType r;
    
    if(pos < 1 || pos + len - 1 > StrLength(*s) || len < 0) {
        return ERROR;
    }
    
    // 如果待删除的长度为0，则提前返回
    if(len == 0) {
        return OK;
    }
    
    r = (StringType) malloc((StrLength(*s) - len + 1) * sizeof(char));
    strncpy(r, *s, pos - 1);
    strcpy(r + pos - 1, *s + pos + len - 1);
    
    *s = r;
    
    return OK;
}

// 输出字符串
void StrPrint(StringType s) {
    printf("%s\n", s);
}
