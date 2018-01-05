/*********************************************
 *						                     *
 * 文件夹: ▲04 串\05 WordIndexTable         *
 * 							                 *
 * 文件名: WordIndexTable.c                  *
 * 				     		                 *
 * 算  法: 4.9、4.10、4.11、4.12、4.13、4.14 *
 *                                           *
 *********************************************/

#ifndef WORDINDEXTABLE_C
#define WORDINDEXTABLE_C

#include "WordIndexTable.h"					//**▲04 串**//

/*════╗
║ 算法4.9║ 
╚════*/
void Main(char *bookinfo, char *bookidx)
{
	FILE *f, *g;
	char b[MaxLineLen];						//书目临时缓存区
	IdxListType idxlist;					//关键词索引表 
	int i;
	LElemType_E bno;						//书号	
	
	if(f=fopen(bookinfo, "r"))				//以只读模式打开书目文件 
	{
		if(g=fopen(bookidx,  "w"))
		{
			InitIdxList(&idxlist);			//初始化索引表 
			
			fgets(b, MaxLineLen, f);		//跳过文件第一行 
			
			while(!feof(f))					//开始读取文件f 
			{
				GetLine(f);					//从文件f读入一个书目信息到书目缓冲区gBuf		
				
				ExtractKeyWord(&bno); 		//从gBuf提取关键词到词表gWdList，书号存入bno
				
				InsIdxList(&idxlist, bno); 	//将书号及对应的关键词插入索引表idxlist
			}
			
			PutText(g, idxlist);			//向g中写入数据 			
		}
	}
	
	fclose(g);
	fclose(f);								//关闭文件	
}

void InitIdxList(IdxListType *idxlist)
{
	char *chars = "关键词            书号索引";		//作为索引表的表头 
	
	StrAssign_H(&((*idxlist).item[0].key), chars);
	InitList_E(&((*idxlist).item[0].bnolist));
	
	(*idxlist).num = 0;								//表头为第0条信息 
}

void GetLine(FILE *f)
{
	int len; 

	fgets(gBuf, MaxLineLen, f);				//此处需要反复读取，故b必须为字符数组，不可为字符指针

	len = strlen(gBuf);						//包括换行符的长度 
	
	gBuf[len-1] = '\0';						//换行符处用'\0'取代 
}

void ExtractKeyWord(int *bno)
{
	char *title;
	FILE *fp;	
	
	*bno = strtol(gBuf, &title, 10);							//分解字符串gBuf，书号存入bno，书名存入title	
	strlwr(title); 												//大写变小写
		
	fp = tmpfile();												//建立临时文件 
	fprintf(fp, "%s", title);									//把字符串写入临时文件 
	fseek(fp, 0, SEEK_SET);										//文件指针移到起始位置 	

	for(gWdList.last=0; gWdList.last<MaxWordNum; gWdList.last++)
	{
		gWdList.str[gWdList.last] = (char*)malloc(MaxLineLen*sizeof(char));
		if(!gWdList.str[gWdList.last])
			exit(OVERFLOW);
																//从临时文件中读取字符串 
		if(fscanf(fp, "%s", gWdList.str[gWdList.last])==EOF)	//读取失败则退出循环 
			break;
	}		
}

/*═════╗
║ 算法4.10 ║ 
╚═════*/
Status InsIdxList(IdxListType *idxlist, int bno)
{
	int i, j;
	Bool boo;
	HString wd;
	
	if(!gWdList.last)
		return ERROR;

	for(i=0; i<gWdList.last; i++)
	{		
		GetWord(i, &wd);							//用堆串wd获取关键词词表第i个字符串
		
		if(!isCommonWords(wd))						//如果此关键词不是常用词，则需要进行插入操作 
		{			
			j = Locate(*idxlist, wd, &boo);
	
			if(boo==FALSE)							//当前关键词不在索引表中，则需插入此关键词
				InsertNewKey(idxlist, j, wd);

			if(!InsertBook(idxlist, j, bno))		//插入书号 
				return ERROR;				
		}		
	}
	return OK;
}

void PutText(FILE *g, IdxListType idxlist)
{
	int i, j, m, n;
	Link p;
	HString S;
	ELinkList L;
	
	for(i=0; i<=idxlist.num; i++)
	{
		S = idxlist.item[i].key;					//输出关键词 
		for(m=0; m<S.length; m++)
			fprintf(g, "%c", S.ch[m]);
		
		if(i)										//不是表头 
		{
			for(j=1; j<=18-idxlist.item[i].key.length; j++)		//输入一定数量的空格隔开 
				fprintf(g, " ");
			
			L = idxlist.item[i].bnolist;			//输出书号索引 
			for(n=1,p=L.head->next; n<=L.len; n++)
			{
				fprintf(g, "%03d", p->data);
				p = p->next;
				if(p)
					fprintf(g, "，");
			}
		}
		
		if(i!=idxlist.num)							//未到最后一行 
			fprintf(g, "\n");			
	}	
	
}

/*═════╗
║ 算法4.11 ║ 
╚═════*/
void GetWord(int i, HString *wd)
{
	char *p = gWdList.str[i];
	
	StrAssign_H(wd, p);	
}

/*═════╗
║ 算法4.12 ║ 
╚═════*/
int Locate(IdxListType idxlist, HString wd, Bool *b)
{
	int i, m;
	
	for(i=idxlist.num; i>0 && (m=StrCompare_H(idxlist.item[i].key,wd))>0; i--);
	
	if(m==0 && idxlist.num!=0)
	{
		*b = TRUE;
		return i;
	}
	else
	{
		*b = FALSE;
		return i+1;
	}	
}

/*═════╗
║ 算法4.13 ║ 
╚═════*/
void InsertNewKey(IdxListType *idxlist, int i, HString wd)
{
	int j;
	
	for(j=(*idxlist).num; j>=i; j--)					//索引项后移 
		(*idxlist).item[j+1] = (*idxlist).item[j];

	StrCopy_H(&((*idxlist).item[i].key), wd);			//插入索引项
	
	(*idxlist).num++;									//索引书目增一 

	InitList_E(&((*idxlist).item[i].bnolist)); 
}

/*═════╗
║ 算法4.14 ║ 
╚═════*/
Status InsertBook(IdxListType *idxlist, int i, LElemType_E bno)
{
	Link p;	

	if(!MakeNode_E(&p, bno))							//分配失败 
		return ERROR;

	Append_E(&((*idxlist).item[i].bnolist), p);			//插入新的书号索引

	return OK;
}

Status isCommonWords(HString S)				//此处指向的字符串并无空字符结尾 
{											//常用词词表中的字符串是有空字符结尾的 
	int i, len;
	char a[S.length+1];
	Status flag = FALSE;
	
	for(i=0; i<S.length; i++)
		a[i] = S.ch[i];
	a[i] = '\0';
		
	for(i=0; i<gWordList.last; i++)
	{ 	
		if(!strcmpi(a, gWordList.str[i]))	//对两字符串进行忽略大小写的比较 
		{
			flag = TRUE;
			break;							//两字符串相等则退出循环 
		}
	}
	
	return flag;
}

#endif
