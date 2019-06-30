/* 8 最大队列—顺序循环队列+数组
本题主要考察内容：
1/设计最大队列的数据结构
2/重写入队出队操作
最大队列，指求队列中最大元素和出队操作只需O(1)时间，入队和出队操作需O(N)时间（可以找到O(logN)时间的方法，但是没有找到O(1)时间的方法，你如果找到了，赶快联系汤老师）。
方法如下：维护一个主队列A和一个辅助数组B，主队列A的操作与普通队列无异。辅助数组B[0]存放的为队列A中最大元素。
入队一个元素，将此元素入队列A，对辅助数组B的操作如下：若辅助数组B为空，将此元素存入B[0]，若辅助数组B不为空：1）若能找到辅助数组中小于此元素的第一个下标k，将此元素存入B[k]，更新数组B的长度为k+1。2）若不能，则在数组B的尾部之后存入此元素，更新数组B的长度。请注意数组B中元素肯定是降序排列，为什么？你能说出理由吗？那么，可以用2分法找到此合适的位置，时间为O(logN)。
出队一个元素，将队列A出队并获取其值x，x与数组B的B[0]元素是否相等？若相等，讲数组B左移一个位置（此时移动所花时间为O(N)，若将数组B改为一个顺序表或链表，那么只需顺序表或链表的“首元”后移一个位置即可，时间为O(1)），若不等（x小），则数组B不做任何操作，若不等（x大），肯定是出错了!！！为什么？
例如，入队元素依次为8 5 9 7 6 8 ，然后连续出队4次，然后4 3 7依次入队。
入/出队次序	元素	队列A				辅助数组B
1			8		8					8
2			5		8 5					8 5
3			9		8 5 9					9
4			7		8 5 9 7				9 7
5			6		8 5 9 7 6				9 7 6
6			8		8 5 9 7 6 8			9 8
7			8		5 9 7 6 8//出队		9 8
8			5		9 7 6 8//出队			9 8
9			9		7 6 8//出队			8
10			7		6 8//出队			8
11			4		6 8 4					8 4
12			3		6 8 4 3				8 4 3
13			7		6 8 4 3 7				8 7 */
/* 【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define QUEUEMAX 15 //设置队列最大容量
#define MAX 15 //设置数组最大容量
typedef int DATA;
typedef struct {
	DATA data[QUEUEMAX]; //队列数组
	int head;
	int tail;
	DATA arr[QUEUEMAX]; //辅助数组
	int length;
} CycQueueMax;
//请注意，判断假溢出的方法是，少用一个存储单元
//判队满： front=＝(rear+1)%MaxQueueSize
//判队空： rear==front
CycQueueMax* CycQueueMaxInit() {//请认真体会此函数
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

void CycQueueMaxFree(CycQueueMax* q) { //释放队列内存
	if (q != NULL) {
		free(q);
	}
}

int CycQueueMaxIsEmpty(CycQueueMax* q) {//判断队列是否为空
	return (q->head == q->tail);
}

int CycQueueMaxIsFull(CycQueueMax* q) { //判断队列是否为满
	return ((q->tail + 1) % QUEUEMAX == q->head);
}

int CycQueueMaxLen(CycQueueMax* q) { //获取队列长度
	int n;
	n = q->tail - q->head;
	if (n < 0) {
		n = QUEUEMAX + n;
	}
	return n;
}
int CycQueueMaxShow(CycQueueMax* q) { //从队头至队尾打印元素
	int p = q->head, pp = q->tail;
	if (CycQueueMaxIsEmpty(q)) {
		//printf("队列为空！\n");
		return 0;
	}
	else
		while (p != pp) {
			printf("%d ", q->data[p]);
			p = (p + 1) % QUEUEMAX; //请填写一行代码  head++ 当tail到达最大值后就变1
		}
	printf("\n");
	return 1;
}
/*入队*/
int CycQueueMaxIn(CycQueueMax* q, DATA data) {//入队成功返回1，否则返回0
	int i;
	if (CycQueueMaxIsFull(q)) {
		//printf("队列已满！\n");
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

		//入队一个元素，将此元素入队列A，对辅助数组B的操作如下：若辅助数组B为空，将此元素存入B[0]，若辅助数组B不为空：1）若能找到辅助数组中小于此元素的第一个下标k，将此元素存入B[k]，更新数组B的长度为k+1。2）若不能，则在数组B的尾部之后存入此元素，更新数组B的长度。请注意数组B中元素肯定是降序排列，为什么？你能说出理由吗？那么，可以用2分法找到此合适的位置，时间为O(logN)。
		//出队一个元素，将队列A出队并获取其值x，x与数组B的B[0]元素是否相等？若相等，讲数组B左移一个位置（此时移动所花时间为O(N)，若将数组B改为一个顺序表或链表，那么只需顺序表或链表的“首元”后移一个位置即可，时间为O(1)），若不等（x小），则数组B不做任何操作，若不等（x大），肯定是出错了!！！为什么？
		//【2】请填写多行代码
		return 1;
	}
}

/*出队*/
DATA* CycQueueMaxOut(CycQueueMax* q) {//注意此函数的返回值类型
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
	//出队一个元素，将队列A出队并获取其值x，x与数组B的B[0]元素是否相等？若相等，讲数组B左移一个位置（此时移动所花时间为O(N)，若将数组B改为一个顺序表或链表，那么只需顺序表或链表的“首元”后移一个位置即可，时间为O(1)），若不等（x小），则数组B不做任何操作，若不等（x大），肯定是出错了!！！为什么？
	//【3】请填写多行代码
}

DATA* CycQueueMaxPeek(CycQueueMax* q) {//获取队列头部的元素
	if (CycQueueMaxIsEmpty(q)) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		return &q->data[q->head];//请填写一行代码
	}
}
DATA* CycQueueMaxPeek_MAX(CycQueueMax* q) {//获取队列最大的元素
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

/* 【测试用例】
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
队列为空
队列为空
 */