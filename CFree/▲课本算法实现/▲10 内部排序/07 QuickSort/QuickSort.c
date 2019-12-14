/****************************
 *                          *
 * 文件夹: ▲10 内部排序    *
 *                          *
 * 文件名: QuickSort.c      *
 *                          *
 * 算  法: 10.6、10.7、10.8 *
 *                          *
 ****************************/

#ifndef QUICKSORT_C
#define QUICKSORT_C

#include "QuickSort.h" 		//**▲10 内部排序**//

/*══════╗
║ 算法10.6(a)║ 
╚══════*/
int Partition_1(SqList_sort *L, int low, int high)
{
	int pivotkey;	
	RcdType tmp;
	
	pivotkey = (*L).r[low].key;					//用子表第一个记录作枢轴记录 
	
	while(low<high)								//从表的两端交替地向中间扫描 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		tmp = (*L).r[high];						//将比枢轴记录小的记录交换到低端 
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp;
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		tmp = (*L).r[high];						//将比枢轴记录大的记录交换到高端
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp; 
	}
	
	return low;									//返回枢轴所在位置 
}

/*══════╗
║ 算法10.6(b)║ 
╚══════*/
int Partition_2(SqList_sort *L, int low, int high)
{
	int pivotkey;
	
	(*L).r[0] = (*L).r[low];					//用子表第一个记录作枢轴记录
	pivotkey = (*L).r[low].key;					//枢轴记录关键字 
	
	while(low<high)								//从表的两端交替地向中间扫描 
	{
		while(low<high && (*L).r[high].key>pivotkey)
			high--;
		
		(*L).r[low] = (*L).r[high];				//将比枢轴记录小的记录交换到低端 
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		(*L).r[high] = (*L).r[low];				//将比枢轴记录大的记录交换到高端
	}
	
	(*L).r[low] = (*L).r[0];					//枢轴记录到位 
	
	return low;									//返回枢轴所在位置 
}

/*════╗
║算法10.7║ 
╚════*/
void QSort(SqList_sort *L, int low, int high)
{
	int pivotloc;
													
	if(low<high)								//长度大于1 
	{
	//	pivotloc = Partition_1(L, low, high);	//将(*L).r[row..high]一分为二
		
		pivotloc = Partition_2(L, low, high);	//将(*L).r[row..high]一分为二
	
		QSort(L, 1, pivotloc-1);				//对低子表递归排序，pivotloc是枢轴位置 
		QSort(L, pivotloc+1, high);				//对高子表递归排序 
	} 
}

/*════╗
║算法10.8║ 
╚════*/
void QuickSort(SqList_sort *L)
{
	QSort(L, 1, (*L).length);
}

#endif
