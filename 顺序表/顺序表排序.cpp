#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct sqlist {
	ElemType list[MaxSize];
	int size;
}SqList;
//1初始化顺序表
void InitSqList(SqList* L) {
	L->size = 0;
}

//2求顺序表长度 
int ListLength(SqList L) {
	return L.size;
}
int PushFront(SqList* L, ElemType x) {//5在顺序表的头部插入值为data的元素
	int j;
	if (L->size >= MaxSize) {
		printf("list is full.\n"); return 0;
	}
	for (j = L->size; j >= 1; j--) {
		L->list[j] = L->list[j - 1];
	}
	L->list[0] = x;
	L->size++;
	return 1;
}
int ListUpdate(SqList* L, int i, ElemType x) {//9修改顺序表的位置i元素之值为x
	if (i<0 || i>L->size - 1) {
		printf("Parameter illegal.\n"); return 0;
	}
	L->list[i] = x;
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

void BubbleSort(SqList* L) {//16使用冒泡排序给顺序表中的元素排序
	int i, j, temp;    int flag = 1;
	for (i = 1; i < L->size && flag == 1; i++) {
		flag = 0;
		for (j = 0; j < L->size - i; j++) {
			if (L->list[j] > L->list[j + 1]) {
				temp = L->list[j];
				L->list[j] = L->list[j + 1];
				L->list[j + 1] = temp;
				flag = 1;
			}
		}
	}
}
void SelectSort(SqList* L) {//17使用选择排序给顺序表中的元素排序
	int i, j, min, temp;
	for (i = 0; i <= L->size - 1; i++) {
		min = i;
		for (j = i + 1; j <= L->size - 1; j++)
			if (L->list[j] < L->list[min])
				min = j;
		if (min != i) {
			temp = L->list[i];
			L->list[i] = L->list[min];
			L->list[min] = temp;
		}
	}
}

void InsertSort(SqList* L) {//18直接插入排序：将第一个数据看做一个顺序表，将后面的数据一次插入表中
	int i, j, x;
	for (i = 1; i < L->size; i++) {
		if (L->list[i] < L->list[i - 1]) {//若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入  
			j = i - 1;   //表中最后一个数据
			x = L->list[i];        //复制为哨兵，即存储待排序元素  
			L->list[i] = L->list[i - 1];           //先后移一个元素 (因为a[i]就是X，所以不怕丢失) 
			while (j >= 0 && x < L->list[j]) {  //查找在有序表的插入位置  (遍历表)
				L->list[j + 1] = L->list[j];
				j--;         //元素后移  
			}
			L->list[j + 1] = x;      //插入到正确位置  
		}
	}
}
void BInsertSort(SqList* L) { //折半插入
	int i, j, low, high, x, m;
	for (i = 1; i < L->size; i++) {
		low = 0, high = i;
		if (L->list[i] < L->list[i - 1]) {//若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入  
			x = L->list[i];        //复制为哨兵，即存储待排序元素  
			L->list[i] = L->list[i - 1];           //先后移一个元素 (因为a[i]就是X，所以不怕丢失) 
			while (low <= high) {  //查找在有序表的插入位置  (遍历表)
				m = (low + high) / 2;
				if (x < L->list[m])  high = m - 1;
				else low = m + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
				L->list[j + 1] = L->list[j];
			L->list[j + 1] = x;      //插入到正确位置  
		}
	}
}
void DecendSort(SqList* L) {//16使用冒泡排序给顺序表中的元素排序
	int i, j, temp;    int flag = 1;
	for (i = 1; i < L->size && flag == 1; i++) {
		flag = 0;
		for (j = 0; j < L->size - i; j++) {
			if (L->list[j] < L->list[j + 1]) {
				temp = L->list[j];
				L->list[j] = L->list[j + 1];
				L->list[j + 1] = temp;
				flag = 1;
			}
		}
	}
}
//--------主函数-------- 
int main() {
	SqList my_list;
	int x, n, i, num;
	int switch_num;
	scanf("%d", &switch_num);
	InitSqList(&my_list);
	for (i = 1; i <= 18; i++)
		PushFront(&my_list, i);
	ListUpdate(&my_list, 17, -9);
	ListUpdate(&my_list, 15, 23);
	ListUpdate(&my_list, 13, -1);
	ListUpdate(&my_list, 11, -16);
	ListUpdate(&my_list, 9, -2);
	ListUpdate(&my_list, 7, 10);
	ListUpdate(&my_list, 5, -10);
	ListUpdate(&my_list, 3, 21);
	ListUpdate(&my_list, 1, 100);
	ListUpdate(&my_list, 0, 30);

	ShowSeqList(&my_list);

	switch (switch_num) {
	case 1:	BubbleSort(&my_list); ShowSeqList(&my_list); break;
	case 2: SelectSort(&my_list); ShowSeqList(&my_list); break;
	case 3: InsertSort(&my_list); ShowSeqList(&my_list); break;
	case 4: BInsertSort(&my_list); ShowSeqList(&my_list); break;
	case 5:	DecendSort(&my_list); ShowSeqList(&my_list); break;
	}
	return 0;
}
