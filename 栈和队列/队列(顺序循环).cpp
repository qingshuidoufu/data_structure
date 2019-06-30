/* 2 队列—顺序循环
本题主要考察内容
1/初始化顺序循环队列（用函数返回值，即return语句返回队列的指针）
2/顺序循环队列判断假溢出的方法是：少用一个存储单元
3/入队操作
4/出队操作
5/遍历队列并打印元素
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define QUEUEMAX 15 //设置队列数组最大容量
typedef int DATA;
typedef struct {
	DATA data[QUEUEMAX]; //队列数组
	int head;
	int tail;
} CycQueue;
//请注意，本题判断假溢出的方法是：少用一个存储单元，
//因而队列最大长度为QUEUEMAX-1=15-1=14 
//判队满： front=＝(rear+1)%MaxQueueSize
//判队空： rear==front

//初始化顺序队列，请多学习体会！！！ 
//函数用return 语句返回一个 CycQueue类型的指针，
//注意与单链表章节所用的方法进行区别
//单链表：（函数参数有一个**p，一个指向指针的指针去影响主调函数的值） 
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

void CycQueueFree(CycQueue* q) { //释放队列内存
	if (q != NULL) {
		free(q);
	}
}

int CycQueueIsEmpty(CycQueue* q) {//判断队列是否为空
	return (q->head == q->tail);
}

int CycQueueIsFull(CycQueue* q) { //判断队列是否为满
	return ((q->tail + 1) % QUEUEMAX == q->head);
}

int CycQueueLen(CycQueue* q) { //获取队列长度
	int n;
	n = q->tail - q->head;
	if (n < 0) {
		n = QUEUEMAX + n;
	}
	return n;
}
int CycQueueShow(CycQueue* q) { //从队头至队尾打印元素
	int p = q->head, pp = q->tail;
	if (CycQueueIsEmpty(q)) {
		printf("队列为空！\n");
		return 0;
	}
	else {
		while (p != pp) {
			printf("%d ", q->data[p]);
			p = (p + 1) % QUEUEMAX;

		}
		//【1】请填写多行代码，打印格式为：printf("%d ",);
	}
	printf("\n");
	return 1;
}
/*入队*/
int CycQueueIn(CycQueue* q, DATA data) {
	if (CycQueueIsFull(q)) {
		printf("Queue is full\n");
		return 0;
	}
	else {
		q->data[q->tail] = data;
		q->tail = (q->tail + 1) % QUEUEMAX;
		return 1;
		//【2】 请填写多行代码，注意return语句
	}
}

/*出队*/
DATA* CycQueueOut(CycQueue* q) {
	DATA* data;
	if (CycQueueIsEmpty(q)) {
		printf("Queue is empty\n");
		return 0;
	}
	else {
		data = &q->data[q->head];
		q->head = (q->head + 1) % QUEUEMAX;
		//【3】请填写多行代码，注意return语句及其返回值
		return data;
	}
}

DATA* CycQueuePeek(CycQueue* q) {//获取队列头部的元素
	if (CycQueueIsEmpty(q)) {
		printf("队列为空\n");
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
/* 【测试用例】
1
1 3 5 7 9
5 7 9

2
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 队列已满！
6 7 8 9 10 1 4 9 16 25 36 49 64 81
队列为空
队列为空
队列为空
队列为空
队列为空
队列为空

EUEMAX */