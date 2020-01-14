/*===========================
 * 广义表的扩展线性链表存储表示
 ============================*/

#include "GList-E.h"            //**▲05 数组和广义表**//

/*
 * 初始化
 *
 * 初始化空的广义表，长度为0，深度为1。
 *
 *【注】
 * 需要对每一层带上括号考察
 */
Status InitGList(GList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    *L = (GList) malloc(sizeof(GLNode));
    if(!*L) {
        exit(OVERFLOW);
    }
    
    (*L)->tag = List;
    (*L)->Node.hp = NULL;
    (*L)->tp = NULL;
    
    return OK;
}

/*
 * 创建
 *
 * 由字符串S创建广义表L。
 */
Status CreateGList(GList* L, SString S) {
    SString emp, hsub, sub, tmp;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // 清理字符串S中的空白，包括清理不可打印字符和清理空格
    ClearBlank(S);
    
    if(StrEmpty(S)) {
        return ERROR;
    }
    
    // 复制是为了不破坏S
    StrCopy(sub, S);
    
    /*
     * 初次执行到此时，带着最外层的括号
     * 再次执行到此时，已经脱去了外层括号
     */
    sever(hsub, sub);
    
    *L = (GList) malloc(sizeof(GLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    StrAssign(emp, "()");
    
    if(!StrCompare(hsub, emp)) {
        (*L)->tag = List;
        (*L)->Node.hp = NULL;
    } else {
        if(StrLength(hsub) == 1) {
            (*L)->tag = Atom;
            (*L)->Node.atom = hsub[1];
        } else {
            (*L)->tag = List;
            
            SubString(tmp, hsub, 2, StrLength(hsub) - 2);
            
            CreateGList(&((*L)->Node.hp), tmp);
        }
    }
    
    // 如果不存在队尾，则退出本层递归
    if(StrEmpty(sub)) {
        (*L)->tp = NULL;
    } else {
        // 继续递归求表尾
        CreateGList(&((*L)->tp), sub);
    }
    
    return OK;
}

/*
 * 销毁
 *
 * 释放广义表所占内存。
 */
Status DestroyGList(GList* L) {
    GList head, tail;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // 处理子表结点
    if((*L)->tag == List) {
        head = (*L)->Node.hp;  // 表头
        tail = (*L)->tp;       // 表尾
        
        free(*L);
        *L = NULL;
        
        // 递归处理表头
        if(head != NULL) {
            DestroyGList(&head);
        }
        
        // 递归处理表尾
        if(tail != NULL) {
            DestroyGList(&tail);
        }
        
        // 处理原子结点
    } else {
        tail = (*L)->tp;    // 表尾
        
        free(*L);
        *L = NULL;
        
        if(tail != NULL) {
            DestroyGList(&tail);
        }
    }
    
    return OK;
}

/*
 * 复制
 *
 * 由广义表L复制得到广义表T。
 */
Status CopyGList(GList* T, GList L) {
    
    if(L == NULL) {
        return ERROR;
    }
    
    *T = (GList) malloc(sizeof(GLNode));
    if(*T == NULL) {
        exit(OVERFLOW);
    }
    
    // 复制原子
    if(L->tag == Atom) {
        (*T)->tag = Atom;
        (*T)->Node.atom = L->Node.atom;
        
        // 复制子表
    } else {
        (*T)->tag = List;
        
        // 复制表头
        if(L->Node.hp != NULL) {
            CopyGList(&((*T)->Node.hp), L->Node.hp);
        } else {
            (*T)->Node.hp = NULL;
        }
    }
    
    // 复制表尾
    if(L->tp != NULL) {
        CopyGList(&((*T)->tp), L->tp);
    } else {
        (*T)->tp = NULL;
    }
    
    return OK;
}

/*
 * 计数
 *
 * 返回广义表的长度。
 */
int GListLength(GList L) {
    int count = 0;
    GList p;
    
    // 广义表不存在
    if(L == NULL) {
        return -1;
    }
    
    p = L->Node.hp;
    
    while(p != NULL) {
        ++count;
        p = p->tp;
    }
    
    return count;
}

/*
 * 深度
 *
 * 返回广义表的深度
 */
int GListDepth(GList L) {
    int max, deep;
    GList p;
    
    max = 0;
    
    // 广义表不存在
    if(L == NULL) {
        return -1;
    }
    
    // 空表深度为1
    if(L->tag == List && !L->Node.hp) {
        return 1;
    }
    
    // 原子深度为0
    if(L->tag == Atom) {
        return 0;
    }
    
    // 递归求子表深度
    for(p = L->Node.hp; p != NULL; p = p->tp) {
        // 求以p为头指针的子表深度
        deep = GListDepth(p);
        if(deep > max) {
            max = deep;
        }
    }
    
    return max + 1;
}

/*
 * 判空
 *
 * 判断广义表是否为空。
 */
Status GListEmpty(GList L) {
    // 广义表不存在
    if(L == NULL) {
        return ERROR;
    }
    
    if(L->tag == List && L->Node.hp == NULL && L->tp == NULL) {
        return TRUE;
    } else {
        return ERROR;
    }
}

/*
 * 表头
 */
GList GetHead(GList L) {
    GList p, q;
    
    // 广义表不存在或广义表为空表，无法获取表头
    if(L == NULL || L->Node.hp == NULL) {
        return NULL;
    }
    
    q = L->Node.hp->tp;         // 临时保存L的表尾信息
    L->Node.hp->tp = NULL;      // 截去L的表尾部分
    
    CopyGList(&p, L->Node.hp);  // 复制表头信息（已屏蔽表尾）
    
    L->Node.hp->tp = q;         // 恢复L的表尾信息
    
    return p;
}

/*
 * 表尾
 */
GList GetTail(GList L) {
    GList p, q;
    
    // 广义表不存在或广义表为空表，无法获取表尾
    if(L == NULL || L->Node.hp == NULL) {
        return NULL;
    }
    
    q = L->Node.hp;         // 临时保存L的表头信息
    L->Node.hp = q->tp;     // 摘下L的表头部分
    
    CopyGList(&p, L);       // 复制表尾信息（已屏蔽表头）
    
    q->tp = L->Node.hp;     // 恢复L的表头信息
    L->Node.hp = q;
    
    return p;
}

/*
 * 插入
 *
 * 将元素e插入为广义表L的第一个元素。
 */
Status InsertFirst(GList* L, GList e) {
    
    // 广义表不存在
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    if(e == NULL) {
        return ERROR;
    }
    
    e->tp = (*L)->Node.hp;
    (*L)->Node.hp = e;
    
    return OK;
}

/*
 * 删除
 *
 * 将广义表L的第一个元素删除，并用e返回。
 */
Status DeleteFirst(GList* L, GList* e) {
    GList p;
    
    // 广义表不存在或广义表为空表，则无法删除表头
    if(*L == NULL || (*L)->Node.hp == NULL) {
        return ERROR;
    }
    
    p = (*L)->Node.hp;
    (*L)->Node.hp = p->tp;
    p->tp = NULL;
    
    *e = p;
    
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问广义表L。
 */
void Traverse(GList L, void(Visit)(AtomType)) {
    if(L == NULL) {
        return;
    }
    
    if(L->tag == List) {
        Traverse(L->Node.hp, Visit);
    } else {
        Visit(L->Node.atom);
    }
    
    Traverse(L->tp, Visit);
}

/*
 * 图形化输出
 *
 * 带括号输出广义表L。
 */
void PrintGList(GList L) {
    Print(L);
    printf("\n");
}

/*
 * 图形化输出的内部实现。
 */
static void Print(GList L) {
    if(L == NULL) {
        return;
    }
    
    // 处理表结点
    if(L->tag == List) {
        printf("(");
        
        if(L->Node.hp) {
            Print(L->Node.hp);
        }
        
        if(L->tp) {
            printf("),");
            Print(L->tp);
        } else {
            printf(")");
        }
        
        // 处理原子结点
    } else {
        printf("%c", L->Node.atom);
        if(L->tp) {
            printf(",");
            Print(L->tp);
        }
    }
}

/*
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，
 *   但str外层的括号可能脱去，也可能未脱去。
 * 2.分离完成后，str也会发生变化
 */
static void sever(SString hstr, SString str) {
    int i, k, n;
    SString ch;
    
    n = StrLength(str);
    
    i = 0;  // 遍历字符串时的游标
    k = 0;  // 标记遇到的未配对括号数量
    
    do {
        ++i;
        
        // 截取str第一个字符
        SubString(ch, str, i, 1);
        
        if(ch[1] == '(') {
            ++k;
        }
        if(ch[1] == ')') {
            --k;
        }
    } while(i < n && (ch[1] != ',' || k != 0));
    
    if(i < n) {
        SubString(hstr, str, 1, i - 1);
        SubString(str, str, i + 1, n - i);
    } else {
        StrCopy(hstr, str);
        ClearString(str);
    }
}
