/******************************
 *                            *
 * �ļ���: ��09 ����          *
 *                            *
 * �ļ���: TrieTree.h         *
 *                            *
 * ��  ��: Trie����ز����б� *
 *                            *
 ******************************/

#ifndef TRIETREE_H
#define TRIETREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>						//�ṩisalphaԭ�� 
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* �궨�� */
#define MAXKEYLEN 26							//�ؼ��ֵ���󳤶� 

/* ���Ͷ��� */
typedef enum{ LEAF, BRANCH }NodeKind;			//������ࣺ0-Ҷ�ӣ�1-��֧
typedef struct
{
	char ch[MAXKEYLEN+1];						//�ؼ��� 
	int num;									//�ؼ��ֳ��� 
}KeysType;										//�ؼ������� 
typedef struct									//Ҷ�ӽ��ļ�¼����
{
	char key[MAXKEYLEN+1];
}Record;										//��¼���� 
typedef struct TrieNode							//Trie���洢��ʾ
{
	NodeKind kind;								//�������	 
	union
	{
		struct
		{	
			struct TrieNode* ptr[MAXKEYLEN+1];	//�洢26��Ӣ����ĸ��1��"��"��ĸ 
			int count;							//��ǰ��֧�����ռ�õ���ĸ�� 
		}bh;									//��֧��� 
		
		struct
		{
			KeysType K;
			Record *infoptr;
		}lf;									//Ҷ�ӽ�� 
	}Ptr;
}TrieNode;										//Trie����� 
typedef TrieNode* TrieTree;						//ָ��Trie������ָ��

/* Trie�������б� */
Status CreateTrie(FILE *fp, TrieTree *TT);
/*����������������
��(01)����Trie����
����������������*/

Record* SearchTrie(TrieTree TT, KeysType K);
/*��������������������
��(02)�㷨9.16�����ҩ�
��������������������*/

Status InsertTrie(TrieTree *TT, Record R); 
/*��������������
��(03)�����¼��
��������������*/

Status DeleteTrie(TrieTree *TT, KeysType K);
/*����������������������������
��(04)ɾ�����йؼ���K�ļ�¼ ��
����������������������������*/

int ord(char ch); 
/*������������������������������������
��(05)�����ַ�ch��Trie������е�λ��
������������������������������������*/

Status cmp(KeysType A, KeysType B);
/*��������������������������
��(06)�жϽṹA��B�Ƿ���ȩ�
��������������������������*/

void TraverseTrie(TrieTree TT, void(Visit)(Record*)); 
/*����������������
��(07)����Trie����
����������������*/

#endif 
