/*==================
 * 无向网的最小生成树
 *
 * 包含算法: 7.9
 ==================*/

#include "MinimumSpanningTree.h"

/*
 * 使用克鲁斯卡尔算法求取最小生成树
 */
CSTree MinSpanTree_KRUSKAL(Graph G) {
    int k;
    int v1, v2;
    int s1, s2;
    
    CSTree T = NULL;
    CSTree parent[MAX_VERTEX_NUM] = {NULL}; // 追踪各顶点在树中的位置(用指针指向该顶点)
    SqQueue queue;
    int root;
    
    // 记录已经加入到最小生成树的顶点集，这里使用集合的目的是快速判断候选顶点是否会造成环路
    MFSet S;
    Relation relation;
    
    // 存储有向网边集的一个副本
    EdgeSetType* EdgeSet;
    
    // 存储最小生成树中包含的边集
    EdgeSetType* tree;
    EdgeSetType edge;
    
    // 复制有向网的边集
    EdgeSet = (EdgeSetType*) malloc((G.EdgeSet[0].weight * sizeof(EdgeSetType)));
    for(k = 0; k <= G.EdgeSet[0].weight; k++) {
        EdgeSet[k] = G.EdgeSet[k];  // 结构体可以直接复制
    }
    
    // 最小生成树中包含的边的数量为顶点数-1，但这里多分配了一个单元，因为0号单元要存储边的数量
    tree = (EdgeSetType*) malloc(G.vexnum * sizeof(EdgeSetType));
    tree[0].weight = 0;
    
    // 初始化顶点集合
    initial_mfset(&S, G.vexnum);
    
    // 从边集中依次选择权值最小，且不构成环路的边加入到最小生成树
    for(k = 0; k < G.arcnum; k++) {
        // 选出一条权值最小的边
        GetMinEdge(EdgeSet, &v1, &v2);
        // 选完之后就可以从边集的副本中删掉这条边了，因为后续不再需要它
        DelMinEdge(EdgeSet, v1, v2);
        
        s1 = find_mfset(S, v1);
        s2 = find_mfset(S, v2);
        
        // 如果这两个端点位于同一个集合，则跳过该条边
        if(s1 == s2) {
            continue;
        }
        
        // 构造二元关系
        relation.n = 1;
        relation.pairs[0].i = v1;
        relation.pairs[0].j = v2;
        
        build_mfset(&S, relation);
        
        // 打印顶点和边的信息
        printf("%c %c\n", G.vexs[v1], G.vexs[v2]);
        
        // 创建树结点v1
        if(parent[v1] == NULL) {
            parent[v1] = (CSTree) malloc(sizeof(CSNode));
            parent[v1]->data = G.vexs[v1];
            parent[v1]->firstchild = parent[v1]->nextsibling = NULL;
        }
        
        // 创建树结点v2
        if(parent[v2] == NULL) {
            parent[v2] = (CSTree) malloc(sizeof(CSNode));
            parent[v2]->data = G.vexs[v2];
            parent[v2]->firstchild = parent[v2]->nextsibling = NULL;
        }
        
        // 向集合中存储构成最小生成树的边
        tree[0].weight++;
        tree[tree[0].weight].u = v1;
        tree[tree[0].weight].v = v2;
    }
    
    
    /* 接下来使用已知的边来构造树的孩子-兄弟链表存储结构 */
    
    if(tree[0].weight<=0) {
        return NULL;
    }
    
    InitQueue(&queue);
    
    // 确定整棵树的根结点
    T = parent[tree[1].u];
    
    // 追踪每棵子树的根结点
    root = tree[1].u;
    
    while(tree[0].weight > 0) {
        // 查找包含端点root的边
        for(k = 1; k <= tree[0].weight; k++) {
            if(tree[k].u == root || tree[k].v == root) {
                break;
            }
        }
        
        // 找到了这样的边
        if(k <= tree[0].weight) {
            edge = tree[k];
            
            // 移除这条边，此处只是用最后一条边的信息简单地覆盖这条边的信息
            tree[k] = tree[tree[0].weight];
            tree[0].weight--;
            
            if(edge.u == root) {
                // 把结点v添加为结点u的一个孩子结点，这里简单地使用头插法
                parent[edge.v]->nextsibling = parent[edge.u]->firstchild;
                parent[edge.u]->firstchild = parent[edge.v];
                
                EnQueue(&queue, edge.v);
            } else {
                // 把结点u添加为结点v的一个孩子结点，这里简单地使用头插法
                parent[edge.u]->nextsibling = parent[edge.v]->firstchild;
                parent[edge.v]->firstchild = parent[edge.u];
    
                EnQueue(&queue, edge.u);
            }
        } else {
            // 获取新的子树的root
            DeQueue(&queue, &root);
        }
    }
    
    return T;
}
