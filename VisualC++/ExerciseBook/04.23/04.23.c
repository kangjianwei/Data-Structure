#include <stdio.h>
#include "LString.h"    //**��04 ��**//

/*
 * �жϸ����Ĵ��Ƿ�Գơ�
 * �մ����ַ��Ĵ��ᱻ��Ϊ�ǶԳƵġ�
 */
Status Algo_4_23(LString T);


int main(int argc, char* argv[]) {
    char* t = "abcdefgfedcba";
    LString T;
    
    StrAssign(&T, t);
    printf("T = ");
    StrPrint(T);
    
    Algo_4_23(T) ? printf("T�ǶԳƴ���\n") : printf("T�ǷǶԳƴ�����\n");
    
    return 0;
}


/*
 * �жϸ����Ĵ��Ƿ�Գơ�
 * �մ����ַ��Ĵ��ᱻ��Ϊ�ǶԳƵġ�
 */
Status Algo_4_23(LString T) {
    int len;    // T�ĳ���
    
    int a1, b1; // T��ǰ�벿�ֱ߽�
    int a2, b2; // T�ĺ�벿�ֱ߽�
    int k;      // ���Ʊ���Tʱ��Ҫ������Ԫ������
    int i;      // ����Tʱ���α�
    Chunk* t;
    
    char* stack;    // ģ��ջ
    int top;        // ջ�α�
    
    char c;         // ��T��ȡ�����ַ�
    
    len = StrLength(T);
    
    // �մ�����Ϊ�ǶԳƵ�
    if(len == 0) {
        return OK;
    }
    
    // ������ĳ�����ż��
    if(len % 2 == 0) {
        a1 = 0;
        b1 = len / 2 - 1;
        a2 = len / 2;
        b2 = len - 1;
        // ������ĳ���������
    } else {
        a1 = 0;
        b1 = len / 2 - 1;
        a2 = len / 2 + 1;
        b2 = len - 1;
    }
    
    stack = (char*) malloc(len * sizeof(char));
    top = -1;
    
    i = 0;
    t = T.head;
    
    // ���ڴ���ǰ�벿�֣�������ջ
    for(k = a1; k <= b1; k++) {
        c = t->ch[i];
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
        
        stack[++top] = c;
    }
    
    // �������Ϊ��������Ҫ���һ���ַ�
    if(len % 2 == 1) {
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
    }
    
    for(k = a2; k <= b2; k++) {
        c = t->ch[i];
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
        
        // �����˲��ԳƵ��ַ�
        if(stack[top--] != c) {
            return ERROR;
        }
    }
    
    if(top == -1) {
        return OK;
    } else {
        return ERROR;
    }
}
