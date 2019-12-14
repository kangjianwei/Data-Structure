/****************************************
 *    	    		                    *
 * 文件夹: ▲07 图\08 ArticulationPoint *
 * 					                    *
 * 文件名: ArticulationPoint.h          *
 *                                      *
 * 内  容: 无向图关节点相关操作列表     *
 *                                      *
 ****************************************/

#ifndef ARTICULATIONPOINT_H
#define ARTICULATIONPOINT_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"					//**▲01 绪论**//
#include "../02 ALGraph/ALGraph.c" 					//**▲07 图**//

/* 全局变量 */
int count;
int low[MAX_VERTEX_NUM+1];							//以当前结点为根的树可以直接追溯的最早祖先位置 
int node[MAX_VERTEX_NUM+1];							//存放关节点，0号单元统计关节点个数 

/* 无向图关节点函数列表 */
void FindArticul(ALGraph G);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法7.10：查找并输出G上全部关节点。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

void DFSArticul(ALGraph G, int v0);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法7.11：从第v0个顶点出发深度优先遍历图G，查找并输出所有关节点。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status StorageAPoint(int n);
/*━━━━━━━━━━━━━━━━━━━┓
┃(03)存储先序编号为n的关节点到node中。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

void OutputAPoint(ALGraph G);
/*━━━━━━━━━━━━┓
┃(04)输出G中全部关节点。 ┃
┗━━━━━━━━━━━━*/

#endif
