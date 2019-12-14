#include <stdio.h>
#include "Status.h"    //**��01 ����**//
#include "String.h"    //**�ַ���**//

/*
 * �滻��Replace
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ�
 */
Status Algo_4_12(StringType* S, StringType T, StringType V) {
    int i;
    
    if(StrLength(*S) == 0 || StrLength(T) == 0) {
        return ERROR;
    }
    
    i = 1;
    
    // ������S��Ѱ��ģʽ��T��һ�γ��ֵ�λ��
    while((i = Index(*S, T, i)) != 0) {
        StrDelete(S, i, StrLength(T));  // ��S��ɾ��T
        StrInsert(S, i, V);             // ��S�в���V
        
        i += StrLength(V);  // i�л�����һ��λ��
    }
    
    return OK;
}


int main(int argc, char* argv[]) {
    char* s = "----***--*-**-****-*****-----";
    char* t = "**";
    char* v = "^^";
    StringType T, S, V;
    
    printf("�滻ǰ...\n");
    
    StrAssign(&S, s);
    StrAssign(&T, t);
    StrAssign(&V, v);
    
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    printf("V = ");
    StrPrint(V);
    
    printf("�滻��...\n");
    printf("S = ");
    Algo_4_12(&S, T, V);
    StrPrint(S);
    
    return 0;
}
