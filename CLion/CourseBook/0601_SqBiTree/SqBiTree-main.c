#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqBiTree.h"   //**▲06 树和二叉树**//

// 测试函数，打印元素
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    SqBiTree T;
    
    printf("████████ InitBiTree \n");
    {
        printf("█ 初始化空二叉树 T ...\n");
        InitBiTree(T);
    }
    PressEnterToContinue();
    
    
    printf("████████ CreateBiTree \n");
    {
        printf("█ 按先序序列创建二叉树 T ...\n");
        CreateBiTree(T, "TestData_Pre.txt");
    }
    PressEnterToContinue();
    
    
    printf("████████ BiTreeDepth \n");
    {
        printf("█ 二叉树 T 的深度为：%d \n", BiTreeDepth(T));
    }
    PressEnterToContinue();
    
    
    printf("████████ PrintGraph \n");
    {
        printf("█ 按二叉树的结构打印树 T ...\n");
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("████████ PreOrderTraverse \n");
    {
        printf("█ 前序遍历二叉树 T = ");
        PreOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("████████ InOrderTraverse \n");
    {
        printf("█ 中序遍历二叉树 T = ");
        InOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("████████ PostOrderTraverse \n");
    {
        printf("█ 后序遍历二叉树 T = ");
        PostOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("████████ LevelOrderTraverse \n");
    {
        printf("█ 层序遍历二叉树 T = ");
        LevelOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("████████ Value \n");
    {
        TElemType e = 'F';
        printf("█ 结点 %c 的值为 %c\n", e, Value(T, e));
    }
    PressEnterToContinue();
    
    
    printf("████████ Assign \n");
    {
        TElemType e = 'F';
        TElemType value = 'X';
        printf("█ 将结点 %c 赋值为 %c 后，T = \n", e, value);
        Assign(T, e, value);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("████████ Root \n");
    {
        printf("█ T 的根结点为 %c\n", Root(T));
    }
    PressEnterToContinue();
    
    
    printf("████████ Parent \n");
    {
        TElemType e = 'E';
        printf("█ 结点 %c 的双亲为：%c \n", e, Parent(T, e));
    }
    PressEnterToContinue();
    
    
    printf("████████ LeftChild、RightChild \n");
    {
        TElemType e = 'E';
        printf("█ 结点 %c 的左孩子结点值为：%c ，右孩子结点值为：%c\n", e, LeftChild(T, e), RightChild(T, e));
    }
    PressEnterToContinue();
    
    
    printf("████████ LeftSibling \n");
    {
        TElemType e = 'I';
        printf("█ 结点 %c 的左兄弟为：%c\n", e, LeftSibling(T, e));
    }
    PressEnterToContinue();
    
    
    printf("████████ RightSibling \n");
    {
        TElemType e = 'H';
        printf("█ 结点 %c 的右兄弟为：%c\n", e, RightSibling(T, e));
    }
    PressEnterToContinue();
    
    
    printf("████████ InsertChild \n");
    {
        SqBiTree c1, c2;
        TElemType p1 = 'D';
        TElemType p2 = 'E';
        
        printf("█ 创建子树 c1 ...\n");
        InitBiTree(c1);
        CreateBiTree(c1, "TestData_c1.txt");
        PrintGraph(c1);
    
        printf("█ 创建子树 c2 ...\n");
        InitBiTree(c2);
        CreateBiTree(c2, "TestData_c2.txt");
        PrintGraph(c2);
    
        printf("█ 将子树 c1 插入为二叉树 T 中 %c 结点的右子树 ...\n", p1);
        InsertChild(T, p1, 1, c1);
        PrintGraph(T);
    
        printf("█ 将子树 c2 插入为二叉树 T 中 %c 结点的左子树 ...\n", p2);
        InsertChild(T, p2, 0, c2);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("████████ DeleteChild \n");
    {
        TElemType p1 = 'D';
        TElemType p2 = 'E';
    
        printf("█ 删除二叉树 T 中 %c 结点的右子树 ...\n", p1);
        DeleteChild(T, p1, 1);
        PrintGraph(T);
    
        printf("█ 删除二叉树 T 中 %c 结点的左子树 ...\n", p2);
        DeleteChild(T, p2, 0);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("████████ ClearBiTree、BiTreeEmpty \n");
    {
        printf("█ 清空前：");
        BiTreeEmpty(T) ? printf("T 为空！\n") : printf("T 不为空！\n");
        
        ClearBiTree(T);
    
        printf("█ 清空后：");
        BiTreeEmpty(T) ? printf("T 为空！\n") : printf("T 不为空！\n");
    }
    PressEnterToContinue();
    
    return 0;
}
