#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "HString.h"    //**▲04 串**//

/*
 * 联接：Concat
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_24(HString* T, HString S1, HString S2);

/*
 * 替换：Replace
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_25(HString* S, HString T, HString V);

/*
 * 插入：StrInsert
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_26(HString* S, int pos, HString T);


int main(int argc, char* argv[]) {
    char* s = "---*^***^*^*^*---";
    char* s1 = "*";
    char* s2 = "^*";
    char* v = "*_*";
    HString S1, S2, T, V, S;
    
    StrAssign(&S1, s1);
    StrAssign(&S2, s2);
    StrAssign(&V, v);
    StrAssign(&S, s);
    
    printf("S1 = ");
    StrPrint(S1);
    printf("S2 = ");
    StrPrint(S2);
    printf("V = ");
    StrPrint(V);
    printf("S = ");
    StrPrint(S);
    
    printf("███题 4.24 验证...███\n");
    printf("连接S1和S2为T...\n");
    Algo_4_24(&T, S1, S2);
    printf("T = ");
    StrPrint(T);
    
    printf("███题 4.25 验证...███\n");
    printf("用 V 替换 S 中的 T...\n");
    Algo_4_25(&S, T, V);
    printf("S = ");
    StrPrint(S);
    
    printf("███题 4.26 验证...███\n");
    printf("将 T 插入到 S 的第 2 个位置...\n");
    Algo_4_26(&S, 2, T);
    printf("S = ");
    StrPrint(S);
    
    return 0;
}


/*
 * 联接：Concat
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_24(HString* T, HString S1, HString S2) {
    return Concat(T, S1, S2);
}

/*
 * 替换：Replace
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_25(HString* S, HString T, HString V) {
    return Replace(S, T, V);
}

/*
 * 插入：StrInsert
 *
 *【注】
 * 该函数已在HString相关文件中定义
 */
Status Algo_4_26(HString* S, int pos, HString T) {
    return StrInsert(S, pos, T);
}
