 /********************
 *                   *
 * �ļ���: ��09 ���� *
 *                   *
 * �ļ���: Base.c    *
 *                   *
 *********************/

#ifndef BASE_C
#define BASE_C

#include "Base.h" 					//**��09 ����**//

Status Create(FILE *fp, Table *T, int n)
{
	int i;
	int a;
	float b;
	 
	T->elem = (ElemType_Search *)malloc((n+1)*sizeof(ElemType_Search));
	if(!(T->elem))
		exit(OVERFLOW);
	
	//�˱�0�ŵ�Ԫ�����õ� 
	for((*T).length=0,i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d%f", &a, &b)==2)
		{
			(*T).elem[i].key = a;
			(*T).elem[i].weight = b;
			(*T).length++;
		}
	}
	
	return OK;
}

void Destory(Table *T)
{
	if(T->elem)
		free(T->elem);
	
	T->elem = NULL;
	T->length = 0;
}

void Traverse(Table T, void(Visit)(ElemType_Search))
{
	int i;
	
	for(i=0; i<T.length; i++)
	{
		if(i && !(i%10))
			printf("\n");
		
		Visit(T.elem[i+1]);
	}
	
	printf("\n");	
}

/* ������ұ��еĹؼ��� */
void PrintKey(ElemType_Search e)
{
	printf("%3d ", e.key);
}

#endif
