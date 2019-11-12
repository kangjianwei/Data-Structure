#include <stdio.h>
#include "SString.h"    //**▲04 串**//

/* 函数原型 */
int Algo_4_27(SString S, SString T, int pos);


/*
 * 查找：Index
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 相比与传统的Index函数，其改进之处在于会先比较首个字符与末尾字符，
 * 当它们都匹配时，才会继续比较剩下的字符
 */
int main(int argc, char* argv[]) {
    char* s = "aaaaaaaaaaaaaaab";
    char* t = "aaaab";
    SString S, T;
    
    StrAssign(S, s);
    StrAssign(T, t);
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("T在S中首次出现的位置为：");
    printf("%d\n", Algo_4_27(S, T, 1));
    
    return 0;
}


/*
 * 查找：Index
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 相比与传统的Index函数，其改进之处在于会先比较首个字符与末尾字符，
 * 当它们都匹配时，才会继续比较剩下的字符
 */
int Algo_4_27(SString S, SString T, int pos) {
    int i, j;
    
    if(pos < 1 || pos > S[0] || T[0] == 0) {
        return 0;
    }
    
    i = pos;
    j = 1;
    
    while(i <= S[0] - T[0] + 1) {
        // 先尝试比较首个字符与末尾字符
        if(S[i] != T[j] || S[i + T[0] - 1] != T[T[0]]) {
            i++;
            continue;
        }
        
        // 这里的j不需要等于T[0]，因为T[0]这种情形已经验证了
        for(i++,j++; j<T[0] && S[i]==T[j]; i++,j++) {
            // 查找失配位置
        }
    
        // 找到了匹配的字符串
        if(j==T[0]) {
            return i-j+1;
            
            // 如果没找到，游标回退，重新比较
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    
    return 0;
}
