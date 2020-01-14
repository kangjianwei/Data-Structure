#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "CTree.h"      //**▲06 树和二叉树**//

/*
 * 创建孩子链表(已考虑双亲结点)
 */
void Algo_6_75(CTree* T, FILE* fp);

// 创建树的内部实现，parent标记当前位置结点的双亲结点位置
void Create(CTree* T, int parent, FILE* fp);

/*
 * 按广义表方式打印孩子链表
 */
void Algo_6_76(CTree T, int i);


int main(int argc, char* argv[]) {
    FILE* fp;
    CTree T;
    
    printf("题 6.75 验证...\n");
    printf("创建孩子链表形式的树：\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_75(&T, fp);
    fclose(fp);
    PrintTree(T);
    printf("\n");
    
    printf("题 6.76 验证...\n");
    printf("按广义表方式打印孩子链表...\n");
    Algo_6_76(T, T.r);
    printf("\n");
    
    return 0;
}


/*
 * 创建孩子链表(已考虑双亲结点)
 */
void Algo_6_75(CTree* T, FILE* fp) {
    CTree CT;
    ChildPtr r;
    int mark[MAX_TREE_SIZE];
    int i, j, p;
    
    CT.r = 0;   // 将根结点默认设置到0号单元处
    CT.n = 0;   // 从0号单元开始存储
    Create(&CT, -1, fp);    // 此处创建出的树，其结点排列是先序的
    
    T->n = CT.n;
    T->r = 0;
    j = T->r;
    
    // 调整结点顺序为层序
    for(p = -1; p < CT.n; p++) {
        // 选出父结点为p的元素
        for(i = 0; i < CT.n; i++) {
            if(CT.nodes[i].parent == p) {
                T->nodes[j] = CT.nodes[i];
                mark[i] = j;    // 下标为i的元素移动到了新数组的下标j处
                j++;
            }
        }
    }
    
    // 下标更正
    for(i = 0; i < T->n; i++) {
        p = T->nodes[i].parent;
        if(p != -1) {
            // 修改parent域的下标
            T->nodes[i].parent = mark[p];
        }
    
        // 修改孩子链表中的元素下标
        for(r = T->nodes[i].firstchild; r != NULL; r = r->next) {
            r->child = mark[r->child];
        }
    }
}

// 创建树的内部实现，parent标记当前位置结点的双亲结点位置
void Create(CTree* T, int parent, FILE* fp) {
    char c;
    ChildPtr p, q;
    
    while(TRUE) {
        if(feof(fp) != 0) {
            break;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c >= 'A' && c <= 'Z') {
            T->nodes[T->n].data = c;            // T.n用来追踪结点个数
            T->nodes[T->n].parent = parent;
            T->nodes[T->n].firstchild = NULL;
            
            // 非根结点
            if(parent != -1) {
                // 创建孩子结点
                p = (ChildPtr) malloc(sizeof(CTNode));
                p->child = T->n;
                p->next = NULL;
                
                // 获取当前孩子结点的父结点的孩子链表
                q = T->nodes[parent].firstchild;
                
                // 父结点的孩子链表为空
                if(q == NULL) {
                    T->nodes[parent].firstchild = p;
                } else {
                    // 查找父结点孩子链表的尾部
                    while(q->next != NULL) {
                        q = q->next;
                    }
                    
                    // 向父结点的孩子链表插入该孩子结点
                    q->next = p;
                }
            }
            
            T->n++;
        } else if(c == '(') {
            Create(T, T->n - 1, fp);  // T.n-1结点的第一个孩子
            
        } else if(c == ',') {
            Create(T, parent, fp);    // 创建兄弟结点
            break;
        } else {
            break;
        }
    }
}

/*
 * 按广义表方式打印孩子链表
 */
void Algo_6_76(CTree T, int i) {
    ChildPtr p;
    
    if(!T.n) {
        return;
    }
    
    // 打印双亲结点
    printf("%c", T.nodes[i].data);
    
    if(T.nodes[i].firstchild) {
        printf("(");
        
        // 遍历孩子结点
        for(p = T.nodes[i].firstchild; p; p = p->next) {
            Algo_6_76(T, p->child);
            
            // 存在下一个孩子
            if(p->next != NULL) {
                printf(",");
            }
        }
        
        printf(")");
    }
}
