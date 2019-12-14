#include <stdio.h>
#include "SString.h"    //**��04 ��**//

/*
 * �ڴ�S�в����״γ��ֵ���ظ��Ӵ�����λ��
 * Sub������¼�ظ��Ӵ�
 * pos������¼����S�г��ֵ�λ��
 *
 * �˴�����ظ��Ӵ������º��壺
 * 1.�Ӵ���������
 * 2.���Ӵ��������ظ��Ӵ������׸���������ģ�
 * 3.�Ӵ�������ص���������ȡabcabca�Ľ��Ϊabca��
 * 4.�Ӵ��ڿ����ظ�������ȡaaaa�Ľ��Ϊaaa��
 */
Status Algo_4_30(SString S, SString Sub, int* pos);


int main(int argc, char* argv[]) {
    char* s = "abcdeabcabcbcdefbcdefefghefgh";
    SString Sub, S;
    int pos;
    
    StrAssign(S, s);
    printf("����...\n");
    printf("S   = ");
    StrPrint(S);
    
    printf("�����׸�����ظ��Ӵ�...\n");
    printf("Sub = ");
    Algo_4_30(S, Sub, &pos);
    StrPrint(Sub);
    printf("Sub �� S ���״γ��ֵ�λ��Ϊ %d\n", pos);
    
    return 0;
}


/*
 * �ڴ�S�в����״γ��ֵ���ظ��Ӵ�����λ��
 * Sub������¼�ظ��Ӵ�
 * pos������¼����S�г��ֵ�λ��
 *
 * �˴�����ظ��Ӵ������º��壺
 * 1.�Ӵ���������
 * 2.���Ӵ��������ظ��Ӵ������׸���������ģ�
 * 3.�Ӵ�������ص���������ȡabcabca�Ľ��Ϊabca��
 * 4.�Ӵ��ڿ����ظ�������ȡaaaa�Ľ��Ϊaaa��
 */
Status Algo_4_30(SString S, SString Sub, int* pos) {
    int i, j, is, js;
    int k, start;
    int len, maxLen;
    
    // �������Ȳ�������2
    if(S[0] < 2) {
        return ERROR;
    }
    
    start = 0;
    maxLen = 0;
    
    // �������������п��ܵ����
    for(k = 1; k < S[0]; k++) {
        is = k;     // �������
        js = k + 1;   // �Ӵ����
        
        // ���ʣ����ַ�����������֪����ظ��ַ����������������ٱ�����ȥ
        if(S[0] - js + 1 <= maxLen) {
            break;
        }
        
        // ������isΪ���Ĵ��ظ��Ĵ�
        while(TRUE) {
            // Ѱ��Ǳ�ڵ��ظ��Ӵ����
            while(js <= S[0] && S[is] != S[js]) {
                js++;
            }
            
            // ˵��������㴦���ַ���Ψһ
            if(js > S[0]) {
                break;
            }
            
            // ���ʣ����ַ�����������֪����ظ��ַ����������������ٱ�����ȥ
            if(S[0] - js + 1 <= maxLen) {
                break;
            }
            
            len = 0;
            i = is;
            j = js;
            
            // �����ظ����ĳ���
            while(j <= S[0] && S[i] == S[j]) {
                i++;
                j++;
                len++;
            }
            
            if(len > maxLen) {
                start = k;
                maxLen = len;
            }
            
            // �鿴������û�и������ظ���
            if(j < S[0]) {
                js++;
            }
        }
    }
    
    *pos = start;
    SubString(Sub, S, start, maxLen);
    
    return OK;
}
