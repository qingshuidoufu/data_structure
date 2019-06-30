/* 2 ���С�˳��ѭ��
������Ҫ��������
1/��ʼ��˳��ѭ�����У��ú�������ֵ����return��䷵�ض��е�ָ�룩
2/˳��ѭ�������жϼ�����ķ����ǣ�����һ���洢��Ԫ
3/��Ӳ���
4/���Ӳ���
5/�������в���ӡԪ��
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define QUEUEMAX 15 //���ö��������������
typedef int DATA;
typedef struct {
	DATA data[QUEUEMAX]; //��������
	int head;
	int tail;
} CycQueue;
//��ע�⣬�����жϼ�����ķ����ǣ�����һ���洢��Ԫ��
//���������󳤶�ΪQUEUEMAX-1=15-1=14 
//�ж����� front=��(rear+1)%MaxQueueSize
//�жӿգ� rear==front

//��ʼ��˳����У����ѧϰ��ᣡ���� 
//������return ��䷵��һ�� CycQueue���͵�ָ�룬
//ע���뵥�����½����õķ�����������
//������������������һ��**p��һ��ָ��ָ���ָ��ȥӰ������������ֵ�� 
CycQueue* CycQueueInit() {
	CycQueue* q;
	if (q = (CycQueue*)malloc(sizeof(CycQueue))) {
		q->head = 0;
		q->tail = 0;
		return q;
	}
	else {
		return NULL;
	}
}

void CycQueueFree(CycQueue* q) { //�ͷŶ����ڴ�
	if (q != NULL) {
		free(q);
	}
}

int CycQueueIsEmpty(CycQueue* q) {//�ж϶����Ƿ�Ϊ��
	return (q->head == q->tail);
}

int CycQueueIsFull(CycQueue* q) { //�ж϶����Ƿ�Ϊ��
	return ((q->tail + 1) % QUEUEMAX == q->head);
}

int CycQueueLen(CycQueue* q) { //��ȡ���г���
	int n;
	n = q->tail - q->head;
	if (n < 0) {
		n = QUEUEMAX + n;
	}
	return n;
}
int CycQueueShow(CycQueue* q) { //�Ӷ�ͷ����β��ӡԪ��
	int p = q->head, pp = q->tail;
	if (CycQueueIsEmpty(q)) {
		printf("����Ϊ�գ�\n");
		return 0;
	}
	else {
		while (p != pp) {
			printf("%d ", q->data[p]);
			p = (p + 1) % QUEUEMAX;

		}
		//��1������д���д��룬��ӡ��ʽΪ��printf("%d ",);
	}
	printf("\n");
	return 1;
}
/*���*/
int CycQueueIn(CycQueue* q, DATA data) {
	if (CycQueueIsFull(q)) {
		printf("Queue is full\n");
		return 0;
	}
	else {
		q->data[q->tail] = data;
		q->tail = (q->tail + 1) % QUEUEMAX;
		return 1;
		//��2�� ����д���д��룬ע��return���
	}
}

/*����*/
DATA* CycQueueOut(CycQueue* q) {
	DATA* data;
	if (CycQueueIsEmpty(q)) {
		printf("Queue is empty\n");
		return 0;
	}
	else {
		data = &q->data[q->head];
		q->head = (q->head + 1) % QUEUEMAX;
		//��3������д���д��룬ע��return��估�䷵��ֵ
		return data;
	}
}

DATA* CycQueuePeek(CycQueue* q) {//��ȡ����ͷ����Ԫ��
	if (CycQueueIsEmpty(q)) {
		printf("����Ϊ��\n");
		return NULL;
	}
	else {
		return &(q->data[(q->head) % QUEUEMAX]);
	}
}

int main() {
	CycQueue* Q;
	int* x, i;
	Q = CycQueueInit();
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 2:
		for (i = 1; i <= 10; i++) {
			CycQueueIn(Q, i);
		}
		CycQueueShow(Q);
		for (i = 1; i <= 5; i++) {
			x = CycQueueOut(Q);
			printf("%d ", *x);
		}
		for (i = 1; i <= 10; i++)
			CycQueueIn(Q, i * i);
		CycQueueShow(Q);
		for (i = 1; i <= 20; i++)
			CycQueueOut(Q);
		break;
	case 1:
		CycQueueIn(Q, 1);
		CycQueueIn(Q, 3);
		CycQueueIn(Q, 5);
		CycQueueIn(Q, 7);
		CycQueueIn(Q, 9);
		CycQueueShow(Q);
		CycQueueOut(Q);
		CycQueueOut(Q);
		CycQueueShow(Q);
		break;
	}
	return 0;
}
/* ������������
1
1 3 5 7 9
5 7 9

2
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 ����������
6 7 8 9 10 1 4 9 16 25 36 49 64 81
����Ϊ��
����Ϊ��
����Ϊ��
����Ϊ��
����Ϊ��
����Ϊ��

EUEMAX */