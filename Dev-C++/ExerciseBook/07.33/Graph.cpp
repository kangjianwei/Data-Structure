/*=================================
 * 由题7.33的描述创建的一种无向网结构
 ==================================*/

#include "Graph.h"

// 录入数据的源文件；fp为null时，说明需要从控制台录入
static FILE* fp = NULL;


/*
 * 创建无向网
 *
 * path为NULL或为""时，从控制台读取图的初始化信息。
 * 否则，从预设的文件中读取图的初始化信息。
 */
Status CreateGraph(Graph* G, char* path) {
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    // 需要从文件读取
    if(!readFromConsole) {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
    }
    
    Create(G);
    
    if(fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
    
    return OK;
}

/*
 * 创建无向网的核心算法
 */
static void Create(Graph* G) {
    int u, v, k;
    VertexType v1, v2;
    int weight;
    
    // 从控制台读取
    if(fp == NULL) {
        printf("请输入无向网的顶点数：");
        scanf("%d", &((*G).vexnum));
        printf("请输入无向网的边数：");
        scanf("%d", &((*G).arcnum));
        
        // 录入顶点集
        printf("请录入 %d 个顶点，不同顶点之间用空格隔开：", (*G).vexnum);
        for(k = 0; k < (*G).vexnum; k++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(stdin);
            scanf("%c", &((*G).vexs[k]));
        }
        
        // 从文件读取
    } else {
        ReadData(fp, "%d", &((*G).vexnum)); // 录入顶点数
        ReadData(fp, "%d", &((*G).arcnum)); // 录入边数
        
        // 录入顶点集
        for(k = 0; k < (*G).vexnum; k++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(fp);
            ReadData(fp, "%c", &((*G).vexs[k]));
        }
    }
    
    // 仅在控制台录入信息时输出此提示
    if(fp == NULL && (*G).arcnum != 0) {
        printf("请为无向网依次录入 %d 条边的信息，顶点与权值之间用空格隔开：\n", (*G).arcnum);
    }
    
    // 构造边集结构，0号单元存储边的数量
    (*G).EdgeSet = (EdgeSetType*) malloc(((*G).arcnum + 1) * sizeof(EdgeSetType));
    if((*G).EdgeSet == NULL) {
        exit(ERROR);
    }
    
    // EdgeSet的0号单元存储了无向网中边的数量
    (*G).EdgeSet[0].weight = (*G).arcnum;
    
    // 录入边的信息
    for(k = 0; k < (*G).arcnum; k++) {
        if(fp == NULL) {
            printf("第 %2d 条边与权值：", k + 1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v2);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%d", &weight);
        } else {
            // 跳过空白，寻找下一个可读符号
            skipBlank(fp);
            ReadData(fp, "%c%c%d", &v1, &v2, &weight);
        }
        
        u = LocateVex(*G, v1);  // 获取顶点v1在顶点集中的位置
        v = LocateVex(*G, v2);  // 获取顶点v2在顶点集中的位置
        
        (*G).EdgeSet[k + 1].u = u;
        (*G).EdgeSet[k + 1].v = v;
        (*G).EdgeSet[k + 1].weight = weight;
    }
}

/*
 * 查找
 *
 * 返回顶点u在无向网中的位置
 */
int LocateVex(Graph G, VertexType u) {
    int i;
    
    for(i = 0; i < G.vexnum; i++) {
        if(G.vexs[i] == u) {
            return i;
        }
    }
    
    return -1;
}

/*
 * 从边集EdgeSet中获取最小边的顶点u和v，并返回TRUE。
 * 若边集为空，则返回FASLE。
 */
Boolean GetMinEdge(EdgeSetType* EdgeSet, int* u, int* v) {
    int i, j, k;
    int min = INT_MAX;  // 记录权值的最大值
    
    // 边集为空
    if(EdgeSet[0].weight == 0) {
        return FALSE;
    }
    
    // 查找权值最小的边
    for(k = 1; k <= EdgeSet[0].weight; k++) {
        if(EdgeSet[k].weight < min) {
            min = EdgeSet[k].weight;
            i = EdgeSet[k].u;
            j = EdgeSet[k].v;
        }
    }
    
    // 记录顶点信息
    *u = i;
    *v = j;
    
    return TRUE;
}

/*
 * 从边集中删除依附于顶点u和v的最小边。
 * 删除成功返回TRUE，否则，返回FALSE。
 */
Boolean DelMinEdge(EdgeSetType* EdgeSet, int u, int v) {
    int k;
    Boolean found = FALSE;  // 是否找到了边<u, v>
    
    // 边集为空
    if(EdgeSet[0].weight == 0) {
        return FALSE;
    }
    
    // 先查找该条边在边集中的位置
    for(k = 1; k <= EdgeSet[0].weight; k++) {
        if((EdgeSet[k].u == u && EdgeSet[k].v == v) || (EdgeSet[k].u == v && EdgeSet[k].v == u)) {
            found = TRUE;
            break;
        }
    }
    
    if(found == FALSE) {
        return FALSE;
    }
    
    // 这里采用的删除方式是直接用最后一条边的信息覆盖待删除边的信息
    EdgeSet[k] = EdgeSet[EdgeSet[0].weight];
    EdgeSet[0].weight--;
    
    return TRUE;
}

/*
 * 打印无向网结构
 */
void PrintGraph(Graph G) {
    int i, j, k, w;
    int adjs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    
    if(G.vexnum == 0) {
        printf("空图，无需打印！\n");
        return;
    }
    
    // 初始化边的信息
    for(i = 0; i < G.vexnum; i++) {
        for(j = 0; j < G.vexnum; j++) {
            adjs[i][j] = INFINITE;
        }
    }
    
    // 构造边集矩阵
    for(k = 1; k <= G.EdgeSet[0].weight; k++) {
        i = G.EdgeSet[k].u;
        j = G.EdgeSet[k].v;
        w = G.EdgeSet[k].weight;
        
        adjs[i][j] = adjs[j][i] = w;
    }
    
    printf("当前无向网包含 %2d 个顶点， %2d 条边...\n", G.vexnum, G.arcnum);
    
    printf("  ");
    for(i = 0; i < G.vexnum; i++) {
        printf("  %c", G.vexs[i]);
    }
    printf("\n");
    
    for(i = 0; i < G.vexnum; i++) {
        printf("%c ", G.vexs[i]);
        
        for(j = 0; j < G.vexnum; j++) {
            if(adjs[i][j] == INFINITE) {
                printf("  -");
            } else {
                printf("%3d", adjs[i][j]);
            }
        }
        
        printf("\n");
    }
}
