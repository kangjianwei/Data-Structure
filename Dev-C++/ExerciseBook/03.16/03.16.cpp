#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SqStack.h"    //**��03 ջ�Ͷ���**//

/*
 * ���ɳ���������У�����'I'������ջ��'O'�����ջ
 *
 * ����������ұߣ���������ߣ��ҳ����ȡ˳�򡾴����ҡ�
 *
 * En ���ȴ����ȵ��г�����
 * seq����������
 */
void Algo_3_16(char* En, char seq[]);

/*
 * ʹ��Լ���õĵ�������seq�������En���ĳ�����ȵ�����Ex
 *
 * �÷����ɿ����ǶԵ������еļ���
 *
 * En ���ȴ����ȵ��г�����
 * seq����������
 * Ex ��������ɺ������
 */
Status Dispatch(char* En, char* seq, char Ex[]);


int main(int argc, char* argv[]) {
    char* En = "HSHHSHHHSSHSSSHS";  // �ȴ����ȵ��г�����
    char Ex[100] = {'\0'};          // ������ɵ��г�����
    char seq[100] = {'\0'};         // ��������
    
    printf("�������� ��ڴ������У�\n");
    printf("�� En  = %s\n", En);
    
    Algo_3_16(En, seq);
    printf("�������� ���ɵĵ������У�\n");
    printf("�� seq = %s\n", seq);
    
    Dispatch(En, seq, Ex);
    printf("�������� �������ɵĵ������У�����ڴ��ĳ�����ȣ�������ɺ�ĳ������У�\n");
    printf("�� Ex  = %s\n", Ex);
    
    return 0;
}


/*
 * ���ɳ���������У�����'I'������ջ��'O'�����ջ
 *
 * ����������ұߣ���������ߣ������ȡ˳�������
 *
 * En ���ȴ����ȵ��г�����
 * seq����������
 */
void Algo_3_16(char* En, char seq[]) {
    int i, j;
    SqStack S;
    SElemType e;
    
    // ��ʼ��һ����תջ
    InitStack(&S);
    
    // ��������������
    for(i = j = 0; En[i] != '\0'; i++) {
        // ����Ӳϯ��������ջ
        if(En[i] == 'H') {
            Push(&S, En[i]);
            seq[j++] = 'I';
        }
        
        // ������ϯ��������ջ����������ջ���൱����ջ����ת
        if(En[i] == 'S') {
            Push(&S, En[i]);
            Pop(&S, &e);
            seq[j++] = 'I';
            seq[j++] = 'O';
        }
    }
    
    // ����תջ�е�Ӳϯ��ջ
    while(!StackEmpty(S)) {
        Pop(&S, &e);
        seq[j++] = 'O';
    }
    
    seq[j] = '\0';
    
    DestroyStack(&S);
}

/*
 * ʹ��Լ���õĵ�������seq�������En���ĳ�����ȵ�����Ex
 *
 * �÷����ɿ����ǶԵ������еļ���
 *
 * En ���ȴ����ȵ��г�����
 * seq����������
 * Ex ��������ɺ������
 */
Status Dispatch(char* En, char* seq, char Ex[]) {
    int i, j, k;
    SqStack S;
    SElemType e;
    
    // ��ʼ��һ����תջ
    InitStack(&S);
    
    i = j = k = 0;
    
    // ������������
    while(seq[k] != '\0') {
        // ������ջ��ǣ��򽫳��������תջ
        if(seq[k] == 'I') {
            Push(&S, En[i++]);
        }
        
        // ������ջ��ǣ��򽫳����Ƴ�����ת�Ƶ����ڴ�
        if(seq[k] == 'O') {
            Pop(&S, &e);
            Ex[j++] = e;
        }
        
        k++;
    }
    
    // �����������Ϊ�գ�������ڴ�����δ���ȵĳ��ᣬ������תջ�����δ����ĳ��ᣬ���ʾ��������
    if(seq[k] == '\0' && (En[i] || StackEmpty(S))) {
        return ERROR;
    }
    
    Ex[j] = '\0';
    
    DestroyStack(&S);
    
    return OK;
}
