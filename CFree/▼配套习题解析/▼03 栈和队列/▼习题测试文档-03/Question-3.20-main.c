/* ���㷨�������Թ�Ѱ·�㷨 */
#include <stdio.h>		
#include <stdlib.h>										//�ṩ system����
#include <time.h>										//�ṩ time ����ԭ�� 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* �궨�� */
#define SleepTime 2 
#define Row 10
#define Col	17

/* ���Ͷ��� */
typedef enum{ East, South, West, North }Direction;	//���ʷ��� 
typedef enum{ Color_1, Color_2, Color_3 }Color;		//��ɫ 
typedef struct
{
	int	x;											//���ص�ĺᡢ�����궨�� 
	int y;
	int	di;											//�Ӵ����ص�������һ���ص��"����" 
}SElemType;											//ջ��Ԫ������

/* ����ԭ�� */
void Coloring_3_20(int g[][17], SElemType start); 	//�Թ�Ⱦɫ����
void InitGrap(int g[][17], SElemType *start);		//��ʼ��ͼ�������Ⱦɫ��� 
void PaintGrap(int g[][17]);						//����ͼ��
void ShowGrap(int g[][17]);							//����Ļ����ʾ��ǰͼ��
Status Pass(SElemType e, int g[][17]);				//�ж�ĳ�����Ƿ���ҪȾɫ 
void Mark(SElemType *e, int g[][17]);				//��������Ⱦɫ�ĵ㼴���±�ǣ���Ⱦ����Ӧ����ɫ
Status NextPos(SElemType *e);						//��ȡ��һ����Ⱦɫ�ĵ����Ϣ 
Status IsCross(SElemType e);						//�жϵ�ǰ�ĵ��Ƿ���� 

int main(int argc, char **argv)
{
	int g[Row][Col];								//���ͼ����������ɫ 
	SElemType start;								//Ⱦɫ����� 
	
	InitGrap(g, &start);	
	PaintGrap(g);

	Coloring_3_20(g, start);
	
	return 0;
}

/*����������������������
����3.20����ĳͼ��Ⱦɫ��
����������������������*/
void Coloring_3_20(int g[][Col], SElemType start)
{
	SElemType e;
	SElemType stack[10000];						//����һ���㹻���������Ϊջ�����Ⱦ��ɫ�ĵ� 
	int top = -1;								//ջ��ָ�� 

	e = start;	
	do
	{
		if(Pass(e, g))							//�����ҪȾɫ 
		{
			Mark(&e, g);						//����Ⱦɫ���������ǰ������
			ShowGrap(g);			
			stack[++top] = e;					//�����ʹ������ص���ջ			
			NextPos(&e);						//�ó���һ�����ص���Ϣ 
		}
		else
		{
			if(top!=-1)
			{
				e = stack[top--];
				 
				while(e.di==North && top!=-1)	//ջ�е����ĵ���û���෽��ɷ��� 
					e = stack[top--];
					
				if(e.di<North)
				{
					e.di++;
					stack[++top] = e;
					NextPos(&e);		
				}
			}
		}		
	}while(top!=-1);							//ջ��Ϊ�� 
}

/* ��ʼ��ͼ�������Ⱦɫ��� */
void InitGrap(int g[][Col], SElemType *start)
{
	int i, j;
	int a[Row][Col]={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
					 {0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
					 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
					 {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
					 {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
				     {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};//������ɫ0����ɫ1 
		
	for(i=0; i<10; i++)
	{
		for(j=0; j<17; j++)			
			g[i][j] = a[i][j];	
	}
		
	(*start).x = 9;										//������� 
	(*start).y = 8;	
	(*start).di = East;									//East����������		
}

/* ����ͼ�� */
void PaintGrap(int g[][Col])
{
	int i, j;
		
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			if(g[i][j]==Color_1)						//��ɫ0��"^"��ʾ 
				printf("^");
		 	if(g[i][j]==Color_2)						//��ɫ1��ʾΪ�հ� 
				printf(" ");
			if(g[i][j]==Color_3)						//��ɫ2��"*"��ʾ 
				printf("*");
				
			if(j && !(j%(Col-1)))
				printf("\n");
		}	
	}
}

/* ����Ļ����ʾ��ǰͼ�� */
void ShowGrap(int g[][Col])
{
	Wait(SleepTime);
	system("cls");
	PaintGrap(g);
}

/* �ж�ĳ�����Ƿ���ҪȾɫ */
Status Pass(SElemType e,int g[][Col])
{
	int x = e.x;
	int y = e.y;
	
	if(g[x][y]==1)									//����ɫΪ1�ĵ�Ⱦ��������ɫ 
		return YES;
	else
		return NO;
}

/* ��������Ⱦɫ�ĵ㼴���±�ǣ���Ⱦ����Ӧ����ɫ */
void Mark(SElemType *e, int g[][Col])
{
	int x = (*e).x;
	int y = (*e).y;
	
	(*e).di = East;									//��Ǵ����ص��ǰ������ 
	
	g[x][y] = 2;									//�������ص���ɫȾΪ��ɫ2		
}

/* ��ȡ��һ����Ⱦɫ�ĵ����Ϣ */
Status NextPos(SElemType *e)
{	
	SElemType tmp;
	tmp = *e;
	
	switch(tmp.di)
	{
		case East: (tmp.y)++;						//East�������� 
			break;
		case South: (tmp.x)++;						//South�������� 
			break;
		case West: (tmp.y)--;						//West�������� 
			break;
		case North: (tmp.x)--;						//North�������� 
			break;
		default: 
			return FALSE;
	}
	
	if(IsCross(tmp))
	{
		++(*e).di;
		NextPos(e);
	}
	else
		*e = tmp;

	return TRUE;	
}

/* �жϵ�ǰ�ĵ��Ƿ���� */
Status IsCross(SElemType e)
{
	int x = e.x;
	int y = e.y;
	
	if(x<0 || y<0 || x>Row-1 || y>Col-1)
		return YES;									//Խ�� 
	else
		return NO; 
}
