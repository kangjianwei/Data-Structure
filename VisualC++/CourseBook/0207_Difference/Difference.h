/*===============
 * 静态链表去重
 *
 * 包含算法: 2.17
 ================*/

#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <stdio.h>
#include "Status.h"           //**▲01 绪论**//
#include "SLinkList.h"        //**▲02 线性表**//

/*
 * ████████ 算法2.17 ████████
 *
 * S = (A-B)∪(B-A)
 *
 * 对集合A和集合B进行(A-B)∪(B-A)计算，计算结果存入静态链表S
 *
 *【备注】
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而选择了从预设的文件path中读取测试数据。
 */
void difference(char path[], SLinkList space, int* S);

#endif
