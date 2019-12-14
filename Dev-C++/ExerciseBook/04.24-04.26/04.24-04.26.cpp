#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "HString.h"    //**��04 ��**//

/*
 * ���ӣ�Concat
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_24(HString* T, HString S1, HString S2);

/*
 * �滻��Replace
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_25(HString* S, HString T, HString V);

/*
 * ���룺StrInsert
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_26(HString* S, int pos, HString T);


int main(int argc, char* argv[]) {
    char* s = "---*^***^*^*^*---";
    char* s1 = "*";
    char* s2 = "^*";
    char* v = "*_*";
    HString S1, S2, T, V, S;
    
    StrAssign(&S1, s1);
    StrAssign(&S2, s2);
    StrAssign(&V, v);
    StrAssign(&S, s);
    
    printf("S1 = ");
    StrPrint(S1);
    printf("S2 = ");
    StrPrint(S2);
    printf("V = ");
    StrPrint(V);
    printf("S = ");
    StrPrint(S);
    
    printf("�������� 4.24 ��֤...������\n");
    printf("����S1��S2ΪT...\n");
    Algo_4_24(&T, S1, S2);
    printf("T = ");
    StrPrint(T);
    
    printf("�������� 4.25 ��֤...������\n");
    printf("�� V �滻 S �е� T...\n");
    Algo_4_25(&S, T, V);
    printf("S = ");
    StrPrint(S);
    
    printf("�������� 4.26 ��֤...������\n");
    printf("�� T ���뵽 S �ĵ� 2 ��λ��...\n");
    Algo_4_26(&S, 2, T);
    printf("S = ");
    StrPrint(S);
    
    return 0;
}


/*
 * ���ӣ�Concat
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_24(HString* T, HString S1, HString S2) {
    return Concat(T, S1, S2);
}

/*
 * �滻��Replace
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_25(HString* S, HString T, HString V) {
    return Replace(S, T, V);
}

/*
 * ���룺StrInsert
 *
 *��ע��
 * �ú�������HString����ļ��ж���
 */
Status Algo_4_26(HString* S, int pos, HString T) {
    return StrInsert(S, pos, T);
}
