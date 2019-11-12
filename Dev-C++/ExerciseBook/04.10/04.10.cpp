#include <stdio.h>
#include "String.h"    //**字符串**//

/*
 * 字符串逆置：将T逆置为R。
 */
StringType Algo_4_10(StringType T) {
    int i;
    StringType R = "", Sub;
    
    // 从后向前截取字符
    for(i = StrLength(T); i >= 1; i--) {
        Sub = SubString(T, i, 1);
        R = Concat(R, Sub);
    }
    
    return R;
}


int main(int argc, char* argv[]) {
    char* s = "0123456789";
    StringType T, R;
    
    printf("逆置前，T = ");
    StrAssign(&T, s);
    StrPrint(T);
    
    printf("逆置后，R = ");
    R = Algo_4_10(T);
    StrPrint(R);
    
    return 0;
}

