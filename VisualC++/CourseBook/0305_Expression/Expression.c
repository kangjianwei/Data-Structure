/*==============
 * ���ʽ����
 *
 * �����㷨: 3.4
 ===============*/

#include "Expression.h"        //**��03 ջ�Ͷ���**//

/*
 * ���������������� �㷨3.4 ����������������
 *
 * ��exp������ʽ����������ʽ��������
 *
 *��ע��
 * 1.�̲�ʹ�õ��ǿ���̨���룬����Ϊ�˱��ڲ��ԣ�ֱ�Ӹ�Ϊ���βν��ղ���
 * 2.�ü��㹦�����ޣ������Ͻ�֧�ֶԸ�λ�����㣬��Ҫ��ÿһ����������Ҳ�Ǹ�λ����
 *   �̲��ṩ���㷨��Ŀ������֤ջ��ʹ�ã��������չ���������֧�֣�������Բ�������֧�֣�
 *   �����˳�Ŵ�˼·���иİ�
 */
OperandType EvaluateExpression(const char exp[]) {
    SElemType c;   // ��������
    
    SqStack OPTR;   // �����ջ
    SqStack OPND;   // ������ջ
    
    OperatorType theta, x;  // �����
    OperandType a, b;       // ������
    
    int i = 0;
    
    // ��ʼ�������ջ������һ�����޷�'#'��ջ
    InitStack(&OPTR);
    Push(&OPTR, '#');
    
    // ��ʼ��������ջ������ʼ��ȡ����
    InitStack(&OPND);
    c = exp[i++];
    
    // ���������������޷�'#'���������ջ��ջ��Ԫ��Ҳ�ǽ��޷�'#'ʱ�����ʾ��ȡ���������������
    while(c != '#' || GetTop(OPTR) != '#') {
        // ���ch�����������������Ϊ��������������ջ
        if(!In(c, OP)) {
            Push(&OPND, c);    // ����������ջ
            c = exp[i++];      // ��ȡ��һ�������ַ�
        } else {
            switch(Precede(GetTop(OPTR), c)) {
                // ջ����������ȼ��ͣ�������ջ
                case '<':
                    Push(&OPTR, c);
                    c = exp[i++];
                    break;
        
                // ���ȼ����ʱ��˵�������������ţ���Ҫ������
                case '=':
                    Pop(&OPTR, &x);
                    c = exp[i++];
                    break;
                    
                /*
                 * ջ����������ȼ���ʱ���ȼ��㣬�ٽ�������ѹ��ջ
                 *
                 * ע�����û�ж��ַ���c�����Ļ��ǸղŶ������ַ�
                 */
                case '>':
                    Pop(&OPTR, &theta); // ���������
                    Pop(&OPND, &b);     // �����ұߵĲ�����
                    Pop(&OPND, &a);     // ������ߵĲ�����
                    Push(&OPND, Operate(a, theta, b));
                    break;
            }
        }
    }
    
    return GetTop(OPND);
}

// �ж�ָ����������Ƿ�Ϲ�
Status In(SElemType c, const char OP[]) {
    
    SElemType* e = strchr(OP, c);
    
    // ��������c���ںϹ淶Χ�ڣ�˵��ָ������������Ϲ�
    if(e == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/*
 * �ж������ջ�в�����o1����ʽ�еĲ�����o2�����ȼ���
 *
 * ����'>'��'<'��'='����ָʾo1��o2�����ȼ�
 */
OperatorType Precede(OperatorType o1, OperatorType o2) {
    int x, y;
    
    // ��ȡָ�������������������е�λ��
    char* p1 = strchr(OP, o1);
    char* p2 = strchr(OP, o2);
    
    // �����һ����������ȼ�������
    x = p1 - OP;
    y = p2 - OP;
    
    return PrecedeTable[x][y];
}

/*
 * �Բ�������������
 *
 * a��b�ǲ�������theta���������
 * ���ڲ�������������������֤�Ը�λ����֧��
 */
OperandType Operate(OperandType a, OperatorType theta, OperandType b) {
    int x, y, z = CHAR_MAX - 48;
    
    // �ȴ��ַ���תΪ����
    x = a - '0';
    y = b - '0';
    
    switch(theta) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
    }
    
    // ������ɺ󣬽�����ת��Ϊ�ַ��ͷ���
    return z + 48;
}
