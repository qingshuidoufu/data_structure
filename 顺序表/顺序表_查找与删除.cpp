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
int ListSearch(SqList L, ElemType x) {//12查找顺序表中值为x的的第一个元素，找到则返回该元素的位置，否则返回-1 
	int j;
	for (j = 0; j < L.size; j++) {
		if (L.list[j] == x) {
			return j;
		}
	}
	if (j >= L.size) {
		return -1;
	}
}
int ListDelete(SqList* L, int i, ElemType* x) { //8删除顺序表的位置i元素，其值存入指针x所指单元 
	int j;
	if (L->size <= 0) {
		printf("There is no element in the sequence table that can be deleted.\n");
		return 0;
	}
	if (i<0 || i>L->size) {
		printf("Parameter illegal.\n"); return 0;
	}
	*x = L->list[i];
	for (j = i + 1; j < L->size; j++) {
		L->list[j - 1] = L->list[j];
	}
	L->size--;
	return 1;
}
int Remove(SqList* L, ElemType data) {//13删除顺序表中第一个值为data的元素,方法一 
	int i, x;
	i = ListSearch(*L, data);
	if (i == -1) {
		printf("The deleted element was not found.\n"); return -1;
	}
	ListDelete(L, i, &x);
	return 0;
}
int Remove1(SqList* L, ElemType data) {//13删除顺序表中第一个值为data的元素，方法二 
	int i, j, x;
	for (j = 0; j < L->size; j++) {
		if (L->list[j] == data) {
			break;
		}
	}
	i = j;
	if (i >= L->size) {
		printf("The deleted element was not found.\n");
		return -1;
	}
	for (j = i + 1; j <= L->size - 1; j++) {
		L->list[j - 1] = L->list[j];
	}
	L->size--;
	return 1;
}
int Remove_all(SqList* L, ElemType data) {//14删除顺序表中所有值为data的元素
	int i, x;
	int k;
	for (k = 0; k < L->size; k++) {
		i = ListSearch(*L, data);
		if (i != -1) {
			ListDelete(L, i, &x);
			k--;
		}
	}
	return 0;
}
int BinarySearch(SqList* L, ElemType data) {//15使用二分查找降序排列中的元素
	int left = 0, right = L->size - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (L->list[mid] < data)
			left = mid + 1;
		else if (L->list[mid] > data)
			right = mid - 1;
		else if (data == L->list[mid])
			return mid;
	}
	return -1;
}
int main() {
	SqList my_list;
	int x, n, i, num;
	int switch_num;
	scanf("%d", &switch_num);
	InitSqList(&my_list);
	for (i = 1; i <= 18; i++)
		PushFront(&my_list, i);
	ListUpdate(&my_list, 17, -9);	ListUpdate(&my_list, 15, 10);
	ListUpdate(&my_list, 13, -1);	ListUpdate(&my_list, 11, 10);
	ListUpdate(&my_list, 9, -2);	ListUpdate(&my_list, 7, 10);
	ListUpdate(&my_list, 5, -10);	ListUpdate(&my_list, 3, 21);
	ListUpdate(&my_list, 1, 100);	ListUpdate(&my_list, 0, 30);
	switch (switch_num) {
	case 1:	ShowSeqList(&my_list);
		i = ListSearch(my_list, 10);
		if (i >= 0)
			printf("The first one is equal to 10 at %d\n", i);
		else
			printf("The element 10 was not found.\n");
		i = ListSearch(my_list, 30);
		if (i >= 0)
			printf("The first one is equal to 30 at %d\n", i);
		else
			printf("The element 30 was not found.\n");
		i = ListSearch(my_list, -9);
		if (i >= 0)
			printf("The first one is equal to -9 at %d\n", i);
		else
			printf("The element -9 was not found.\n");
		i = ListSearch(my_list, -100);
		if (i >= 0)
			printf("The first one is equal to -100 at %d\n", i);
		else
			printf("The element -100 was not found.\n");
		i = ListSearch(my_list, 200);
		if (i >= 0)
			printf("The first one is equal to 200 at %d\n", i);
		else
			printf("The element 200 was not found.\n");
		break;
	case 2: ShowSeqList(&my_list);
		Remove(&my_list, 30); ShowSeqList(&my_list);
		Remove(&my_list, 12); ShowSeqList(&my_list);
		Remove(&my_list, 10); ShowSeqList(&my_list);
		Remove(&my_list, -30); ShowSeqList(&my_list);
		break;
	case 3: ShowSeqList(&my_list);
		Remove1(&my_list, 30); ShowSeqList(&my_list);
		Remove1(&my_list, 12); ShowSeqList(&my_list);
		Remove1(&my_list, 10); ShowSeqList(&my_list);
		Remove1(&my_list, -30); ShowSeqList(&my_list);
		break;
	case 4: ShowSeqList(&my_list);
		Remove_all(&my_list, 30); ShowSeqList(&my_list);
		Remove_all(&my_list, 10); ShowSeqList(&my_list);
		//Remove_all(&my_list,-30);ShowSeqList(&my_list);
		break;
	case 5: InitSqList(&my_list);
		for (i = 1; i <= 18; i++)
			PushFront(&my_list, i);
		ShowSeqList(&my_list);
		i = BinarySearch(&my_list, 10);
		if (i >= 0)
			printf("The first one is equal to 10 at %d\n", i);
		else
			printf("The element 10 was not found.\n");
		i = BinarySearch(&my_list, 18);
		if (i >= 0)
			printf("The first one is equal to 18 at %d\n", i);
		else
			printf("The element 18 was not found.\n");
		i = BinarySearch(&my_list, 1);
		if (i >= 0)
			printf("The first one is equal to 1 at %d\n", i);
		else
			printf("The element 1 was not found.\n");
		i = BinarySearch(&my_list, -100);
		if (i >= 0)
			printf("The first one is equal to -100 at %d\n", i);
		else
			printf("The element -100 was not found.\n");
		i = BinarySearch(&my_list, 200);
		if (i >= 0)
			printf("The first one is equal to 200 at %d\n", i);
		else
			printf("The element 200 was not found.\n");
		break;
	}
}
