#include <stdio.h>
#include "LString.h"    //**��04 ��**//

/*
 * ��S���뵽T�е��ַ�c֮��
 * ����ж��c����S���뵽�������ұ���Tʱ�������׸�c֮��
 * ���T�ڲ�����c����S���뵽T��ĩβ��
 */
void Algo_4_22(LString* T, char ch, LString S);


int main(int argc, char* argv[]) {
    char* t = "----***--*-**-**^**-*****-----";
    char* s = "12345";
    char ch = '^';
    LString T, S;
    
    StrAssign(&T, t);
    StrAssign(&S, s);
    printf("T = ");
    StrPrint(T);
    printf("S = ");
    StrPrint(S);
    
    Algo_4_22(&T, ch, S);
    printf("T = ");
    StrPrint(T);
    
    return 0;
}


/*
 * ��S���뵽T�е��ַ�c֮��
 * ����ж��c����S���뵽�������ұ���Tʱ�������׸�c֮��
 * ���T�ڲ�����c����S���뵽T��ĩβ��
 */
void Algo_4_22(LString* T, char c, LString S) {
    int i;
    char tmp[2];
    LString Tmp;
    
    // ����Ŀ�괮
    tmp[0] = c;
    tmp[1] = '\0';
    StrAssign(&Tmp, tmp);
    
    // Ѱ���ַ�c��T�е�λ��
    i = Index((*T), Tmp, 1);
    
    // ����ҵ���c����S���뵽�ַ�c֮��
    if(i != 0) {
        StrInsert(T, i + 1, S);
        
        // ���û�ҵ�c����S���뵽T��ĩβ
    } else {
        StrInsert(T, (*T).curlen + 1, S);
    }
} 
