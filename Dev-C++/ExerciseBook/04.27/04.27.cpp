#include <stdio.h>
#include "SString.h"    //**��04 ��**//

/* ����ԭ�� */
int Algo_4_27(SString S, SString T, int pos);


/*
 * ���ң�Index
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * ����봫ͳ��Index��������Ľ�֮�����ڻ��ȱȽ��׸��ַ���ĩβ�ַ���
 * �����Ƕ�ƥ��ʱ���Ż�����Ƚ�ʣ�µ��ַ�
 */
int main(int argc, char* argv[]) {
    char* s = "aaaaaaaaaaaaaaab";
    char* t = "aaaab";
    SString S, T;
    
    StrAssign(S, s);
    StrAssign(T, t);
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    printf("T��S���״γ��ֵ�λ��Ϊ��");
    printf("%d\n", Algo_4_27(S, T, 1));
    
    return 0;
}


/*
 * ���ң�Index
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * ����봫ͳ��Index��������Ľ�֮�����ڻ��ȱȽ��׸��ַ���ĩβ�ַ���
 * �����Ƕ�ƥ��ʱ���Ż�����Ƚ�ʣ�µ��ַ�
 */
int Algo_4_27(SString S, SString T, int pos) {
    int i, j;
    
    if(pos < 1 || pos > S[0] || T[0] == 0) {
        return 0;
    }
    
    i = pos;
    j = 1;
    
    while(i <= S[0] - T[0] + 1) {
        // �ȳ��ԱȽ��׸��ַ���ĩβ�ַ�
        if(S[i] != T[j] || S[i + T[0] - 1] != T[T[0]]) {
            i++;
            continue;
        }
        
        // �����j����Ҫ����T[0]����ΪT[0]���������Ѿ���֤��
        for(i++,j++; j<T[0] && S[i]==T[j]; i++,j++) {
            // ����ʧ��λ��
        }
    
        // �ҵ���ƥ����ַ���
        if(j==T[0]) {
            return i-j+1;
            
            // ���û�ҵ����α���ˣ����±Ƚ�
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    
    return 0;
}
