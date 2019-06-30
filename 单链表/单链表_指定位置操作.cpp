//vs中出现位置错误cl.exe退出,代码=2,但是vscode中可运行
/* 本题主要考查内容：
1>在单链表指定位置插入节点
2>在单链表指定位置删除节点
3>在有序单链表插入一个元素，使之仍然有序
4>删除单链表中第一个等于指定值的节点
5>删除单链表中所有等于指定值的节点
6>获取单链表指定位置节点的数据域
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct SingleNode {
	ElemType data;
	struct SingleNode* next;
}SingleNodeList, * Linklist;
void LinkedListInit(SingleNodeList** head) {//1初始化有头节点的单链表 
	Linklist p;
	if ((*head = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	(*head)->next = NULL;
}
int LinkedListLength(SingleNodeList* head) {//2求单链表长度 
	SingleNodeList* p = head;
	int size = 0;
	while (p->next != NULL) {
		size++;
		p = p->next;
	}
	return size;
}
int LinkedListShow(SingleNodeList* head) {//3打印单链表
	SingleNodeList* p = head;
	//ElemType x;
	if (p->next == NULL) {
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	}
	while (p->next != NULL) {
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}
int LinkedListInsert(SingleNodeList* head, int i, ElemType x) {//4在ai（0<=i<=size）前插入节点 
	SingleNodeList* p = head, * q;
	int count = 0;
	int j;
	for (j = 0; j < i - 1; j++) {
		p = p->next;
		count++;
	}
	if ((q = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	p->next = q; //请填写多行代码
	return 1;
}
int LinkedListDelete(SingleNodeList* head, int i, ElemType* x) {//5删除i位置（0<=i<=size）前节点 
	SingleNodeList* p = head, * q;
	int j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1) {
		p = p->next; j++;
	}
	if (j != i - 1) {
		printf("The location parameter of the delete node is wrong.");
		return	0;
	}
	q = p->next;
	p->next = q->next;
	*x = q->data;
	//请填写多行代码
	free(q);
	return 1;
}
int LinkedListInsert_Order(SingleNodeList* head, ElemType x) {//6有序插入x 
	SingleNodeList* pre, * curr, * q;
	int j = -1;
	pre = head;
	curr = head->next;
	while (curr != NULL && curr->data <= x) {
		curr = curr->next;
		pre = pre->next;//请填写多行代码
	}
	if ((q = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	q->data = x;
	q->next = curr;//赋值q->next 
	pre->next = q; //重链接p->next 
	return 1;
}
int LinkedListDelete_Order(SingleNodeList* head, ElemType x) {//7删除第一个值为x的节点 
	SingleNodeList* p = head, * q;
	while (p->next != NULL && p->next->data != x) {
		p = p->next;
	}
	if (p->next == NULL) {
		printf("There is no node %d to delete.\n", x); return -1;
	}
	q = p->next;
	p->next = q->next;//请填写多行代码
	free(q);
	return 1;
}
int LinkedListDelete_All(SingleNodeList* head, ElemType x) {//8删除所有值为x的节点 
	//用p从头至尾扫描单链表，pre指向*p节点的前驱。若p所指节点值为x，则删除，并让p
	//移向下一个节点，否则让pre、p指针同步后移一个节点。 
	SingleNodeList* p = head->next, * pre = head, * q;
	int j = 0;
	while (p != NULL) {
		if (p->data == x) {
			q = p;
			pre->next = q->next;
			p = p->next;
			free(q);
			j++;
		}
		else {//同步后移 
			pre = p;
			p = p->next;
		}
	}
	if (j == 0)
		printf("There is no node %d to delete.\n", x);
	else
		printf("There is  %d node deleted.\n", j);
	return 1;
}
int LinkedListGet(SingleNodeList* head, int i, ElemType* x) {//9取单链表第i个节点的数据，存入x指针 
	SingleNodeList* p;
	int j = 0;
	p = head;
	for (j = 0; j < i; j++) {
		p = p->next;
	}
	*x = p->data;
	return 1;
}
void LinkedListDestroy(SingleNodeList** head) {//10释放链表 
	SingleNodeList* p = *head, * q;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}

int main() {
	SingleNodeList* head;
	ElemType i, x;
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		LinkedListInit(&head);
		for (i = 1; i <= 10; i++)
			LinkedListInsert(head, 0, i);
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);
		break;
	case 2:
		LinkedListInit(&head);
		for (i = 1; i <= 10; i++)
			LinkedListInsert(head, 0, i);
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);

		for (i = 1; i <= 3; i++)
			LinkedListDelete(head, i, &x);
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);
		break;
	case 3:
		LinkedListInit(&head);
		for (i = 1; i <= 8; i++) {
			scanf("%d", &x);
			LinkedListInsert_Order(head, x);
		}
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);
		break;
	case 4:
		LinkedListInit(&head);
		for (i = 1; i <= 5; i++) {
			scanf("%d", &x);
			LinkedListInsert(head, 0, x);
		}
		LinkedListShow(head);

		scanf("%d", &x);
		LinkedListDelete_Order(head, x);
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);
		break;
	case 5:
		LinkedListInit(&head);
		for (i = 1; i <= 5; i++) {
			scanf("%d", &x);
			LinkedListInsert(head, 0, x);
		}
		LinkedListShow(head);

		scanf("%d", &x);
		LinkedListDelete_All(head, x);
		printf("%d\n", LinkedListLength(head));
		LinkedListShow(head);
		break;
	}
	return 0;
}
/* 【测试用例】
1
10
10 9 8 7 6 5 4 3 2 1

2
10
10 9 8 7 6 5 4 3 2 1
7
10 8 6 4 3 2 1

3
1 3 5 7 9 2 4 6
8
1 2 3 4 5 6 7 9


4
11 22 33 22 44
22

44 22 33 22 11
4
44 33 22 11


5
11 22 33 22 22
22

22 22 33 22 11
There is  3 node deleted.
2
33 11
 */