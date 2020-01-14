/*============================
 * 广义表的头尾链表存储表示
 *
 * 包含算法: 5.5、5.6、5.7、5.8
 =============================*/

#include "GList-HT.h"                        //**▲05 数组和广义表**//

/*
 * 初始化
 *
 * 初始化空的广义表，长度为0，深度为1。
 *
 *【注】
 * 需要对每一层去掉括号考察
 */
Status InitGList(GList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    *L = NULL;
    
    return OK;
}

/*
 * ████████ 算法5.7 ████████
 *
 * 创建
 *
 * 由字符串S创建广义表L。
 */
Status CreateGList(GList* L, SString S) {
    SString emp;        // 代表空广义表的字符串
    SString hsub, sub;
    GList p, q;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // 清理字符串S中的空白，包括清理不可打印字符和清理空格
    ClearBlank(S);
    
    if(StrEmpty(S)) {
        return ERROR;
    }
    
    StrAssign(emp, "()");
    
    /*
     * 如果输入串为()，则代表需要创建空的广义表
     *
     *【注】
     * 教材这里的代码是有问题的。
     * StrCompare的返回值指示的是两个字符串的大小，而不是指示两个字符串是否相等。
     * 如果给定的S与()相等，返回值应当是0。
     */
    if(!StrCompare(S, emp)) {
        *L = NULL;
    } else {
        *L = (GList) malloc(sizeof(GLNode));
        if(*L == NULL) {
            exit(OVERFLOW);
        }
        
        // 创建原子
        if(StrLength(S) == 1) {
            (*L)->tag = Atom;
            (*L)->Node.atom = S[1];
        } else {
            (*L)->tag = List;
            
            p = *L;
            
            // 去掉最外层括号
            SubString(sub, S, 2, StrLength(S) - 2);
            
            // 重复建n个子表
            do {
                // 从sub中分离出表头串hsub，分离完成后，sub也会发生变化
                sever(hsub, sub);
                
                // 递归创建广义表
                CreateGList(&(p->Node.ptr.hp), hsub);
                
                q = p;
                
                // 如果表尾不为空，需要继续处理表尾
                if(!StrEmpty(sub)) {
                    p = (GList) malloc(sizeof(GLNode));
                    if(p == NULL) {
                        exit(OVERFLOW);
                    }
                    
                    p->tag = List;
                    
                    q->Node.ptr.tp = p;
                }
            } while(!StrEmpty(sub));
            
            q->Node.ptr.tp = NULL;
        }
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
    
    // 删除原子结点
    if((*L)->tag == Atom) {
        free(*L);
        *L = NULL;
        
        // 删除子表结点
    } else {
        head = (*L)->Node.ptr.hp;
        tail = (*L)->Node.ptr.tp;
        free(*L);
        *L = NULL;
        DestroyGList(&head);
        DestroyGList(&tail);
    }
    
    return OK;
}

/*
 * ████████ 算法5.6 ████████
 *
 * 复制
 *
 * 由广义表L复制得到广义表T。
 */
Status CopyGList(GList* T, GList L) {
    if(T == NULL) {
        return ERROR;
    }
    
    if(L == NULL) {
        *T = NULL;
    } else {
        // 新建广义表结点
        *T = (GList) malloc(sizeof(GLNode));
        if(*T == NULL) {
            exit(OVERFLOW);
        }
        
        (*T)->tag = L->tag;
        
        // 复制单原子
        if(L->tag == Atom) {
            (*T)->Node.atom = L->Node.atom;
            
            // 复制表头和表尾
        } else {
            CopyGList(&((*T)->Node.ptr.hp), L->Node.ptr.hp);
            CopyGList(&((*T)->Node.ptr.tp), L->Node.ptr.tp);
        }
    }
    
    return OK;
}

/*
 * 计数
 *
 * 返回广义表的长度。
 */
int GListLength(GList L) {
    int count;
    
    for(count = 0; L != NULL; count++, L = L->Node.ptr.tp) {
    }
    
    return count;
}

/*
 * ████████ 算法5.5 ████████
 *
 * 深度
 *
 * 返回广义表的深度
 */
int GListDepth(GList L) {
    int max, deep;
    GList p;
    
    // 空表深度为1
    if(L == NULL) {
        return 1;
    }
    
    // 原子深度为0
    if(L->tag == Atom) {
        return 0;
    }
    
    // 递归求子表深度
    for(max = 0, p = L; p != NULL; p = p->Node.ptr.tp) {
        deep = GListDepth(p->Node.ptr.hp);
        if(deep > max) {
            max = deep;
        }
    }
    
    // 非空表的深度是各子元素最大深度加一
    return max + 1;
}

/*
 * 判空
 *
 * 判断广义表是否为空。
 */
Status GListEmpty(GList L) {
    return L == NULL ? TRUE : FALSE;
}

/*
 * 表头
 */
GList GetHead(GList L) {
    GList p;
    
    // 空表无表头，这里不能返回NULL，不然分不清是失败了还是返回了空表
    if(L == NULL) {
        exit(ERROR);
    }
    
    CopyGList(&p, L->Node.ptr.hp);
    
    return p;
}

/*
 * 表尾
 */
GList GetTail(GList L) {
    GList p;
    
    // 空表无表尾，这里不能返回NULL，不然分不清是失败了还是返回了空表
    if(L == NULL) {
        exit(ERROR);
    }
    
    CopyGList(&p, L->Node.ptr.tp);
    
    return p;
}

/*
 * 插入
 *
 * 将元素e插入为广义表L的第一个元素。
 */
Status InsertFirst(GList* L, GList e) {
    GList g;
    
    if(L == NULL) {
        return ERROR;
    }
    
    g = (GList) malloc(sizeof(GLNode));
    if(g == NULL) {
        exit(OVERFLOW);
    }
    
    g->tag = List;
    g->Node.ptr.hp = e;
    g->Node.ptr.tp = *L;
    *L = g;
    
    return OK;
}

/*
 * 删除
 *
 * 将广义表L的第一个元素删除，并用e返回。
 */
Status DeleteFirst(GList* L, GList* e) {
    GList p;
    
    // 空表无法删除
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    p = *L;
    *L = (*L)->Node.ptr.tp;
    
    CopyGList(e, p->Node.ptr.hp);
    
    free(p);
    
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
    
    if(L->tag == Atom) {
        Visit(L->Node.atom);
    } else {
        Traverse(L->Node.ptr.hp, Visit);
        Traverse(L->Node.ptr.tp, Visit);
    }
    
}

/*
 * 图形化输出
 *
 * 带括号输出广义表L。
 */
void PrintGList(GList L) {
    Print(L, Head);
    printf("\n");
}

/*
 * 图形化输出的内部实现，mark是图形化输出标记。
 */
static void Print(GList L, Mark mark) {
    // L为空
    if(L == NULL) {
        if(mark == Head) {
            printf("(");
        }
        
        printf(")");
        
        // L不为空时
    } else {
        // 对于原子结点，输出原子
        if(L->tag == Atom) {
            printf("%c", L->Node.atom);
            
            // 对于子表结点，要对表头、表尾分别讨论
        } else {
            if(mark == Head) {
                printf("(");
            } else {
                printf(",");
            }
            
            Print(L->Node.ptr.hp, Head);
            Print(L->Node.ptr.tp, Tail);
        }
    }
}

/*
 * ████████ 算法5.8 ████████
 *
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，且str【已经脱去最外层括号】。
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
    
    // 如果存在多个广义表结点
    if(i < n) {
        SubString(hstr, str, 1, i - 1);
        SubString(str, str, i + 1, n - i);
        
        // 只有一个广义表结点
    } else {
        StrCopy(hstr, str);
        ClearString(str);
    }
}
