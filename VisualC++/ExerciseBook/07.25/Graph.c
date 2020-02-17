/*=================================
 * 由题7.25的描述创建的一种有向图结构
 ==================================*/

#include "Graph.h"

// 录入数据的源文件；fp为null时，说明需要从控制台录入
static FILE* fp = NULL;


/*
 * 创建有向图
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
 * 创建有向图的核心算法
 */
static void Create(Graph* G) {
    int i, j, k;
    VertexType v1, v2;
    Boolean adjs[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {FALSE};   // 记录邻接点信息
    int cur;
    
    // 从控制台读取
    if(fp == NULL) {
        printf("请输入有向图的顶点数：");
        scanf("%d", &((*G).vexnum));
        printf("请输入有向图的弧数：");
        scanf("%d", &((*G).arcnum));
        
        // 录入顶点集
        printf("请录入 %d 个顶点，不同顶点之间用空格隔开：", (*G).vexnum);
        for(i = 0; i < (*G).vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(stdin);
            scanf("%c", &((*G).vexs[i]));
        }
        
        // 从文件读取
    } else {
        ReadData(fp, "%d", &((*G).vexnum)); // 录入顶点数
        ReadData(fp, "%d", &((*G).arcnum)); // 录入弧数
        
        // 录入顶点集
        for(i = 0; i < (*G).vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(fp);
            ReadData(fp, "%c", &((*G).vexs[i]));
        }
    }
    
    // 仅在控制台录入信息时输出此提示
    if(fp == NULL && (*G).arcnum != 0) {
        printf("请为有向图依次录入 %d 条弧的信息，顶点之间用空格隔开：\n", (*G).arcnum);
    }
    
    // 录入弧的信息
    for(k = 0; k < (*G).arcnum; k++) {
        if(fp == NULL) {
            printf("第 %2d 条弧：", k + 1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v2);
        } else {
            // 跳过空白，寻找下一个可读符号
            skipBlank(fp);
            ReadData(fp, "%c%c", &v1, &v2);
        }
        
        i = LocateVex(*G, v1);  // 获取顶点v1在顶点集中的位置
        j = LocateVex(*G, v2);  // 获取顶点v2在顶点集中的位置
        
        adjs[i][j] = TRUE;
    }
    
    cur = 0;
    
    // 记录邻接点信息
    for(i = 0; i < G->vexnum; i++) {
        G->fst[i] = -1;
        G->lst[i] = -2;
        
        for(j = 0; j < G->vexnum; j++) {
            if(adjs[i][j] == TRUE) {
                if(G->fst[i] == -1) {
                    G->fst[i] = cur;
                }
                
                G->s[cur++] = j;    // 存储后继顶点信息
            }
        }
        
        if(G->fst[i] != -1) {
            G->lst[i] = cur - 1;
        }
    }
}

/*
 * 查找
 *
 * 返回顶点u在有向图中的位置
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
 * 打印有向图结构
 */
void PrintGraph(Graph G) {
    int i, j;
    
    if(G.vexnum == 0) {
        printf("空图，无需打印！\n");
        return;
    }
    
    printf("当前有向图包含 %2d 个顶点， %2d 条弧...\n", G.vexnum, G.arcnum);
    
    for(i = 0; i < G.vexnum; i++) {
        printf("%c -> ", G.vexs[i]);
        for(j = G.fst[i]; j <= G.lst[i]; j++) {
            printf("%c ", G.vexs[G.s[j]]);
        }
        printf("\n");
    }
}
