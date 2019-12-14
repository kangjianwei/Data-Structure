#include <stdio.h>
#include <stdlib.h>
#include "SString.h"    //**��04 ��**//

/*
 * R=S-S��T������a�洢R��ÿ���ַ���S�е�һ�γ��ֵ�λ��
 *
 * ע������a��0�ŵ�Ԫ�洢����a��Ԫ�صĸ���
 */
void Algo_4_19(SString R, SString S, SString T, int** a);


int main(int argc, char* argv[]) {
    char* s = "amdhcjgfdlpinbefcopgkqikeb";
    char* t = "mhjlpinopkqik";
    int* a;
    SString T, S, R;
    int i;
    
    printf("��ʼ��S��T...\n");
    StrAssign(S, s);
    StrAssign(T, t);
    
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    Algo_4_19(R, S, T, &a);
    printf("R = ");
    StrPrint(R);
    printf("a = ");
    for(i = 1; i <= a[0]; i++) {
        printf("%d ", a[i]);
    }
	printf("\n");
    
    return 0;
}


/*
 * R=S-S��T������a�洢R��ÿ���ַ���S�е�һ�γ��ֵ�λ��
 *
 * ע������a��0�ŵ�Ԫ�洢����a��Ԫ�صĸ���
 */
void Algo_4_19(SString R, SString S, SString T, int** a) {
    int i, p;
    SString ch;
    
    *a = (int*) malloc((StrLength(S) + 1) * sizeof(int));
    
    StrAssign(R, "");
    
    for(i = 1, (*a)[0] = 0; i <= StrLength(S); i++) {
        // ȡ���ַ������ж�
        SubString(ch, S, i, 1);
        
        // ��ȡS[i]��T�е�λ��
        p = Index_2(T, ch, 1);
        
        // ���S[i]����T��
        if(p == 0) {
            // ��ȡS[i]��R�е�λ��
            p = Index_2(R, ch, 1);
        }
        
        // ���S[i]�Ȳ���T�У���û��R�г��ֹ�
        if(p == 0) {
            (*a)[0]++;
            (*a)[(*a)[0]] = i;
            
            // ��R�����S[i]
            StrInsert(R, (*a)[0], ch);
        }
    }
}
