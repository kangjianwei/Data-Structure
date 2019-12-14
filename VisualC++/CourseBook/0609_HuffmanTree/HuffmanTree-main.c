#include <stdio.h>
#include "HuffmanTree.h"     //**��06 ���Ͷ�����**//

int main(int argc, char* argv[]) {
    int *w;
    int n;
    HuffmanTree HT;
    HuffmanCode HC;
    
    printf("���������������� InitEnvironment \n");
    {
        printf("�� ��ʼ����������Ҫ�ǳ�ʼ��Ȩֵ��Ϣ...\n");
        InitEnvironment(&w, &n, "TestData_HT.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� HuffmanCodeing \n");
    {
        printf("�� ���룺��Ȩֵ��Ϣ��ȡ�շ�������...\n");
        HuffmanCodeing_1(&HT, &HC, w, n);   // �㷨6.12
//        HuffmanCodeing_2(&HT, &HC, w, n);   // �㷨6.13
        
        printf("�� ��ӡ�շ������ṹ...\n");
        PrintHuffmanTree(HT);
    
        printf("�� ��ӡ�շ�������...\n");
        PrintHuffmanCode(HT, HC);
    }
    PressEnterToContinue();
    
    
    printf("���������������� HuffmanDecoding \n");
    {
        int* weight;
        
        printf("�� ���룺�ɺշ��������ȡȨֵ��Ϣ...\n");
        HuffmanDecoding(HT,HC,&weight,n);
    
        printf("�� ��ӡȨֵ��Ϣ...\n");
        PrintWeight(HC, weight, n);
    }
    PressEnterToContinue();
    
    return OK;
}