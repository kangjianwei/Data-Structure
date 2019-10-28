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
 * 销毁
 *
 * 将串S销毁。
 *
 *【注】
 * 堆串的结构可以销毁，但不是在销毁操作中
 */
Status DestroyString(HString* S) {
    return OK;
}

/*
 * 清空
 *
 * 将串S清空。
 */
Status ClearString(HString* S) {
    // 没有有效元素时，销毁堆串结构
    if((*S).ch != 0) {
        free((*S).ch);
        (*S).ch = NULL;
    }
    
    (*S).length = 0;
    
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
Status StrEmpty(HString S) {
    return S.length == 0 ? TRUE : FALSE;
}

/*
 * 计数
 *
 * 返回串S中元素的个数。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(HString S) {
    return S.length;
}

/*
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(HString* Sub, HString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length) {
        return ERROR;
    }
    
    // 如果是截取0个字符，不需要分配空间
    if(len == 0) {
        (*Sub).ch = NULL;
        (*Sub).length = 0;
    
        return OK;
    }
    
    (*Sub).ch = (char*) malloc(len * sizeof(char));
    if(!(*Sub).ch) {
        exit(OVERFLOW);
    }
    
    // 复制元素
    for(i = 0; i < len; i++) {
        (*Sub).ch[i] = S.ch[i + pos - 1];
    }
    
    // 确定新长度
    (*Sub).length = len;
    
    return OK;
}

/*
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现需要依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index(HString S, HString T, int pos) {
    int i, s, t;
    HString sub;
    
    if(pos < 1 || pos > S.length || StrEmpty(T)) {
        return 0;
    }
    
    s = S.length;
    t = T.length;
    i = pos;
    
    // 保证长度不越界
    while(i + t - 1 <= s) {
        // 获取S[i, i+t-1]
        SubString(&sub, S, i, t);
        
        // 如果子串与模式串不匹配，则需要继续推进
        if(StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    
    return 0;
}

/*
 * ████████ 算法4.4 ████████
 *
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(HString* S, int pos, HString T) {
    int i;
    
    if(pos < 1 || pos > (*S).length + 1) {
        return ERROR;
    }
    
    // 如果待插入的串为空，则提前返回
    if(StrEmpty(T)) {
        return OK;
    }
    
    // 分配新空间，会将旧元素一起复制过去
    (*S).ch = (char*) realloc((*S).ch, ((*S).length + T.length) * sizeof(char));
    if(!(*S).ch) {
        exit(OVERFLOW);
    }
    
    // 在S中腾出位置，为插入T做准备
    for(i = (*S).length - 1; i >= pos - 1; i--) {
        // 从后向前遍历，将前面的元素挪到后面
        (*S).ch[i + T.length] = (*S).ch[i];
    }
    
    // 将串T插入在S中腾出的位置上
    for(i = pos - 1; i <= pos + T.length - 2; i++) {
        (*S).ch[i] = T.ch[i - pos + 1];
    }
    
    // 长度增加
    (*S).length += T.length;
    
    return OK;
}

/*
 * 删除
 *
 * 删除S[pos, pos+len-1]。
 */
Status StrDelete(HString* S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos + len - 1 > (*S).length || len < 0) {
        return ERROR;
    }
    
    // 如果待删除的长度为0，则提前返回
    if(len == 0) {
        return OK;
    }
    
    // 把后面的元素挪到前面，覆盖掉被删除的元素
    for(i = pos + len - 1; i <= (*S).length - 1; i++) {
        (*S).ch[i - len] = (*S).ch[i];
    }
    
    // 长度减少
    (*S).length -= len;
    
    // 缩减分配的空间（如果长度减少为0，这里会返回空指针）
    (*S).ch = (char*) realloc((*S).ch, (*S).length * sizeof(char));
    
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
    
    if(StrEmpty(S)) {
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

/*
 * 替换
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 1.该操作依赖最小操作子集
 * 2.该实现比较低效
 */
Status Replace(HString* S, HString T, HString V) {
    int i;
    
    if(StrEmpty(*S) || StrEmpty(T)) {
        return ERROR;
    }
    
    // 在主串S中寻找模式串T第一次出现的位置
    i = Index(*S, T, 1);
    
    // 如果存在匹配的字符串
    while(i != 0) {
        StrDelete(S, i, StrLength(T));  // 从S中删除T
        StrInsert(S, i, V);             // 向S中插入V
        
        i += StrLength(V);          // i切换到下一个位置
        
        i = Index(*S, T, i);        // 查找下一个匹配的字符串
    }
    
    return OK;
}

/*
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 * 堆串的空间被认为是无限的，因此这里总是返回TRUE，指示串不会被裁剪。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(HString* T, HString S1, HString S2) {
    int i;
    
    // 确定新长度
    (*T).length = S1.length + S2.length;
    
    // 分配空间
    (*T).ch = (char*) malloc((*T).length * sizeof(char));
    if(!(*T).ch) {
        exit(OVERFLOW);
    }
    
    // 先把S1的内容拷贝出来
    for(i = 0; i < S1.length; i++) {
        (*T).ch[i] = S1.ch[i];
    }
    
    // 再拷贝S2的内容
    for(i = 0; i < S2.length; i++) {
        (*T).ch[S1.length + i] = S2.ch[i];
    }
    
    return TRUE;
}
