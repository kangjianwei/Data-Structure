/*==============
 * 求并集
 *
 * 包含算法: 2.1
 ===============*/

#include "Union.h"      //**▲02 线性表**//

/*
 * ████████ 算法2.1 ████████
 *
 * A=A∪B
 *
 * 计算La与Lb的并集并返回。
 * 由于生成的并集会拼接在La上，所以La的入参为指针类型。
 */
void Union(SqList* La, SqList Lb) {
    int La_len, Lb_len;
    int i;
    ElemType e;
    
    // 求顺序表长度
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    
    for(i = 1; i <= Lb_len; i++) {
        // 取Lb中第i个元素赋给e
        GetElem(Lb, i, &e);
        
        // 若e不在La中则插入
        if(!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

/*
 * 判等
 *
 * 判断两元素是否相等。
 * 如果相等，则返回TRUE，否则，返回FALSE。
 */
Status equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}
