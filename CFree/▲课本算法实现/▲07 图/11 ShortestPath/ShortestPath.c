/***********************************
 *						           *
 * �ļ���: ��07 ͼ\11 ShortestPath *
 * 						           *
 * �ļ���: ShortestPath.c          *
 *    	    			           *
 * ��  ��: 7.15��7.16              * 
 *    	    			           *
 **********************************/

#ifndef SHORTESTPATH_C
#define SHORTESTPATH_C

#include "ShortestPath.h" 							//**��07 ͼ**//

/*�T�T�T�T�[
�U�㷨7.15�U 
�^�T�T�T�T*/
/*
 * ��ά����P1�У���i�д洢v0��vi�����Ľ�㣨������� 
 *  
 * һά����D1�У�D1[i]�洢v0��vi�����·������
 */ 
void ShortestPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[])
{
	int v, w, i, j, min;
	Status final[MAX_VERTEX_NUM+1];					//��ǵ�ǰ����Ƿ��Ѽ������·�� 
	
		//0�ŵ�Ԫ���� 
	for(v=1; v<=G1.vexnum; v++)
	{
		final[v] = FALSE;							//final[v]ΪTRUE���ҽ���v��S�����Ѿ���ô�v0��v�����·��
		D1[v] = G1.arcs[v0][v].adj;
		
		for(w=1; w<=G1.vexnum; w++)					//P1[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ��� 
			P1[v][w] = FALSE;						//���·�� 
		
		if(D1[v]<INFINITY)
		{
			P1[v][v0] = TRUE;						//v��v0��ͨʱ��v0�϶���v0��v�ϵĵ� 
			P1[v][v] = TRUE;
		}
	}
	
	D1[v0] = 0;										//��ʼ����v0��������S��
	final[v0] = TRUE;							 
		
			//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��������v��S�� 
	for(i=2; i<=G1.vexnum; i++)					//����G1.vexnum-1������
	{
		min = INFINITY;							//��ǰ��֪��v0������������

		for(w=1; w<=G1.vexnum; w++)
		{
			if(!final[w])						//w������V-S��
			{
			 	if(D1[w]<min)					//w������v0������� 
		 		{
	 				v = w;
	 				min = D1[w];				//ѡ����ǰ״̬��v0��������������Сֵvv 
				}				
			}
		}
			
		final[v] = TRUE;						//��v0���������v����S�� 
			
		for(w=1; w<=G1.vexnum; w++)				//���µ�ǰ���·��������
		{
			if(!final[w] && min<INFINITY && G1.arcs[v][w].adj<INFINITY && (min + G1.arcs[v][w].adj < D1[w]))//�޸�D1[w]��P1[w],w��V-S 
			{
				D1[w] = min + G1.arcs[v][w].adj;
				for(j=1; j<=G1.vexnum; j++)
					P1[w][j] = P1[v][j];
				P1[w][w] = TRUE;				//P1[w] = P1[v] + P1[w]
			}
		} 
	}
}

void OutputPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[])
{
	int i, j, k, tmp;
	int count[MAX_VERTEX_NUM+1];
	int order[MAX_VERTEX_NUM+1];
		
	for(i=1; i<=G1.vexnum; i++)
	{
		order[i] = i;
		count[i] = 0;
		for(j=1; j<=G1.vexnum; j++)
		{
			if(P1[i][j])
				count[i]++;
		}
	}	
	
	for(i=1; i<=G1.vexnum; i++)
	{
		for(j=i+1; j<=G1.vexnum; j++)
		{
			if(count[j]<count[i])
			{
				tmp = count[i];
				count[i] = count[j];
				count[j] = tmp;
				
				for(k=1; k<=G1.vexnum; k++)
				{
					tmp = P1[k][i];
					P1[k][i] = P1[k][j];
					P1[k][j] = tmp;
				}
				
				tmp = order[i];
				order[i] = order[j];
				order[j] = tmp;
			}	
		}
	}
	
	for(i=1; i<=G1.vexnum; i++)
	{
		if(order[i]!=v0)
		{
			printf("%c �� %c �����·��Ϊ��", G1.vexs[v0], G1.vexs[order[i]]);
			
			if(!count[i])
				printf("��");
			else
			{
				for(j=1; j<=G1.vexnum; j++)
				{
					if(P1[order[i]][j])
						printf("%c ", G1.vexs[order[j]]);
				}
			}
			
			printf("��ȨֵΪ��");
			if(D1[order[i]]<INFINITY)
				printf("%2d\n", D1[order[i]]);
			else
				printf("��\n");
		}
	}		
}

void Dijkstra(MGraph G1, int v0, PathMatrix path1[], ShortPathTable dist1[])
{
	int set[MAX_VERTEX_NUM+1];
	int min, i, j, v;
	int tmp[MAX_VERTEX_NUM+1], k;
	
	for(i=1; i<=G1.vexnum; i++)					//�����ʼ��
	{
		dist1[i] = G1.arcs[v0][i].adj;			//dist1[i]��v0��i�����·������ 
		set[i] = 0;								//set[i]��������飬��Ǹ������Ƿ��Ѽ���·�� 
		if(G1.arcs[v0][i].adj < INFINITY)
			path1[i] = v0;						//path1[i]�������v0��vi·����vi��ǰһ������ 
		else
			path1[i] = -1;						//����v0��vi�м䲻�����κζ��㣨���ܲ�ͨ��Ҳ���������� 
	}
	
	set[v0] = 1;
	path1[v0] = -1;
	
	for(i=1; i<=G1.vexnum; i++)					//��ʼ���������ؼ�������ʼ���ж�����G1.vexnum-1�����㣩 
	{
		min = INFINITY;
		
		for(j=1; j<=G1.vexnum; j++)				//ѡ��v0��ʣ�ඥ������̵�һ��·��
		{
			if(!set[j] && dist1[j]<min)
			{
				v = j;
				min = dist1[j];					//v0��ʣ�ඥ������·��<v0, v> 
			}
		}
			
		set[v] = 1;								//������v�������·��
		
		for(j=1; j<=G1.vexnum; j++)				//�ж�v�ļ����Ƿ�����v0��ʣ�ඥ��ĸ���·�� 
		{
			if(!set[j] && min<INFINITY &&  G1.arcs[v][j].adj<INFINITY && (min + G1.arcs[v][j].adj) < dist1[j])
			{
				dist1[j] = min + G1.arcs[v][j].adj;
				path1[j] = v;
			}
		}
	}
	
	//���·�� 
	for(i=1; i<=G1.vexnum; i++)
	{
		if(v0!=i)
		{
			printf("%c �� %c ��·��Ϊ��", G1.vexs[v0], G1.vexs[i]);
			
			if(path1[i]==-1)
				printf("��");
			else
			{
				tmp[0] = 0;								//����·���ϵĶ������ 
	
				if(v0!=i)
				{
					k = i;
					do
					{
						tmp[0]++;
						tmp[tmp[0]] = k;
						k = path1[k];			
					}while(path1[k]!=-1);			
				}
				
				printf("%c ", G1.vexs[v0]);
				
				if(tmp[0])
				{
					for(j=tmp[0]; j>=1; j--)
						printf("%c ", G1.vexs[tmp[j]]);
				}
			}
				
			printf("��Ȩ��Ϊ��");
			if(dist1[i]==INFINITY)
				printf("��\n");
			else
				printf("%2d\n", dist1[i]);
		}
	}	
} 

/*�T�T�T�T�[
�U�㷨7.16�U 
�^�T�T�T�T*/
void ShortestPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1])
{
	int i, v, w, u;
	
	for(v=1; v<=G2.vexnum; v++)						//�Ը����֮���ʼ��֪·�������� 
	{
		for(w=1; w<=G2.vexnum; w++)
		{
			D2[v][w] = G2.arcs[v][w].adj;

			for(u=1; u<=G2.vexnum; u++)
				P2[v][w][u] = FALSE;

			if(D2[v][w]<INFINITY)					//��v��w��ֱ��·�� 
			{
				P2[v][w][v] = TRUE;	
				P2[v][w][w] = TRUE;			
			}
		}
	}
	
	for(u=1; u<=G2.vexnum; u++)
	{
		for(v=1; v<=G2.vexnum; v++)
		{
			for(w=1; w<=G2.vexnum; w++)
			{
				if(v!=w && D2[v][u]<INFINITY && D2[u][w]<INFINITY && D2[v][u]+D2[u][w]<D2[v][w]) //��v��u��w��һ��·������
				{
					D2[v][w] = D2[v][u] + D2[u][w];
						
					for(i=1; i<=G2.vexnum; i++)
						P2[v][w][i] = P2[v][u][i] || P2[u][w][i];					
				}	
			}
		}
	}	
}

void OutputPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1])
{
	int i, j, k, t, m;
	int count[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
	int tmp[MAX_VERTEX_NUM+1];	
	
	for(i=1; i<=G2.vexnum; i++)
	{
		for(j=1; j<=G2.vexnum; j++)
		{
			count[i][j] = 0;
			for(k=1; k<=G2.vexnum; k++)
			{
				if(P2[i][j][k])
					count[i][j]++;
			}
		}
	}

	for(i=1; i<=G2.vexnum; i++)
	{
		for(j=1; j<=G2.vexnum; j++)
		{
			if(i!=j)
			{
				printf("%c �� %c �����·��Ϊ��", G2.vexs[i], G2.vexs[j]);			

				if(!count[i][j])
					printf("��");
				else
				{
					tmp[0] = 0;
					for(k=1; k<=G2.vexnum; k++)
					{
						if(k!=i && k!=j && P2[i][j][k])
						{
							m = tmp[0];
							while(m>0 && count[i][tmp[m]]>count[i][k])
							{
								tmp[m+1] = tmp[m];
								m--;
							}
							tmp[m+1] = k;
							tmp[0]++; //�ҵ�����λ�� 
						}
					}
					
					printf("%c ", G2.vexs[i]);
					for(t=1; t<=tmp[0]; t++)
						printf("%c ", G2.vexs[tmp[t]]);
					printf("%c ", G2.vexs[j]);
				}
				
				printf("��ȨֵΪ��");
				if(D2[i][j]<INFINITY)
					printf("%2d\n", D2[i][j]);
				else
					printf("��\n");
			}
		}
	}		
}

void Floyd(MGraph G2, PathMatrix path2[][MAX_VERTEX_NUM+1], ShortPathTable dist2[][MAX_VERTEX_NUM+1])
{
	int i, j, k;
	int tmp[MAX_VERTEX_NUM+1];
		
	for(i=1; i<=G2.vexnum; i++)
	{
		for(j=1; j<=G2.vexnum; j++)
		{
			dist2[i][j] = G2.arcs[i][j].adj;
			path2[i][j] = -1;
		}
	}
	
	for(k=1; k<=G2.vexnum; k++)							//��kΪ�м������Զ������� 
	{
		for(i=1; i<=G2.vexnum; i++)
		{
			for(j=1; j<=G2.vexnum; j++)
			{
				if(i!=j && dist2[i][k]<INFINITY && dist2[k][j]<INFINITY && dist2[i][k]+dist2[k][j]<dist2[i][j])
				{
					dist2[i][j] = dist2[i][k] + dist2[k][j];
					path2[i][j] = k;
				}
			}
		}
	}
	
	//������Զ���֮��·�� 
	for(i=1; i<=G2.vexnum; i++)
	{
		for(j=1; j<=G2.vexnum; j++)
		{
			if(i!=j)
			{
				printf("%c �� %c �����·��Ϊ��", G2.vexs[i], G2.vexs[j]);
				
				if(dist2[i][j]!=INFINITY)
				{
					printf("%c ", G2.vexs[i]);
					k = i;
					while(path2[k][j]!=-1)
					{
						printf("%c ", G2.vexs[path2[k][j]]);
						k = path2[k][j];
					}				
					printf("%c ", G2.vexs[j]);				
				}
				else
					printf("��");
				
				printf("��ȨֵΪ��");
				if(dist2[i][j]==INFINITY)
					printf("��\n");
				else
					printf("%d\n", dist2[i][j]);
			}
		}
	}
}

#endif 
