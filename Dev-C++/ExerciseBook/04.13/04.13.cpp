#include <stdio.h>
#include "String.h"    //**字符串**//

/*
 * 删除S中包含的T
 */
Status Algo_4_13(StringType* S, StringType T) {
    int i;
    
    // 在S中查找T，如果找到就删除
    while((i = Index(*S, T, 1)) != 0) {
        if(StrDelete(S, i, StrLength(T)) == ERROR) {
            return ERROR;
        }
    }
    
    return OK;
}


int main(int argc, char* argv[]) {
    char* s = "----***--*-**-****-*****-----";
    char* t = "**";
    StringType T, S;
    
    printf("删除前...\n");
    StrAssign(&S, s);
    StrAssign(&T, t);
    
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("删除后...\n");
    printf("S = ");
    Algo_4_13(&S, T);
    StrPrint(S);
    
    return 0;
}
