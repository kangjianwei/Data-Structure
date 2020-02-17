/*==================
 * 无向图的生成树
 *
 * 包含算法: 7.7、7.8
 ===================*/

#include "SpanningTree.h"


// 访问标志数组，记录访问过的顶点
Boolean visited[MAX_VERTEX_NUM];


/*
 * ████████ 算法7.7 ████████
 *
 * 构造无向图的生成树(森林)
 */
void DFSForest(MGraph G, CSTree* T) {
    int v;
    CSTree p, q;
    
    InitTree(T);
    
    for(v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE;
    }
    
    for(v = 0; v < G.vexnum; v++) {
        // 跳过已访问过的顶点
        if(visited[v]) {
            continue;
        }
        
        p = (CSTree) malloc(sizeof(CSNode));    // 分配根结点
        if(!p) {
            exit(OVERFLOW);
        }
        p->data = GetVex(G, v);
        p->firstchild = p->nextsibling = NULL;
    
        if(!(*T)) {                            // 是第一棵生成树的根
            *T = p;
        } else {                               // 是其他生成树的根（前一棵树根的兄弟）
            q->nextsibling = p;
        }
    
        q = p;                                 // q指示当前生成树的根
        
        DFSTree(G, v, &p);                     // 建立以p为根的生成树
    }
}

/*
 * ████████ 算法7.8 ████████
 *
 * 通过深度优先遍历各结点，构造结点v起始的树
 */
void DFSTree(MGraph G, int v, CSTree* T) {
    Status first;
    int w;
    CSTree p, q;
    
    visited[v] = TRUE;
    first = TRUE;
    
    // for循环的意义在于找出v结点的所有孩子
    for(w = FirstAdjVex(G, G.vexs[v]); w>=0; w = NextAdjVex(G, G.vexs[v], G.vexs[w])) {
        // 跳过已访问过的顶点
        if(visited[w]) {
            continue;
        }
    
        // 构造孩子结点
        p = (CSTree) malloc(sizeof(CSNode));
        if(!p) {
            exit(OVERFLOW);
        }
        p->data = GetVex(G, w);
        p->firstchild = p->nextsibling = NULL;
        
        // 如果是第一个孩子
        if(first) {
            (*T)->firstchild = p;
            first = FALSE;
            
            // 如果不是第一个孩子，则添加为兄弟结点
        } else {
            q->nextsibling = p;
        }
        
        q = p;
        
        DFSTree(G, w, &q);
    }
}
