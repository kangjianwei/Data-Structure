/*==============
 * 无用单元收集
 *
 * 包含算法: 8.3
 ===============*/

#include "GarbageCollection.h"

/*
 * ████████ 算法8.3 ████████
 *
 * 遍历广义表(不使用栈)。
 */
void MakeList(GList G) {
    GList t, p, q;
    Status finished;
    
    if(!G || G->mark != 0) {
        return;
    }
    
    t = NULL;   // t为p的母表
    p = G;
    finished = FALSE;
    
    while(!finished) {
        while(p->mark == 0) {
            p->mark = 1;        // MakeHead(p)的细化
            q = p->Node.ptr.hp; // q指向p的表头
            
            if(q != NULL && q->mark == 0) {
                // 表头为原子结点
                if(q->tag == Atom) {
                    q->mark = 1;
                    
                    // 继续遍历子表
                } else {
                    p->Node.ptr.hp = t;
                    p->tag = Atom;
                    t = p;
                    p = q;
                }
            }
        } // 完成对表头的标记
        
        q = p->Node.ptr.tp;
        
        // 继续遍历表尾
        if(q != NULL && q->mark == 0) {
            p->Node.ptr.tp = t;
            t = p;
            p = q;
            
            // BackTrack(finished)的细化
        } else {
            // 表结点，从表尾回溯
            while(t && t->tag == List) {
                q = t;
                t = q->Node.ptr.tp;
                q->Node.ptr.tp = p;
                p = q;
            }
            
            // 结束
            if(t == NULL) {
                finished = TRUE;
                
                // 从表头回溯
            } else {
                q = t;
                t = q->Node.ptr.hp;
                q->Node.ptr.hp = p;
                p = q;
                p->tag = List;
            }// 继续遍历表尾
        }
    }
}
