/*==============
 * �б༭����
 *
 * �����㷨: 3.2
 ===============*/

#include "LineEdit.h"                //**��03 ջ�Ͷ���**//

/*
 * ���������������� �㷨3.2 ����������������
 *
 * �б༭����ģ��༭�ı�ʱ���˸�������еĲ�����
 *
 *��ע��
 * �̲�ʹ�õ��ǿ���̨���룬����Ϊ�˱��ڲ��ԣ�ֱ�Ӹ�Ϊ���βν��ղ���
 */
void LineEdit(const char buffer[]) {
    SqStack S;                        //����������ַ�
    SElemType e;
    int i;
    char ch;
    
    // ��ʼ��ջ
    InitStack(&S);
    
    i = 0;
    ch = buffer[i++];
    
    // ���δ���ı�ĩβ
    while(ch != EOF) {
        // ���δ���ı�ĩβ���ұ���δ������δ�������У�
        while(ch != EOF && ch != '\n') {
            switch(ch) {
                case '#':
                    Pop(&S, &e);    // ����'#'��ʾɾ��һ���ַ�
                    break;
                case '@':
                    ClearStack(&S); // ����'@'��ʾ��յ�ǰ��
                    break;
                default :
                    Push(&S, ch);   // ��Ч�ַ���ջ
            }
            
            // ʶ����һ���ַ�
            ch = buffer[i++];
        }
        
        // ���֮ǰ�����ǰջ�����ݣ��˴��̲���û��
        StackTraverse(S, Print);
        
        // ��ո��еĻ�����
        ClearStack(&S);
        
        // ���δ���ı�ĩβ��˵��������'\n'�������н�����
        if(ch != EOF) {
            // ������һ��
            ch = buffer[i++];
        }
    }
    
    // �Ѿ������ı�ĩβ�����Ŀǰջ�е�Ԫ�أ��˴��̲���û��
    StackTraverse(S, Print);
    
    // ����ջ
    DestroyStack(&S);
}

// ���Ժ�������ӡԪ��
void Print(SElemType e) {
    printf("%c", e);
}
