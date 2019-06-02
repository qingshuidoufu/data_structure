#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100  //线性表的初始空间分配量 
#define LISTINCREMENT 10 		//线性表的存储空间增量 
typedef char ElemType;			//数据元素的类型，假设是int 
typedef struct {
	ElemType* elem;			//储存位置的基础地址 
	int length;				//当前线性表的长度 
	int listsize;			//当前分配的储存容量 ;
}SqList;

//创建线性表

int InitList(SqList& L)
{
	//开辟一个存储空间，并把这个空间的基地址赋值给elem 
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) {
		return -1;		//空间分配失败 
	}
	L.length = 0;			//当前长度
	L.listsize = LIST_INIT_SIZE;		//当前分配量 
	return 0;
}

//查找元素

int LocateElem(SqList L, ElemType x)
{
	int pos = -1;
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.elem[i] == x) {
			pos = i;
		}
	}
	return pos;
}

//插入元素

int ListInsert(SqList& L, int i, ElemType e)
{
	//判断插入位置的合法性
	if (i<1 || i>L.length + 1) {
		return -1;
	}
	//判断储存空间是否够用
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			return -1;	//储存空间分配失败 
		}
		L.elem = newbase;	//新的基址 
		L.listsize += LISTINCREMENT;		//增加储存用量 
	}
	//插入操作
	ElemType* q, * p;		//定义两个指针用量
	q = &(L.elem[i - 1]);		//q为插入位置（注意形参i是序号，序号是从1开始的，而下标是从0开始的，因此这里转成下标后是i-1）
	for (p = &(L.elem[L.length - 1]); p >= q; --p)	 //从ai到an-1依次后移，注意后移操作要从后往前进行 
		* (p + 1) = *p;
	*q = e;
	++L.length;		//表长加一 
	return 0;
}
//删除元素
int ListDelete(SqList& L, int i, ElemType& e)
{
	//判断删除位置的合法性
	if (i<1 || i>L.length)
	{
		return -1;
	}
	//删除操作
	ElemType* q, * p;  	//定义两个指针变量
	p = &(L.elem[i - 1]);	//p为被删除元素的位置（注意形参i是序号，序号是从从1开始的，而下标是从0开始的，因此这里转成下标后是i-1)
	e = *p;		//被删除的元素赋给e（可能用不到，也可能用到） 
	q = L.elem + L.length - 1;	//q指向表尾的最后一个元素（q是最后一个元素的地址）
	for (++p; p <= q; ++p)		//从p的下一个元素开始依次前移
	{
		*(p - 1) = *p;
	}
	--L.length;		//表长减一
	return 0;
}

