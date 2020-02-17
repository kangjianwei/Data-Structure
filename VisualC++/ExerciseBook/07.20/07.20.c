#include <stdio.h>
#include "Status.h"  //**▲01 绪论**//
#include "MGraph.h"  //**▲07 图**//

/*
 * 判断图G是否可传递
 */
Status Algo_7_20(MGraph G);


int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并输出图...\n");
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
    
    Algo_7_20(G) ? printf("图G可传递！\n") : printf("图G不可传递！\n");
    printf("\n");
    
    return 0;
}


/*
 * 判断图G是否可传递
 */
Status Algo_7_20(MGraph G) {
    Status trans;
    int x, y, z;
    int flag;   // 不连通的标记
    
    // 对于图，不连通标记是0
    if(G.kind == DG || G.kind == UDG) {
        flag = 0;
        
        // 对于网，不连通标记是INFINITE
    } else if(G.kind == DN || G.kind == UDN) {
        flag = INFINITE;
    } else {
        return ERROR;
    }
    
    // 预设为可传递
    trans = TRUE;
    
    // 对于V中每个x
    for(x = 0; x < G.vexnum; x++) {
        // N(x)中每个y
        for(y = 0; y < G.vexnum; y++) {
            if(G.arcs[x][y].adj != flag) {
                // N(y)中不等于x的每个z
                for(z = 0; z < G.vexnum; z++) {
                    if(G.arcs[y][z].adj != flag && z != x) {
                        // z不在N(x)中
                        if(G.arcs[x][z].adj == flag) {
                            // 不可传递
                            trans = FALSE;
                            return trans;
                        }
                    }
                }
            }
        }
    }
    
    return trans;
}
