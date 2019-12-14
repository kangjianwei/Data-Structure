#include <stdio.h>
#include <string.h>
#include "SqStack.h"    //**��03 ջ�Ͷ���**//
#include "String.h"     //**�ַ���**//

/*
 * ��ǰ׺���ʽprefixת��Ϊ��׺���ʽ
 *
 *��ע��
 * δ��ǰ׺���ʽ����ȷ�Խ�����֤
 */
Status Algo_4_14(const char* prefix, char** suffix) {
    StringType P, S;
    StringType Operator;    // �����
    SqStack stack;          // ���ʽջ
    StringType e;           // ջ��Ԫ��
    StringType o;           // ����ջ���������
    int i, len;
    int readStr;    // �Ƿ���Ҫ��ȡ�ַ���
    
    len = (int) strlen(prefix);
    
    if(len == 0) {
        *suffix = NULL;
        return ERROR;
    }
    
    // ������Ͳ�����
    StrAssign(&Operator, "+-*/");
    
    // ǰ׺���ʽ
    StrAssign(&P, prefix);
    
    // ��׺���ʽջ
    InitStack(&stack);
    
    readStr = 1;
    i = 1;
    
    // ����ǰ׺���ʽ�������ȡԪ��
    while(TRUE) {
        if(readStr == 1) {
            S = SubString(P, i++, 1);
        }
        
        // ������������������ֱ����ջ
        if(Index(Operator, S, 1) != 0) {
            Push(&stack, S);
            readStr = 1;
            
            // ��������˲�����
        } else {
            // ��ȡջ��Ԫ�أ����ջ�Ѿ�Ϊ�գ���S�д洢�˺�׺���ʽ
            if(GetTop(stack, &e) == ERROR) {
                break;
            }
            
            // ���ջ��Ԫ������������򽫲�����ֱ����ջ
            if(Index(Operator, e, 1) != 0) {
                Push(&stack, S);
                readStr = 1;
                
                // ����ջ��Ҳ�ǲ���������Ҫ���м�����
            } else {
                Pop(&stack, &e);    // ����ջ��������
                Pop(&stack, &o);    // ��������ջ���������
                
                S = Concat(e, S);
                S = Concat(S, o);
                
                // ���������²���Ҫ��ȡ�ַ���������Ҫ�жϸոռ������Sub
                readStr = 0;
            }
        }
    }
    
    // ��ȡ��׺���ʽ
    *suffix = S;
    
    return OK;
}


int main(int argc, char* argv[]) {
    char* prefix = "-+a*bc/de";  // ���׺���ʽΪ��abc*+de/-
    char* suffix;
    
    Algo_4_14(prefix, &suffix);
    
    printf("ǰ׺���ʽ��%s\n", prefix);
    printf("��׺���ʽ��%s\n", suffix);
}
