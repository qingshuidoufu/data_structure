#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 100
typedef int ElemType;
typedef struct sqlist {
	ElemType list[MaxSize];
	int size;
}SqList;
void InitSqList(SqList* L) {//1��ʼ��˳���
	L->size = 0;
}
int ListLength(SqList L) {//2��˳����� 
	return L.size;
}
//--------˳����β������--------- 
int PushBack(SqList* L, ElemType x) {//3��˳����β������ֵΪdata��Ԫ��	
	if (L->size >= MaxSize) {
		printf("list is full.\n"); return 0;
	}
	else {
		L->list[L->size] = x;
		L->size++;
	}
	return 1;
}
int PopBack(SqList* L, ElemType* x) {//4ɾ��˳����βԪ��,��ֵ����ָ��x��ָ��Ԫ
	if (L->size <= 0)
	{
		printf("There is no element in the sequence table that can be deleted.\n");
		*x = -12345;
		return 0;
	}
	else {
		*x = L->list[L->size - 1];
	} //3 
	L->size--;//4 
	return 1;
}
int ShowSeqList(SqList* L) {//11��ӡ˳���������Ԫ��
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
		printf("%d\n", my_list.size);
		ShowSeqList(&my_list);
		break;
	case 2:	InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushBack(&my_list, num);
		}
		ShowSeqList(&my_list);
		break;
	case 3: InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushBack(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n - 2; i++) {
			PopBack(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	case 4: InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushBack(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n; i++) {
			PopBack(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	case 5:InitSqList(&my_list);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &num);
			PushBack(&my_list, num);
		}
		ShowSeqList(&my_list);
		for (i = 1; i <= n + 2; i++) {
			PopBack(&my_list, &x);
			printf("The %d PopBack delete  num = %d\n", i, x);
		}
		ShowSeqList(&my_list);
		break;
	}
	return 0;
}

