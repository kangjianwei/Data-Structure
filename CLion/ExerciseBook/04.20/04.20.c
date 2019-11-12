#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//

/*
 * 删除S中包含的T
 */
Status Algo_4_20(SString S, SString T);


int main(int argc, char* argv[]) {
    char* s = "----***--*-**-****-*****-----";
    char* t = "**";
    SString T, S;
    
    printf("删除前...\n");
    StrAssign(S, s);
    StrAssign(T, t);
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("删除后...\n");
    printf("S = ");
    Algo_4_20(S, T);
    StrPrint(S);
    
    return 0;
}


/*
 * 删除S中包含的T
 */
Status Algo_4_20(SString S, SString T) {
    int i;
    
    // 在S中查找T，如果找到就删除
    while((i = Index_2(S, T, 1)) != 0) {
        if(StrDelete(S, i, StrLength(T)) == ERROR) {
            return ERROR;
        }
    }
    
    return OK;
}
