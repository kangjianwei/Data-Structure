#include <stdio.h>
#include "SString.h"    //**��04 ��**//
#include "GList-E.h"    //**��05 ����͹����**//

// ��������ȣ���չ��������洢��ʾ��
int Algo_5_30_2(GList L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    printf("��������Ϊ�� %d\n", Algo_5_30_2(L));
    
    return 0;
}


// ��������ȣ���չ��������洢��ʾ��
int Algo_5_30_2(GList L) {
    int m, n;
    
    if(L==NULL) {
        return 1;   // �ձ����Ϊ1
    }
    
    if(L->tag == Atom) {
        return 0;   // ԭ�����Ϊ0
    }
    
    m = Algo_5_30_2(L->Node.hp) + 1;
    n = Algo_5_30_2(L->tp);
    
    return m > n ? m : n;
}
