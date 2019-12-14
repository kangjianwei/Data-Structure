#include <stdio.h>
#include <stdlib.h>												//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	        //**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_35(FILE *fp, GList *L);
Status Creat_5_35(FILE *fp, GList *L);		//创建头尾链表存储表示的广义表

int main(int argc, char *argv[])
{
	GList L;	
	FILE *fp;
	
	printf("创建广义表 L ...\n");
	fp = fopen("Data/Algo_5_35.txt", "r");
	Algo_5_35(fp, &L);
	fclose(fp);
		
	printf("L = ");
	Output_GL_H_T(L, 0);	
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━┓
┃题5.35：创建广义表┃
┗━━━━━━━━━*/ 
Status Algo_5_35(FILE *fp, GList *L)	 
{
	char ch;
	
	ch = getc(fp);
	if(ch=='(')								//跳过开头首个'(' 
	{
		if(Creat_5_35(fp, L))				//开始创建广义表 
			return OK;
	}
	
	return ERROR;
}

Status Creat_5_35(FILE *fp, GList *L)
{
	char ch;
	
	ch = getc(fp);
	
	if(ch==' ')					//处理空表 
	{
		*L = NULL;
		if(getc(fp)!=')')
			return ERROR;
	}
	else
	{
		*L = (GList)malloc(sizeof(GLNode));	//处理非空表情况 
		if(!*L)
			exit(OVERFLOW);	
		(*L)->tag = List;
		
		if(ch>='a' && ch<='z')				//若表元素是原子，则建原子结点 
		{
			(*L)->Union.ptr.hp = (GList)malloc(sizeof(GLNode));
			(*L)->Union.ptr.hp->tag = Atom;
			(*L)->Union.ptr.hp->Union.atom = ch;
		}
		else if(ch=='(')					//若表元素是表，则新建表结点 									
			Creat_5_35(fp, &((*L)->Union.ptr.hp));
		else
			return ERROR;
		
		ch = getc(fp);						//当前结点收尾 
		
		if(ch==')')							//当前结点后再无结点 
			(*L)->Union.ptr.tp = NULL;
		else if(ch==',')					//当前结点后仍有结点 
			Creat_5_35(fp, &((*L)->Union.ptr.tp));
		else
			return ERROR;	
	}
	
	return OK;	
}
