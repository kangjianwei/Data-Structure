#include <stdio.h>
#include "String.h"    //**�ַ���**//

/*
 * ɾ��S�а�����T
 */
Status Algo_4_13(StringType* S, StringType T) {
    int i;
    
    // ��S�в���T������ҵ���ɾ��
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
    
    printf("ɾ��ǰ...\n");
    StrAssign(&S, s);
    StrAssign(&T, t);
    
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("ɾ����...\n");
    printf("S = ");
    Algo_4_13(&S, T);
    StrPrint(S);
    
    return 0;
}
