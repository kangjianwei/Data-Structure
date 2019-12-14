#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//

/*
 * 初始化：StrAssign
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_15(SString T, char* chars);

/*
 * 比较：StrCompare
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
int Algo_4_16(SString S, SString T);

/*
 * 替换：Replace
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_17(SString S, SString T, SString V);


int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("███题 4.15 验证...███\n");
    Algo_4_15(T, t);
    Algo_4_15(S, s);
    printf("T = ");
    StrPrint(T);
    printf("S = ");
    StrPrint(S);
    
    printf("███题 4.16 验证...███\n");
    i = Algo_4_16(S, T);
    if(i > 0) {
        printf("S > T\n");
    } else if(i < 0) {
        printf("S < T\n");
    } else {
        printf("S == T\n");
    }
    
    printf("███题 4.17 验证...███\n");
    Algo_4_15(M1, "**");
    Algo_4_15(M2, "^");
    Algo_4_17(S, M1, M2);
    printf("用 \"^\" 替换 \"**\" 后：\nS = ");
    StrPrint(S);
    
    return 0;
}

/*
 * 初始化：StrAssign
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_15(SString T, char* chars) {
    return StrAssign(T, chars);
}

/*
 * 比较：StrCompare
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
int Algo_4_16(SString S, SString T) {
    return StrCompare(S, T);
}

/*
 * 替换：Replace
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_17(SString S, SString T, SString V) {
    return Replace(S, T, V);
}
