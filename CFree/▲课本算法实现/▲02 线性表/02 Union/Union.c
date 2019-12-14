/********************************
 *                              *
 * �ļ���: ��02 ���Ա�\02 Union *
 *                              *
 * �ļ���: Union.c              *
 *                              *
 * ��  ��: 2.1                  * 
 *                              *
 ********************************/

#ifndef UNION_C
#define UNION_C

#include "Union.h"							//**��02 ���Ա�**//

/*�T�T�T�T�[
�U �㷨2.1�U 
�^�T�T�T�T*/
void Union(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	int i;
	LElemType_Sq e;
	
	La_len = ListLength_Sq(*La);			//��˳����� 
	Lb_len = ListLength_Sq(Lb);
	
	for(i=1; i<=Lb_len; i++)
	{
		GetElem_Sq(Lb, i, &e);				//ȡLb�е�i��Ԫ�ظ���e 
		if(!LocateElem_Sq(*La, e, equal)) 	//��e����La�������
			ListInsert_Sq(La, ++La_len, e);	
	}
}

Status equal(LElemType_Sq e1, LElemType_Sq e2)
{
   return e1==e2 ? TRUE : FALSE;
}

#endif
