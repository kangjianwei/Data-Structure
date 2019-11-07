/*========================
 * 一元多项式(基于线性链表)
 *
 * 包含算法: 2.22、2.23
 =========================*/

#include "Polynomial.h"


/*━━━━━━━━━━━━━━━━━━━━━━ 一元多项式操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * ████████ 算法2.22 ████████
 *
 * 创建
 *
 * 根据输入的系数和指数，创建项数为m的一元多项式
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
void CreatPolyn(Polynomial* P, int m, char* path) {
    int i;
    ElemType e;
    Position h, q;
    Link s;
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    // 初始化一个线性链表存放一元多项式
    InitList(P);
    
    // 获取多项式头指针
    h = GetHead(*P);
    
    // 为头结点填充数据
    e.coef = 0.0f;
    e.expn = -1;
    SetCurElem(h, e);
    
    if(!readFromConsole) {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            exit(ERROR);
        }
    }
    
    if(readFromConsole) {
        printf("请输入 %d 个元素：\n", m);
    }
    
    // 依次录入m个有效项
    for(i = 1; i <= m; i++) {
        // 读取系数和指数信息，临时存入e
        if(readFromConsole) {
            printf("请输入第 %d 组系数和指数：", i);
            scanf("%f%d", &(e.coef), &(e.expn));
        } else {
            ReadData(fp, "%f%d", &(e.coef), &(e.expn));
        }
        
        // 如果当前链表中不存在该指数项
        if(LocateElem(*P, e, &q, Cmp) == FALSE && q != NULL) {
            // 创建新结点
            if(MakeNode(&s, e) == OK) {
                // 在q结点之后插入s
                InsFirst(P, q, s);
            }
        }
    }
    
    if(!readFromConsole) {
        fclose(fp);
    }
}

/*
 * 销毁
 *
 * 销毁一元多项式。
 */
void DestroyPolyn(Polynomial* P) {
    DestroyList(P);
}

/*
 * 计数
 *
 * 返回一元多项式的项数。
 */
int PolynLength(Polynomial P) {
    return ListLength(P);
}

/*
 * ████████ 算法2.23 ████████
 *
 * 加法
 *
 * 一元多项式加法Pa=Pa+Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void AddPolyn(Polynomial* Pa, Polynomial* Pb) {
    Position ha, hb;
    Position qa, qb;
    ElemType a, b;
    float sum;
    
    // ha、hb分别指向Pa、Pb头结点
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);
    
    // qa、qb分别指向Pa、Pb的当前结点
    qa = NextPos(*Pa, ha);
    qb = NextPos(*Pb, hb);
    
    // qa、qb均非空
    while(qa && qb) {
        // a和b为两表中当前比较元素
        a = GetCurElem(qa);
        b = GetCurElem(qb);
        
        //比较当前元素的指数大小
        switch(Cmp(a, b)) {
            // 多项式Pa中当前结点的指数值较小
            case -1: {
                ha = qa;
                qa = NextPos(*Pa, qa);
            }
            break;
                
            // 两者数值相等
            case 0: {
                sum = a.coef + b.coef;
                
                // 相加不能抵消时更新Pa结点的系数值
                if(sum != 0.0) {
                    // 这里用SetCurElem()不合适，不如直接赋值
                    qa->data.coef = sum;
                    // ha后移
                    ha = qa;
                    
                    //相加抵消时，删除Pa中当前结点
                } else {
                    // 删除ha后面的结点（其实删的就是qa）
                    DelFirst(Pa, ha, &qa);
                    // 释放被删除结点所占空间
                    FreeNode(&qa);
                }
                
                // 删除Pb中扫描过的结点
                DelFirst(Pb, hb, &qb);
                // 释放被删除结点所占空间
                FreeNode(&qb);
                
                // qa、qb均后移
                qa = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
            break;
                
            // 多项式Pb中当前结点的指数值较小
            case 1: {
                // 摘下Pb当前结点
                DelFirst(Pb, hb, &qb);
                
                // 将摘下结点链入Pa中
                InsFirst(Pa, ha, qb);
                
                ha = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
            break;
        }//switch
    }//while
    
    // 若Pb还未扫描完，将剩余项链接到Pa后
    if(qb != NULL) {
        Append(Pa, qb);
    }
    
    // 释放Pb头结点
    FreeNode(&hb);
    
    // 设置Pb为销毁状态
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

/*
 * 减法
 *
 * 一元多项式减法Pa=Pa-Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void SubtractPolyn(Polynomial* Pa, Polynomial* Pb) {
    Position ha, hb;
    Position qa, qb;
    Position r;
    ElemType a, b;
    float sum;
    
    // ha、hb分别指向Pa、Pb头结点
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);
    
    // qa、qb分别指向Pa、Pb的当前结点
    qa = NextPos(*Pa, ha);
    qb = NextPos(*Pb, hb);
    
    // qa、qb均非空
    while(qa && qb) {
        // a和b为两表中当前比较元素
        a = GetCurElem(qa);
        b = GetCurElem(qb);
        
        // 比较当前元素的指数大小
        switch(Cmp(a, b)) {
            // 多项式Pa中当前结点的指数值较小
            case -1: {
                ha = qa;
                qa = NextPos(*Pa, ha);
            }
                break;
                
            // 两者数值相等
            case 0: {
                sum = a.coef - b.coef;
                
                // 相减不能抵消时更新Pa结点的系数值
                if(sum != 0.0) {
                    // 更新系数
                    qa->data.coef = sum;
                    // ha后移
                    ha = qa;
                    
                    // 相减抵消时，删除Pa中当前结点
                } else {
                    // 删除ha后面的结点（其实删的就是qa）
                    DelFirst(Pa, ha, &qa);
                    // 释放被删除结点所占空间
                    FreeNode(&qa);
                }
                
                // 删除Pb中扫描过的结点
                DelFirst(Pb, hb, &qb);
                // 释放被删除结点所占空间
                FreeNode(&qb);
                
                // qa、qb均后移
                qa = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
            break;
                
            // 多项式Pb中当前结点的指数值较小
            case 1: {
                // 摘下Pb当前结点
                DelFirst(Pb, hb, &qb);
                
                // 改变当前结点符号
                qb->data.coef = -qb->data.coef;
                
                // 将摘下结点链入Pa中
                InsFirst(Pa, ha, qb);
                
                ha = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
            break;
        }//switch
    }//while
    
    // 若Pb还未扫描完，将剩余项的系数取反后链接到Pa后
    if(qb != NULL) {
        // 改变剩余项的符号
        for(r = qb = 0; r != NULL; r = r->next) {
            r->data.coef = -r->data.coef;
        }
        
        Append(Pa, qb);
    }
    
    // 释放Pb头结点
    FreeNode(&hb);
    
    // 设置Pb为销毁状态
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

/*
 * 乘法
 *
 * 一元多项式乘法Pa=Pa*Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void MultiplyPolyn(Polynomial* Pa, Polynomial* Pb) {
    Polynomial Pc, Ptmp;
    int i, j, la, lb;
    Position ha, hb;
    Position qa, qb;
    Link s;
    ElemType e;
    
    // 获取两个多项式的长度
    la = PolynLength(*Pa);
    lb = PolynLength(*Pb);
    
    // ha、hb分别指向Pa、Pb头结点
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);
    
    // 累加计算结果
    InitList(&Pc);
    
    // 遍历Pa中的元素
    for(i = 1; i <= la; i++) {
        // 存储临时计算结果
        InitList(&Ptmp);
        
        // 逐个摘下Pa中的结点
        DelFirst(Pa, ha, &qa);
        
        // 遍历Pb中所有结点，与Pa中摘下的结点进行运算
        for(j = 1, qb = NextPos(*Pb, hb); j <= lb; j++, qb = NextPos(*Pb, qb)) {
            e.coef = qa->data.coef * qb->data.coef;    //系数相乘
            e.expn = qa->data.expn + qb->data.expn;    //指数相加
            
            // 创建新结点存储结算结果
            MakeNode(&s, e);
            
            // 添加到临时多项式
            Append(&Ptmp, s);
        }
        
        // 将新的多项式累加到Pc上
        AddPolyn(&Pc, &Ptmp);
    }
    
    // 将所有结果添加到Pa上
    AddPolyn(Pa, &Pc);
    
    // 销毁多项式Pb
    DestroyPolyn(Pb);
}


/*━━━━━━━━━━━━━━━━━━━━━━ 基础操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 输出
 *
 * 打印输出一元多项式。
 */
void PrintPolyn(Polynomial P) {
    int i;
    Link p;
    
    p = P.head->next;
    for(i = 1; i <= P.len; i++) {
        if(p->data.coef == 0.0f) {
            continue;
        }
        
        if(i == 1) {
            printf("%g", p->data.coef);
        } else {
            if(p->data.coef > 0) {
                printf(" + ");
                printf("%g", p->data.coef);
            } else {
                printf(" - ");
                printf("%g", -p->data.coef);
            }
        }
        
        if(p->data.expn) {
            printf("x");
            
            if(p->data.expn != 1) {
                printf("^%d", p->data.expn);
            }
        }
        
        p = p->next;
    }
    
    printf("\n");
}

/*
 * 比较
 *
 * 比较c1项和c2项指数大小。
 */
int Cmp(ElemType c1, ElemType c2) {
    // 计算指数差
    int i = c1.expn - c2.expn;
    
    if(i < 0) {
        return -1;
    } else if(i == 0) {
        return 0;
    } else {
        return 1;
    }
}
