#include <stdio.h>
#include "ALGraph.h"
#include "ShortestPaths.h"

/*
 * 使用Dijkstra算法计算从单源顶点出发的最短路径
 */
void Algo_7_42(ALGraph G, int v0, PathMatrix_DIJ P, ShortPathTable_DIJ D);


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并打印无向图/网... \n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "TestData_DN.txt";
        path[2] = "TestData_UDG.txt";
        path[3] = "TestData_UDN.txt";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 迪杰斯特拉算法求单源最短路径... \n");
    {
        VertexType v0 = 'A';
        PathMatrix_DIJ P;
        ShortPathTable_DIJ D;
    
        printf("输出从顶点 %c 到其余顶点的最短路径：\n", v0);
        Algo_7_42(G, LocateVex(G, v0), P, D);
        printf("\n");
    }
}


/*
 * 使用Dijkstra算法计算从单源顶点出发的最短路径
 */
void Algo_7_42(ALGraph G, int v0, PathMatrix_DIJ P, ShortPathTable_DIJ D) {
    
    // ★★必须首先调用此函数计算各顶点之间的关系
    GetAdjs(G);
    
    // 最短路径算法
    ShortestPath_DIJ(G, v0, P, D);
    
    // 打印计算出的结果（此步骤可选）
    PrintPath_DIJ(G, v0, P, D);
}
