/* 6 ��ջ���кϷ����жϡ���ջ+˳��ѭ������
������Ҫ��������
1/��ջ�Ļ�������
2/˳��ѭ�����еĻ�������
3/ջ�Ͷ��е��ۺ�����--��ջ���кϷ����ж�
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LiStack;
/****************��ʼ����ջ********************/
void InitStack(LiStack** s)
{
	(*s) = (LiStack*)malloc(sizeof(LiStack));
	(*s)->next = NULL;
}
int  is_empty_stack(LiStack* s)
{
	if (s->next == NULL)
	{
		return 1;
	}
	else  return 0;
}
int push_stack(LiStack* s, ElemType x)
{
	LiStack* p = (LiStack*)malloc(sizeof(LiStack));
	p->data = x;
	p->next = NULL;
	p->next = s->next;
	s->next = p;
	return 1;
}
int pop_stack(LiStack* s, ElemType* x)
{
	if (is_empty_stack(s)) {
		return 0;
	}
	else {
		LiStack* p = s->next;
		*x = s->next->data;
		s->next = s->next->next;
		free(p);
		return 1;
	}

}
ElemType get_stack_top(LiStack* stack)
{
	return stack->next->data;
}
//��1������д�й���ջ�Ķ��������������
#define QUEUEMAX 15 //���ö����������
typedef char DATA;
typedef struct {
	DATA data[QUEUEMAX]; //��������
	int head;
	int tail;
} CycQueue;
int init_queue(CycQueue** q)
{
	(*q) = (CycQueue*)malloc(sizeof(CycQueue));
	(*q)->head = 0;
	(*q)->tail = 0;
	return 1;
}
int is_empty_queue(CycQueue q)
{
	if (q.head == q.tail) {
		return 1;
	}
	else return 0;
}
int is_full_queue(CycQueue q)
{
	if (((q.tail + 1) % QUEUEMAX) == q.head) {
		return 1;
	}
	else return 0;
}
int push_queue(CycQueue* q, DATA x)
{
	if (is_full_queue(*q)) {
		return 0;
	}
	else
	{
		q->data[q->tail] = x;
		q->tail = (q->tail + 1) % QUEUEMAX;
		return 1;
	}
}
int pop_queue(CycQueue* q, DATA* x)
{
	if (is_empty_queue(*q))
	{
		return 0;
	}
	else
	{
		*x = q->data[q->head];
		q->head = (q->head + 1) % QUEUEMAX;
		return 1;
	}

}
DATA get_queue_front(CycQueue Q)
{
	return Q.data[Q.head];
}
//��2������д�й�˳��ѭ�����еĶ��������������
//��������жϣ��Լ���ô���ж϶��п������������ ����ѡ����
//�������дmain�����еġ�3������10���գ��������дmain����

/* int main ()
{
	LiStack* stack;
	CycQueue queue;
	InitStack(&stack);
	init_queue(&queue);

	push_stack(stack,'1');
	 push_stack(stack,'2');
	  push_stack(stack,'3');
	   push_stack(stack,'4');

	push_queue(&queue,'9');
	push_queue(&queue,'8');
	push_queue(&queue,'7');
	push_queue(&queue,'6');

	char x,y;
	pop_stack(stack,&x);
	printf("%c",x);
	pop_stack(stack,&x);
	printf("%c",x);
	pop_queue(&queue,&y);
	printf ("%c",y);

 pop_queue(&queue,&y);
	printf ("%c",y);
	return 0;
}
 */




int main() {
	char ch, * p, a[100], x;
	LiStack* stack;
	CycQueue* Q;

	InitStack(&stack);//��3����ʼ����ջ 

	init_queue(&Q);//��4����ʼ��˳����� 
	//�����ջ���У��������Q��
	scanf("%c", &ch);
	while (ch != '\n') {

		push_queue(Q, ch);    	//��5����� 
		scanf("%c", &ch);//����һ������ 
	}
	//���ζ����������У������д���
	scanf("%c", &ch);
	while (ch != '\n') {
		ElemType a, b;
		push_stack(stack, ch); //��ջ 
		//ȡջͷ���ͷ�������ȣ����ջ&���ӣ�������ȣ������������һ������ 
		a = get_queue_front(*Q);//��ȡ��ͷԪ�� 
		b = get_stack_top(stack);   //��8����ȡջ��Ԫ�� 
		while (a == b && !is_empty_queue(*Q) && !is_empty_stack(stack)) {
			//�����ͷԪ����ջ��Ԫ����ȣ������/��ջ��֮��
	//�����ж϶�ͷԪ����ջ��Ԫ���Ƿ���ȣ���������������/��ջ
			char tem1, tem2;
			pop_queue(Q, &tem1);
			pop_stack(stack, &tem2);
			if (!is_empty_queue(*Q) && !is_empty_stack(stack)) {
				a = get_queue_front(*Q);//��ȡ��ͷԪ�� 
				b = get_stack_top(stack);
			}//��8����ȡջ��Ԫ��
		}
		scanf("%c", &ch); //����������������
	}
	if (ch != '\n' || !is_empty_stack(stack) || !is_empty_queue(*Q))  //11����ջ��Ϊ�գ�12������в�Ϊ��
		printf("------failue!!!------");
	else
		printf("------success!!!------");
	return	0;
}
/* ������������
45321
12345
------success!!!------

34512
12345
------failue!!!------
 */