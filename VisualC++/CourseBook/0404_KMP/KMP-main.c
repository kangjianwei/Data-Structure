#include "KMP.h"                        //**��04 ��**//

// ���Ժ�������ӡ�ַ���
void PrintElem(SString S);

int main(int argc, char** argv) {
    char* s = "abaaabcaabaabcacabaabcaabaabcac";
    char* t = "abaabcac";
    SString S, T;
    int* next;      // ģʽ����next����ֵ
    int* nextval;   // ģʽ����nextval����ֵ
    int pos;        // ƥ�����
    int i, j;
    
    StrAssign(S, s);                    // ��ʼ������
    printf("S       = ");
    PrintElem(S);
    
    StrAssign(T, t);                    // ��ʼ��ģʽ��
    printf("T       = ");
    PrintElem(T);
    
    
    // ע��next�����nextval�����0�ŵ�Ԫ�����õģ���1�ŵ�Ԫ��ʼ�洢��Ч����
    next    = (int*) malloc((T[0] + 1) * sizeof(int));
    nextval = (int*) malloc((T[0] + 1) * sizeof(int));
    
    get_next(T, next);                  // �㷨4.7
    get_nextval(T, nextval);            // �㷨4.8�����㷨4.7�ĸĽ���
    
    printf("next    : ");
    for(i = 1; i <= T[0]; i++) {
        printf("%d", next[i]);
    }
    printf("\n");
    
    printf("nextval : ");
    for(i = 1; i <= T[0]; i++) {
        printf("%d", nextval[i]);
    }
    printf("\n");
    
    
    pos = 1;
    
    i = Index_KMP(S, T, pos, next);
    j = Index_KMP(S, T, pos, nextval);
    
    printf("��%d���ַ���T �� S �е�һ��ƥ��ɹ���λ��Ϊ %d\n", pos, i);
    printf("��%d���ַ���T �� S �е�һ��ƥ��ɹ���λ��Ϊ %d\n", pos, j);
    
    return 0;
}

// ���Ժ�������ӡ�ַ���
void PrintElem(SString S) {
    int i;
    
    for(i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }
    
    printf("\n");
}
