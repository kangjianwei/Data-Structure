#include <stdio.h>
#include "../../../���α��㷨ʵ��/��07 ͼ/06 StronglyConnectedComponents/SCC.c" //**��07 ͼ**//

/* ����ԭ�� */
void Algo_7_31(OLGraph G);

int main(int argc, char *argv[])
{
    OLGraph G;
    FILE *fp;											//��Ϊ����Դ

    printf("��ʼ�����������ͼ...\n");
    fp = fopen("Data/Algo_7_31.txt", "r");				//�ĵ��л���¼��Ϊ����
    CreateDG_OL(fp, &G);
    fclose(fp);
    OutputOLGraph(G);
    printf("\n");

    printf("���������ͼ��ǿ��ͨ����...\n");
    Algo_7_31(G);
    printf("\n");
}

/*����������������������������
����7.31��������ͼǿ��ͨ������
����������������������������*/
void Algo_7_31(OLGraph G)								//��ʮ������洢�ṹΪ�� 
{
	Kosaraju(G);
}
