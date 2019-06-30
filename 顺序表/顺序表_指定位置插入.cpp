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

//--------˳����ָ��λ�ò���---------

int ListInsert(SqList* L, int i, ElemType x) {//7��˳����λ��i����ֵΪx��Ԫ�� 

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

int ListDelete(SqList* L, int i, ElemType* x) { //8ɾ��˳����λ��iԪ�أ���ֵ����ָ��x��ָ��Ԫ 

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

int ListUpdate(SqList* L, int i, ElemType x) {//9�޸�˳����λ��iԪ��ֵ֮Ϊx

	if (i<0 || i>L->size - 1) {

		printf("Parameter illegal.\n"); return 0;

	}

	L->list[i] = x;// 6 

	return 1;

}

int ListGet(SqList L, int i, ElemType* x) {////10��ȡ˳����iλ��Ԫ��ֵ֮,��ֵ����ָ��x��ָ��Ԫ

	if (i<0 || i>L.size - 1) {

		printf("Parameter illegal.\n"); *x = -12345; return 0;

	}

	*x = L.list[i];// 7

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

	int x, i;

	int switch_num;

	scanf("%d", &switch_num);

	switch (switch_num) {

	case 1: InitSqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//��һ��ͷ���� 

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//�ڶ���ͷ����  

		scanf("%d", &x);

		ListInsert(&my_list, 0, x);//������ͷ����

		scanf("%d", &x);

		ShowSeqList(&my_list);

		ListInsert(&my_list, 3, x);//��һ��β���� ���ڶ�������Ϊʲô��3�� 

		scanf("%d", &x);

		ListInsert(&my_list, 4, x);//�ڶ���β���� ���ڶ�������Ϊʲô��4��

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 2, x);//	��λ��2����

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 3, x);//	��λ��3����	

		ShowSeqList(&my_list);

		scanf("%d", &x);

		ListInsert(&my_list, 5, x);//	��λ��5����		   

		ShowSeqList(&my_list);

		break;

	case 2: InitSqList(&my_list);

		for (i = 1; i <= 10; i++)

			ListInsert(&my_list, 0, i);

		ShowSeqList(&my_list);

		ListInsert(&my_list, -1, 100);//��һ���Ƿ�λ�ã�С��0λ�� 

		ListInsert(&my_list, my_list.size + 1, 100);//�ڶ����Ƿ�λ�ã�����βλ�� ,Ϊʲô��С�� 

		//ShowSeqList(&my_list);                  // my_list.size+1�� 

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

		ShowSeqList(&my_list);//3��ͷɾ����Ľ�� 



		ListDelete(&my_list, 6, &x);

		printf("The 1st PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 5, &x);

		printf("The 2rd PopBack delete  num = %d    .   \n", x);

		ShowSeqList(&my_list);//2��βɾ����Ľ�� 



		ListDelete(&my_list, 2, &x);

		printf("The 1st PopBack delete  num = %d    .   \n", x);

		ListDelete(&my_list, 3, &x);

		printf("The 2rd PopBack delete  num = %d    .   \n", x);

		ShowSeqList(&my_list);//2��ָ��λ��ɾ����Ľ��



		ListDelete(&my_list, -1, &x);//��һ���Ƿ�λ�ã�С��0λ�� 

		ListDelete(&my_list, my_list.size, &x);//�ڶ����Ƿ�λ�ã�����βλ��

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