#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//

/*
 * ɾ��S�а�����T
 */
Status Algo_4_20(SString S, SString T);


int main(int argc, char* argv[]) {
    char* s = "----***--*-**-****-*****-----";
    char* t = "**";
    SString T, S;
    
    printf("ɾ��ǰ...\n");
    StrAssign(S, s);
    StrAssign(T, t);
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("ɾ����...\n");
    printf("S = ");
    Algo_4_20(S, T);
    StrPrint(S);
    
    return 0;
}


/*
 * ɾ��S�а�����T
 */
Status Algo_4_20(SString S, SString T) {
    int i;
    
    // ��S�в���T������ҵ���ɾ��
    while((i = Index_2(S, T, 1)) != 0) {
        if(StrDelete(S, i, StrLength(T)) == ERROR) {
            return ERROR;
        }
    }
    
    return OK;
}
