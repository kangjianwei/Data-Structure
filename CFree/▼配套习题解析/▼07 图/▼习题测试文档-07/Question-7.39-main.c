#include <stdio.h>
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_7_39(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;												//����Դ 
	char tmp;
		
	InitBiTree(&T); 

	printf("�������������������У�B1��/+*+a^^b^^*b^^-c^^d^^*-c^^d^^e^^*-c^^d^^e^^...\n");
	fp = fopen("Data/Algo_7_39.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������Ϊ��\n");
	PrintTree(T);
	printf("\n"); 

	printf("�˱��ʽ���沨��ʽΪ��");	
	Algo_7_39(T);
	printf("\n\n");	
		
	return 0;
}

/*������������������������������������
����7.39�� ���ʽ�Ķ�������洢�ṹ ��
������������������������������������*/
void Algo_7_39(BiTree T)			//�ö������洢			
{
	if(T)							//�����Ǻ������ 
	{
		Algo_7_39(T->lchild);
		Algo_7_39(T->rchild);
		printf("%c", T->data);
	}	
}
