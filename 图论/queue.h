#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//˳����нṹ
typedef struct my_queue {
	int  a[MAX_SIZE];
	int size;
}my_queue;

//��ʼ��
my_queue* queue_init() {
	my_queue* q;
	q = (my_queue*)malloc(sizeof(my_queue));
	for (int i = 0; i < MAX_SIZE; i++) {
		q->a[i] = NULL;
	}
	q->size = 0;
	return q;
}
//���
int queue_push(my_queue* q, int x) {
	if (q->size == MAX_SIZE) {
		return 0;
	}
	q->a[q->size] = x;
	q->size++;
	return 1;
}
//�˶�
int queue_pop(my_queue* q, int* x) {
	if (q->size == 0) {
		return 0;
	}

	*x = q->a[0];
	for (int i = 0; i < q->size - 1; i++) {
		q->a[i] = q->a[i + 1];
	}
	q->size--;
	return 1;
}
//�п�
int is_empty(my_queue q) {
	if (q.size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
