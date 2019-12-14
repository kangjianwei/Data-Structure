#include <stdio.h>
#include <stdlib.h>     // �ṩ system ����ԭ��
#include "Status.h"     //**��01 ����**//

/* ���㷨�������Թ�Ѱ·�㷨 */

/* �궨�� */
#define SleepTime 2
#define Row 10
#define Col    17

/* ���ʷ��� */
typedef enum {
    East, South, West, North
} Direction;

/* ��ɫö�� */
typedef enum {
    Color_1, Color_2, Color_3
} Color;

/* ջ��Ԫ������ */
typedef struct {
    int x, y;   // ���ص�ĺᡢ�����궨��
    int di;     // �Ӵ����ص�������һ���ص��"����"
} SElemType;

// �Թ�Ⱦɫ��������ָ����ͼ��Ⱦɫ
void Algo_3_20(int g[][17], SElemType start);

// ��ʼ��ͼ�������Ⱦɫ���
void InitGrap(int g[][17], SElemType* start);

// ����Ļ����ʾ��ǰͼ��
void PaintGrap(int g[][17]);

// �ж�ĳ�����Ƿ���ҪȾɫ
Status Pass(SElemType e, int g[][17]);

// ��������Ⱦɫ�ĵ㼴���±�ǣ���Ⱦ����Ӧ����ɫ
void Mark(SElemType* e, int g[][17]);

// ��ȡ��һ����Ⱦɫ�ĵ����Ϣ
Status NextPos(SElemType* e);

// �жϵ�ǰ�ĵ��Ƿ����
Status IsCross(SElemType e);


int main(int argc, char** argv) {
    int g[Row][Col];    // ���ͼ����������ɫ
    SElemType start;    // Ⱦɫ�����
    
    InitGrap(g, &start);
    PaintGrap(g);
    
    Algo_3_20(g, start);
    
    return 0;
}


// ��ָ����ͼ��Ⱦɫ
void Algo_3_20(int g[][Col], SElemType start) {
    SElemType e;
    SElemType stack[10000];     // ����һ���㹻���������Ϊջ�����Ⱦ��ɫ�ĵ�
    int top = -1;               // ջ��ָ��
    
    e = start;
    do {
        // �����ҪȾɫ
        if(Pass(e, g)) {
            Mark(&e, g);        // ����Ⱦɫ���������ǰ������
            PaintGrap(g);
            stack[++top] = e;   // �����ʹ������ص���ջ
            NextPos(&e);        // �ó���һ�����ص���Ϣ
        } else {
            if(top != -1) {
                e = stack[top--];
    
                // ջ�е����ĵ���û���෽��ɷ���
                while(e.di == North && top != -1) {
                    e = stack[top--];
                }
                
                if(e.di < North) {
                    e.di++;
                    stack[++top] = e;
                    NextPos(&e);
                }
            }
        }
    } while(top != -1); // ջ��Ϊ��
}

/* ��ʼ��ͼ�������Ⱦɫ��� */
void InitGrap(int g[][Col], SElemType* start) {
    int i, j;
    
    // ������ɫ0����ɫ1
    int a[Row][Col]={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
                     {0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                     {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
                     {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
                     {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};
    
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 17; j++) {
            g[i][j] = a[i][j];
        }
    }
    
    (*start).x = 9;         // �������
    (*start).y = 8;
    (*start).di = East;     // East����������
}

/* ����Ļ����ʾ��ǰͼ�� */
void PaintGrap(int g[][Col]) {
    int i, j;
    
    Wait(SleepTime);
    system("cls");

    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            // ��ɫ0��"^"��ʾ
            if(g[i][j] == Color_1) {
                printf(".");
            }
    
            // ��ɫ1��ʾΪ�հ�
            if(g[i][j] == Color_2) {
                printf(" ");
            }
    
            // ��ɫ2��"*"��ʾ
            if(g[i][j] == Color_3) {
                printf("*");
            }
            
            if(j && !(j % (Col - 1))) {
                printf("\n");
            }
        }
    }
    
    printf("\n");
}

/* �ж�ĳ�����Ƿ���ҪȾɫ */
Status Pass(SElemType e, int g[][Col]) {
    int x = e.x;
    int y = e.y;
    
    // ����ɫΪ1�ĵ�Ⱦ��������ɫ
    if(g[x][y] == 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* ��������Ⱦɫ�ĵ㼴���±�ǣ���Ⱦ����Ӧ����ɫ */
void Mark(SElemType* e, int g[][Col]) {
    int x = (*e).x;
    int y = (*e).y;
    
    (*e).di = East;     // ��Ǵ����ص��ǰ������
    
    g[x][y] = 2;        // �������ص���ɫȾΪ��ɫ2
}

/* ��ȡ��һ����Ⱦɫ�ĵ����Ϣ */
Status NextPos(SElemType* e) {
    SElemType tmp;
    tmp = *e;
    
    switch(tmp.di) {
        case East:
            (tmp.y)++;      // East��������
            break;
        case South:
            (tmp.x)++;      // South��������
            break;
        case West:
            (tmp.y)--;      // West��������
            break;
        case North:
            (tmp.x)--;      // North��������
            break;
        default:
            return FALSE;
    }
    
    if(IsCross(tmp)) {
        ++(*e).di;
        NextPos(e);
    } else {
        *e = tmp;
    }
    
    return TRUE;
}

/* �жϵ�ǰ�ĵ��Ƿ���� */
Status IsCross(SElemType e) {
    int x = e.x;
    int y = e.y;
    
    // Խ��
    if(x < 0 || y < 0 || x > Row - 1 || y > Col - 1) {
        return OK;
    } else {
        return ERROR;
    }
}
