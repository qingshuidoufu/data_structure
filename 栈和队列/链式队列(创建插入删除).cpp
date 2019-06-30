/* 1	队列--链式
此题主要考查内容
1/队列的链式实现
2/链式队列的出队与入队操作
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;//请注意这里说明了一个指针类型 QueuePtr

typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//队列链式表示
//队列初始化
int InitQueue(LinkQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	return 1;
}
//判断队列是否为空
int QueueEmpty(LinkQueue* Q) {
	if (Q->front == NULL) {
		//printf("队列为空！\n");
		return 1;//判断是否是空队列 
	}
	return 0;
}
//删除元素
int DeleteQueue(LinkQueue* Q, ElemType* e)
{
	QueuePtr p;
	if (Q->front == NULL) {
		printf("Queue is empty\n");
		return 0;//判断是否是空队列 
	}
	p = Q->front->next;
	*e = Q->front->data;
	free(Q->front);
	Q->front = p;

	//【1】       请填写多行代码
	return 1;
}

//插入元素到队列中
int InsertQueue(LinkQueue* Q, ElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = (QNode*)malloc(sizeof(QNode));
	if (!p) {
		printf("队列已满！\n");
		return 0;
	}
	p->data = e;
	p->next = NULL;
	if (QueueEmpty(Q))
	{
		Q->front = Q->rear = p;
	}
	Q->rear->next = p;
	Q->rear = p;

	//【2】      请填写多行代码
	return 1;
}
//遍历队列中的元素
int VisitQueue(LinkQueue* Q)
{
	QueuePtr p;
	if (Q->front == NULL) {
		printf("Queue is empty\n");
		return 0;//判断是否是空队列 
	}
	p = Q->front;//p指向队头结点
	while (p)//p不为空时
	{
		printf("%d ", p->data);;//输出p指向的结点的值
		p = p->next;//指针后移
	}
	printf("\n");
	return 1;
}

int main()
{
	int e, i;
	LinkQueue Q;
	InitQueue(&Q);
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		InsertQueue(&Q, 1);
		InsertQueue(&Q, 2);
		InsertQueue(&Q, 3);
		InsertQueue(&Q, 4);
		InsertQueue(&Q, 5);
		VisitQueue(&Q);
		DeleteQueue(&Q, &e);
		InsertQueue(&Q, 6);
		VisitQueue(&Q);
		break;
	case 2:
		for (i = 1; i <= 10; i++)
			InsertQueue(&Q, i);
		VisitQueue(&Q);
		for (i = 1; i <= 15; i++)
			DeleteQueue(&Q, &e);
		for (i = 1; i <= 10; i++)
			InsertQueue(&Q, i * i);
		VisitQueue(&Q);

	}
	return 0;
}

/* 【测试用例】
1
1 2 3 4 5
2 3 4 5 6

2
1 2 3 4 5 6 7 8 9 10
队列为空！
队列为空！
队列为空！
队列为空！
队列为空！
1 4 9 16 25 36 49 64 81 100

 */