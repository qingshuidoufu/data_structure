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
	L->list[0] = x;//1 
	L->size++;//2 
	return 1;
}
int PopFront(SqList* L, ElemType* x) {//6删除顺序表的头部元素,其值存入指针x所指单元
	int j;
	if (L->size <= 0)
	{
		printf("There is no element in the sequence table that can be deleted.\n");
		*x = -12345;
		return 0;
	}
	//3 
	for (j = 1; j < L->size; j++) {
		L->list[j] = L->list[j - 1];
	}
	L->size--;
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
	int x, n, i, num;
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:	InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushFront(&my_list, num);
		}
		ShowSeqList(&my_list);
		break;
	case 2:	InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushFront(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n - 2; i++) {
			PopFront(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	case 3:	InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushFront(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n; i++) {
			PopFront(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	case 4:	InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushFront(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n + 2; i++) {
			PopFront(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	case 5:	InitSqList(&my_list);
		for (i = 1; i <= 3; i++) {
			PopFront(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;

	}
	return 0;
}