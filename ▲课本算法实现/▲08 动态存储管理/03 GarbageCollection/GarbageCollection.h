/*******************************
 *                             *
 * 文件夹: ▲08 动态存储管理   *
 *                             *
 * 文件名: GarbageCollection.h *
 *                             *
 * 内  容: 无用单元搜集        *
 *                             *
 ******************************/

#ifndef GARBAGECOLLECTION_H
#define GARBAGECOLLECTION_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"												//**▲01 绪论**//
#include "../../▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//

/* 无用单元收集函数列表 */
void MakeList(GList G); 
/*━━━━━━━━━━━━━━━━━━━┓
┃(01)算法8.3：遍历广义表（不利用栈）。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif 
