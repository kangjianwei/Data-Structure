#include <stdio.h>
#include <string.h>											//�ṩstrlenԭ�� 
#include <stdlib.h>											//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"		//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ȫ�ֱ��� */
char Pre[] = "ABDGEHICFJ";
char In[] =  "GDBHEIAFJC";

/* ����ԭ�� */
BiTree Algo_6_65_2();
BiTree BuildTree_pre_in(int pre_start, int pre_end, int in_start, int in_end);	//�ݹ鴴�������� 

int main(int argc, char *argv[])
{
	BiTree T;

	printf("��������������Ϊ��%s\n", Pre);
	printf("��������������Ϊ��%s\n", In);
	printf("\n");
			
	T = Algo_6_65_2(Pre, In);
	printf("�ɴ˹���Ķ�����Ϊ��\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*������������������������������������������
����6.65������ǰ�����к��������д�����������
������������������������������������������*/
/* ����2���ݹ����ǰ��洢�Ľ�㴴�������� */
BiTree Algo_6_65_2()							//Pre��In��Ϊȫ�ֱ��� 
{
	int len_pre, len_in;
	BiTree T;
	
	len_pre = strlen(Pre);
	len_in = strlen(In);
	
	T = BuildTree_pre_in(0, len_pre-1, 0, len_in-1);
	
	return T;
}

BiTree BuildTree_pre_in(int pre_start, int pre_end, int in_start, int in_end)
{
	BiTree T;
	int i, LTreeLen, RTreeLen;
	
	T = (BiTree)malloc(sizeof(BiTNode));		//��������� 
	if(!T)
		exit(OVERFLOW);
	T->data = Pre[pre_start];					//����ǰ��洢�Ľ�� 
	T->lchild = T->rchild = NULL;				//��ʼ��ʱ�ÿ����Һ���ָ�� 
		
	i=in_start;
	while(In[i]!=T->data)						//������������Ѱ�Ҹ����λ��
		i++;	 
	
	LTreeLen = i-in_start;						//���������� 
	RTreeLen = in_end - i;						//����������
		
	if(LTreeLen) 								//����������
		T->lchild = BuildTree_pre_in(pre_start+1, pre_start+LTreeLen, in_start, i-1);
	
	if(RTreeLen) 								//����������
		T->rchild = BuildTree_pre_in(pre_start+LTreeLen+1, pre_end, i+1, in_end);

	return T;
}
