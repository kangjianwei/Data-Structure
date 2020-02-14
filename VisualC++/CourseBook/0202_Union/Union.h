/*==============
 * 求并集
 *
 * 包含算法: 2.1
 ===============*/

#ifndef UNION_H
#define UNION_H

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqList.h"   //**▲02 线性表**//

/*
 * ████████ 算法2.1 ████████
 *
 * A=A∪B
 *
 * 计算La与Lb的并集并返回。
 * 由于生成的并集会拼接在La上，所以La的入参为指针类型。
 */
void Union(SqList* La, SqList Lb);

/*
 * 判等
 *
 * 判断两元素是否相等。
 * 如果相等，则返回TRUE，否则，返回FALSE。
 */
Status equal(ElemType e1, ElemType e2);

#endif
