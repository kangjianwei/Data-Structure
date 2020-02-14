#include <stdio.h>
#include "HuffmanTree.h"     //**▲06 树和二叉树**//

int main(int argc, char* argv[]) {
    int *w;
    int n;
    HuffmanTree HT;
    HuffmanCode HC;
    
    printf("████████ InitEnvironment \n");
    {
        printf("█ 初始化环境，主要是初始化权值信息...\n");
        InitEnvironment(&w, &n, "TestData_HT.txt");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ HuffmanCodeing \n");
    {
        printf("█ 编码：由权值信息获取赫夫曼编码...\n");
        HuffmanCodeing_1(&HT, &HC, w, n);   // 算法6.12
//        HuffmanCodeing_2(&HT, &HC, w, n);   // 算法6.13
        
        printf("█ 打印赫夫曼树结构...\n");
        PrintHuffmanTree(HT);
    
        printf("█ 打印赫夫曼编码...\n");
        PrintHuffmanCode(HT, HC);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ HuffmanDecoding \n");
    {
        int* weight;
        
        printf("█ 解码：由赫夫曼编码获取权值信息...\n");
        HuffmanDecoding(HT,HC,&weight,n);
    
        printf("█ 打印权值信息...\n");
        PrintWeight(HC, weight, n);
    }
    PressEnterToContinue(debug);
    
    return OK;
}