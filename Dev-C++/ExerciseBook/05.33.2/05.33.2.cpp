#include <stdio.h>
#include "SString.h"    //**��04 ��**//
#include "GList-E.h"    //**��05 ����͹����**//

/*
 * ��������������ԭ��������ڲ�Σ���չ��������洢��ʾ��
 */
void Algo_5_33_2(GList L, int d);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    Algo_5_33_2(L, 0);
    
    return 0;
}


/*
 * ��������������ԭ��������ڲ�Σ���չ��������洢��ʾ��
 */
void Algo_5_33_2(GList L, int d) {
    int i = d;  // d��ֵ��Ϊ0
    
    if(L == NULL) {
        return;
    }
    
    if(L->tag == Atom) {
        printf("%c -> ��%d��\n", L->Node.atom, i);
    }
    
    
    if(L->tag == List) {
        Algo_5_33_2(L->Node.hp, i + 1); // ��ͷָ��ָ���Ļ�������һ
    }
    
    Algo_5_33_2(L->tp, i);
}
