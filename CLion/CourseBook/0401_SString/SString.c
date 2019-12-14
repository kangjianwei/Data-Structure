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
 * 销毁
 *
 * 将串S销毁。
 *
 *【注】
 * 顺序串的结构无法销毁
 */
Status DestroyString(SString S) {
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
 * ████████ 算法4.1 ████████
 *
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现需要依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index_1(SString S, SString T, int pos) {
    int i, n, m;       // 记录S和T的长度
    SString sub;
    
    /*
     * 失败情形提前处理
     * 这里与教材写法略微不同
     */
    if(pos < 1 || pos > S[0] || StrEmpty(T)) {
        return 0;
    }
    
    n = StrLength(S);
    m = StrLength(T);
    i = pos;
    
    // 保证长度不越界
    while(i <= n - m + 1) {
        // 获取S[i, i+m-1]
        SubString(sub, S, i, m);
        
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
 * ████████ 算法4.5 ████████
 *
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现不依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index_2(SString S, SString T, int pos) {
    int i = pos;
    int j = 1;
    
    if(pos < 1 || pos > S[0] || StrEmpty(T)) {
        return 0;
    }
    
    while(i <= S[0] && j <= T[0]) {
        // 遇到相同字符，则继续比较后继字符
        if(S[i] == T[j]) {
            i++;
            j++;
            
            // 遇到不同的字符，则游标需要回退，重新比较
        } else {
            i = i - (j - 1) + 1;    // j-1代表徒劳地前进了j-1个元素，在第j个元素上功亏一篑
            j = 1;                  // 游标j回到串T的第一个位置
        }
    }
    
    // 增加了一个T[0]>0的判断
    if(j > T[0] && T[0] > 0) {      // T不为空串
        return i - T[0];            // 匹配成功
    } else {
        return 0;
    }
}

/*
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(SString S, int pos, SString T) {
    int i;
    
    if(pos < 1 || pos > S[0] + 1 || S[0] + T[0] > MAXSTRLEN) {
        return ERROR;
    }
    
    // 如果待插入的串为空，则提前返回
    if(StrEmpty(T)) {
        return OK;
    }
    
    // 在S中腾出位置，为插入T做准备
    for(i = S[0]; i >= pos; i--) {
        // 从后向前遍历，将前面的元素挪到后面
        S[i + T[0]] = S[i];
    }
    
    // 将串T插入在S中腾出的位置上
    for(i = pos; i <= pos + T[0] - 1; i++) {
        S[i] = T[i - pos + 1];
    }
    
    // 长度增加
    S[0] += T[0];
    
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
 * 替换
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 1.该操作依赖最小操作子集
 * 2.该实现比较低效
 */
Status Replace(SString S, SString T, SString V) {
    int i;
    
    if(StrEmpty(S) || StrEmpty(T)) {
        return ERROR;
    }
    
    // 在主串S中寻找模式串T第一次出现的位置
    i = Index_2(S, T, 1);
    
    // 如果存在匹配的字符串，且可以被完全替换（替换后不溢出）
    while(i != 0 && S[0] - T[0] + V[0] <= MAXSTRLEN) {
        StrDelete(S, i, StrLength(T));  // 从S中删除T
        StrInsert(S, i, V);             // 向S中插入V
        
        i += StrLength(V);      // i切换到下一个位置
        
        i = Index_2(S, T, i);   // 查找下一个匹配的字符串
    }
    
    if(i == 0) {                // S中的T已全部被替换
        return OK;
    } else {                    // S中尚有T，但是V已经插不进去了
        return ERROR;
    }
}

/*
 * ████████ 算法4.2 ████████
 *
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(SString T, SString S1, SString S2) {
    int i;
    int uncut;  // 新串是否完整
    
    // 完全不需要裁剪
    if(S1[0] + S2[0] <= MAXSTRLEN) {
        // 复制S1到T中
        for(i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        
        // 复制S2到T中
        for(i = S1[0] + 1; i <= S1[0] + S2[0]; i++) {
            T[i] = S2[i - S1[0]];
        }
        
        // 设置新长度
        T[0] = S1[0] + S2[0];
        
        // 未裁剪，完整
        uncut = TRUE;
        
        // 需要裁剪S2
    } else if(S1[0] <= MAXSTRLEN) {
        // 复制S1到T中
        for(i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        
        // 将S2的一部分复制到T中
        for(i = S1[0] + 1; i <= MAXSTRLEN; i++) {
            T[i] = S2[i - S1[0]];
        }
        
        // 设置新长度
        T[0] = MAXSTRLEN;
        
        uncut = FALSE;
        
        // 只需要复制S1的一部分
    } else {
        // 连同长度信息一起复制
        for(i = 0; i <= MAXSTRLEN; i++) {
            T[i] = S1[i];
        }
        
        uncut = FALSE;
    }
    
    return uncut;
}
