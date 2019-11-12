#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "String.h"    //**字符串**//

/*
 * 替换：Replace
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串
 */
Status Algo_4_12(StringType* S, StringType T, StringType V) {
    int i;
    
    if(StrLength(*S) == 0 || StrLength(T) == 0) {
        return ERROR;
    }
    
    i = 1;
    
    // 在主串S中寻找模式串T第一次出现的位置
    while((i = Index(*S, T, i)) != 0) {
        StrDelete(S, i, StrLength(T));  // 从S中删除T
        StrInsert(S, i, V);             // 向S中插入V
        
        i += StrLength(V);  // i切换到下一个位置
    }
    
    return OK;
}


int main(int argc, char* argv[]) {
    char* s = "----***--*-**-****-*****-----";
    char* t = "**";
    char* v = "^^";
    StringType T, S, V;
    
    printf("替换前...\n");
    
    StrAssign(&S, s);
    StrAssign(&T, t);
    StrAssign(&V, v);
    
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    printf("V = ");
    StrPrint(V);
    
    printf("替换后...\n");
    printf("S = ");
    Algo_4_12(&S, T, V);
    StrPrint(S);
    
    return 0;
}
