/* 8 �����С�˳��ѭ������+����
������Ҫ�������ݣ�
1/��������е����ݽṹ
2/��д��ӳ��Ӳ���
�����У�ָ����������Ԫ�غͳ��Ӳ���ֻ��O(1)ʱ�䣬��Ӻͳ��Ӳ�����O(N)ʱ�䣨�����ҵ�O(logN)ʱ��ķ���������û���ҵ�O(1)ʱ��ķ�����������ҵ��ˣ��Ͽ���ϵ����ʦ����
�������£�ά��һ��������A��һ����������B��������A�Ĳ�������ͨ�������졣��������B[0]��ŵ�Ϊ����A�����Ԫ�ء�
���һ��Ԫ�أ�����Ԫ�������A���Ը�������B�Ĳ������£�����������BΪ�գ�����Ԫ�ش���B[0]������������B��Ϊ�գ�1�������ҵ�����������С�ڴ�Ԫ�صĵ�һ���±�k������Ԫ�ش���B[k]����������B�ĳ���Ϊk+1��2�������ܣ���������B��β��֮������Ԫ�أ���������B�ĳ��ȡ���ע������B��Ԫ�ؿ϶��ǽ������У�Ϊʲô������˵����������ô��������2�ַ��ҵ��˺��ʵ�λ�ã�ʱ��ΪO(logN)��
����һ��Ԫ�أ�������A���Ӳ���ȡ��ֵx��x������B��B[0]Ԫ���Ƿ���ȣ�����ȣ�������B����һ��λ�ã���ʱ�ƶ�����ʱ��ΪO(N)����������B��Ϊһ��˳����������ôֻ��˳��������ġ���Ԫ������һ��λ�ü��ɣ�ʱ��ΪO(1)���������ȣ�xС����������B�����κβ����������ȣ�x�󣩣��϶��ǳ�����!����Ϊʲô��
���磬���Ԫ������Ϊ8 5 9 7 6 8 ��Ȼ����������4�Σ�Ȼ��4 3 7������ӡ�
��/���Ӵ���	Ԫ��	����A				��������B
1			8		8					8
2			5		8 5					8 5
3			9		8 5 9					9
4			7		8 5 9 7				9 7
5			6		8 5 9 7 6				9 7 6
6			8		8 5 9 7 6 8			9 8
7			8		5 9 7 6 8//����		9 8
8			5		9 7 6 8//����			9 8
9			9		7 6 8//����			8
10			7		6 8//����			8
11			4		6 8 4					8 4
12			3		6 8 4 3				8 4 3
13			7		6 8 4 3 7				8 7 */
/* ������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define QUEUEMAX 15 //���ö����������
#define MAX 15 //���������������
typedef int DATA;
typedef struct {
	DATA data[QUEUEMAX]; //��������
	int head;
	int tail;
	DATA arr[QUEUEMAX]; //��������
	int length;
} CycQueueMax;
//��ע�⣬�жϼ�����ķ����ǣ�����һ���洢��Ԫ
//�ж����� front=��(rear+1)%MaxQueueSize
//�жӿգ� rear==front
CycQueueMax* CycQueueMaxInit() {//���������˺���
	CycQueueMax* q;
	if (q = (CycQueueMax*)malloc(sizeof(CycQueueMax))) {
		q->head = 0;
		q->tail = 0;
		q->length = 0;
		return q;
	}
	else {
		return NULL;
	}
}

void CycQueueMaxFree(CycQueueMax* q) { //�ͷŶ����ڴ�
	if (q != NULL) {
		free(q);
	}
}

int CycQueueMaxIsEmpty(CycQueueMax* q) {//�ж϶����Ƿ�Ϊ��
	return (q->head == q->tail);
}

int CycQueueMaxIsFull(CycQueueMax* q) { //�ж϶����Ƿ�Ϊ��
	return ((q->tail + 1) % QUEUEMAX == q->head);
}

int CycQueueMaxLen(CycQueueMax* q) { //��ȡ���г���
	int n;
	n = q->tail - q->head;
	if (n < 0) {
		n = QUEUEMAX + n;
	}
	return n;
}
int CycQueueMaxShow(CycQueueMax* q) { //�Ӷ�ͷ����β��ӡԪ��
	int p = q->head, pp = q->tail;
	if (CycQueueMaxIsEmpty(q)) {
		//printf("����Ϊ�գ�\n");
		return 0;
	}
	else
		while (p != pp) {
			printf("%d ", q->data[p]);
			p = (p + 1) % QUEUEMAX; //����дһ�д���  head++ ��tail�������ֵ��ͱ�1
		}
	printf("\n");
	return 1;
}
/*���*/
int CycQueueMaxIn(CycQueueMax* q, DATA data) {//��ӳɹ�����1�����򷵻�0
	int i;
	if (CycQueueMaxIsFull(q)) {
		//printf("����������\n");
		return 0;
	}
	else {
		DATA tem = q->data[q->head];
		q->data[q->tail] = data;
		q->tail = (q->tail + 1) % QUEUEMAX;
		if (q->length == 0) {
			q->arr[0] = data;
			q->length = 1;
		}
		else {
			for (i = 0; i < q->length; i++) {
				if (q->arr[i] < data) {
					q->arr[i] = data;
					q->length = i + 1;
					break;
				}
			}

			if (i >= q->length) {
				q->arr[q->length] = data;
				q->length++;
			}
		}

		//���һ��Ԫ�أ�����Ԫ�������A���Ը�������B�Ĳ������£�����������BΪ�գ�����Ԫ�ش���B[0]������������B��Ϊ�գ�1�������ҵ�����������С�ڴ�Ԫ�صĵ�һ���±�k������Ԫ�ش���B[k]����������B�ĳ���Ϊk+1��2�������ܣ���������B��β��֮������Ԫ�أ���������B�ĳ��ȡ���ע������B��Ԫ�ؿ϶��ǽ������У�Ϊʲô������˵����������ô��������2�ַ��ҵ��˺��ʵ�λ�ã�ʱ��ΪO(logN)��
		//����һ��Ԫ�أ�������A���Ӳ���ȡ��ֵx��x������B��B[0]Ԫ���Ƿ���ȣ�����ȣ�������B����һ��λ�ã���ʱ�ƶ�����ʱ��ΪO(N)����������B��Ϊһ��˳����������ôֻ��˳��������ġ���Ԫ������һ��λ�ü��ɣ�ʱ��ΪO(1)���������ȣ�xС����������B�����κβ����������ȣ�x�󣩣��϶��ǳ�����!����Ϊʲô��
		//��2������д���д���
		return 1;
	}
}

/*����*/
DATA* CycQueueMaxOut(CycQueueMax* q) {//ע��˺����ķ���ֵ����
	if (CycQueueMaxIsEmpty(q)) {
		return NULL;
	}
	else {
		DATA x;
		x = q->data[q->head];
		q->head = (q->head + 1) % QUEUEMAX;
		if (x == q->arr[0]) {
			int i;
			for (i = 0; i < q->length - 1; i++) {
				q->arr[i] = q->arr[i + 1];
			}
			q->length = q->length--;
		}
		return &q->data[q->head];
	}
	//����һ��Ԫ�أ�������A���Ӳ���ȡ��ֵx��x������B��B[0]Ԫ���Ƿ���ȣ�����ȣ�������B����һ��λ�ã���ʱ�ƶ�����ʱ��ΪO(N)����������B��Ϊһ��˳����������ôֻ��˳��������ġ���Ԫ������һ��λ�ü��ɣ�ʱ��ΪO(1)���������ȣ�xС����������B�����κβ����������ȣ�x�󣩣��϶��ǳ�����!����Ϊʲô��
	//��3������д���д���
}

DATA* CycQueueMaxPeek(CycQueueMax* q) {//��ȡ����ͷ����Ԫ��
	if (CycQueueMaxIsEmpty(q)) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		return &q->data[q->head];//����дһ�д���
	}
}
DATA* CycQueueMaxPeek_MAX(CycQueueMax* q) {//��ȡ��������Ԫ��
	if (CycQueueMaxIsEmpty(q)) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		return &(q->arr[0]);
	}
}

int main() {
	CycQueueMax* Q;
	int* x, i;
	Q = CycQueueMaxInit();
	CycQueueMaxIn(Q, 8);
	CycQueueMaxIn(Q, 5);
	CycQueueMaxIn(Q, 7);
	CycQueueMaxIn(Q, 9);
	CycQueueMaxIn(Q, 6);
	CycQueueMaxIn(Q, 12);
	CycQueueMaxIn(Q, 4);
	CycQueueMaxIn(Q, 3);
	CycQueueMaxIn(Q, 10);
	CycQueueMaxShow(Q);
	x = CycQueueMaxPeek_MAX(Q);
	printf("%d\n", *x);

	for (i = 1; i <= 9; i++) {
		CycQueueMaxOut(Q);
		CycQueueMaxShow(Q);
		x = CycQueueMaxPeek_MAX(Q);
		if (x != NULL)
			printf("%d\n", *x);
		else
			printf("Queue is empty");
	}

	return 0;
}

/* ������������
8 5 7 9 6 12 4 3 10
12
5 7 9 6 12 4 3 10
12
7 9 6 12 4 3 10
12
9 6 12 4 3 10
12
6 12 4 3 10
12
12 4 3 10
12
4 3 10
10
3 10
10
10
10
����Ϊ��
����Ϊ��
 */