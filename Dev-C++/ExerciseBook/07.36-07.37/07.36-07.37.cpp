#include <stdio.h>
#include "Status.h"             //**▲01 绪论**//
#include "ALGraph.h"            //**▲07 图**//
#include "TopologicalSorting.h" //**▲07 图**//

/*
 * 求有向无环图各顶点的最长路径。
 *
 * 可以借助其拓扑序列，从后向前遍历各顶点来计算最长路径，
 * 原理是对于任一顶点出发的最长路径p1，其邻接点的最长路径p2也必定在最长路径p1上，
 * 即：某顶点的最长路径 = max{邻接点的最长路径}
 *
 * 这里没有将MPL域直接写在ALGraph结构中，而是将其单独作为一个数组取声明，在核心算法上没有任何区别。
 */
void Algo_7_36(ALGraph G, int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1]);

/*
 * 打印各顶点的最长路径
 */
static void PrintPath_7_36(ALGraph G, int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1]);

/*
 * 求取有向无环图的最长路径
 */
void Algo_7_37(ALGraph G, int mpl[MAX_VERTEX_NUM + 1]);


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并输出图...\n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "";
        path[2] = "";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 题7.36：求取有向无环图各顶点的最长路径...\n");
    {
        int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1];
        
        Algo_7_36(G, MPL);
        PrintPath_7_36(G, MPL);
        printf("\n");
    }
    
    printf("████████ 题7.37：求取有向无环图中的最长路径...\n");
    {
        int mpl[MAX_VERTEX_NUM + 1];
        int i;
        
        Algo_7_37(G, mpl);
        for(i = 1; i <= mpl[0] + 1; i++) {
            printf("%c ", G.vertices[mpl[i]].data);
        }
        printf("\n");
    }
    
    return 0;
}


/*
 * 求有向无环图各顶点的最长路径。
 *
 * 可以借助其拓扑序列，从后向前遍历各顶点来计算最长路径，
 * 原理是对于任一顶点出发的最长路径p1，其邻接点的最长路径p2也必定在最长路径p1上，
 * 即：某顶点的最长路径长度 = max{邻接点的最长路径长度} + 1
 *
 * 这里没有将MPL域直接写在ALGraph结构中，而是将其单独作为一个数组取声明，在核心算法上没有任何区别。
 */
void Algo_7_36(ALGraph G, int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1]) {
    int i, j, v, w;
    int max, k;
    int topo[MAX_VERTEX_NUM];
    ArcNode* p;
    
    if(TopologicalSort(G, topo) == ERROR) {
        printf("给定的有向图存在回路，无法获取其拓扑序列...\n");
        return;
    }
    
    // 逆序遍历拓扑序列
    for(i = G.vexnum - 1; i >= 0; i--) {
        v = topo[i];
        
        MPL[v][0] = 0;  // 0号单元存储路径长度
        MPL[v][1] = v;  // 1号单元存储路径的起始顶点序号
        
        p = G.vertices[v].firstarc;
        
        // 对于没有邻接点的顶点，其最长路径长度为0，无需再研究下去
        if(p == NULL) {
            continue;
        }
        
        max = -1;   // 邻接点中最大路径长度
        k = -1;     // 记录拥有最大路径长度的邻接点的序号
        
        // 遍历邻接点
        while(p != NULL) {
            w = p->adjvex;  // 邻接点序号
            
            // 如果有多条相同长度的路径，则只取首先发现的一条
            if(MPL[w][0] > max) {
                max = MPL[w][0];
                k = w;
            }
            
            p = p->nextarc;
        }
        
        // 顶点最长路径长度 =  max{邻接点的最长路径长度} + 1
        MPL[v][0] = max + 1;
        
        // 将邻接点出发的最长路径复制到当前顶点的最长路径上
        for(j = 1; j <= max + 1; j++) {
            MPL[v][j + 1] = MPL[k][j];
        }
    }
}

/*
 * 打印各顶点的最长路径
 */
static void PrintPath_7_36(ALGraph G, int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1]) {
    int i, j;
    
    for(i = 0; i < G.vexnum; i++) {
        printf("从顶点 %c 出发的最长路径为：", G.vertices[i].data);
        for(j = 1; j <= MPL[i][0] + 1; j++) {
            printf("%c ", G.vertices[MPL[i][j]].data);
        }
        printf("\n");
    }
}

/*
 * 求取有向无环图的最长路径
 */
void Algo_7_37(ALGraph G, int mpl[MAX_VERTEX_NUM + 1]) {
    int MPL[MAX_VERTEX_NUM][MAX_VERTEX_NUM + 1];
    int i, max, k;
    
    // 求取所有顶点的最长路径
    Algo_7_36(G, MPL);
    
    max = -1;
    
    for(i = 0; i < G.vexnum; i++) {
        if(MPL[i][0] > max) {
            max = MPL[i][0];
            k = i;
        }
    }
    
    for(i = 0; i <= MPL[k][0] + 1; i++) {
        mpl[i] = MPL[k][i];
    }
}
