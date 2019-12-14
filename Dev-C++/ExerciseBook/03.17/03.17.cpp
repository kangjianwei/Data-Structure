#include <stdio.h>
#include "Status.h"   //**��01 ����**//
#include "SqStack.h"  //**��03 ջ�Ͷ���**//

/*
 * �ж����������Ƿ�Ϊ"����1&����2"����ģʽ
 * ���У�����2������1������
 *
 * s������֤�����У���'@'���Ž�β
 */
Status Algo_3_17(char* s);


int main(int argc, char* argv[]) {
    char* s = "a+b-c&c-b+a@";
    
    printf("�ж����� %s �Ƿ�Ϲ�...\n", s);
    
    if(Algo_3_17(s)) {
        printf("�� �����������⣡\n");
    } else {
        printf("�� ���в��������⣡��\n");
    }
    
    return 0;
}


/*
 * �ж����������Ƿ�Ϊ"����1&����2"����ģʽ
 * ���У�����2������1������
 *
 * s������֤�����У���'@'���Ž�β
 */
Status Algo_3_17(char* s) {
    SqStack S;
    SElemType e;
    int i;
    
    InitStack(&S);
    i = 0;
    
    // ��'&'ǰ��������ջ
    while(s[i] != '@' && s[i] != '&') {
        Push(&S, s[i]);
        i++;
    }
    
    // ���������'&'����
    if(s[i] != '@') {
        i++;    // ����&����
    
        // ��'&'������г�ջ
        while(!StackEmpty(S) && s[i] != '@') {
            Pop(&S, &e);
            if(s[i] != e) {
                return ERROR;
            }
            i++;
        }
    }
    
    // ���ջΪ�գ�������ǡ�÷����꣬˵����������
    if(StackEmpty(S) && s[i] == '@') {
        return OK;
    }
    
    return ERROR;
}
