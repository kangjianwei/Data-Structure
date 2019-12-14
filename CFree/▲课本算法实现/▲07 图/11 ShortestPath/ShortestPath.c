/***********************************
 *						           *
 * 文件夹: ▲07 图\11 ShortestPath *
 * 						           *
 * 文件名: ShortestPath.c          *
 *    	    			           *
 * 算  法: 7.15、7.16              * 
 *    	    			           *
 **********************************/

#ifndef SHORTESTPATH_C
#define SHORTESTPATH_C

#include "ShortestPath.h" 							//**▲07 图**//

/*════╗
║算法7.15║ 
╚════*/
/*
 * 二维数组P1中，第i行存储v0到vi经过的结点（结点无序） 
 *  
 * 一维数组D1中，D1[i]存储v0到vi的最短路径长度
 */ 
void ShortestPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[])
{
	int v, w, i, j, min;
	Status final[MAX_VERTEX_NUM+1];					//标记当前结点是否已加入最短路径 
	
		//0号单元弃用 
	for(v=1; v<=G1.vexnum; v++)
	{
		final[v] = FALSE;							//final[v]为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径
		D1[v] = G1.arcs[v0][v].adj;
		
		for(w=1; w<=G1.vexnum; w++)					//P1[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点 
			P1[v][w] = FALSE;						//设空路径 
		
		if(D1[v]<INFINITY)
		{
			P1[v][v0] = TRUE;						//v跟v0连通时，v0肯定是v0到v上的点 
			P1[v][v] = TRUE;
		}
	}
	
	D1[v0] = 0;										//初始化，v0顶点属于S集
	final[v0] = TRUE;							 
		
			//开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集 
	for(i=2; i<=G1.vexnum; i++)					//其余G1.vexnum-1个顶点
	{
		min = INFINITY;							//当前所知离v0顶点的最近距离

		for(w=1; w<=G1.vexnum; w++)
		{
			if(!final[w])						//w顶点在V-S中
			{
			 	if(D1[w]<min)					//w顶点离v0顶点更近 
		 		{
	 				v = w;
	 				min = D1[w];				//选出当前状态下v0到各顶点距离的最小值vv 
				}				
			}
		}
			
		final[v] = TRUE;						//离v0顶点最近的v加入S集 
			
		for(w=1; w<=G1.vexnum; w++)				//更新当前最短路径及距离
		{
			if(!final[w] && min<INFINITY && G1.arcs[v][w].adj<INFINITY && (min + G1.arcs[v][w].adj < D1[w]))//修改D1[w]和P1[w],w∈V-S 
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
			printf("%c 到 %c 的最短路径为：", G1.vexs[v0], G1.vexs[order[i]]);
			
			if(!count[i])
				printf("×");
			else
			{
				for(j=1; j<=G1.vexnum; j++)
				{
					if(P1[order[i]][j])
						printf("%c ", G1.vexs[order[j]]);
				}
			}
			
			printf("，权值为：");
			if(D1[order[i]]<INFINITY)
				printf("%2d\n", D1[order[i]]);
			else
				printf("∞\n");
		}
	}		
}

void Dijkstra(MGraph G1, int v0, PathMatrix path1[], ShortPathTable dist1[])
{
	int set[MAX_VERTEX_NUM+1];
	int min, i, j, v;
	int tmp[MAX_VERTEX_NUM+1], k;
	
	for(i=1; i<=G1.vexnum; i++)					//数组初始化
	{
		dist1[i] = G1.arcs[v0][i].adj;			//dist1[i]：v0到i的最短路径长度 
		set[i] = 0;								//set[i]：标记数组，标记各顶点是否已加入路径 
		if(G1.arcs[v0][i].adj < INFINITY)
			path1[i] = v0;						//path1[i]：保存从v0到vi路径上vi的前一个顶点 
		else
			path1[i] = -1;						//代表v0到vi中间不经过任何顶点（可能不通，也可能是自身） 
	}
	
	set[v0] = 1;
	path1[v0] = -1;
	
	for(i=1; i<=G1.vexnum; i++)					//初始化结束，关键操作开始（判断其余G1.vexnum-1个顶点） 
	{
		min = INFINITY;
		
		for(j=1; j<=G1.vexnum; j++)				//选出v0到剩余顶点中最短的一条路径
		{
			if(!set[j] && dist1[j]<min)
			{
				v = j;
				min = dist1[j];					//v0到剩余顶点的最短路径<v0, v> 
			}
		}
			
		set[v] = 1;								//将顶点v加入最短路径
		
		for(j=1; j<=G1.vexnum; j++)				//判断v的加入是否会造就v0到剩余顶点的更短路径 
		{
			if(!set[j] && min<INFINITY &&  G1.arcs[v][j].adj<INFINITY && (min + G1.arcs[v][j].adj) < dist1[j])
			{
				dist1[j] = min + G1.arcs[v][j].adj;
				path1[j] = v;
			}
		}
	}
	
	//输出路径 
	for(i=1; i<=G1.vexnum; i++)
	{
		if(v0!=i)
		{
			printf("%c 到 %c 的路径为：", G1.vexs[v0], G1.vexs[i]);
			
			if(path1[i]==-1)
				printf("×");
			else
			{
				tmp[0] = 0;								//计数路径上的顶点个数 
	
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
				
			printf("，权长为：");
			if(dist1[i]==INFINITY)
				printf("∞\n");
			else
				printf("%2d\n", dist1[i]);
		}
	}	
} 

/*════╗
║算法7.16║ 
╚════*/
void ShortestPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1])
{
	int i, v, w, u;
	
	for(v=1; v<=G2.vexnum; v++)						//对各结点之间初始已知路径及距离 
	{
		for(w=1; w<=G2.vexnum; w++)
		{
			D2[v][w] = G2.arcs[v][w].adj;

			for(u=1; u<=G2.vexnum; u++)
				P2[v][w][u] = FALSE;

			if(D2[v][w]<INFINITY)					//从v到w有直接路径 
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
				if(v!=w && D2[v][u]<INFINITY && D2[u][w]<INFINITY && D2[v][u]+D2[u][w]<D2[v][w]) //从v经u到w的一条路径更短
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
				printf("%c 到 %c 的最短路径为：", G2.vexs[i], G2.vexs[j]);			

				if(!count[i][j])
					printf("×");
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
							tmp[0]++; //找到合适位置 
						}
					}
					
					printf("%c ", G2.vexs[i]);
					for(t=1; t<=tmp[0]; t++)
						printf("%c ", G2.vexs[tmp[t]]);
					printf("%c ", G2.vexs[j]);
				}
				
				printf("，权值为：");
				if(D2[i][j]<INFINITY)
					printf("%2d\n", D2[i][j]);
				else
					printf("∞\n");
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
	
	for(k=1; k<=G2.vexnum; k++)							//以k为中间点检测各对顶点间距离 
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
	
	//输出各对顶点之间路径 
	for(i=1; i<=G2.vexnum; i++)
	{
		for(j=1; j<=G2.vexnum; j++)
		{
			if(i!=j)
			{
				printf("%c 到 %c 的最短路径为：", G2.vexs[i], G2.vexs[j]);
				
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
					printf("×");
				
				printf("，权值为：");
				if(dist2[i][j]==INFINITY)
					printf("∞\n");
				else
					printf("%d\n", dist2[i][j]);
			}
		}
	}
}

#endif 
