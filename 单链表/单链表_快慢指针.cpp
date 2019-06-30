//vs中出现位置错误cl.exe退出,代码=2,但是vscode中可运行
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
int LinkedList_PushBack(SingleNodeList* head, ElemType x) {//4单链表尾插入 
	SingleNodeList* p = head, * q;
	while (p->next != NULL)
		p = p->next;
	if ((q = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	q->data = x; q->next = NULL; //尾节点的数据域与指针域赋值 
	p->next = q;//尾节点加入链表 
	return 1;
}
int LinkedListGetMid(SingleNodeList* head, ElemType* x) {//5取单链表中间的数据，存入x指针 
	SingleNodeList* fast, * slow;
	fast = slow = head->next;
	while (fast->next->next != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	*x = slow->data;
	return 1;
	//请填入多行代码
}
int LinkedListGetLastofN(SingleNodeList* head, int n, ElemType* x) {//6取单链表倒数第n个节点数据，存入x指针 
	SingleNodeList* fast, * slow;
	int j = 0;
	fast = slow = head;
	while (fast->next != NULL) {
		if (j == n) {
			break;
		}
		j++;
		fast = fast->next;
		//请填入多行代码

	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	if (j < n)* x = -12345;
	else	*x = slow->data;
	return 1;
}
int LinkedListReversal(SingleNodeList* head, int n) {//7单链表翻转n（循环前移n位） 
	SingleNodeList* fast, * slow;
	int j = 0;
	fast = slow = head;
	while (fast->next != NULL) {
		for (; j < n - 1; j++) {
			fast = fast->next;
		}
		slow = slow->next;
		fast = fast->next;

		//请填入多行代码	
	}
	fast->next = head->next;
	head->next = slow->next;
	slow->next = NULL;
	return 0;
}
// 循环链表 
//1》判断某有头节点单链表是否为循环链表
//2》如果是循环链表，求出环的长度
//3》求出环的起点
//4》将循环链表断链成一个单链表
int Is_circular_linked_list(SingleNodeList* head, ElemType* x) {//8判断是否为循环链表 ，是则返回1，否则返回0
	SingleNodeList* fast, * slow;
	fast = head;
	slow = head;
	int count = 0;
	int flag = -1;
	*x = -12345;
	while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			flag = 1;
			break;
		}
	}
	if (fast == NULL && fast->next == NULL && fast->next->next == NULL) {
		flag = -1;
	}
	if (flag == 1)
	{
		do {
			fast = fast->next;
			count++;
		} while (fast != slow);

		slow = head;
		do {
			fast = fast->next;
			slow = slow->next;
		} while (slow->next != fast->next);
		*x = fast->next->data;
		fast->next = NULL;
	}
	return count;

}
//请填入多行代码}

int LinkedListShow_N(SingleNodeList* head, int n) {  //9打印单链表前n个节点 
	SingleNodeList* p = head;
	int i = 0;
	if (p->next == NULL) {
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	}
	while (i <= n) {
		printf("%d ", p->next->data);
		p = p->next;
		i++;
	}
	//请填入多行代码	
	printf("\n");
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
	SingleNodeList* head, * p, * q;
	ElemType i, x;
	int switch_num;
	LinkedListInit(&head);
	scanf("%d", &switch_num);
	for (i = 1; i <= 20; i++)
		LinkedList_PushBack(head, i);
	printf("%d\n", LinkedListLength(head));
	LinkedListShow(head);
	switch (switch_num) {
	case 1:
		LinkedListGetMid(head, &x);
		printf("The mid of list is= %d\n", x);
		break;
	case 2: LinkedListGetLastofN(head, 5, &x);
		printf("The last of 5 in  list is= %d\n", x);
		break;
	case 3:
		LinkedListReversal(head, 5);
		LinkedListShow(head);
		//printf("The last of 5 in  list is= %d\n",x);
		break;
	case 4:
		i = 0; p = head;
		while (p->next != NULL) {
			p = p->next;
			i++;
			if (i <= 8) q = p;
		}
		p->next = q;
		LinkedListShow_N(head, 50);
		printf("\n");
		i = Is_circular_linked_list(head, &x);
		printf("The circular_linked_list'length is= %d\n", i);
		printf("The circular_linked_list start at node = %d\n", x);
		LinkedListShow(head);
		break;
	case 5:
		i = Is_circular_linked_list(head, &x);
		printf("The circular_linked_list'length is= %d\n", i);
		printf("The circular_linked_list start at node = %d\n", x);
		LinkedListShow(head);
		break;
	}
	LinkedListDestroy(&head);
	return 0;
}
/* 【测试用例】

1
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
The mid of list is= 10

2
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
The last of 5 in  list is= 16

3
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
17 18 19 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

4
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 8 9 10 11 12 13 14 15 16 17 1
8 19 20 8 9 10 11 12 13 14 15 16 17 18 19 20 8 9 10 11 12

The circular_linked_list'length is= 13
The circular_linked_list start at node = 8
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

5
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
The circular_linked_list'length is= 0
The circular_linked_list start at node = -12345
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

 */