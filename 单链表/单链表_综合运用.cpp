/* ������Ҫ�������ݣ�
1>��������
2>�����ӷ�
3>������ԭ������
4>������������鲢����
5>ɾ�����������������ظ�Ԫ��
6>��������ͷ�ڵ㵥�����Ƿ� �ཻ������ཻ�����������������أ��������-12345
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct SingleNode {
	ElemType data;
	struct SingleNode* next;
}SingleNodeList, * Linklist;
void LinkedListInit(SingleNodeList** head) {//1��ʼ����ͷ�ڵ�ĵ����� 
	Linklist p;
	if ((*head = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	(*head)->next = NULL;
}
int LinkedList_PushBack(SingleNodeList* head, ElemType x) {//2������β���� 
	SingleNodeList* p = head, * q;
	while (p->next != NULL)
		p = p->next;
	if ((q = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
		exit(1);
	}
	q->data = x; q->next = NULL; //β�ڵ����������ָ����ֵ 
	p->next = q;//β�ڵ�������� 
	return 1;
}

int LinkedListShow(SingleNodeList* head) {//3��ӡ������
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
void LinkedListDestroy(SingleNodeList** head) {//4�ͷ����� 
	SingleNodeList* p = *head, * q;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}
//�˺���������¹���
//1������һ�����ݣ����� 1 3 5 7 9 8 6 4 2 ����Щ������֯��һ����ͷ�ڵ�ĵ�����A����Ԫ��
//Ϊ1. A���� head(A)->1->3->5->7->9->8->6->4->2
//2������һ����X������X=5.5����A����ֳ�B��C�������֣�B�нڵ�ֵ��XС��C�нڵ㶼��X��
//�磺A���ֽ��B��C����head(B)->1->3->5->4->2   head(C)->6->8->9->7
//��ע��B��C������Ԫ����ԭ����A�еĴ���
//3����B��C�ϲ�������A��ͷָ��֮���� head(A)->1->3->5->4->2->6->8->9->7
int LinkedList_Divide(SingleNodeList* head, ElemType x) {//5������Ļ��� 
	SingleNodeList* headA, * headB;
	LinkedListInit(&headA);
	LinkedListInit(&headB);
	SingleNodeList* A, * B;
	A = headA;
	B = headB;
	SingleNodeList* p;
	p = head->next;

	while (p) {

		if (p->data < x) {
			A->next = p;
			A = A->next;
		}
		else if (p->data > x) {
			SingleNodeList* tem;
			if ((tem = (SingleNodeList*)(malloc(sizeof(SingleNodeList)))) == NULL) {
				exit(0);
			}
			tem->data = p->data;
			tem->next = NULL;
			tem->next = headB->next;
			headB->next = tem;
		}

		p = p->next;
	}

	A->next = headB->next;
	head->next = headA->next;
	return 1;
	//��������д���
}
int LinkedList_Add(SingleNodeList* head, ElemType x1, ElemType x2) {
	SingleNodeList* p;
	int tem1 = x1, tem2 = x2;
	while (tem1 != 0)
	{
		printf("%d ", tem1 % 10);
		tem1 = tem1 / 10;
	}
	printf("\n");
	while (tem2 != 0)
	{
		printf("%d ", tem2 % 10);
		tem2 = tem2 / 10;
	}
	printf("\n");

	int max = x1, min = x1;
	if (x2 > max) {
		max = x2;
	}
	if (x2 < min) {
		min = x2;
	}
	while (max != 0) {
		LinkedList_PushBack(head, max % 10);
		max = max / 10;
	}

	p = head->next;
	SingleNodeList* p1;
	p1 = p->next;
	while (min != 0) {
		p->data = min % 10 + p->data;
		if (p->data >= 10) {
			p->data = p->data % 10;
			p1->data++;
		}
		min = min / 10;
		p = p->next;
		p1 = p->next;
	}

	return 0;
	//6����ת��������ṹ�����  
	//��������д���
}
int LinkedList_Rever(SingleNodeList* head) {//7ԭ������ 
	Linklist pre = NULL, next = NULL, p;
	p = head->next;

	//p�ǵ�ǰ�ڵ㣬pre��p��ֱ��ǰ����next��p�ĺ�� 
	while (p != NULL) {
		next = p->next;
		p->next = pre;
		pre = p;
		p = next;
	}

	//��������д���	

	head->next = pre;
	return 0;
}
//P1������11->23->35->47->59
//P1������8->36->44->52
//�ϲ���P1������8->11->23->35->35->44->47->52->59 
int LinkedList_MergingSort(Linklist p1, Linklist p2) {//8p1��p2�鲢���򣬲�������p1��ͷ�ڵ� 
	SingleNodeList* q1, * q2, * q1pre, * tem;
	q1 = p1->next;
	q1pre = p1;
	q2 = p2->next;
	while (q2 != NULL)
	{
		q1 = p1->next;
		q1pre = p1;
		while (q1->data < q2->data && q1 != NULL) {
			q1pre = q1;
			q1 = q1->next;
		}
		if ((tem = (SingleNodeList*)malloc(sizeof(SingleNodeList))) == NULL) {
			exit(0);
		}
		tem->data = q2->data;
		tem->next = NULL;
		q1pre->next = tem;
		tem->next = q1;
		q2 = q2->next;


	}

	return 0;

	//��������д���	
}
//��һ������Ϊ 36 -> 37 -> 65 -> 76 -> 97 -> 98 -> 98 -> 98 -> 98 -> 98 
//ɾ���ظ�Ԫ�غ�Ϊ: 36 -> 37 -> 65 -> 76 -> 97 -> 98
int LinkedList_Sorted_Delete(Linklist head) {//9ɾ�����������������ظ�Ԫ��
	Linklist curr = head->next, temp;

	while (curr->next != NULL) {
		temp = curr->next;
		if (temp->data == curr->data) {
			curr->next = temp->next;
		}
		else {
			curr = curr->next;
		}
	}
	return 0;

	//��������д���	
}

//10�ж�������ͷ�ڵ㵥�����Ƿ��ཻ������ཻ�����������������أ��������-12345 

int LinkedList_Is_Intersect(Linklist p1, Linklist p2, ElemType* x) {
	SingleNodeList* q1, * q2, * temp;
	temp = p1->next;
	q1 = p1->next;
	q2 = p2->next;
	int flag = -1;
	while (q2 != NULL) {
		q1 = p1->next;
		while (q1 != NULL) {
			if (q1->data == q2->data) {
				temp = q1;
				SingleNodeList* q1x, * q2x;
				q1x = q1;
				q2x = q2;
				while (q1x->next != NULL) {
					q1x = q1x->next;
					q2x = q2x->next;
					if (q1x->data == q2x->data) {
						flag = 1;
					}
					else {
						flag = -1;
					}
				}
			}
			q1 = q1->next;
			if (flag == 1) {
				break;
			}
		}
		q2 = q2->next;
		if (flag == 1) {
			break;
		}
	}
	if (flag == 1) {
		*x = temp->data;
	}
	return 0;
	//��������д���	
}
int main() {
	SingleNodeList* head, * p, * q;
	Linklist p1, p2;
	ElemType i, x, x1, x2;
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		LinkedListInit(&head);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 5);
		LinkedList_PushBack(head, 7);
		LinkedList_PushBack(head, 9);
		LinkedList_PushBack(head, 8);
		LinkedList_PushBack(head, 6);
		LinkedList_PushBack(head, 4);
		LinkedList_PushBack(head, 2);
		LinkedListShow(head);
		LinkedList_Divide(head, 5);
		LinkedListShow(head);
		break;
	case 2:
		LinkedListInit(&head);
		LinkedList_Add(head, 12345, 5678999);
		LinkedListShow(head);
		LinkedList_Rever(head);
		LinkedListShow(head);
		break;
	case 3:
		LinkedListInit(&head);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 5);
		LinkedList_PushBack(head, 7);
		LinkedList_PushBack(head, 9);
		LinkedList_PushBack(head, 8);
		LinkedList_PushBack(head, 6);
		LinkedList_PushBack(head, 4);
		LinkedList_PushBack(head, 2);
		LinkedListShow(head);
		LinkedList_Rever(head);
		LinkedListShow(head);
		break;
	case 4:
		LinkedListInit(&p1);
		LinkedListInit(&p2);
		LinkedList_PushBack(p1, 11);
		LinkedList_PushBack(p1, 23);
		LinkedList_PushBack(p1, 35);
		LinkedList_PushBack(p1, 47);
		LinkedList_PushBack(p1, 59);
		LinkedListShow(p1);
		LinkedList_PushBack(p2, 8);
		LinkedList_PushBack(p2, 36);
		LinkedList_PushBack(p2, 44);
		LinkedList_PushBack(p2, 52);
		LinkedListShow(p2);
		LinkedList_MergingSort(p1, p2);
		LinkedListShow(p1);
		break;
	case 5:
		LinkedListInit(&head);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 19);
		LinkedList_PushBack(head, 19);
		LinkedList_PushBack(head, 26);
		LinkedList_PushBack(head, 34);
		LinkedList_PushBack(head, 34);
		LinkedList_PushBack(head, 34);
		LinkedList_PushBack(head, 54);
		LinkedListShow(head);
		LinkedList_Sorted_Delete(head);
		LinkedListShow(head);
		break;
	case 6:
		LinkedListInit(&head);
		LinkedList_PushBack(head, 1);
		LinkedList_PushBack(head, 3);
		LinkedList_PushBack(head, 5);
		LinkedList_PushBack(head, 7);
		LinkedList_PushBack(head, 9);
		LinkedList_PushBack(head, 8);
		LinkedList_PushBack(head, 6);
		LinkedList_PushBack(head, 4);
		LinkedList_PushBack(head, 2);
		LinkedListShow(head);
		LinkedListInit(&p1);
		LinkedListInit(&p2);
		LinkedList_PushBack(p1, 11);
		LinkedList_PushBack(p1, 23);
		LinkedList_PushBack(p1, 35);
		LinkedList_PushBack(p1, 47);
		LinkedList_PushBack(p1, 59);
		p = p1;
		while (p->next != NULL)
			p = p->next;
		p->next = head->next;
		LinkedListShow(p1);
		LinkedList_PushBack(p2, 8);
		LinkedList_PushBack(p2, 36);
		LinkedList_PushBack(p2, 44);
		LinkedList_PushBack(p2, 52);
		p = p2;
		while (p->next != NULL)
			p = p->next;
		p->next = head->next;
		LinkedListShow(p2);

		LinkedList_Is_Intersect(p1, p2, &x);
		printf("The intersect node  num = %d\n", x);
	}
	//LinkedListDestroy(&head);
	return 0;
}
/* ������������
1
1 3 5 7 9 8 6 4 2
1 3 4 2 6 8 9 7

2
5 4 3 2 1
9 9 9 8 7 6 5
4 4 3 1 9 6 5
5 6 9 1 3 4 4

3
1 3 5 7 9 8 6 4 2
2 4 6 8 9 7 5 3 1

4
11 23 35 47 59
8 36 44 52
8 11 23 35 36 44 47 52 59

5
1 1 1 1 1 3 3 3 19 19 26 34 34 34 54
1 3 19 26 34 54

6
1 3 5 7 9 8 6 4 2
11 23 35 47 59 1 3 5 7 9 8 6 4 2
8 36 44 52 1 3 5 7 9 8 6 4 2
The intersect node  num = 1

 */