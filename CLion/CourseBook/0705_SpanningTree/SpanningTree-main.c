#include <stdio.h>
#include "MGraph.h"
#include "SpanningTree.h"

int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并打印无向图... \n");
    {
        char* path[4];
    
        path[0] = "";
        path[1] = "";
        path[2] = "TestData_UDG.txt";
        path[3] = "";
    
        CreateGraph(&G, path);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ DFSForest、DFSTree \n");
    {
        CSTree T;
        
        printf("构造无向图的生成树（森林）... \n");
        DFSForest(G, &T);
        PrintTree(T);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}
