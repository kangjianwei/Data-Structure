#include <stdio.h>

/* ������� */
#define N 15

/*
 * ��������������ֵ
 */
int Algo_6_35(char* BiTree, int i);


int main(int argc, char* argv[]) {
    // ˳��洢�Ķ�����(����0�ŵ�Ԫ��ʼ�洢)
    char BiTree[N] = {'A', 'B', 'C', 'D', 'E', 'F', '\0', 'G', '\0', 'H', 'I', '\0', 'J', '\0', '\0'};
    int i, j;
    
    printf("��Ϊʾ����������������˳��洢�ṹ��^������ַ������˴�û�н����Ϣ����ABCDEF^G^HI^J^^");
    printf("\n");
    
    printf("������������(0~%d)��", N);
    scanf("%d", &i);
    printf("\n");
    
    j = Algo_6_35(BiTree, i);
    
    if(j != -1) {
        printf("��� %d ��Ӧ��ʮ��������Ϊ %d ��\n", i, j);
    } else {
        printf("�˴���㲻���ڣ�\n");
    }
    
    return 0;
}


/*
 * ��������������ֵ
 */
int Algo_6_35(char* BiTree, int i) {
    if(BiTree[i] == '\0') {
        return -1;  // �˴������ڽ��
    }
    
    return i + 1;
}
