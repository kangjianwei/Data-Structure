#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "SString.h"    //**��04 ��**//
#include "GList-E.h"    //**��05 ����͹����**//

/*
 * ɾ���������ֵΪx��ԭ�����չ��������洢��ʾ��
 */
void Algo_5_37_2(GList* L, AtomType x);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((b),(e),(a,(b,c,d)),(b,((b),b)),x,b,(y))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    printf("ɾ�� L �е�Ԫ�� 'b' ...\n");
    Algo_5_37_2(&L, 'b');
    printf("L = ");
    PrintGraph(L);
    
    return 0;
}


/*
 * ɾ���������ֵΪx��ԭ�����չ��������洢��ʾ��
 */
void Algo_5_37_2(GList* L, AtomType x) {
    GList p;
    
    if(L == NULL || *L == NULL) {
        return;
    }
    
    if((*L)->tag == List) {
        Algo_5_37_2(&((*L)->Node.hp), x);
        Algo_5_37_2(&((*L)->tp), x);
    } else {
        if((*L)->Node.atom == x) {
            p = *L;
            *L = (*L)->tp;
            free(p);
            
            Algo_5_37_2(L, x);
        } else {
            Algo_5_37_2(&((*L)->tp), x);
        }
    }
}
