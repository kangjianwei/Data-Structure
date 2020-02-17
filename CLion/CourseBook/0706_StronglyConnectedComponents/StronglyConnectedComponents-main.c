#include <stdio.h>
#include "OLGraph.h"
#include "StronglyConnectedComponents.h"

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
    }
    PressEnterToContinue(debug);
    
    printf("████████ Tarjan算法求取强连通分量... \n");
    {
        Tarjan(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ Kosaraju算法求取强连通分量... \n");
    {
        Kosaraju(G);
    }
    PressEnterToContinue(debug);
    
    return 0;
}
