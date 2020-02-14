#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>
#include "Status.h"     //**▲01 绪论**//

/*
 * 单链表元素类型定义
 *
 *【注】
 * 这里的链表虽然用作字符串，但是元素类型仍然用int，原因是：
 * 1.需要借用头结点存储结点的数量，所以用int比直接用char合适
 * 2.char可以与int兼容，所以结点虽然是int，但也可以用来存储char
 */
typedef int ElemType;

/*
 * 单链表结构
 *
 * 注：这里的单链表存在头结点
 */
typedef struct SNode {
    ElemType data;      // 数据结点
    struct SNode* next; // 指向下一个结点的指针
} SNode;

// 指向单链表结点的指针，用作字符串类型
typedef SNode* String;


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 */
Status StrAssign_4_21(String* S, char* chars);

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy_4_21(String* S, String T);

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 */
int StrCompare_4_21(String S, String T);

/*
 * 计数
 *
 * 返回串S中元素的个数。
 */
int StrLength_4_21(String S);

/*
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 */
Status Concat_4_21(String* R, String S1, String S2);

/*
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 */
Status SubString_4_21(String* Sub, String S, int pos, int len);

// 字符串输出
void StrPrint_4_21(String S);


int main(int argc, char* argv[]) {
    char* chars = "0123456789";
    String S, T;
    int i;
    
    printf("████████ StrAssign \n");
    {
        printf("█ 为顺序串 S 赋值...\n");
        StrAssign_4_21(&S, chars);
        printf("█ S = ");
        StrPrint_4_21(S);
    }
    PressEnterToContinue(debug);
    
    printf("████████ StrLength \n");
    {
        i = StrLength_4_21(S);
        printf("█ S 的长度为 %d \n", i);
    }
    PressEnterToContinue(debug);
    
    printf("████████ StrCopy \n");
    {
        printf("█ 复制 S 到 T ...\n");
        StrCopy_4_21(&T, S);
        printf("█ T = ");
        StrPrint_4_21(T);
    }
    PressEnterToContinue(debug);
    
    printf("████████ StrCompare \n");
    {
        printf("█ 比较字符串 S 和 T ...\n");
        i = StrCompare_4_21(S, T);
        i == 0 ? printf("█ S==T\n") : (i < 0 ? printf("█ S<T\n") : printf("█ S>T\n"));
    }
    PressEnterToContinue(debug);
    
    printf("████████ SubString \n");
    {
        String Sub;
        
        printf("█ 用 Sub 返回 S 中第 6 个字符起的 5 个字符...\n");
        SubString_4_21(&Sub, S, 6, 5);
        printf("█ Sub = ");
        StrPrint_4_21(Sub);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Concat \n");
    {
        String Tmp, S1, S2;
        
        StrAssign_4_21(&S1, "+++++");
        StrAssign_4_21(&S2, "-----");
        
        printf("█ 联接 \"+++++\" 和 \"-----\" 形成 Tmp ...\n");
        Concat_4_21(&Tmp, S1, S2);
        printf("█ Tmp = ");
        StrPrint_4_21(Tmp);
    }
    PressEnterToContinue(debug);
    
    return 0;
}


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 */
Status StrAssign_4_21(String* S, char* chars) {
    int i, len;
    String p;
    
    if(S == NULL || chars == NULL) {
        return ERROR;
    }
    
    len = (int) strlen(chars);
    
    *S = (SNode*) malloc(sizeof(SNode));
    (*S)->data = len;
    
    p = *S;
    
    for(i = 0; i < len; i++) {
        p->next = (SNode*) malloc(sizeof(SNode));
        p->next->data = chars[i];
        p = p->next;
    }
    
    p->next = NULL;
    
    return OK;
}

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy_4_21(String* S, String T) {
    String p, r, t;
    
    if(S == NULL || T == NULL) {
        return ERROR;
    }
    
    for(t = T; t != NULL; t = t->next) {
        r = (SNode*) malloc(sizeof(SNode));
        r->data = t->data;
        
        if(t == T) {
            *S = r;
            p = r;
        } else {
            p->next = r;
            p = p->next;
        }
    }
    
    p->next = NULL;
    
    return OK;
}

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 */
int StrCompare_4_21(String S, String T) {
    String s, t;
    
    if(S == NULL || T == NULL) {
        return StrLength_4_21(S) - StrLength_4_21(T);
    }
    
    s = S->next;
    t = T->next;
    
    while(s != NULL && t != NULL) {
        if(s->data != t->data) {
            return s->data - t->data;
        }
        
        s = s->next;
        t = t->next;
    }
    
    if(s == NULL && t != NULL) {
        return -1;
    } else if(s != NULL && t == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * 计数
 *
 * 返回串S中元素的个数。
 */
int StrLength_4_21(String S) {
    return S == NULL ? 0 : S->data;
}

/*
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 */
Status Concat_4_21(String* R, String S1, String S2) {
    String r, s, p;
    
    if(R == NULL || S1 == NULL || S2 == NULL) {
        return ERROR;
    }
    
    *R = (SNode*) malloc(sizeof(SNode));
    (*R)->data = S1->data + S2->data;
    
    r = *R;
    
    for(s = S1->next; s != NULL; s = s->next) {
        p = (SNode*) malloc(sizeof(SNode));
        p->data = s->data;
        r->next = p;
        r = r->next;
    }
    
    for(s = S2->next; s != NULL; s = s->next) {
        p = (SNode*) malloc(sizeof(SNode));
        p->data = s->data;
        r->next = p;
        r = r->next;
    }
    
    r->next = NULL;
    
    return OK;
}

/*
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 */
Status SubString_4_21(String* Sub, String S, int pos, int len) {
    int i, slen;
    String sub, s, p;
    
    slen = StrLength_4_21(S);
    
    if(Sub == NULL || S == NULL || pos < 1 || pos > slen || len < 0 || pos + len - 1 > slen) {
        return ERROR;
    }
    
    *Sub = (SNode*) malloc(sizeof(SNode));
    (*Sub)->data = len;
    
    for(i = 0, s = S; i < pos; i++, s = s->next) {
        // 查找第pos个结点，并用s指向它
    }
    
    sub = *Sub;
    
    for(i = 0; i < len; i++) {
        sub->next = (SNode*) malloc(sizeof(SNode));
        sub->next->data = s->data;
        sub = sub->next;
        
        s = s->next;
    }
    
    sub->next = NULL;
    
    return OK;
}

// 字符串输出
void StrPrint_4_21(String S) {
    String p;
    
    if(S == NULL) {
        return;
    }
    
    for(p = S->next; p != NULL; p = p->next) {
        printf("%c", p->data);
    }
    printf("\n");
}
