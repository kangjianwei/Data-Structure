#include <stdio.h>
#include "OLGraph.h"
#include "StronglyConnectedComponents.h"

/*
 * 求有向图的强连通分量
 */
void Algo_7_31(OLGraph G);


int main(int argc, char* argv[]) {
    OLGraph G;
    
    printf("████████ 创建并打印有向图... \n");
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
    
    printf("████████ 求有向图的强连通分量... \n");
    {
        Algo_7_31(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 求有向图的强连通分量
 */
void Algo_7_31(OLGraph G) {
    printf("Tarjan算法：\n");
    Tarjan(G);
    
//    printf("Kosaraju算法：\n");
//    Kosaraju(G);
}
