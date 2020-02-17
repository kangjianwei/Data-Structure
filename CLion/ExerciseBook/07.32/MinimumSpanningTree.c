/*===================
 * 无向网的最小生成森林
 ===================*/

#include "MinimumSpanningTree.h"

/*
 * 普里姆算法中用到的辅助数组，
 * 用来记录从顶点子集U到顶点子集V-U的代价最小的边
 */
static struct {
    VertexType adjvex;      // 顶点子集U中的顶点
    int lowcost;            // 顶点子集V-U到当前顶点adjvex的边的权值
} closedge[MAX_VERTEX_NUM]; // 辅助数组


/*
 * 使用普里姆算法构造无向网G的最小生成森林
 */
CSTree MinSpanTree_PRIM(ALGraph G) {
    int i, j, k;
    ArcNode* p;
    CSTree r;
    CSTree T = NULL;
    CSTree curRoot = NULL;                  // 追踪森林中子树的根结点
    CSTree parent[MAX_VERTEX_NUM] = {NULL}; // 追踪各顶点在森林中的位置(用指针指向该顶点)
    
    // 辅助数组初始化：初始化所有权值为0
    for(j=0; j<G.vexnum; j++) {
        closedge[j].lowcost = INT_MAX;
    }
    
    // 这里从0开始遍历，因为一开始并未指定哪个顶点作为首棵树的根
    for(i = 0; i < G.vexnum; i++) {
        // 从顶点子集V-U中选出下一个候选顶点以便后续加入到最小生成树
        k = minimum(G);
    
        r = (CSTree) malloc(sizeof(CSNode));
        r->firstchild = r->nextsibling = NULL;
        
        // 出现了新的子树
        if(k==-1) {
            printf("----------\n");
            
            // 确定森林中子树的根
            for(k=0; k<G.vexnum; k++) {
                if(closedge[k].lowcost==INT_MAX) {
                    r->data = G.vertices[k].data;
                    parent[k] = r;
                    
                    if(curRoot==NULL) {
                        T = curRoot = r;
                    } else {
                        // 链接到森林中下一棵树
                        curRoot->nextsibling = r;
                        curRoot = r;
                    }
                    
                    break;
                }
            }
        } else {
            r->data = G.vertices[k].data;
            
            // 获取父结点在图中的序号
            j = LocateVex(G, closedge[k].adjvex);
            if(parent[j]->firstchild==NULL) {
                parent[j]->firstchild = r;
            } else {
                // 直接采用头插法即可
                r->nextsibling = parent[j]->firstchild->nextsibling;
                parent[j]->firstchild->nextsibling = r;
            }
    
            parent[k] = r;
            
            // 打印顶点和边的信息
            printf("%c --%2d-- %c\n", closedge[k].adjvex, closedge[k].lowcost, G.vertices[k].data);
        }
        
        // 将顶点k加入到顶点子集U
        closedge[k].lowcost = 0;
    
        // 新顶点进入顶点子集U后，需要更新顶点子集U与顶点子集V-U的边的信息
        for(p=G.vertices[k].firstarc; p!=NULL; p = p->nextarc) {
            j = p->adjvex;
    
            if(p->info->weight<closedge[j].lowcost) {
                closedge[j].adjvex = G.vertices[k].data;
                closedge[j].lowcost = p->info->weight;
            }
        }
    }
    
    return T;
}

/*
 * 从顶点子集V-U中选出下一个候选顶点以便后续加入到最小生成树
 *
 * 选择顶点子集U到顶点子集V-U的权值最小的边，
 * 并返回该边在顶点子集V-U中那头的端点，
 * 该端点后续会加入到顶点子集U中，成为最小生成树的新结点。
 */
static int minimum(ALGraph G) {
    int i, k = -1;
    int min = INT_MAX;
    
    // 从权值不为0的边中选择拥有最小权值的边
    for(i = 0; i < G.vexnum; i++) {
        if(closedge[i].lowcost != 0 && closedge[i].lowcost < min) {
            min = closedge[i].lowcost;
            k = i;
        }
    }
    
    return k;
}
