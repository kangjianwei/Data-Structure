#include <stdio.h>
#include <stdlib.h>
#include "SString.h"    //**��04 ��**//

/*
 * ͳ���ַ���S�в�ͬ�ַ�������ÿ���ַ��ĸ���������ͳ�ƽ��
 */
int* Algo_4_18(SString S);


int main(int argc, char* argv[]) {
    char* s = "dbasydujhge638940[gptokljrsehgadcsbnmv,c.b'ng[p098437eywdghswqdecxvghju";
    SString S;
    int* total;
    int i;
    
    StrAssign(S, s);
    printf("S = ");
    StrPrint(S);
    
    total = Algo_4_18(S);
    printf(" S �в�ͬ���ַ����� %d ����\n", total[0]);
    for(i = 1; i <= 127; i++) {
        if(total[i] != 0) {
            printf("�ַ� \'%c\' �� %d ��.\n", i, total[i]);
        }
    }
    printf("ͳ�����...\n");
    
    return 0;
}


/*
 * ͳ���ַ���S�в�ͬ�ַ�������ÿ���ַ��ĸ���������ͳ�ƽ��
 */
int* Algo_4_18(SString S) {
    int i;
    int* total;
    
    /*
     * total������Ϊ128��
     * 0�ŵ�Ԫ�洢��ͬ�ַ���������
     * ������Ԫ�洢���ֲ�ͬ�ַ���������
     *
     * ע����ͳ�ƿ��ַ�'\0'
     */
    total = (int*) malloc(128 * sizeof(int));
    memset(total, 0, 128 * sizeof(int));
    
    for(i = 1; i <= S[0]; i++) {
        // ������������ַ�����ͳ�Ʋ�ͬ�ַ�������
        if(total[S[i]] == 0) {
            total[0]++;
        }
        
        // ͳ���������ַ�����
        total[S[i]]++;
    }
    
    return total;
}
