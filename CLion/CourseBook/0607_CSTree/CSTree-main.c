#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

// 测试函数，打印元素
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("████████ InitTree \n");
    {
        printf("█ 初始化空树 T ...\n");
        InitTree(&T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ CreateTree \n");
    {
        printf("█ 按先序序列创建树 T ...\n");
        CreateTree(&T, "TestData_T.txt");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ TreeDepth \n");
    {
        printf("█ 树 T 的深度为：%d \n", TreeDepth(T));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PrintTree \n");
    {
        printf("█ 按树的结构打印树 T ...\n");
        printf("█ T = \n");
        PrintTree(T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PreOrderTraverse \n");
    {
        printf("█ 前序遍历树 T = ");
        PreOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PostOrderTraverse \n");
    {
        printf("█ 后序遍历树 T = ");
        PostOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ LevelOrderTraverse \n");
    {
        printf("█ 层序遍历树 T = ");
        LevelOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Value \n");
    {
        TElemType e = 'F';
        printf("█ 结点 %c 的值为 %c\n", e, Value(T, e));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Assign \n");
    {
        TElemType e = 'F';
        TElemType value = 'X';
        printf("█ 将结点 %c 赋值为 %c ...\n", e, value);
        Assign(T, e, value);
        printf("█ T = \n");
        PrintTree(T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Root \n");
    {
        printf("█ T 的根结点为 %c\n", Root(T));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Parent \n");
    {
        TElemType e = 'E';
        printf("█ 结点 %c 的双亲为：%c \n", e, Parent(T, e));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ChildCount \n");
    {
        TElemType e = 'X';
        printf("█ 结点 %c 有 %d 个孩子\n", e, ChildCount(T, e));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Child \n");
    {
        TElemType e = 'X';
        int i = 2;
        printf("█ 结点 %c 的第 %d 个孩子结点值为：%c \n", e, i, Child(T, e, i));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ LeftSibling \n");
    {
        TElemType e = 'H';
        printf("█ 结点 %c 的左兄弟为：%c\n", e, LeftSibling(T, e));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ RightSibling \n");
    {
        TElemType e = 'H';
        printf("█ 结点 %c 的右兄弟为：%c\n", e, RightSibling(T, e));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ InsertChild \n");
    {
        CSTree c;
        TElemType p = 'C';
        int i = 2;
        
        printf("█ 创建子树 c ...\n");
        InitTree(&c);
        CreateTree(&c, "TestData_c.txt");
        printf("█ c = \n");
        PrintTree(c);
        
        printf("█ 将子树 c 插入为树 T 中 %c 结点的第 %d 棵子树 ...\n", p, i);
        InsertChild(&T, p, i, c);
        printf("█ T = \n");
        PrintTree(T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ DeleteChild \n");
    {
        TElemType p = 'C';
        int i = 1;
        
        printf("█ 删除树 T 中 %c 结点的第 %d 棵子树 ...\n", p, i);
        DeleteChild(&T, p, i);
        printf("█ T = \n");
        PrintTree(T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ClearTree、TreeEmpty \n");
    {
        printf("█ 清空前：");
        TreeEmpty(T) ? printf("T 为空！\n") : printf("T 不为空！\n");
        
        ClearTree(&T);
        
        printf("█ 清空后：");
        TreeEmpty(T) ? printf("T 为空！\n") : printf("T 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}
