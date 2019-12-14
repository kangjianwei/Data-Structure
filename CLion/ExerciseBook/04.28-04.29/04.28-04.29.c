#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"             //**▲01 绪论**//

/*
 * 单链表元素类型定义
 *
 *【注】
 * 这里的链表虽然用作字符串，但是元素类型仍然用int，原因是：
 * 1.需要借用头结点存储结点的数量，所以用int比直接用char合适
 * 2.char可以与int兼容，所以结点虽然是int，但也可以用来存储char
 */
typedef int ElemType;

/* 字符串结点 */
typedef struct SNode {
    ElemType chdata;        // 数据结点
    struct SNode* succ;  // 指向后继结点
    struct SNode* next;  // next在主串中，指向前驱结点，在模式串中，指向该结点处失配时应当参与比较的下一个结点
} SNode;

// 字符串
typedef SNode* String;


// 初始化
Status StrAssign_4_28(String* S, char* chars);

// 求串长
int StrLength_4_28(String S);

// 字符串输出
void StrPrint_4_28(String S);

/*
 * 计算模式串的next值（改进后的算法）
 *
 * 功能相当于KMP算法那章的get_nextval函数
 */
Status Algo_4_28(String T);

/*
 * KMP算法
 *
 * 功能相当于KMP算法那章的Index_KMP函数
 */
int Algo_4_29(String S, String T, int pos);


int main(int argc, char* argv[]) {
    char* s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
    char* t = "abaabcac";
    String S, T;
    int pos, i;
    
    StrAssign_4_28(&S, s);  //主串
    StrAssign_4_28(&T, t);  //模式串
    
    printf("主　串：S = ");
    StrPrint_4_28(S);
    printf("模式串：T = ");
    StrPrint_4_28(T);
    
    printf("███题 4.28 验证...███\n");
    Algo_4_28(T);
    printf("创建next表...\n");
    
    printf("███题 4.29 验证...███\n");
    pos = 18;
    i = Algo_4_29(S, T, pos);
    printf("模式串 T 从主串 S 的第 %d 个字符起第一次匹配成功的位置为 %d\n", pos, i);
    
    return 0;
}


// 初始化
Status StrAssign_4_28(String* S, char* chars) {
    int i, len;
    String p;
    
    if(S == NULL || chars == NULL) {
        return ERROR;
    }
    
    len = (int) strlen(chars);
    
    // 创建头结点
    *S = (String) malloc(sizeof(SNode));
    (*S)->chdata = len; // 记录串的长度
    (*S)->next = NULL;  // 头结点的前驱
    
    p = *S;
    
    for(i = 0; i < len; i++) {
        p->succ = (String) malloc(sizeof(SNode));
        p->succ->chdata = chars[i];
        p->succ->next = p;          // next默认指向前一个结点
        p = p->succ;
    }
    
    // 最后一个结点的后继为NULL
    p->succ = NULL;
    
    return OK;
}

// 求串长
int StrLength_4_28(String S) {
    return S == NULL ? 0 : S->chdata;
}

// 字符串输出
void StrPrint_4_28(String S) {
    String p;
    
    if(S == NULL) {
        printf("\n");
        return;
    }
    
    for(p = S->succ; p != NULL; p = p->succ) {
        printf("%c", p->chdata);
    }
    
    printf("\n");
}

/*
 * 计算模式串的next值（改进后的算法）
 *
 * 功能相当于KMP算法那章的get_nextval函数
 */
Status Algo_4_28(String T) {
    SNode* i, * j;
    
    if(StrLength_4_28(T) == 0) {
        return ERROR;
    }
    
    i = T->succ;    // 相当于之前的i=1
    j = T;          // 相当于之前的j=0
    
    // 模式串第一个字符处失配时，模式串需要从头比较，主串需要前进到下一个位置比较
    i->next = T;
    
    // 遍历模式串上的字符
    while(i->succ != NULL) {
        if(j == T || i->chdata == j->chdata) {
            i = i->succ;
            j = j->succ;
            
            if(i->chdata != j->chdata) {
                i->next = j;
            } else {
                i->next = j->next;
            }
        } else {
            j = j->next;
        }
    }
    
    return OK;
}

/*
 * KMP算法
 *
 * 功能相当于KMP算法那章的Index_KMP函数
 */
int Algo_4_29(String S, String T, int pos) {
    int count;        // 记录i的位置
    SNode* i, * j;    // i遍历S，j遍历T
    
    if(pos < 1 || StrLength_4_28(S) == 0 || StrLength_4_28(T) == 0) {
        return 0;
    }
    
    for(count = 1, i = S->succ; count < pos; count++, i = i->succ) {
        // 用i指向第pos个结点
    }
    
    j = T->succ;
    
    // 比较字符串
    while(i != NULL && j != NULL) {
        /*
         * 两种情形：
         * 1.在模式串的第一个字符处就失配
         * 2.主串和模式串处的字符相等
         */
        if(j == T || i->chdata == j->chdata) {
            i = i->succ;
            j = j->succ;
            
            count++;        // 记录i的位置
        } else {
            // 失配时回到前一个适当的位置
            j = j->next;
        }
    }
    
    // 匹配成功，返回匹配位置
    if(j == NULL) {
        return count-StrLength_4_28(T);
    } else {
        // 匹配失败
        return 0;
    }
}
