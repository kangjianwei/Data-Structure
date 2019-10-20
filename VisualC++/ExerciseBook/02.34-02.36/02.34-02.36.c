#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>
#include "Status.h"     //**▲01 绪论**//

// 异或指针链表元素
typedef char XElemType;

// 异或指针链表结点结构
typedef struct XorNode {
    XElemType data;
    struct XorNode* LRPtr;
} XorNode;
typedef XorNode* XorPointer;

// 无头结点的异或指针双向链表的头尾指针
typedef struct {
    XorPointer Left;    // 分别指向链表的最左端（头指针）和最右端（尾指针）
    XorPointer Right;
} XorLinkedList;


/*
 * 题2.34——方法一：借助PriorOrNext函数遍历链表
 *
 * 输出L，mark表示输出方向：0，从左向右输出，1，从右向左输出
 */
void Algo_2_34_1(XorLinkedList L, int mark);

/*
 * 题2.34——方法二：【不】借助PriorOrNext函数遍历链表
 *
 * 输出L，mark表示输出方向：0，从左向右输出，1，从右向左输出
 */
void Algo_2_34_2(XorLinkedList L, int mark);

/*
 * 题2.35
 *
 * 将元素e插入到第i个结点之前
 */
Status Algo_2_35(XorLinkedList* L, int i, XElemType e);

/*
 * 题2.36
 *
 * 删除第i(>0)个结点，并用e接受结点中元素值
 */
Status Algo_2_36(XorLinkedList* L, int i, char* e);

// 指针异或函数，返回指针p和q的异或值（异或运算：p^q）
XorPointer XorP(XorPointer p, XorPointer q);

// 创建异或指针链表L
Status Create(XorLinkedList* L, XElemType elems[], int n);

// 获取当前结点(cur)的前驱(mark=0)或后继(mark=1)
XorPointer PriorOrNext(XorLinkedList L, XorPointer cur, int mark);


int main(int argc, char** argv) {
    XorLinkedList L;
    XElemType e;
    XElemType* data = "123456789";
    
    Create(&L, data, strlen(data));
    printf("████████ 题 2.34 验证...\n");
    printf("█ 正向输出 L = ");
    Algo_2_34_1(L, 0);
    printf("█ 逆向输出 L = ");
    Algo_2_34_1(L, 1);
    
    printf("████████ 题 2.35 验证...\n");
    Algo_2_35(&L, 5, '*');
    printf("█ 插入 '*' 为L的第5个结点后顺序输出...\n");
    printf("█ 正向输出 L = ");
    Algo_2_34_2(L, 0);
    
    printf("████████ 题 2.36 验证...\n");
    Algo_2_36(&L, 5, &e);
    printf("█ 删除L的第5个结点 '%c' 后逆序输出...\n", e);
    printf("█ 逆向输出 L = ");
    Algo_2_34_2(L, 1);
    
    return 0;
}


// 异或运算：p^q
XorPointer XorP(XorPointer p, XorPointer q) {
    unsigned long x, y, z;
    
    x = (unsigned long) p;
    y = (unsigned long) q;
    
    // 求异或
    z = x ^ y;
    
    return (XorPointer) z;
}

// 创建异或指针链表L
Status Create(XorLinkedList* L, XElemType elems[], int n) {
    int i;
    XorPointer pre_l, pre_m, pre_r; // 准备三个指针，指向链表中紧邻的三个结点
    
    (*L).Left = NULL;
    (*L).Right = NULL;
    
    pre_l = pre_m = NULL;
    
    for(i = 0; i < n; i++) {
        pre_r = (XorPointer) malloc(sizeof(XorNode));
        if(pre_r == NULL) {
            exit(OVERFLOW);
        }
        pre_r->data = elems[i];
        
        // 左指针（创建首结点时设立）
        if(i == 0) {
            L->Left = pre_r;
        }
        
        // 右指针，指向最后一个结点
        L->Right = pre_r;
        
        // 有新结点加入时，上一个结点的指针域需要作出修改
        if(pre_m != NULL) {
            pre_m->LRPtr = XorP(pre_l, pre_r);
        }
        
        pre_r->LRPtr = XorP(pre_m, NULL);
        pre_l = pre_m;
        pre_m = pre_r;
    }
    
    return OK;
}

// 获取当前结点(cur)的前驱(mark=0)或后继(mark=1)
XorPointer PriorOrNext(XorLinkedList L, XorPointer cur, int mark) {
    XorPointer p_l, p_m, p_r;
    
    if(mark != 1 && mark != 0) {
        return NULL;
    }
    
    // 确保链表存在
    if(L.Left == NULL || L.Right == NULL || cur == NULL) {
        return NULL;
    }
    
    // 求后继，从左向右
    if(mark == 1) {
        p_l = NULL;
        p_m = L.Left;
        
        // 指针不断向右推进
        while(p_m != cur) {
            p_r = XorP(p_l, p_m->LRPtr);    //计算右侧第一个结点地址
            p_l = p_m;
            p_m = p_r;
        }
        
        // p_m指向cur的前驱
        p_r = XorP(p_l, p_m->LRPtr);
        
        return p_r;
        
        // 求前驱，从右向左
    } else {
        p_m = L.Right;
        p_r = NULL;
        
        // 指针不断向左推进
        while(p_m != cur) {
            p_l = XorP(p_m->LRPtr, p_r);    //计算左侧第一个结点地址
            p_r = p_m;
            p_m = p_l;
        }
        
        // p_m指向cur的后继
        p_l = XorP(p_m->LRPtr, p_r);
        
        return p_l;
    }
}

// 输出L，mark表示输出方向：0，从左向右输出，1，从右向左输出
void Algo_2_34_1(XorLinkedList L, int mark) {
    XorPointer cur;
    
    if(mark != 1 && mark != 0) {
        return;
    }
    
    // 确保链表存在
    if(L.Left == NULL || L.Right == NULL) {
        return;
    }
    
    // 从左向右输出
    if(mark == 0) {
        cur = L.Left;
        do {
            printf("%c ", cur->data);
            // 获取cur的后继
            cur = PriorOrNext(L, cur, 1);
        } while(cur != NULL);
        
        // 从右向左输出
    } else {
        cur = L.Right;
        do {
            printf("%c ", cur->data);
            // 获取cur的前驱
            cur = PriorOrNext(L, cur, 0);
        } while(cur != NULL);
    }
    
    printf("\n");
}

// 输出L，mark表示输出方向：0，从左向右输出，1，从右向左输出
void Algo_2_34_2(XorLinkedList L, int mark) {
    XorPointer p_l, p_m, p_r;
    
    if(mark != 1 && mark != 0) {
        return;
    }
    
    // 确保链表存在
    if(L.Left == NULL || L.Right == NULL) {
        return;
    }
    
    // 从左向右输出
    if(mark == 0) {
        p_l = NULL;
        p_m = L.Left;
        
        // p_m为空时说明已输出完毕
        while(p_m != NULL) {
            printf("%c ", p_m->data);
            p_r = XorP(p_l, p_m->LRPtr);    // 计算右侧第一个结点地址
            p_l = p_m;                      // 指针不断向后推进
            p_m = p_r;
        }
        
        // 从右向左输出
    } else {
        p_m = L.Right;
        p_r = NULL;
        
        // p_m为空时说明已输出完毕
        while(p_m != NULL) {
            printf("%c ", p_m->data);
            p_l = XorP(p_m->LRPtr, p_r);    // 计算左侧第一个结点地址
            p_r = p_m;                      // 指针不断向前推进
            p_m = p_l;
        }
    }
    
    printf("\n");
}

// 将元素e插入到第i个结点之前
Status Algo_2_35(XorLinkedList* L, int i, XElemType e) {
    XorPointer pl;  // 指向第i-2个结点
    XorPointer pre; // 指向第i-1个结点
    XorPointer p;   // 指向第i个结点
    XorPointer pr;  // 指向第i+1个结点
    XorPointer s;
    int j;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // i>=1
    if(i < 1) {
        return ERROR;
    }
    
    // 创建新结点
    s = (XorPointer) malloc(sizeof(XorNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    
    // 先处理链表为空的情形
    if((*L).Left == NULL && (*L).Right == NULL) {
        if(i != 1) {
            return ERROR;   // 链表为空时，i只能为1
        }
        
        (*L).Left = (*L).Right = s;
        s->LRPtr = NULL;
        
        return OK;
    }
    
    j = 0;
    pre = NULL;
    p = (*L).Left;
    
    // 查找第i-1个结点，且由pre指向它
    while(j < i - 1 && p != NULL) {
        j++;
        pr = XorP(pre, p->LRPtr);
        pre = p;
        p = pr;
    }
    
    // i值不合规（过大）
    if(j < i - 1) {
        return ERROR;
    }
    
    // 需要插入到链表尾部
    if(p == NULL) {
        pl = XorP(pre->LRPtr, p);
        pre->LRPtr = XorP(pl, s);
        
        s->LRPtr = XorP(pre, p);
        
        (*L).Right = s;
        
        return OK;
    }
    
    // 需要插入到链表的头部
    if(pre == NULL) {
        pr = XorP(pre, p->LRPtr);
        p->LRPtr = XorP(s, pr);
        
        s->LRPtr = XorP(pre, p);
        
        (*L).Left = s;
        
        return OK;
    }
    
    // 其他情形
    pl = XorP(pre->LRPtr, p);
    pr = XorP(pre, p->LRPtr);
    pre->LRPtr = XorP(pl, s);
    p->LRPtr = XorP(s, pr);
    s->LRPtr = XorP(pre, p);
    
    return OK;
}

// 删除第i(>0)个结点，并用e接受结点中元素值
Status Algo_2_36(XorLinkedList* L, int i, XElemType* e) {
    XorPointer pl;  // 指向第i-2个结点
    XorPointer pre; // 指向第i-1个结点
    XorPointer p;   // 指向第i个结点
    XorPointer pr;  // 指向第i+1个结点
    XorPointer prr; // 指向第i+2个结点
    int j;
    
    if(L == NULL || (*L).Left == NULL || (*L).Right == NULL) {
        return ERROR;
    }
    
    // i>=1
    if(i < 1) {
        return ERROR;
    }
    
    // 先处理只有一个结点的情形
    if((*L).Left == (*L).Right) {
        if(i != 1) {
            return ERROR;   // 链表只有一个结点时，i只能为1
        }
        
        *e = (*L).Left->data;
        (*L).Left = (*L).Right = NULL;
        
        return OK;
    }
    
    j = 0;
    pre = NULL;
    p = (*L).Left;
    
    // 查找第i-1个结点，且由pre指向它
    while(j < i - 1 && p != NULL) {
        j++;
        pr = XorP(pre, p->LRPtr);
        pre = p;
        p = pr;
    }
    
    // i值不合规（过大）
    if(j < i - 1 || p == NULL) {
        return ERROR;
    }
    
    // 存储被删元素的值
    *e = p->data;
    
    /* 至此，至少有两个元素存在，且p指向被删除元素 */
    
    pr = XorP(pre, p->LRPtr);
    
    // 删除头结点
    if(pre == NULL) {
        // 由于此时至少有两个结点，故pr!=NULL
        prr = XorP(p, pr->LRPtr);
        
        pr->LRPtr = XorP(pre, prr);
    
        (*L).Left = pr;
    } else {
        pl = XorP(pre->LRPtr, p);
        pre->LRPtr = XorP(pl, pr);
    
        // 删除最后一个结点
        if(pr==NULL) {
            (*L).Right = pre;
        } else {
            prr = XorP(p, pr->LRPtr);
            pr->LRPtr = XorP(pre, prr);
        }
    }
    
    free(p);
    
    return OK;
}
