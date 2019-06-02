#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100  //���Ա�ĳ�ʼ�ռ������ 
#define LISTINCREMENT 10 		//���Ա�Ĵ洢�ռ����� 
typedef char ElemType;			//����Ԫ�ص����ͣ�������int 
typedef struct {
	ElemType* elem;			//����λ�õĻ�����ַ 
	int length;				//��ǰ���Ա�ĳ��� 
	int listsize;			//��ǰ����Ĵ������� ;
}SqList;

//�������Ա�

int InitList(SqList& L)
{
	//����һ���洢�ռ䣬��������ռ�Ļ���ַ��ֵ��elem 
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) {
		return -1;		//�ռ����ʧ�� 
	}
	L.length = 0;			//��ǰ����
	L.listsize = LIST_INIT_SIZE;		//��ǰ������ 
	return 0;
}

//����Ԫ��

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

//����Ԫ��

int ListInsert(SqList& L, int i, ElemType e)
{
	//�жϲ���λ�õĺϷ���
	if (i<1 || i>L.length + 1) {
		return -1;
	}
	//�жϴ���ռ��Ƿ���
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			return -1;	//����ռ����ʧ�� 
		}
		L.elem = newbase;	//�µĻ�ַ 
		L.listsize += LISTINCREMENT;		//���Ӵ������� 
	}
	//�������
	ElemType* q, * p;		//��������ָ������
	q = &(L.elem[i - 1]);		//qΪ����λ�ã�ע���β�i����ţ�����Ǵ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1��
	for (p = &(L.elem[L.length - 1]); p >= q; --p)	 //��ai��an-1���κ��ƣ�ע����Ʋ���Ҫ�Ӻ���ǰ���� 
		* (p + 1) = *p;
	*q = e;
	++L.length;		//����һ 
	return 0;
}
//ɾ��Ԫ��
int ListDelete(SqList& L, int i, ElemType& e)
{
	//�ж�ɾ��λ�õĺϷ���
	if (i<1 || i>L.length)
	{
		return -1;
	}
	//ɾ������
	ElemType* q, * p;  	//��������ָ�����
	p = &(L.elem[i - 1]);	//pΪ��ɾ��Ԫ�ص�λ�ã�ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
	e = *p;		//��ɾ����Ԫ�ظ���e�������ò�����Ҳ�����õ��� 
	q = L.elem + L.length - 1;	//qָ���β�����һ��Ԫ�أ�q�����һ��Ԫ�صĵ�ַ��
	for (++p; p <= q; ++p)		//��p����һ��Ԫ�ؿ�ʼ����ǰ��
	{
		*(p - 1) = *p;
	}
	--L.length;		//����һ
	return 0;
}

