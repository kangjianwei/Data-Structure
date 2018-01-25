#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲12 文件/01 SequentialFile/MergeFile.c"	//**▲12 文件**//

/* 函数原型 */
void Algo_12_11(FILE *f, FILE *g, FILE *h, FILE *log);

int main(int argc, char *argv[])
{
	FILE *f, *g, *h, *log;
	FILE *fp;
			
	printf("创建并输出主文件f和事务文件g...\n");
	f = fopen("main.file", "w+");
	g = fopen("affair.file", "w+");
	InitFile(f,g);
	printf("◆主文件记录：");
	fp = fopen("main.file", "r");
	Print(fp, 0);
	printf("◆事务文件记录：");
	fp = fopen("affair.file", "r");
	Print(fp, 1);
	printf("\n");	

	printf("根据主文件f和事务文件g创建新文件h...\n");	
	f = fopen("main.file", "r");	
	g = fopen("affair.file", "r");	
	h = fopen("new.file", "w+");
	MergeFile(f, g, h, log);	
	printf("◆新文件记录：");
	fp = fopen("new.file", "r");
	Print(fp, 0);
	printf("◆错误日志记录：");
	if((fp=fopen("ErrorLog.file", "r"))!=NULL)
		Print(fp, 1);
	printf("\n\n");
	
	system("del *.file"); 			//删除*.file文件 
	
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题12.11：归并主文件和事务文件 ┃
┗━━━━━━━━━━━━━━━*/
void Algo_12_11(FILE *f, FILE *g, FILE *h, FILE *log)	
{
	MergeFile(f, g, h, log);				 
}
