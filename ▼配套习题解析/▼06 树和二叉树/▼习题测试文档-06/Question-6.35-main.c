#include <stdio.h>

/* 函数原型 */
int Algo_6_35(int i);

int main(int argc, char *argv[])
{
	int i, j;
	char BiTree[100] = {'A', 'B', 'C', 'D', 'E', 'F', '\0', 'G', '\0', 'H', 'I', '\0', 'J'};
	
	printf("作为示例，建立二叉树的顺序存储结构（^代表空字符）：ABCDEF^G^HI^J^^");
	printf("\n");
	
	printf("请输入0-14之间的下标值： ");
	fflush(stdin);
	scanf("%d", &i);
	printf("\n");
		
	j = Algo_6_35(i);
	
	printf("下标值为 %d 的结点的对应的十进制整数为 %d 。\n\n", i, j);
	
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.35：求符合题意的整数值┃
┗━━━━━━━━━━━━━*/
int Algo_6_35(int i)					//结点从0号单元开始存储			
{
	return i+1;
}
