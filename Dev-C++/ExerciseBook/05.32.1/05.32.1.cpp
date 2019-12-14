#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//
#include "GList-HT.h"   //**��05 ����͹����**//

/*
 * �жϹ�����Ƿ���ȣ�ͷβ����洢��ʾ��
 */
Status Algo_5_32_1(GList A, GList B);


int main(int argc, char* argv[]) {
    GList A, B;
    char* a = "((),(e),(a,(b,c,d)))";
    char* b = "((),(e),(a,(b,c,f)))";
    SString Sa, Sb;
    
    printf("��������� A��B ...\n");
    StrAssign(Sa, a);
    CreateGList(&A, Sa);
    StrAssign(Sb, b);
    CreateGList(&B, Sb);
    printf("A = ");
    PrintGraph(A);
    printf("B = ");
    PrintGraph(B);
    
    Algo_5_32_1(A, B) ? printf("���������ȣ�\n") : printf("���������ȣ���\n");
    
    return 0;
}


/*
 * �жϹ�����Ƿ���ȣ�ͷβ����洢��ʾ��
 */
Status Algo_5_32_1(GList A, GList B) {
    if(!A && !B) {
        return TRUE;  // �����ձ����
    }
    
    // ���������Ϊ��
    if(A && B) {
        // Ԫ��������ͬ
        if(A->tag == B->tag) {
            // ԭ�ӽ��
            if(A->tag == Atom) {
                if(A->Node.atom == B->Node.atom) {
                    return TRUE;
                }
                
                // ����
            } else {
                if(Algo_5_32_1(A->Node.ptr.hp, B->Node.ptr.hp) == TRUE) {
                    if(Algo_5_32_1(A->Node.ptr.tp, B->Node.ptr.tp) == TRUE) {
                        return TRUE;
                    }
                }
            }
        }
    }
    
    return FALSE;
}
