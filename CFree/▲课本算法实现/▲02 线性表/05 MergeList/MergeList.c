/************************************
 *					                *
 * �ļ���: ��02 ���Ա�\05 MergeList *
 * 					                *
 * �ļ���: MergeList.c              *
 * 				                    *
 * ��  ��: 2.12                     * 
 *                                  *
 ************************************/

#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"					//**��02 ���Ա�**//

/*�T�T�T�T�T�[
�U �㷨2.12 �U 
�^�T�T�T�T�T*/
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{										//ָ��Lb,LcҪ�ı䣬���β���ָ��ָ���ָ�� 
	LinkList pa, pb, pc;
	
	pa = La->next;
	pb = (*Lb)->next;
	pc = *Lc = La;						//��La��ͷ�����ΪLc��ͷ��� 						

	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}	
	}

	pc->next = pa ? pa : pb;			//����ʣ��� 
	
	free(*Lb);							//�ͷ�Lb��ͷ���
	*Lb = NULL; 
}

#endif
