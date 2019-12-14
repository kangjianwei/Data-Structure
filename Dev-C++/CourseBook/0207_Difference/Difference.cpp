/*===============
 * ��̬����ȥ��
 *
 * �����㷨: 2.17
 ================*/

#include "Difference.h"

/*
 * ���������������� �㷨2.17 ����������������
 *
 * S = (A-B)��(B-A)
 *
 * �Լ���A�ͼ���B����(A-B)��(B-A)���㣬���������뾲̬����S
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
void difference(SLinkList space, int* S, char* path) {
    int m, n;       // ����A�ͼ���B��Ԫ������
    int j;          // ѭ��������
    int R;          // ָ��̬�������һ�����
    int i, k, p;
    int b;          // ��ʱ�洢�Ӽ���B�ж���������
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    // ��ʼ�����ÿռ�
    InitSpace(space);

    // ��ȡ��̬����ͷ���
    *S = Malloc(space);

    // ��Rִ�о�̬�������Ľ��
    R = *S;

    // ��ȡ����A�ͼ���B��Ԫ�ظ���
    if(readFromConsole) {
        printf("�����뼯��A��Ԫ�ظ�����");
        scanf("%d", &m);
        printf("�����뼯��B��Ԫ�ظ�����");
        scanf("%d", &n);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            exit(ERROR);
        }

        ReadData(fp, "%d%d", &m, &n);
    }

    if(readFromConsole) {
        printf("������ %d ��Ԫ�ش��뼯��A��", m);
    }

    // ¼�뼯��A������
    for(j = 1; j <= m; ++j) {
        // ������
        i = Malloc(space);

        // ���뼯��A��Ԫ��ֵ
        if(readFromConsole) {
            scanf("%d", &space[i].data);
        } else {
            ReadData(fp, "%d", &space[i].data);
        }

        // ���½����뵽��β
        space[R].cur = i;
        R = i;
    }

    // β����ָ���ÿ�
    space[R].cur = 0;

    if(readFromConsole) {
        printf("������ %d ��Ԫ�ش��뼯��B��", n);
    }

    // ¼�뼯��B������
    for(j = 1; j <= n; ++j) {
        // ���뼯��B��Ԫ��ֵ
        if(readFromConsole) {
            scanf("%d", &b);
        } else {
            ReadData(fp, "%d", &b);
        }

        p = *S;             // ָ��̬����ͷ��㣬��������ָ��k��ǰһ��λ��
        k = space[*S].cur;  // ָ��̬�����е��׸�Ԫ��

        // �ڵ�ǰ��̬�����в����Ƿ����bԪ��
        while(k != space[R].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }

        // �����Ԫ�ز����ڣ�����뾲̬����
        if(k == space[R].cur) {
            i = Malloc(space);
            space[i].data = b;
            space[i].cur = space[R].cur;
            space[R].cur = i;

            // �����Ԫ���Ѵ��ڣ�����Ҫ�Ƴ�
        } else {
            space[p].cur = space[k].cur;
            Free(space, k);
            if(R == k) {
                R = p;
            }
        }
    }

    if(!readFromConsole) {
        fclose(fp);
    }
}

