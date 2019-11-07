/*===============
 * 静态链表去重
 *
 * 包含算法: 2.17
 ================*/

#include "Difference.h"

/*
 * ████████ 算法2.17 ████████
 *
 * S = (A-B)∪(B-A)
 *
 * 对集合A和集合B进行(A-B)∪(B-A)计算，计算结果存入静态链表S
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
void difference(SLinkList space, int* S, char* path) {
    int m, n;       // 集合A和集合B中元素数量
    int j;          // 循环计数器
    int R;          // 指向静态链表最后一个结点
    int i, k, p;
    int b;          // 临时存储从集合B中读到的数据
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据

    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    // 初始化备用空间
    InitSpace(space);

    // 获取静态链表头结点
    *S = Malloc(space);

    // 让R执行静态链表最后的结点
    R = *S;

    // 读取集合A和集合B的元素个数
    if(readFromConsole) {
        printf("请输入集合A的元素个数：");
        scanf("%d", &m);
        printf("请输入集合B的元素个数：");
        scanf("%d", &n);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            exit(ERROR);
        }

        ReadData(fp, "%d%d", &m, &n);
    }

    if(readFromConsole) {
        printf("请输入 %d 个元素存入集合A：", m);
    }

    // 录入集合A的数据
    for(j = 1; j <= m; ++j) {
        // 分配结点
        i = Malloc(space);

        // 输入集合A的元素值
        if(readFromConsole) {
            scanf("%d", &space[i].data);
        } else {
            ReadData(fp, "%d", &space[i].data);
        }

        // 将新结点插入到表尾
        space[R].cur = i;
        R = i;
    }

    // 尾结点的指针置空
    space[R].cur = 0;

    if(readFromConsole) {
        printf("请输入 %d 个元素存入集合B：", n);
    }

    // 录入集合B的数据
    for(j = 1; j <= n; ++j) {
        // 输入集合B的元素值
        if(readFromConsole) {
            scanf("%d", &b);
        } else {
            ReadData(fp, "%d", &b);
        }

        p = *S;             // 指向静态链表头结点，后续总是指向k的前一个位置
        k = space[*S].cur;  // 指向静态链表中的首个元素

        // 在当前静态链表中查找是否存在b元素
        while(k != space[R].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }

        // 如果该元素不存在，则加入静态链表
        if(k == space[R].cur) {
            i = Malloc(space);
            space[i].data = b;
            space[i].cur = space[R].cur;
            space[R].cur = i;

            // 如果该元素已存在，则需要移除
        } else {
            space[p].cur = space[k].cur;
            Free(space, k);
            if(R == k) {
                R = p;
            }
        }
    }

    if(!readFromConsole) {
        fclose(fp);
    }
}

