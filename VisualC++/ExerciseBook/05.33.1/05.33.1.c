#include <stdio.h>
#include "SString.h"    //**��04 ��**//
#include "GList-HT.h"   //**��05 ����͹����**//

/*
 * ��������������ԭ��������ڲ�Σ�ͷβ����洢��ʾ��
 */
void Algo_5_33_1(GList L, int d);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    Algo_5_33_1(L, 0);
    
    return 0;
}


/*
 * ��������������ԭ��������ڲ�Σ�ͷβ����洢��ʾ��
 */
void Algo_5_33_1(GList L, int d) {
    int i = d;  // d�ĳ�ֵ��ֵΪ0
    
    if(L == NULL) {
        return;
    }
    
    if(L->tag == Atom) {
        printf("%c -> ��%d��\n", L->Node.atom, i);
    }
    
    // ��ͷָ��ָ���Ļ�������һ
    if(L->tag == List) {
        Algo_5_33_1(L->Node.ptr.hp, i + 1);
        Algo_5_33_1(L->Node.ptr.tp, i);
    }
}
