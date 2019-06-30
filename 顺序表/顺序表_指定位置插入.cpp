#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxSize 100

typedef int ElemType;

typedef struct sqlist {

	ElemType list[MaxSize];

	int size;

}SqList;

void InitSqList(SqList* L) {//1初始化顺序表

	L->size = 0;

}

int ListLength(SqList L) {//2求顺序表长度 

	return L.size;

}

//--------顺序表的指定位置操作---------

int ListInsert(SqList* L, int i, ElemType x) {//7在顺序表的位置i插入值为x的元素 

	int j;

	if (L->size >= MaxSize) {

		printf("list is full.\n"); return 0;

	}

	if (i<0 || i>L->size) {

		printf("Parameter illegal\n"); return 0;

	}

	//1 

	for (j = L->size; j > i; j--) {
		L->list[j] = L->list[j - 1];


	}

	L->list[i] = x;

	//2
	L->size++;
	return 1;

}

int ListDelete(SqList* L, int i, ElemType* x) { //8删除顺序表的位置i元素，其值存入指针x所指单元 

	int j;

	if (L->size <= 0) {

		printf("There is no element in the sequence table that can be deleted.\n");

		*x = -12345;

		return 0;

	}

	if (i<0 || i>L->size - 1) {

		printf("Parameter illegal.\n"); *x = -12345; return 0;

	}

	*x = L->list[i]; ;//3 	

	for (j = i + 1; j <= L->size - 1; j++) {

		L->list[j - 1] = L->list[j]; ;//4

	}

	L->size--; //5 

	return 1;

}

int ListUpdate(SqList* L, int i, ElemType x) {//9修改顺序表的位置i元素之值为x

	if (i<0 || i>L->size - 1) {

		printf("Parameter illegal.\n"); return 0;

	}

	L->list[i] = x;// 6 

	return 1;

}

int ListGet(SqList L, int i, ElemType* x) {////10获取顺序表的i位置元素之值,其值存入指针x所指单元

	if (i<0 || i>L.size - 1) {

		printf("Parameter illegal.\n"); *x = -12345; return 0;

	}

	*x = L.list[i];// 7

	return 1;

}

int ShowSeqList(SqList* L) {//11打印顺序表中所有元素

	int i;

	if (L->size == 0) {

		printf("There is no element in the sequence table.\n"); return 0;

	}

	for (i = 0; i < L->size; i++)

		printf("%d ", L->list[i]);

	printf("\n");

	return 1;

}

int main() {

	SqList my_list;

	int x, i;

	int switch_num;

	scanf("%d", &switch_num);

	switch (switch_num) {

	case 1: InitSqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//第一次头插入 

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//第二次头插入  

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//第三次头插入

		scanf("%d", &x);

		ShowSeqList(&my_list);

		ListInsert(&my_list, 3, x);//第一次尾插入 ，第二个参数为什么是3？ 

		scanf("%d", &x);

		ListInsert(&my_list, 4, x);//第二次尾插入 ，第二个参数为什么是4？

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 2, x);//	在位置2插入

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 3, x);//	在位置3插入	

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 5, x);//	在位置5插入		   

		ShowSeqList(&my_list);

		break;

	case 2: InitSqList(&my_list);

		for (i = 1; i <= 10; i++)

			ListInsert(&my_list, 0, i);

		ShowSeqList(&my_list);

		ListInsert(&my_list, -1, 100);//第一个非法位置，小于0位置 

		ListInsert(&my_list, my_list.size + 1, 100);//第二个非法位置，大于尾位置 ,为什么最小是 

		//ShowSeqList(&my_list);                  // my_list.size+1？ 

		break;

	case 3: InitSqList(&my_list);

		for (i = 1; i <= 10; i++)

			ListInsert(&my_list, 0, i);

		ShowSeqList(&my_list);

		ListDelete(&my_list, 0, &x);

		printf("The 1st PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 0, &x);

		printf("The 2nd PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 0, &x);

		printf("The 3rd PopBack delete  num = %d    .   \n", x);

		ShowSeqList(&my_list);//3次头删除后的结果 



		ListDelete(&my_list, 6, &x);

		printf("The 1st PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 5, &x);

		printf("The 2rd PopBack delete  num = %d    .   \n", x);

		ShowSeqList(&my_list);//2次尾删除后的结果 



		ListDelete(&my_list, 2, &x);

		printf("The 1st PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 3, &x);

		printf("The 2rd PopBack delete  num = %d    .   \n", x);

		ShowSeqList(&my_list);//2次指定位置删除后的结果



		ListDelete(&my_list, -1, &x);//第一个非法位置，小于0位置 

		ListDelete(&my_list, my_list.size, &x);//第二个非法位置，大于尾位置

		ShowSeqList(&my_list);

		break;

	case 4:	InitSqList(&my_list);

		for (i = 1; i <= 10; i++)

			ListInsert(&my_list, 0, i);

		ShowSeqList(&my_list);

		ListUpdate(&my_list, 0, 100);

		ListUpdate(&my_list, 3, 1000);

		ListUpdate(&my_list, my_list.size - 1, 10000);

		ShowSeqList(&my_list);

		ListUpdate(&my_list, -1, 100000);

		ListUpdate(&my_list, my_list.size, 100000);

		break;

	case 5: InitSqList(&my_list);

		for (i = 1; i <= 10; i++)

			ListInsert(&my_list, 0, i);

		ShowSeqList(&my_list);

		ListGet(my_list, 0, &x);

		printf("The 0 num = %d    .   \n", x);

		ListGet(my_list, 3, &x);

		printf("The 3 num = %d    .   \n", x);

		ListGet(my_list, my_list.size - 1, &x);

		printf("The last num = %d    .   \n", x);

		ListGet(my_list, -1, &x);

		ListGet(my_list, my_list.size, &x);

		break;

	}

	return 0;

}