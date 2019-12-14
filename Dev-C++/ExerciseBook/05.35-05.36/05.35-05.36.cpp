#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//
#include "GList.h"      //**��05 ����͹����**//

/*
 * ���������L�����ｫ"( )"����Ϊ�����Ϊ�յ�״̬��
 */
Status Algo_5_35(GList* L, SString S);

/*
 * ��������������L�����ｫ"( )"����Ϊ�����Ϊ�յ�״̬��
 */
void Algo_5_36(GList L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "(( ),(e),(a,(b,c,d)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    Algo_5_35(&L, S);
    
    printf("L = ");
    Algo_5_36(L);
    
    return 0;
}


/*
 * ���������L�����ｫ"( )"����Ϊ�����Ϊ�յ�״̬��
 */
Status Algo_5_35(GList* L, SString S) {
    return CreateGList(L, S);
}

/*
 * ��������������L�����ｫ"( )"����Ϊ�����Ϊ�յ�״̬��
 */
void Algo_5_36(GList L) {
    PrintGraph(L);
}
