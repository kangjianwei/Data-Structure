#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//
#include "GList-E.h"    //**��05 ����͹����**//

/*
 * ������ƣ���չ��������洢��ʾ��
 *
 *��ע��
 * �ú�������GList-E����ļ��ж���
 */
Status Algo_5_31(GList* T, GList L);


int main(int argc, char* argv[]) {
    GList L, T;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    printf("���ƹ���� L �� T...\n");
    Algo_5_31(&T, L);
    printf("T = ");
    PrintGraph(T);
    
    return 0;
}


/*
 * ������ƣ���չ��������洢��ʾ��
 *
 *��ע��
 * �ú�������GList-E����ļ��ж���
 */
Status Algo_5_31(GList* T, GList L) {
    return CopyGList(T, L);
}
