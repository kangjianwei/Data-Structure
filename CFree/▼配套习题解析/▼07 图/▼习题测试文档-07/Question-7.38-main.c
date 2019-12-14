#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"					//**��07 ͼ**//

/* ȫ�ֱ��� */
int ReversePolish[MAX_VERTEX_NUM+1];	//0�ŵ�Ԫ��������������沨������ 
char c[MAX_VERTEX_NUM+1];		//���ÿ�������Ӧ��ʵ��ֵ 

/* ����ԭ�� */
void Algo_7_38(ALGraph G, int w);
void AssignSign_7_38(ALGraph G, FILE *fp);		//Ϊÿһ���㸳��ʵ������ 

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//��Ϊ����Դ	
	int i;
		
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_38.txt", "r");	
	CreateGraph_AL(fp, &G); 
	AssignSign_7_38(G, fp);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_38(G, 1);
	printf("�˱��ʽ���沨��ʽΪ��");
	for(i=1; i<=ReversePolish[0]; i++)
		printf("%c ", c[ReversePolish[i]]);
	printf("\n\n");	
		
	return 0;
}

/*��������������������������������
����7.38�����ʽ������ͼ�洢�ṹ��
��������������������������������*/
//���ʽ�ṹ�����Խ̲� 
void Algo_7_38(ALGraph G, int w)					//����ͼG�Ķ������д�Դ�㿪ʼ������ 
{	
	ArcNode *r;
	
	for(r=G.vertices[w].firstarc; r; r=r->nextarc)
		Algo_7_38(G, r->adjvex);

	if(!r)
	{
		ReversePolish[0]++;
		ReversePolish[ReversePolish[0]] = w;						//���������д洢	
	}
}

void AssignSign_7_38(ALGraph G, FILE *fp)
{
	char tmp;
	int k;
	
	Scanf(fp, "%c", &tmp);				//�������з�	
	for(k=1; k<=G.vexnum; k++) 
		Scanf(fp, "%c", &c[k]);
}
