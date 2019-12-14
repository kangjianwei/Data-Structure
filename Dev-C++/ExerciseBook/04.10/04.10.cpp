#include <stdio.h>
#include "String.h"    //**�ַ���**//

/*
 * �ַ������ã���T����ΪR��
 */
StringType Algo_4_10(StringType T) {
    int i;
    StringType R = "", Sub;
    
    // �Ӻ���ǰ��ȡ�ַ�
    for(i = StrLength(T); i >= 1; i--) {
        Sub = SubString(T, i, 1);
        R = Concat(R, Sub);
    }
    
    return R;
}


int main(int argc, char* argv[]) {
    char* s = "0123456789";
    StringType T, R;
    
    printf("����ǰ��T = ");
    StrAssign(&T, s);
    StrPrint(T);
    
    printf("���ú�R = ");
    R = Algo_4_10(T);
    StrPrint(R);
    
    return 0;
}

