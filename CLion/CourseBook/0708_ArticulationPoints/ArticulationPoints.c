/*====================
 * 无向图的关节点
 *
 * 包含算法: 7.10、7.11
 =====================*/

#include "ArticulationPoints.h"


/* 全局变量 */
static int count;  // 访问计数
static int visited[MAX_VERTEX_NUM];    // 访问标志数组，记录访问过的顶点次序
static int low[MAX_VERTEX_NUM];        // low[v] ==> 以结点v为根的树可以直接回溯的最早祖先位置
static Boolean found[MAX_VERTEX_NUM] = {FALSE};  // 记录已经找到并输出过的关节点，初始时全部初始化为FALSE


/*
 * ████████ 算法7.10 ████████
 *
 * 查找并输出G上全部关节点
 *
 * 核心思想是深度优先遍历+回溯，与本章第6节求强连通分量的算法有类似之处
 */
void FindArticul(ALGraph G) {
    int i, v;
    ArcNode* p;
    
    count = 1;          // 对访问过的结点计数
    
    visited[0] = 1;     // 设定邻接表上的0号顶点为生成树的根
    
    // 其余顶点尚未访问
    for(i = 1; i < G.vexnum; i++) {
        visited[i] = 0;
    }
    
    // 指向0号顶点的长子
    p = G.vertices[0].firstarc;
    
    // 记下长子结点在图的顶点集中的位置
    v = p->adjvex;
    
    // 从第v顶点触发，通过深度优先遍历查找关节点
    DFSArticul(G, v);
    
    // 如果访问过的结点数量小于该图总结点数量，说明生成树的根有至少两棵子树
    if(count < G.vexnum) {
        if(found[0] == FALSE) {
            // 根是关节点的情形下，输出根
            printf("%c ", G.vertices[0].data);
            found[0] = TRUE;
        }
        
        // 依次遍历根结点的其他子树
        while(p->nextarc != NULL) {
            p = p->nextarc;
            v = p->adjvex;
            
            if(visited[v] == 0) {
                DFSArticul(G, v);
            }
        }
    }
}

/*
 * ████████ 算法7.11 ████████
 *
 * 从第v个顶点出发深度优先遍历图G，查找并输出所有关节点注：由于这里的图是无向图，因此术语孩子、祖先的含义是相对的
 */
void DFSArticul(ALGraph G, int v) {
    int min;    // 暂存结点v可回溯的最早祖先的访问序号
    int w;
    ArcNode* p;
    
    visited[v] = min = ++count; // v是第count个访问的顶点
    
    // 遍历结点v的所有孩子
    for(p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {
        // 获取该孩子在图的顶点集中的位置
        w = p->adjvex;
        
        // 如果作为v结点孩子的w结点未被访问过
        if(visited[w] == 0) {
            // 递归从第w顶点出发，查找关节点
            DFSArticul(G, w);
            
            /*
             * w子树处理访问完成
             *
             * 如果结点w的可回溯祖先小于当前结点的可回溯祖先,
             * 换句话说，v的孩子中有结点可以回溯到更早的祖先，
             * 此时需要更新v结点存储的可回溯祖先的访问序号
             */
            if(low[w] < min) {
                min = low[w];
            }
            
            /*
             * 如果v结点的孩子中，可回溯祖先的序号在v结点自身(包括自身)的访问序号之后，
             * 则说明v结点是关节点，因为删掉v结点后，v的孩子与v的祖先将失去联系
             *
             * 注:教材这一步有个BUG：当v是多棵子树的关节点时，每次从那些子树中返回都会打印一次结点v的信息
             * 　 因此，这里做了改进，新增一个found数组来记录已经找到并输出过的结点
             */
            if(low[w] >= visited[v]) {
                // 对于已经输出过的结点，不再打印
                if(found[v] == FALSE) {
                    printf("%c ", G.vertices[v].data);
                    found[v] = TRUE;
                }
            }
            
            // 遇到已访问过的结点
        } else {
            // 如果w已被访问过，且w是v在生成树上的祖先
            if(visited[w] < min) {
                // 记录w结点的可回溯祖先
                min = visited[w];
            }
        }
    } //for
    
    // 更新结点v的可回溯祖先的访问序号
    low[v] = min;
}
