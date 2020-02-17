#include <stdio.h>
#include "Status.h"   //**▲01 绪论**//
#include "ALGraph.h"  //**▲07 图**//

/*
 * 判断图G是否可传递
 */
Status Algo_7_21(ALGraph G);


int main(int argc, char* argv[]) {
    ALGraph G;
    
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
    
    Algo_7_21(G) ? printf("图G可传递！\n") : printf("图G不可传递！\n");
    printf("\n");
    
    return 0;
}


/*
 * 判断图G是否可传递
 */
Status Algo_7_21(ALGraph G) {
    Status trans;
    int x, y, z;
    ArcNode* py, * pz, * px;
    
    // 预设为可传递
    trans = TRUE;
    
    // 对于V中每个x
    for(x = 0; x < G.vexnum; x++) {
        // N(x)中每个y
        for(py = G.vertices[x].firstarc; py != NULL; py = py->nextarc) {
            y = py->adjvex;
            
            for(pz = G.vertices[y].firstarc; pz != NULL; pz = pz->nextarc) {
                z = pz->adjvex;
                
                // 排除与x相等的z
                if(z != x) {
                    for(px = G.vertices[x].firstarc; px != NULL; px = px->nextarc) {
                        if(px->adjvex == z) {
                            break;  // 找到z后及时跳出
                        }
                    }
                    
                    // 如果z不在N(x)中
                    if(px == NULL) {
                        trans = FALSE;
                        return trans;
                    }
                }
                
            }
        }
    }
    
    return trans;
}
