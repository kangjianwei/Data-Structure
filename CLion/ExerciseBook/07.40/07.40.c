#include <stdio.h>
#include <limits.h>
#include "SqList.h"
#include "ALGraph.h"

/*
 * 获取存储在有向无环图中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.23
 */
void Algo_7_40(ALGraph G, SqList* RPN);

/*
 * 从顶点v出发获取有向图中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 */
static void AntiPolandFormula_7_40(ALGraph G, int v, SqList* RPN);

/*
 * 计算逆波兰式的值
 */
int Evaluation_7_40(SqList RPN);


int main(int argc, char* argv[]) {
    ALGraph G;
    SqList RPN;     // 存储逆波兰表达式
    
    printf("████████ 创建并打印有向网... \n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "";
        path[2] = "";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 求取有向网中存储的表达式的逆波兰式... \n");
    {
        Algo_7_40(G, &RPN);
        printf("\n");
    }
    
    printf("████████ 计算逆波兰式的值... \n");
    {
        printf("计算上述逆波兰式的值为：%d\n", Evaluation_7_40(RPN));
        printf("\n");
    }
    
    return 0;
}


/*
 * 获取存储在有向无环图中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.23
 */
void Algo_7_40(ALGraph G, SqList* RPN) {
    int i, root;
    int indegree[MAX_VERTEX_NUM];   // 所有顶点的入度信息
    ArcNode* p;
    ElemType e;
    
    // 初始化所有顶点的入度为0
    for(i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;
    }
    
    // 遍历所有顶点
    for(i = 0; i < G.vexnum; i++) {
        // 指向该顶点的首个邻接点
        p = G.vertices[i].firstarc;
        
        // 遍历该顶点的所有邻接点，统计各顶点的入度
        while(p != NULL) {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    
    // 查找到根结点
    for(i = 0; i < G.vexnum; i++) {
        if(indegree[i] == 0) {
            root = i;
            break;
        }
    }
    
    // 初始化长度为0的线性表
    InitList(RPN);
    
    // 从有向无环图的根结点出发，通过尾递归获取到其中存储的表达式的逆波兰式
    AntiPolandFormula_7_40(G, root, RPN);
    
    // 输出逆波兰式
    for(i = 1; i <= ListLength(*RPN); i++) {
        GetElem(*RPN, i, &e);
        
        if(e.type == Operand) {
            printf("%d ", e.op);    // 操作数
        } else {
            printf("%c ", e.op);    // 操作符
        }
    }
    printf("\n");
}

/*
 * 从顶点v出发获取有向图中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 */
void AntiPolandFormula_7_40(ALGraph G, int v, SqList* RPN) {
    ArcNode* r;
    Vertex vex;
    
    // 先遍历邻接点
    for(r = G.vertices[v].firstarc; r != NULL; r = r->nextarc) {
        AntiPolandFormula_7_40(G, r->adjvex, RPN);
    }
    
    // 获取操作符/操作数
    vex = G.vertices[v].context;
    
    // 当没有邻接点可遍历时，存储该顶点
    ListInsert(RPN, ListLength(*RPN) + 1, vex);
}

/*
 * 计算逆波兰式的值，如果发生错误，返回INT_MIN。
 */
int Evaluation_7_40(SqList RPN) {
    int stack[MAX_VERTEX_NUM];  // 模拟一个栈，用来存储表达式的计算结果
    int top = 0; // 栈顶游标
    int a, b;
    ElemType e;
    int i;
    Boolean hasError = FALSE;   // 计算过程中出现了错误
    
    for(i = 1; i <= ListLength(RPN) && !hasError; i++) {
        GetElem(RPN, i, &e);
        
        // 操作数
        if(e.type == Operand) {
            stack[top++] = e.op;
            
            // 操作符
        } else {
            if(top > 0) {
                b = stack[--top];
            } else {
                return INT_MIN;
            }
            
            if(top > 0) {
                a = stack[--top];
            } else {
                return INT_MIN;
            }
            
            switch(e.op) {
                case '+':
                    stack[top++] = a + b;
                    break;
                case '-':
                    stack[top++] = a - b;
                    break;
                case '*':
                    stack[top++] = a * b;
                    break;
                case '/':
                    stack[top++] = a / b;
                    break;
                default:
                    printf("无法识别的操作符：%c\n", e.op);
                    hasError = TRUE;
                    break;
            }
        }
    }
    
    // 栈中最后只应该剩一个值
    if(hasError || top != 1) {
        return INT_MIN;
    }
    
    return stack[0];
}
