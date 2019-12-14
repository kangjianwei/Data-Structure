#include <stdio.h>
#include "Status.h"   //**��01 ����**//
#include "SqStack.h"  //**��03 ջ�Ͷ���**//

// �ж����ʽ���������Ƿ���Գ��֣��������Ƿ�ƥ��
Status Algo_3_19(char* s);

// �ж�����a������b֮��������Ƿ�ƥ��
Status Matching(char a, char b);


int main(int argc, char* argv[]) {
    char* s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}";
    
    printf("�жϱ��ʽ %s �����Ƿ�ƥ��...\n", s);
    
    if(Algo_3_19(s)) {
        printf("�� ���ʽ����ƥ�䣡\n");
    } else {
        printf("�� ���ʽ���Ų�ƥ�䣡��\n");
    }
    
    return 0;
}


// �ж����ʽ���������Ƿ���Գ��֣��������Ƿ�ƥ��
Status Algo_3_19(char* s) {
    SqStack S;
    SElemType e;
    int i;
    
    InitStack(&S);
    
    for(i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            // ���������ţ�����ջ
            case '(':
            case '[':
            case '{':
                Push(&S, s[i]);
                break;
        
            // ���������ţ����ջ
            case ')':
            case ']':
            case '}':
                if(StackEmpty(S)) {
                    return ERROR;
                }
                
                Pop(&S, &e);
                
                // �ж������Ƿ�ƥ��
                if(!Matching(e, s[i])) {
                    return ERROR;
                }
                break;
            
            default:
                break;
        }
    }
    
    if(StackEmpty(S)) {
        return OK;
    }
    
    return ERROR;
}

// �ж�����a������b֮��������Ƿ�ƥ��
Status Matching(char a, char b) {
    switch(a) {
        case '(':
            if(b != ')') {
                return ERROR;
            }
            break;
        
        case '[':
            if(b != ']') {
                return ERROR;
            }
            break;
        
        case '{':
            if(b != '}') {
                return ERROR;
            }
            break;
        
        default:
            return ERROR;
    }
    
    return OK;
}
