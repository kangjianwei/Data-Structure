/*===============
 * 归并非降序链表
 *
 * 包含算法: 2.21
 ================*/

#include "MergeEList.h"

Status MergeEList(ELinkList* La, ELinkList* Lb, ELinkList* Lc, int(Compare)(ElemType, ElemType)){
    Link ha, hb, pa, pb, q;
    ElemType a, b;
    
    if(InitList(Lc) == ERROR) {
        return ERROR;
    }
    
    ha = GetHead(*La);   // 指向La头结点
    hb = GetHead(*Lb);   // 指向Lb头结点
    
    // 保证La和Lb是有效的链表，不过有可能是空表
    if(ha == NULL || hb ==NULL) {
        return ERROR;
    }
    
    pa = NextPos(*La, ha);   // 指向La第1个元素
    pb = NextPos(*La, hb);   // 指向Lb第1个元素
    
    // 遍历La和Lb，选出较小的元素，依次加入到Lc中
    while(pa !=NULL && pb!=NULL){
        a = GetCurElem(pa);
        b = GetCurElem(pb);
    
        // 如果La<=Lb
        if(Compare(a, b)<=0) {
            // 摘下La中首个元素
            DelFirst(La, ha, &q);
            
            // 将上述摘下的元素追加到Lc中
            Append(Lc, q);
            
            // 依然是获取La中第1个元素
            pa = NextPos(*La, ha);
        } else {
            // 摘下Lb中首个元素
            DelFirst(Lb, hb, &q);
    
            // 将上述摘下的元素追加到Lc中
            Append(Lc, q);
    
            // 依然是获取La中第1个元素
            pb = NextPos(*Lb, hb);
        }
    }
    
    // 如果La还有剩余
    if(pa!=NULL) {
        Append(Lc, pa);
    } else {
        Append(Lc, pb);
    }
    
    // 释放La的头结点。教材中这里是对ha操作，但是那样无法置空La的头指针，因而这里做了修改
    FreeNode(&(La->head));
    
    // 释放Lb的头结点。教材中这里是对hb操作，但是那样无法置空Lb的头指针，因而这里做了修改
    FreeNode(&(Lb->head));
    
    La->tail = NULL;
    Lb->tail = NULL;
    
    La->len = 0;
    Lb->len = 0;
    
    return OK;
}
