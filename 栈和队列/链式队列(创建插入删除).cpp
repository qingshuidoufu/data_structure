/* 1	����--��ʽ
������Ҫ��������
1/���е���ʽʵ��
2/��ʽ���еĳ�������Ӳ���
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;//��ע������˵����һ��ָ������ QueuePtr

typedef struct
{
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//������ʽ��ʾ
//���г�ʼ��
int InitQueue(LinkQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	return 1;
}
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(LinkQueue* Q) {
	if (Q->front == NULL) {
		//printf("����Ϊ�գ�\n");
		return 1;//�ж��Ƿ��ǿն��� 
	}
	return 0;
}
//ɾ��Ԫ��
int DeleteQueue(LinkQueue* Q, ElemType* e)
{
	QueuePtr p;
	if (Q->front == NULL) {
		printf("Queue is empty\n");
		return 0;//�ж��Ƿ��ǿն��� 
	}
	p = Q->front->next;
	*e = Q->front->data;
	free(Q->front);
	Q->front = p;

	//��1��       ����д���д���
	return 1;
}

//����Ԫ�ص�������
int InsertQueue(LinkQueue* Q, ElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = (QNode*)malloc(sizeof(QNode));
	if (!p) {
		printf("����������\n");
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

	//��2��      ����д���д���
	return 1;
}
//���������е�Ԫ��
int VisitQueue(LinkQueue* Q)
{
	QueuePtr p;
	if (Q->front == NULL) {
		printf("Queue is empty\n");
		return 0;//�ж��Ƿ��ǿն��� 
	}
	p = Q->front;//pָ���ͷ���
	while (p)//p��Ϊ��ʱ
	{
		printf("%d ", p->data);;//���pָ��Ľ���ֵ
		p = p->next;//ָ�����
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

/* ������������
1
1 2 3 4 5
2 3 4 5 6

2
1 2 3 4 5 6 7 8 9 10
����Ϊ�գ�
����Ϊ�գ�
����Ϊ�գ�
����Ϊ�գ�
����Ϊ�գ�
1 4 9 16 25 36 49 64 81 100

 */