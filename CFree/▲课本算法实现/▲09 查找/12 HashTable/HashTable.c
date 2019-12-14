/***********************
 *                     *
 * �ļ���: ��09 ����   *
 *                     *
 * �ļ���: HashTable.c *
 *                     *
 * ��  ��: 9.17��9.18  *
 *                     *
 ***********************/

#ifndef HASHTABLE_C
#define HASHTABLE_C

#include "HashTable.h" 				//**��09 ����**//

void InitHash(HashTable *H)
{
	(*H).count = 0;
	(*H).sizeindex = -1;
	(*H).elem = NULL;
}

Status CreateHash(HashTable *H, Table T)
{
	int i, tag;
	
	InitHash(H);
	
	RecreateHashTable(H);
	
	i=1;
	while(i<=T.length)				//��T�йؼ������β��뵽��ϣ����
	{
		tag = InsertHash(H, T.elem[i].key);
		if(tag==SUCCESS)			//�������йؼ��ֻ�ؼ���˳������ 
			i++;
		else						//�ؽ���ϣ���������� 
			i=1;
	}
	
	return OK;
}

/*�T�T�T�T�[
�U�㷨9.17�U 
�^�T�T�T�T*/
//��д�˿α��㷨 
Status SearchHash(HashTable H, KeyType K, int *p)
{
	int c, sup;
	
	c = 0;							//��¼��ͻ���� 	
	sup = hashsize[H.sizeindex]/2;	//��ͻ���� 
	*p = fHash(H, K);				//pָ��KӦ�ò���ĵ�ַ 	

	while(1)						//��λ���м�¼����K����
	{
		if(H.elem[*p]==NULLKEY)
			return NULLKEY;			
		else if(EQ(H.elem[*p], K))
			return DUPLICATE;		//�������д˹ؼ���
		else if(++c==sup)			//�Ѵ��ͻ���� 
			return FULL;
		else
			collision(H, p);		//���¶�λp�ĵ�ַ 
	}
} 

/*�T�T�T�T�[
�U�㷨9.18�U 
�^�T�T�T�T*/
//��д�˿α��㷨 
Status InsertHash(HashTable *H, KeyType K)
{
	int flag, p; 

	flag = SearchHash(*H, K, &p);
	
	if(flag==FULL)				//������ 
	{
		RecreateHashTable(H);	//�ؽ���ϣ��  
		return UNSUCCESS;
	}		
	else
	{
		if(flag==NULLKEY)
		{
			H->elem[p] = K;		//����K
			++(*H).count;
		}
		return SUCCESS; 
	}
}

Status RecreateHashTable(HashTable *H)
{
	int i, newv;
	HashTable *p;
	
	(*H).count = 0;
	(*H).sizeindex++;
	newv = hashsize[(*H).sizeindex];
	 
	if((*H).elem!=NULL)
		free((*H).elem);
	
	//�����˹�ϣ������
	(*H).elem = (KeyType *)malloc(newv*sizeof(KeyType));
	if((*H).elem==NULL)
		return ERROR;
		
	for(i=0; i<newv; i++)
		(*H).elem[i] = NULLKEY;
	
	return OK;
}

int fHash(HashTable H, KeyType K)	//ֻ�Ǽ򵥵�ȡ�� 
{	
	return K % hashsize[H.sizeindex];
}

void collision(HashTable H, int *p)	//�򵥵���λ 
{
	*p = (*p+1)%hashsize[H.sizeindex];
}

void PrintHash(HashTable H)
{
	int i, v;
	
	v = hashsize[H.sizeindex];
	
	printf("��ϣ������Ϊ��%d������Ԫ�أ�%d ��������Ԫ��Ϊ��\n", v, H.count);
	
	for(i=0; i<v; i++)
	{
		if(H.elem[i]!=NULLKEY)
			printf("%d ",H.elem[i]);
	}
	
	printf("\n");
}

#endif
