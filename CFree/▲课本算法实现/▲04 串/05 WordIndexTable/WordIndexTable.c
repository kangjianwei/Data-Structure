/*********************************************
 *						                     *
 * �ļ���: ��04 ��\05 WordIndexTable         *
 * 							                 *
 * �ļ���: WordIndexTable.c                  *
 * 				     		                 *
 * ��  ��: 4.9��4.10��4.11��4.12��4.13��4.14 *
 *                                           *
 *********************************************/

#ifndef WORDINDEXTABLE_C
#define WORDINDEXTABLE_C

#include "WordIndexTable.h"					//**��04 ��**//

/*�T�T�T�T�[
�U �㷨4.9�U 
�^�T�T�T�T*/
void Main(char *bookinfo, char *bookidx)
{
	FILE *f, *g;
	char b[MaxLineLen];						//��Ŀ��ʱ������
	IdxListType idxlist;					//�ؼ��������� 
	int i;
	LElemType_E bno;						//���	
	
	if(f=fopen(bookinfo, "r"))				//��ֻ��ģʽ����Ŀ�ļ� 
	{
		if(g=fopen(bookidx,  "w"))
		{
			InitIdxList(&idxlist);			//��ʼ�������� 
			
			fgets(b, MaxLineLen, f);		//�����ļ���һ�� 
			
			while(!feof(f))					//��ʼ��ȡ�ļ�f 
			{
				GetLine(f);					//���ļ�f����һ����Ŀ��Ϣ����Ŀ������gBuf		
				
				ExtractKeyWord(&bno); 		//��gBuf��ȡ�ؼ��ʵ��ʱ�gWdList����Ŵ���bno
				
				InsIdxList(&idxlist, bno); 	//����ż���Ӧ�Ĺؼ��ʲ���������idxlist
			}
			
			PutText(g, idxlist);			//��g��д������ 			
		}
	}
	
	fclose(g);
	fclose(f);								//�ر��ļ�	
}

void InitIdxList(IdxListType *idxlist)
{
	char *chars = "�ؼ���            �������";		//��Ϊ������ı�ͷ 
	
	StrAssign_H(&((*idxlist).item[0].key), chars);
	InitList_E(&((*idxlist).item[0].bnolist));
	
	(*idxlist).num = 0;								//��ͷΪ��0����Ϣ 
}

void GetLine(FILE *f)
{
	int len; 

	fgets(gBuf, MaxLineLen, f);				//�˴���Ҫ������ȡ����b����Ϊ�ַ����飬����Ϊ�ַ�ָ��

	len = strlen(gBuf);						//�������з��ĳ��� 
	
	gBuf[len-1] = '\0';						//���з�����'\0'ȡ�� 
}

void ExtractKeyWord(int *bno)
{
	char *title;
	FILE *fp;	
	
	*bno = strtol(gBuf, &title, 10);							//�ֽ��ַ���gBuf����Ŵ���bno����������title	
	strlwr(title); 												//��д��Сд
		
	fp = tmpfile();												//������ʱ�ļ� 
	fprintf(fp, "%s", title);									//���ַ���д����ʱ�ļ� 
	fseek(fp, 0, SEEK_SET);										//�ļ�ָ���Ƶ���ʼλ�� 	

	for(gWdList.last=0; gWdList.last<MaxWordNum; gWdList.last++)
	{
		gWdList.str[gWdList.last] = (char*)malloc(MaxLineLen*sizeof(char));
		if(!gWdList.str[gWdList.last])
			exit(OVERFLOW);
																//����ʱ�ļ��ж�ȡ�ַ��� 
		if(fscanf(fp, "%s", gWdList.str[gWdList.last])==EOF)	//��ȡʧ�����˳�ѭ�� 
			break;
	}		
}

/*�T�T�T�T�T�[
�U �㷨4.10 �U 
�^�T�T�T�T�T*/
Status InsIdxList(IdxListType *idxlist, int bno)
{
	int i, j;
	Bool boo;
	HString wd;
	
	if(!gWdList.last)
		return ERROR;

	for(i=0; i<gWdList.last; i++)
	{		
		GetWord(i, &wd);							//�öѴ�wd��ȡ�ؼ��ʴʱ��i���ַ���
		
		if(!isCommonWords(wd))						//����˹ؼ��ʲ��ǳ��ôʣ�����Ҫ���в������ 
		{			
			j = Locate(*idxlist, wd, &boo);
	
			if(boo==FALSE)							//��ǰ�ؼ��ʲ����������У��������˹ؼ���
				InsertNewKey(idxlist, j, wd);

			if(!InsertBook(idxlist, j, bno))		//������� 
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
		S = idxlist.item[i].key;					//����ؼ��� 
		for(m=0; m<S.length; m++)
			fprintf(g, "%c", S.ch[m]);
		
		if(i)										//���Ǳ�ͷ 
		{
			for(j=1; j<=18-idxlist.item[i].key.length; j++)		//����һ�������Ŀո���� 
				fprintf(g, " ");
			
			L = idxlist.item[i].bnolist;			//���������� 
			for(n=1,p=L.head->next; n<=L.len; n++)
			{
				fprintf(g, "%03d", p->data);
				p = p->next;
				if(p)
					fprintf(g, "��");
			}
		}
		
		if(i!=idxlist.num)							//δ�����һ�� 
			fprintf(g, "\n");			
	}	
	
}

/*�T�T�T�T�T�[
�U �㷨4.11 �U 
�^�T�T�T�T�T*/
void GetWord(int i, HString *wd)
{
	char *p = gWdList.str[i];
	
	StrAssign_H(wd, p);	
}

/*�T�T�T�T�T�[
�U �㷨4.12 �U 
�^�T�T�T�T�T*/
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

/*�T�T�T�T�T�[
�U �㷨4.13 �U 
�^�T�T�T�T�T*/
void InsertNewKey(IdxListType *idxlist, int i, HString wd)
{
	int j;
	
	for(j=(*idxlist).num; j>=i; j--)					//��������� 
		(*idxlist).item[j+1] = (*idxlist).item[j];

	StrCopy_H(&((*idxlist).item[i].key), wd);			//����������
	
	(*idxlist).num++;									//������Ŀ��һ 

	InitList_E(&((*idxlist).item[i].bnolist)); 
}

/*�T�T�T�T�T�[
�U �㷨4.14 �U 
�^�T�T�T�T�T*/
Status InsertBook(IdxListType *idxlist, int i, LElemType_E bno)
{
	Link p;	

	if(!MakeNode_E(&p, bno))							//����ʧ�� 
		return ERROR;

	Append_E(&((*idxlist).item[i].bnolist), p);			//�����µ��������

	return OK;
}

Status isCommonWords(HString S)				//�˴�ָ����ַ������޿��ַ���β 
{											//���ôʴʱ��е��ַ������п��ַ���β�� 
	int i, len;
	char a[S.length+1];
	Status flag = FALSE;
	
	for(i=0; i<S.length; i++)
		a[i] = S.ch[i];
	a[i] = '\0';
		
	for(i=0; i<gWordList.last; i++)
	{ 	
		if(!strcmpi(a, gWordList.str[i]))	//�����ַ������к��Դ�Сд�ıȽ� 
		{
			flag = TRUE;
			break;							//���ַ���������˳�ѭ�� 
		}
	}
	
	return flag;
}

#endif
