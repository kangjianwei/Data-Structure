#include <stdio.h>
#include <ctype.h>    // �ṩisdigitԭ��
#include "Status.h"   //**��01 ����**//
#include "SqStack.h"  //**��03 ջ�Ͷ���**//

/*
 * ���沨�����ʽ��ֵ��������Ҫ�����������������Ϊ��λ����
 *
 *��ע��
 * ���ʽ�ı���Ϊ����ĸ��������ֻ��'+'��'-'��'*'��'/'��������
 */
Status Algo_3_22(char c[], SElemType* Value);

/* ���� a oper b ��ֵ */
char Operate(char a, char oper, char b);


int main(int argc, char* argv[]) {
    char c[] = "124*+93/-";
    SElemType value;
    
    printf("��֪�沨��ʽΪ��");
    printf("%s\n", c);
    
    Algo_3_22(c, &value);
    printf("�沨��ʽ�ļ�����Ϊ��%d\n", value - 48);
    
    return 0;
}


/*
 * ���沨�����ʽ��ֵ��������Ҫ�����������������Ϊ��λ����
 *
 *��ע��
 * ���ʽ�ı���Ϊ����ĸ��������ֻ��'+'��'-'��'*'��'/'��������
 */
Status Algo_3_22(char c[], SElemType* Value) {
    int i;
    SqStack S;
    SElemType a, b;
    
    InitStack(&S);
    
    for(i = 0; c[i]!='\0'; ++i) {
        // ������������ַ�
        if(isdigit(c[i])) {
            Push(&S, c[i]);
        } else {
            // �ȵ��������ڲ��������
            Pop(&S, &b);
            Pop(&S, &a);
            Push(&S, Operate(a, c[i], b));
        }
    }
    
    Pop(&S, Value);
    
    if(!StackEmpty(S)) {
        return ERROR;
    } else {
        return OK;
    }
}

/* ���� a oper b ��ֵ */
char Operate(char a, char oper, char b) {
    char c;
    
    switch(oper) {
        case '+':
            c = (a - 48) + (b - 48) + 48;
            break;
        case '-':
            c = (a - 48) - (b - 48) + 48;
            break;
        case '*':
            c = (a - 48) * (b - 48) + 48;
            break;
        case '/':
            c = (a - 48) / (b - 48) + 48;
            break;
    }
    
    return c;
}
