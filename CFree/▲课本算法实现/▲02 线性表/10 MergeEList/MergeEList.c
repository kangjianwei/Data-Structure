/*************************************
 *					                 *
 * �ļ���: ��02 ���Ա�\10 MergeEList *
 * 					                 *
 * �ļ���: MergeEList.c              *
 * 				                     *
 * ��  ��: 2.21                      * 
 *                                   *
 *************************************/

#ifndef MERGEELIST_C
#define MERGEELIST_C

#include "MergeEList.h"					//**��02 ���Ա�**//

/*�T�T�T�T�T�[
�U �㷨2.21 �U 
�^�T�T�T�T�T*/
Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(Compare)(LElemType_E c1, LElemType_E c2))
{
	Link ha, hb, pa, pb, q;
	LElemType_E c1, c2;

	if(!InitList_E(Lc))					//�洢����ʧ�� 
		return ERROR;

	ha = GetHead_E(La); 				//haָ��Laͷ���
	hb = GetHead_E(Lb); 				//hbָ��Lbͷ���
	pa = NextPos_E(ha);					//paָ��La��һ����� 
	pb = NextPos_E(hb);					//pbָ��Lb��һ�����
	while(!ListEmpty_E(La) && !ListEmpty_E(Lb))
	{									//La��Lb�ǿ� 
		c1 = GetCurElem_E(pa);			//c1��c2Ϊ��ǰ�Ƚϵ�Ԫ��
		c2 = GetCurElem_E(pb);
		if(Compare(c1, c2)<=0)
		{
			DelFirst_E(&La, ha, &q);
			InsFirst_E(Lc, (*Lc).tail, q);
			pa = NextPos_E(ha);
		}
		else
		{
			DelFirst_E(&Lb, hb, &q);
			InsFirst_E(Lc, (*Lc).tail, q);
			pb=NextPos_E(hb);
		}
	}

	if(!ListEmpty_E(La))
		Append_E(Lc, pa);
	else
		Append_E(Lc, pb);

	FreeNode_E(&ha);
	FreeNode_E(&hb);

	return OK;
}

int Cmp(LElemType_E c1, LElemType_E c2)
{
	return c1-c2;
}

Status CreateList_ascend(FILE *fp, ELinkList *L, int count)
{													//���ǽ������д�������L 
	int i;
	LElemType_E e;
		
	InitList_E(L);
	if(!L)
		return ERROR;

	for(i=1; i<=count; i++)
	{	
		Scanf(fp, "%d", &e);
		ListInsert_L_E(L, i, e);
	}
	
	return OK;
}

#endif
