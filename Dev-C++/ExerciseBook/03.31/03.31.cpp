#include <stdio.h>
#include <string.h>   // �ṩstrlen������ԭ��
#include "Status.h"   //**��01 ����**//
#include "SqStack.h"  //**��03 ջ�Ͷ���**//

/*
 * �ж�����s�Ƿ�Ϊ��������
 * �մ�Ҳ����Ϊ��������
 */
Status Algo_3_31(char* s);


int main(int argc, char* argv[]) {
    char* a = "abcdedcba@";
    char* b = "ababab@";
    
    if(Algo_3_31(a)) {
        printf("%s��������@���ǻ������У�\n", a);
    } else {
        printf("%s��������@�����ǻ������У���\n", a);
    }
    
    if(Algo_3_31(b)) {
        printf("%s��������@���ǻ������У�\n", b);
    } else {
        printf("%s��������@�����ǻ������У���\n", b);
    }
    
    return 0;
}


/*
 * �ж�����s�Ƿ�Ϊ��������
 * �մ�Ҳ����Ϊ��������
 */
Status Algo_3_31(char* s) {
    int len;
    int i;
    int m, n;   // ���Ĵ�ǰ��εĽ�β�±�ͺ��εĿ�ʼ�±�
    SqStack S;
    SElemType e;
    
    len = (int) strlen(s);
    
    if(len == 0 || s[len - 1] != '@') {
        return FALSE;
    }
    
    // �մ�����Ϊ�ǻ�������
    if(len == 1) {
        return TRUE;
    }
    
    if(len % 2 == 0) {
        m = (len - 2) / 2 - 1;
        n = m + 2;
    } else {
        m = (len - 2) / 2;
        n = m + 1;
    }
    
    InitStack(&S);
    
    // �Ȱѻ��Ĵ�ǰ�����ջ
    for(i = 0; i <= m; i++) {
        Push(&S, s[i]);
    }
    
    // ȡ�����Ĵ�ǰ��Σ����ַ������к��αȶ�
    for(i = n; i <= len - 2; i++) {
        if(!StackEmpty(S)) {
            Pop(&S, &e);
        } else {
            break;
        }
        
        if(s[i] != e) {
            return ERROR;
        }
    }
    
    // ������״̬Ӧ����ջ����Ϊ�գ���iΪlen-1
    if(!(StackEmpty(S) && i == len - 1)) {
        return ERROR;
    }
    
    return OK;
}
