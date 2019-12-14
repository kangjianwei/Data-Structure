#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"					//**��07 ͼ**//

/* �궨�� */
int ReversePolish[MAX_VERTEX_NUM+1];	//0�ŵ�Ԫ��������������沨������ 

/* ���Ͷ��� */
struct
{
	int sign;							//0����ַ���1�������
	union
	{
		char c;							//���ÿ�������Ӧ��ʵ��ֵ 
		int i;
	}data;
}Elem[MAX_VERTEX_NUM+1];

/* ����ԭ�� */
int Calculate_7_40(ALGraph G, int w); 
void AssignSign_7_40(ALGraph G, FILE *fp);	//Ϊÿһ���㸳��ʵ������ 
void Algo_7_40(ALGraph G, int w);			//����ͼG�Ķ������д�Դ�㿪ʼ������

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//��Ϊ����Դ	
	int i;
		
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_40.txt", "r");	
	CreateGraph_AL(fp, &G); 
	AssignSign_7_40(G, fp);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_40(G, 1);
	printf("�˱��ʽ���沨��ʽΪ��");
	for(i=1; i<=ReversePolish[0]; i++)
	{
		if(Elem[ReversePolish[i]].sign==0)
			printf("%c ", Elem[ReversePolish[i]].data.c);
		else
			printf("%d ", Elem[ReversePolish[i]].data.i);
	}
	printf("\n\n");	
	
	printf("�˱��ʽ��ֵΪ��");
	printf("%d\n", Calculate_7_40(G, 1));
	printf("\n");		
	
	return 0;
}

/*��������������������
����7.40��������ʽ��
��������������������*/
int Calculate_7_40(ALGraph G, int w)		//��Դ�㿪ʼ���� 
{
	ArcNode *p, *q;
	int x, y;
	char oper;
		
	p = G.vertices[w].firstarc;				//p��qͬʱ���ֻ�ͬʱΪ�� 

	if(p)
	{
		q = p->nextarc;
		
		x = Calculate_7_40(G, p->adjvex);	//�����ڶ������ı��� 
		y = Calculate_7_40(G, q->adjvex);
		oper = Elem[w].data.c;
		
		if(oper=='+')
			return x + y;
		if(oper=='-')
			return x - y;
		if(oper=='*')
			return x * y;		
		if(oper=='/')
			return x / y;
	}
	else
		return Elem[w].data.i;	
}

void AssignSign_7_40(ALGraph G, FILE *fp)
{
	char tmp;
	int k;
	
	Scanf(fp, "%c", &tmp);				//�������з�	
	for(k=1; k<=G.vexnum; k++) 
		Scanf(fp, "%d", &Elem[k].sign);

	Scanf(fp, "%c", &tmp);				//�������з�
	for(k=1; k<=G.vexnum; k++)
	{
		if(Elem[k].sign==0)				//���ַ� 
			Scanf(fp, "%c", &Elem[k].data.c);
		else
			Scanf(fp, "%d", &Elem[k].data.i);	
	}
}

//���ʽ�ṹ�����Խ̲� 
void Algo_7_40(ALGraph G, int w)			//����ͼG�Ķ������д�Դ�㿪ʼ������ 
{	
	ArcNode *r;
	
	for(r=G.vertices[w].firstarc; r; r=r->nextarc)
		Algo_7_40(G, r->adjvex);

	if(!r)
	{
		ReversePolish[0]++;
		ReversePolish[ReversePolish[0]] = w;						//���������д洢	
	}
}
