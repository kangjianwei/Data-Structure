#include <stdio.h>
#include <stdlib.h>
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//

/*
 * �������� ��ʾ ��������
 *
 * ��������һ����̬�滮���⣬��ϸ˼·�μ����㷨���ۡ��������15.4�ڡ�
 *
 * ע�����㷨���ۡ��е�"�����������"�����ͳ�Ʋ��������Ӵ������Ǳ���ֻ��ͳ���������Ӵ���
 */


/* ������Ӵ������ */
typedef struct {
    char dir;
    int len;
} LCS;

/* �Ӵ����� */
typedef struct {
    int s;  // ���Ӵ��ڴ�S�е�λ��
    int t;  // ���Ӵ��ڴ�T�е�λ��
} Pos;

/* ������Ӵ����� */
typedef struct {
    int maxlen;     // ������Ӵ��ĳ���
    Pos* pos;       // ����������Ӵ�������
    int count;      // ������Ӵ�������
} Strs;


/*
 * ����S��T�е�������Ӵ���
 *
 * ���У��������ı���Ϊ"��һ�����ֵ�������Ӵ�"��
 */
Status Algo_4_31(SString S, SString T);

/*
 * ��ȡ������Ӵ���������Ϣ
 */
void LocationPos(SString S, SString T, Strs* strs);

/*
 * ����������Ӵ����������ȡ������Ӵ��ĳ��ȡ�
 */
Status BuildLCS(SString S, SString T, LCS*** lcs, int* maxLen);

/*
 * ��ӡ������Ӵ��������ѡ��������
 */
void PrintLCS(SString S, SString T, LCS** lcs);


int main(int argc, char* argv[]) {
    char* s = "csajcu123456ewjfskhsdufasawx";
    char* t = "m123456vsadksjewjfshcdsdufassgcx";
    SString S, T;
    
    StrAssign(S, s);
    StrAssign(T, t);
    
    Algo_4_31(S, T);
    
    return 0;
}


/*
 * ����S��T�е�������Ӵ���
 *
 * ���У��������ı���Ϊ"��һ�����ֵ�������Ӵ�"��
 */
Status Algo_4_31(SString S, SString T) {
    Strs strs;
    SString sub;
    int i;
    
    LocationPos(S, T, &strs);
    
    printf("������Ӵ��ĳ���Ϊ��%d \n", strs.maxlen);
    printf("�������������Ӵ��������꣺\n");
    for(i=0; i<strs.count; i++) {
        printf("(s=%3d t=%3d) ", strs.pos[i].s, strs.pos[i].t);
        
        if(SubString(sub, S, strs.pos[i].s, strs.maxlen)==OK) {
            StrPrint(sub);
        }
    }
    
    return OK;
}

/*
 * ��ȡ������Ӵ���������Ϣ
 */
void LocationPos(SString S, SString T, Strs* strs) {
    LCS** lcs;
    int sLen, tLen;
    int maxLen;
    int i, j;
    int size;
    
    BuildLCS(S, T, &lcs, &maxLen);
    PrintLCS(S, T, lcs);
    
    (*strs).maxlen = maxLen;
    (*strs).count = 0;
    size = 10;
    (*strs).pos = (Pos*) malloc(size * sizeof(Pos));
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    for(i=1; i<=sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            if(lcs[i][j].len!=maxLen || lcs[i][j].dir!='\\') {
                continue;
            }
            
            if((*strs).count>=size) {
                size += 10;
                (*strs).pos = (Pos*) realloc((*strs).pos, size * sizeof(Pos));
            }
            
            (*strs).pos[(*strs).count].s = i-maxLen+1;
            (*strs).pos[(*strs).count].t = j-maxLen+1;
            (*strs).count++;
        }
    }
}

/*
 * ����������Ӵ����������ȡ������Ӵ��ĳ��ȡ�
 */
Status BuildLCS(SString S, SString T, LCS*** lcs, int* maxLen) {
    int sLen, tLen;
    int i, j;
    int max;
    LCS node;
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    if(sLen == 0 || tLen == 0) {
        return ERROR;
    }
    
    // ��ʼ��LCS���
    *lcs = (LCS**) malloc((sLen + 1) * sizeof(LCS*));
    for(i = 0; i <= sLen; i++) {
        (*lcs)[i] = (LCS*) malloc((tLen + 1) * sizeof(LCS));
    }
    
    for(i = 0; i <= sLen; i++) {
        (*lcs)[i][0].dir = ' ';
        (*lcs)[i][0].len = 0;
    }
    
    for(j = 0; j <= tLen; j++) {
        (*lcs)[0][j].dir = ' ';
        (*lcs)[0][j].len = 0;
    }
    
    max = 0;
    
    for(i = 1; i <= sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            // ���������롶�㷨���ۡ��еĽ�����΢��ͬ���˴���Ҫͳ���������Ӵ�
            if(S[i] == T[j]) {
                // ���ǰһ���ַ�Ҳ��ȣ�˵�����Ǹ������Ĺ����Ӵ�
                if(i > 1 && j > 1 && S[i - 1] == T[j - 1]) {
                    node.dir = '\\';
                    node.len = (*lcs)[i - 1][j - 1].len + 1;
                    
                    // �Ͽ���
                } else {
                    node.dir = ' ';
                    node.len = 1;
                }
                
                if(node.len > max) {
                    max = node.len;
                }
            } else {
                if((*lcs)[i - 1][j].len >= (*lcs)[i][j - 1].dir) {
                    node.dir = '^';
                    node.len = (*lcs)[i - 1][j].len;
                } else {
                    node.dir = '<';
                    node.len = (*lcs)[i][j - 1].len;
                }
            }
            
            (*lcs)[i][j] = node;
        }
    }
    
    *maxLen = max;
    
    return ERROR;
}

/*
 * ��ӡ������Ӵ��������ѡ��������
 */
void PrintLCS(SString S, SString T, LCS** lcs) {
    int sLen, tLen;
    int i, j;
    
    sLen = StrLength(S);
    tLen = StrLength(T);
    
    if(sLen == 0 || tLen == 0) {
        return;
    }
    
    // ��һ��
    printf("   ");
    for(j = 1; j <= tLen; j++) {
        printf(" %c  ", T[j]);
    }
    printf("\n");
    
    // �ڶ���
    printf("   ");
    for(j = 1; j <= tLen; j++) {
        printf("--- ");
    }
    printf("\n");
    
    for(i = 1; i <= sLen; i++) {
        for(j = 1; j <= tLen; j++) {
            // ÿһ�еĿ�ʼ
            if(j == 1) {
                printf("%c |", S[i]);
            }
            
            printf("%c%2d ", lcs[i][j].dir, lcs[i][j].len);
        }
        printf("\n");
    }
    
    printf("\n");
}
