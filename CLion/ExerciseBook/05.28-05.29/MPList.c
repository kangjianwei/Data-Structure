/*==========
 * m元多项式
 ===========*/

#include "MPList.h"

// 参见头文件中的声明
char Var[27];

/*
 * 创建
 *
 * 由字符串S创建m元多项P。
 * 不会校验S是否书写正确。
 *
 * P   : 待建的多项式
 * S   : 多项式字符串
 * vars: 变量列表，从第一元开始排列，比如xyz代表三元多项式中的未知数标记
 */
Status CreateMPList(MPList* P, char* S, char* vars) {
    if(P == NULL) {
        return ERROR;
    }
    
    // 清理字符串S中的空白，包括清理不可打印字符和清理空格
    ClearBlank(&S);
    
    if(strlen(S) == 0) {
        *P = NULL;
        return ERROR;
    }
    
    // 初始化元信息
    strcpy(Var, vars);
    
    *P = (MPList) malloc(sizeof(MPNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    
    (*P)->tag = List;
    (*P)->exp = (int) strlen(vars);
    (*P)->tp = NULL;
    
    Create(&(*P)->Node.hp, S);
    
    return OK;
}

/*
 * m元多项式创建函数
 */
static Status Create(MPList* P, char* S) {
    char* Sc;
    char* hhstr, * hstr, * str;
    char* sub;
    MPList r;
    float f;
    
    // 获取S的一个副本
    SubString(&Sc, S, 1, (int) strlen(S));
    
    *P = (MPList) malloc(sizeof(MPNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    
    (*P)->tag = List;
    (*P)->exp = (int) Sc[0];  // 记下未知数标记，例如x、y、z
    (*P)->Node.hp = NULL;
    (*P)->tp = NULL;
    
    StrDelete(&Sc, 1, 1);                           // 删掉未知数标记
    SubString(&str, Sc, 2, (int) strlen(Sc) - 2);   // 脱去最外层括号
    
    r = *P;
    
    while(!StrEmpty(str)) {
        // 拆分
        sever(&hstr, &str);
        
        SubString(&sub, hstr, 2, (int) strlen(hstr) - 2);   // 脱去最外层括号
        sever(&hhstr, &sub);
        
        // 建立子结点
        r->tp = (MPList) malloc(sizeof(MPNode));
        if(r->tp == NULL) {
            exit(OVERFLOW);
        }
        GetElem(hhstr, 1, &f);
        r->tp->exp = (int) f;  // 获取指数
        r->tp->tp = NULL;
        
        if(ElemCount(sub) == 1) {
            r->tp->tag = Atom;
            GetElem(sub, 1, &f);
            r->tp->Node.coef = f;
        } else {
            r->tp->tag = List;
            Create(&(r->tp->Node.hp), sub);
        }
        
        r = r->tp;
    }
    
    return OK;
}

/*
 * 图形化输出
 *
 * 带括号输出m元多项P。
 */
void PrintMPList(MPList P) {
    if(P == NULL) {
        printf("\n");
        return;
    }
    Print(P->Node.hp);
    printf("\n");
}

/*
 * 图形化输出的内部实现
 */
static void Print(MPList head) {
    MPList p;
    
    if(head == NULL) {
        return;
    }
    
    printf("%c(", head->exp);
    
    p = head->tp;
    
    while(p != NULL) {
        printf("(%d,", p->exp);
        
        if(p->tag == List) {
            Print(p->Node.hp);
        } else {
            printf("%.2f", p->Node.coef);
        }
        
        printf(")");
        
        p = p->tp;
        
        if(p != NULL) {
            printf(",");
        }
    }
    
    printf(")");
}

/*
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，且str【已经脱去最外层括号】。
 * 2.分离完成后，str也会发生变化
 */
static void sever(char** hstr, char** str) {
    int i, k, n;
    
    char* head, * tail;
    
    // str为空时，hstr也为空
    if(strlen(*str) == 0) {
        *hstr = NULL;
        return;
    }
    
    n = (int) strlen(*str);
    
    i = 0;  // 遍历字符串时的游标
    k = 0;  // 标记遇到的未配对括号数量
    
    do {
        if((*str)[i] == '(') {
            ++k;
        }
        
        if((*str)[i] == ')') {
            --k;
        }
        
        i++;
    } while(i < n && ((*str)[i] != ',' || k != 0));
    
    if(i < n) {
        head = (char*) malloc((i + 1) * sizeof(char));
        tail = (char*) malloc((n - i - 1 + 1) * sizeof(char));
        
        strncpy(head, *str, i);
        head[i] = '\0';
        
        strncpy(tail, (*str + i + 1), n - i - 1);
        tail[n - i - 1] = '\0';
    } else {
        head = *str;
        tail = (char*) malloc(sizeof(char));
        tail[0] = '\0';
    }
    
    *hstr = head;
    *str = tail;
}


/*
 * 复制多项式，从P复制到Q
 */
void Copy(MPList P, MPList* Q) {
    if(P == NULL) {
        *Q = NULL;
        return;
    }
    
    *Q = (MPList) malloc(sizeof(MPNode));
    (*Q)->tag = P->tag;
    (*Q)->exp = P->exp;
    
    if(P->tag == List) {
        Copy(P->Node.hp, &((*Q)->Node.hp));
    } else {
        (*Q)->Node.coef = P->Node.coef;
    }
    
    Copy(P->tp, &((*Q)->tp));
}
