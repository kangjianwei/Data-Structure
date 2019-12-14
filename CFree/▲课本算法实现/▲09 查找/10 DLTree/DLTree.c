/*********************
 *                   *
 * �ļ���: ��09 ���� *
 *                   *
 * �ļ���: DLTree.c  *
 *                   *
 * ��  ��: 9.15      *
 *                   *
 *********************/

#ifndef DLTREE_C
#define DLTREE_C

#include "DLTree.h" 				//**��09 ����**//

Status CreateDLTree(FILE *fp, DLTree *DLT)
{
	KeysType tmp;
	
	*DLT = (DLTree)malloc(sizeof(DLTNode));	//��������� 
	(*DLT)->kind = BRANCH;					//����㶨��Ϊ��֧���
	(*DLT)->symbol = '\0';
	(*DLT)->next = NULL;
	(*DLT)->Ptr.first = NULL; 
	
	while(Scanf(fp, "%s", &(tmp.ch))==1)
	{
		tmp.num = strlen(tmp.ch);
		
		InsertDLTree(DLT, tmp); 
	}
		
	return OK;
}

/*�T�T�T�T�[
�U�㷨9.15�U 
�^�T�T�T�T*/
Record* SearchDLTree(DLTree DLT, KeysType K)
{
	DLTree p;
	int i;
	
	p = DLT->Ptr.first;
	i = 0;
	
	while(p && i<K.num)
	{
		while(p && p->symbol<K.ch[i])
			p = p->next;					//���ҹؼ��ֵĵ�iλ

		if(p && p->symbol==K.ch[i])
		{
			p = p->Ptr.first;				//����������һλ 
			i++;						
		}
		else								//���Ҳ��ɹ���ǿ������ѭ�� 
			p = NULL; 
	}										//���ҽ��� 
	
	if(p && p->kind==LEAF)					//���ҳɹ� 
		return p->Ptr.infoptr;
	else									//����ʧ�� 
		return NULL;
} 

Status InsertDLTree(DLTree *DLT, KeysType K)
{
	DLTree p, q, h;
	int i, j;
	Record *s;
	
	i = 0;
	q = *DLT;								//ָ��������ʱ�����ڶ������
	p = q->Ptr.first;						//ָ��������ʱ���һ����� 
	
	while(p && i<K.num)
	{
		while(p && p->symbol<K.ch[i])
		{
			q = p;
			p = p->next;					//���ҹؼ��ֵĵ�iλ
		}
		
		if(p && p->symbol==K.ch[i])
		{
			q = p;
			p = p->Ptr.first;				//����������һλ 
			i++;						
		}
		else
			break;
	}
	
	if(i<K.num)							//δ������ 
	{
		for(j=i; j<=K.num; j++)			//��K��ʣ����ַ��������� 
		{
			h = (DLTree)malloc(sizeof(DLTNode));
			
			if(j==i)
			{
				h->kind = BRANCH;
				h->symbol = K.ch[j];
				h->next = p;
				h->Ptr.first = NULL;
				
				if(q->Ptr.first==p)		//�ж�p��q�����λ�������»������ҹ�ϵ 
					q->Ptr.first = h;
				else
					q->next = h;
			}
			else if(j>i&&j<K.num)
			{
				h->kind = BRANCH;
				h->symbol = K.ch[j];
				h->next = NULL;
				h->Ptr.first = NULL;
				q->Ptr.first = h;
			}
			else
			{
				h->kind = LEAF;
				h->symbol = '$';
				h->next = NULL;
				s = (char*)malloc((K.num+1)*sizeof(char));
				h->Ptr.infoptr = strcpy(s, K.ch);
				q->Ptr.first = h;
			}
			
			q = h;
		}
	}
	else								//�ѱ����� 
	{
		if(p->symbol=='$')				//��ȫƥ�� 
			return ERROR;				//δ���в������ 
		else							//�����ҹؼ����Ǽ����е�һ���� 
		{
			s = (char*)malloc((K.num+1)*sizeof(char));
			h = (DLTree)malloc(sizeof(DLTNode));
			h->kind = LEAF;
			h->symbol = '$';
			h->next = p;
			h->Ptr.infoptr = strcpy(s, K.ch);
			q->Ptr.first = h;							
		}		
	}
	
	return OK;	
}

void PrintKeys(DLTree DLT)
{
	if(DLT)
	{
		if(DLT->symbol=='\0')
			PrintKeys(DLT->Ptr.first);
		else if(DLT->symbol=='$')
			printf("%s ", DLT->Ptr.infoptr);
		else
			PrintKeys(DLT->Ptr.first);
		PrintKeys(DLT->next);
	}
}

#endif
