#include <stdio.h>
#include <stdlib.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//

/*
 * ████ 提示 ████
 *
 * 本问题是一个动态规划问题，详细思路参见《算法导论》第三版第15.4节。
 *
 * 注：《算法导论》中的"最长公共子序列"问题会统计不连续的子串，但是本题只会统计连续的子串。
 */


/* 最长公共子串密码表 */
typedef struct {
    char dir;
    int len;
} LCS;

/* 子串坐标 */
typedef struct {
    int s;  // 该子串在串S中的位置
    int t;  // 该子串在串T中的位置
} Pos;

/* 最长公共子串集合 */
typedef struct {
    int maxlen;     // 最长公共子串的长度
    Pos* pos;       // 所有最长公共子串的坐标
    int count;      // 最长公共子串的数量
} Strs;


/*
 * 计算S和T中的最长公共子串。
 *
 * 其中，坐标最靠左的被称为"第一个出现的最长公共子串"。
 */
Status Algo_4_31(SString S, SString T);

/*
 * 获取最长公共子串的坐标信息
 */
void LocationPos(SString S, SString T, Strs* strs);

/*
 * 建立最长公共子串密码表，并获取最长公共子串的长度。
 */
Status BuildLCS(SString S, SString T, LCS*** lcs, int* maxLen);

/*
 * 打印最长公共子串密码表（可选操作）。
 */
void PrintLCS(SString S, SString T, LCS** lcs);


int main(int argc, char* argv[]) {
    char* s = "csajcu123456ewjfskhsdufasawx";
    char* t = "m123456vsadksjewjfshcdsdufassgcx";
    SString S, T;
    
    StrAssign(S, s);
    StrAssign(T, t);
    
    Algo_4_31(S, T);
    
    return 0;
}


/*
 * 计算S和T中的最长公共子串。
 *
 * 其中，坐标最靠左的被称为"第一个出现的最长公共子串"。
 */
Status Algo_4_31(SString S, SString T) {
    Strs strs;
    SString sub;
    int i;
    
    LocationPos(S, T, &strs);
    
    printf("最长公共子串的长度为：%d \n", strs.maxlen);
    printf("输出所有最长公共子串及其坐标：\n");
    for(i=0; i<strs.count; i++) {
        printf("(s=%3d t=%3d) ", strs.pos[i].s, strs.pos[i].t);
        
        if(SubString(sub, S, strs.pos[i].s, strs.maxlen)==OK) {
            StrPrint(sub);
        }
    }
    
    return OK;
}

/*
 * 获取最长公共子串的坐标信息
 */
void LocationPos(SString S, SString T, Strs* strs) {
    LCS** lcs;
    int sLen, tLen;
    int maxLen;
    int i, j;
    int size;
    
    BuildLCS(S, T, &lcs, &maxLen);
    PrintLCS(S, T, lcs);
    
    (*strs).maxlen = maxLen;
    (*strs).count = 0;
    size = 10;
    (*strs).pos = (Pos*) malloc(size * sizeof(Pos));
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    for(i=1; i<=sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            if(lcs[i][j].len!=maxLen || lcs[i][j].dir!='\\') {
                continue;
            }
            
            if((*strs).count>=size) {
                size += 10;
                (*strs).pos = (Pos*) realloc((*strs).pos, size * sizeof(Pos));
            }
            
            (*strs).pos[(*strs).count].s = i-maxLen+1;
            (*strs).pos[(*strs).count].t = j-maxLen+1;
            (*strs).count++;
        }
    }
}

/*
 * 建立最长公共子串密码表，并获取最长公共子串的长度。
 */
Status BuildLCS(SString S, SString T, LCS*** lcs, int* maxLen) {
    int sLen, tLen;
    int i, j;
    int max;
    LCS node;
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    if(sLen == 0 || tLen == 0) {
        return ERROR;
    }
    
    // 初始化LCS表格
    *lcs = (LCS**) malloc((sLen + 1) * sizeof(LCS*));
    for(i = 0; i <= sLen; i++) {
        (*lcs)[i] = (LCS*) malloc((tLen + 1) * sizeof(LCS));
    }
    
    for(i = 0; i <= sLen; i++) {
        (*lcs)[i][0].dir = ' ';
        (*lcs)[i][0].len = 0;
    }
    
    for(j = 0; j <= tLen; j++) {
        (*lcs)[0][j].dir = ' ';
        (*lcs)[0][j].len = 0;
    }
    
    max = 0;
    
    for(i = 1; i <= sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            // 此种情形与《算法导论》中的解析略微不同，此处需要统计连续的子串
            if(S[i] == T[j]) {
                // 如果前一个字符也相等，说明这是个连续的公共子串
                if(i > 1 && j > 1 && S[i - 1] == T[j - 1]) {
                    node.dir = '\\';
                    node.len = (*lcs)[i - 1][j - 1].len + 1;
                    
                    // 断开了
                } else {
                    node.dir = ' ';
                    node.len = 1;
                }
                
                if(node.len > max) {
                    max = node.len;
                }
            } else {
                if((*lcs)[i - 1][j].len >= (*lcs)[i][j - 1].dir) {
                    node.dir = '^';
                    node.len = (*lcs)[i - 1][j].len;
                } else {
                    node.dir = '<';
                    node.len = (*lcs)[i][j - 1].len;
                }
            }
            
            (*lcs)[i][j] = node;
        }
    }
    
    *maxLen = max;
    
    return ERROR;
}

/*
 * 打印最长公共子串密码表（可选操作）。
 */
void PrintLCS(SString S, SString T, LCS** lcs) {
    int sLen, tLen;
    int i, j;
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    if(sLen == 0 || tLen == 0) {
        return;
    }
    
    // 第一行
    printf("   ");
    for(j = 1; j <= tLen; j++) {
        printf(" %c  ", T[j]);
    }
    printf("\n");
    
    // 第二行
    printf("   ");
    for(j = 1; j <= tLen; j++) {
        printf("--- ");
    }
    printf("\n");
    
    for(i = 1; i <= sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            // 每一行的开始
            if(j == 1) {
                printf("%c |", S[i]);
            }
            
            printf("%c%2d ", lcs[i][j].dir, lcs[i][j].len);
        }
        printf("\n");
    }
    
    printf("\n");
}
