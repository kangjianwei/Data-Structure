#include <stdio.h>
#include <string.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"

/* 宏定义 */
#define MAXSIZE 100

/* 类型定义 */
typedef struct
{
	char s[27];		//关键字长度不超过26 
}HNode;
typedef HNode HashTable[MAXSIZE];

/* 函数原型 */
void Algo_9_44(HashTable H);
Status CreateHash_9_44(FILE *fp, HashTable H);//创建哈希表 
int fHash_9_44(char s[]);//返回s首字母(大写)在字母表中的位置

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_44.txt","r");
	CreateHash_9_44(fp, H);
	fclose(fp);
	
	printf("按首字母字典顺序输出哈希表中所有关键字：\n");
	Algo_9_44(H);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━┓
┃题9.44：按关键字首字母顺序输出哈希表中关键字┃
┗━━━━━━━━━━━━━━━━━━━━━━*/
void Algo_9_44(HashTable H)
{
	int i, j;
	
	for(i=1; i<=26; i++)
	{
		j = i;
		
		while(strcmp(H[j].s,"")!=0)
		{
			if(fHash_9_44(H[j].s)==i)
				printf("%s ", H[j].s);
			j = (j+1)%MAXSIZE;
		}
	} 
}

Status CreateHash_9_44(FILE *fp, HashTable H)
{
	int i, p;
	char tmp[26];
	
	for(i=0; i<MAXSIZE; i++)
		strcpy(H[i].s, "");

	while(Scanf(fp, "%s", tmp)==1)			//录入关键字到哈希表 
	{
		p = fHash_9_44(tmp);
		
		while(strcmp(H[p].s, "")!=0)		//出现冲突
			p = (p+1)%MAXSIZE;
		
		if(strcmp(H[p].s, "")==0)
			strcpy(H[p].s, tmp);
		else								//此处未对失败情况做限制 
			return ERROR;		
	}
	
	return OK;
}

int fHash_9_44(char s[])		//哈希函数 
{
	return s[0]-'A'+1;			//设定关键字首字母为大写 
}
