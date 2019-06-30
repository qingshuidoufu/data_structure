/* 6 出栈序列合法性判断—链栈+顺序循环队列
本题主要考察内容
1/链栈的基本操作
2/顺序循环队列的基本操作
3/栈和队列的综合运用--出栈序列合法性判断
【程序片段】 */
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
/****************初始化链栈********************/
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
//【1】请填写有关链栈的多个基本操作函数
#define QUEUEMAX 15 //设置队列最大容量
typedef char DATA;
typedef struct {
	DATA data[QUEUEMAX]; //队列数组
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
//【2】请填写有关顺序循环队列的多个基本操作函数
//假溢出的判断，以及怎么样判断队列空与队列满，可 以任选方法
//你可以填写main函数中的【3】至【10】空，亦可以重写main函数

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

	InitStack(&stack);//【3】初始化链栈 

	init_queue(&Q);//【4】初始化顺序队列 
	//输入出栈序列，存入队列Q中
	scanf("%c", &ch);
	while (ch != '\n') {

		push_queue(Q, ch);    	//【5】入队 
		scanf("%c", &ch);//读下一个符号 
	}
	//依次读入输入序列，并进行处理
	scanf("%c", &ch);
	while (ch != '\n') {
		ElemType a, b;
		push_stack(stack, ch); //入栈 
		//取栈头与队头，如果相等，则出栈&出队，如果不等，则继续处理下一个符号 
		a = get_queue_front(*Q);//获取队头元素 
		b = get_stack_top(stack);   //【8】获取栈顶元素 
		while (a == b && !is_empty_queue(*Q) && !is_empty_stack(stack)) {
			//如果队头元素与栈顶元素相等，则出队/出栈，之后
	//继续判断队头元素与栈顶元素是否相等，若相等则继续出队/出栈
			char tem1, tem2;
			pop_queue(Q, &tem1);
			pop_stack(stack, &tem2);
			if (!is_empty_queue(*Q) && !is_empty_stack(stack)) {
				a = get_queue_front(*Q);//获取队头元素 
				b = get_stack_top(stack);
			}//【8】获取栈顶元素
		}
		scanf("%c", &ch); //继续处理输入序列
	}
	if (ch != '\n' || !is_empty_stack(stack) || !is_empty_queue(*Q))  //11空填栈不为空，12空填队列不为空
		printf("------failue!!!------");
	else
		printf("------success!!!------");
	return	0;
}
/* 【测试用例】
45321
12345
------success!!!------

34512
12345
------failue!!!------
 */