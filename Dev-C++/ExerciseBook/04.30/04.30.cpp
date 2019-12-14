#include <stdio.h>
#include "SString.h"    //**▲04 串**//

/*
 * 在串S中查找首次出现的最长重复子串及其位置
 * Sub用来记录重复子串
 * pos用来记录其在S中出现的位置
 *
 * 此处的最长重复子串有以下含义：
 * 1.子串必须连续
 * 2.此子串在所有重复子串中是首个出现且最长的；
 * 3.子串间可以重叠，比如求取abcabca的结果为abca；
 * 4.子串内可以重复，如求取aaaa的结果为aaa。
 */
Status Algo_4_30(SString S, SString Sub, int* pos);


int main(int argc, char* argv[]) {
    char* s = "abcdeabcabcbcdefbcdefefghefgh";
    SString Sub, S;
    int pos;
    
    StrAssign(S, s);
    printf("主串...\n");
    printf("S   = ");
    StrPrint(S);
    
    printf("计算首个最长不重复子串...\n");
    printf("Sub = ");
    Algo_4_30(S, Sub, &pos);
    StrPrint(Sub);
    printf("Sub 在 S 中首次出现的位置为 %d\n", pos);
    
    return 0;
}


/*
 * 在串S中查找首次出现的最长重复子串及其位置
 * Sub用来记录重复子串
 * pos用来记录其在S中出现的位置
 *
 * 此处的最长重复子串有以下含义：
 * 1.子串必须连续
 * 2.此子串在所有重复子串中是首个出现且最长的；
 * 3.子串间可以重叠，比如求取abcabca的结果为abca；
 * 4.子串内可以重复，如求取aaaa的结果为aaa。
 */
Status Algo_4_30(SString S, SString Sub, int* pos) {
    int i, j, is, js;
    int k, start;
    int len, maxLen;
    
    // 主串长度不能少于2
    if(S[0] < 2) {
        return ERROR;
    }
    
    start = 0;
    maxLen = 0;
    
    // 遍历主串上所有可能的起点
    for(k = 1; k < S[0]; k++) {
        is = k;     // 主串起点
        js = k + 1;   // 子串起点
        
        // 如果剩余的字符数量不比已知的最长重复字符串更长，则无需再遍历下去
        if(S[0] - js + 1 <= maxLen) {
            break;
        }
        
        // 查找与is为起点的串重复的串
        while(TRUE) {
            // 寻找潜在的重复子串起点
            while(js <= S[0] && S[is] != S[js]) {
                js++;
            }
            
            // 说明主串起点处的字符串唯一
            if(js > S[0]) {
                break;
            }
            
            // 如果剩余的字符数量不比已知的最长重复字符串更长，则无需再遍历下去
            if(S[0] - js + 1 <= maxLen) {
                break;
            }
            
            len = 0;
            i = is;
            j = js;
            
            // 计算重复串的长度
            while(j <= S[0] && S[i] == S[j]) {
                i++;
                j++;
                len++;
            }
            
            if(len > maxLen) {
                start = k;
                maxLen = len;
            }
            
            // 查看后面有没有更长的重复串
            if(j < S[0]) {
                js++;
            }
        }
    }
    
    *pos = start;
    SubString(Sub, S, start, maxLen);
    
    return OK;
}
