/*==============
 * ��ŵ��
 *
 * �����㷨: 3.5
 ===============*/

#include "Hanoi.h"                        //**03 ջ�Ͷ���**//

/*
 * ���������������� �㷨3.5 ����������������
 *
 * ��ŵ����⣺��yΪ��������x��ǰn��Բ���ƶ���z
 */
void hanoi(int n, char x, char y, char z) {
    if(n == 1) {                          // ���ƶ�n��Բ�̣������ƶ����ϵ�n-1��Բ��
        move(x, 1, z);                    // �����Ϊ1��Բ�̴�x�Ƶ�z
    } else {
        hanoi(n - 1, x, z, y);            // ��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
        move(x, n, z);                    // �����Ϊn��Բ�̴�x�Ƶ�z
        hanoi(n - 1, y, x, z);            // ��y�ϱ��Ϊ1��n-1��Բ���ƶ���z��x��������
    }
}

void move(char x, int n, char z) {
    // stepΪȫ�ֱ�������main����֮�ⶨ��
    gStep++;
    printf("��%2d�������� %d ��Բ�̴� %c �Ƶ� %c \n", gStep, n, x, z);
    
    // ��ŵ���ƶ���ͼ�α�ʾ
    PrintGraph(x, n, z);
}

/*
 * ��ŵ��ͼ����Ϣ��ʼ��
 *
 *��ע��
 * �̲����޴˲�����
 * ���Ӵ˲�����Ŀ����Ϊ�˱��ڹ۲캺ŵ��Բ�̵��ƶ�����
 */
void init(int n) {
    int i;
    int* towerX, * towerY, * towerZ;

    T.plates = (int**) malloc(3 * sizeof(int*));
    
    towerX = (int*) malloc(n * sizeof(int));
    towerY = (int*) malloc(n * sizeof(int));
    towerZ = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < n; ++i) {
        towerX[i] = n-i;
        towerY[i] = 0;
        towerZ[i] = 0;
    }
    
    T.plates[0] = towerX;
    T.plates[1] = towerY;
    T.plates[2] = towerZ;
    
    T.high[0] = n;
    T.high[1] = 0;
    T.high[2] = 0;
    
    // ��ŵ���ƶ���ͼ�α�ʾ
    PrintGraph('\0', 0, '\0');
}

/*
 * ��ŵ���ƶ���ͼ�α�ʾ
 *
 *��ע��
 * �̲����޴˲�����
 * ���Ӵ˲�����Ŀ����Ϊ�˱��ڹ۲캺ŵ��Բ�̵��ƶ�����
 */
void PrintGraph(char t1, int n, char t2){
    int i, j;
    char** s;
    
    // ��n�����Ӵ�t1���Ƴ�
    if(t1=='x') {
        T.plates[0][T.high[0]-1] = 0;
        T.high[0]--;
    } else if(t1=='y') {
        T.plates[1][T.high[1]-1] = 0;
        T.high[1]--;
    } else if(t1=='z') {
        T.plates[2][T.high[2]-1] = 0;
        T.high[2]--;
    } else {
        // t1�ϵ�Բ�̲���Ҫ�ƶ�
    }
    
    // ��n��������ӵ�t2��
    if(t2=='x') {
        T.plates[0][T.high[0]] = n;
        T.high[0]++;
    } else if(t2=='y') {
        T.plates[1][T.high[1]] = n;
        T.high[1]++;
    } else if(t2=='z') {
        T.plates[2][T.high[2]] = n;
        T.high[2]++;
    } else {
        // t2�ϵ�Բ�̲���Ҫ�ƶ�
    }
    
    s = (char**)malloc((N+2)*sizeof(char*));
    for(i = 0; i<N+2; i++) {
        s[i] = (char*)malloc(N* sizeof(char));
        
        for(j = 0; j < i; j++) {
            if(i==N+1) {
                s[i][j] = '-';  // �����һ�г�ʼ��Ϊ����
            } else {
                s[i][j] = '*';
            }
        }
        
        if(i==N+1) {
            s[i][j-1] = '\0';
        } else {
            s[i][j] = '\0';
        }
    }
    
    for(i = N-1; i >= 0; i--) {
        printf("%-*s | %-*s | %-*s\n", N, s[T.plates[0][i]], N, s[T.plates[1][i]], N, s[T.plates[2][i]]);
    }
    printf("%-*s + %-*s + %-*s\n", N, s[N+1], N, s[N+1], N, s[N+1]);
    printf("%-*s %-*s %-*s\n", N+2, "x", N+2, "y", N+2, "z");
    
    printf("\n");
}
