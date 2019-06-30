/* 4 ��ջ��˳��ջ��˳����Сջ
������Ҫ�������ݣ�
1/��ʼ��˳���ջ�����ջ���ȡ���ȡջ��Ԫ�ص�
2/˳���ջ����ջ����ջ������ջ
3/��ʼ��һ��˳����Сջ
4/˳����Сջ����ջ����ջ����ջ����СԪ�ص�
��Сջ
��Сջ�Ļ�����������ͨջ��ͬ������ջ����ջ����ȡջ��Ԫ�ض���O(1)ʱ�䣻Ҫ�����ͨջ����СԪ����Ҫ��������ջ����ջ����ջβ����O(n)ʱ�䣬����Сջֻ��O(1)ʱ�䡣
ʵ�ַ������£�
��Сջ��һ������ջA����վ����һ������ջB��ɡ�
��Сջ����ջ�������������֣���������ջA����ջ����ջ�Ȳ�������ͨջ��ͬ������ջ�����η������������ջΪ�գ���Ԫ����ջ���������ջ��Ϊ�գ���Ƚ���ջԪ���븨��ջ��ջ��Ԫ�أ���С������ջ��ջ(�����ڵ��ڣ������븨��ջ)��
��Сջ�ĳ�ջ����Ҳ�������֣���������ջA����ջ����ջ�Ȳ�������ͨջ��ͬ������ջ�����η������������ջΪ�գ�������������ջ��Ϊ�գ���Ƚ�����ջ�ĳ�ջԪ���븨��ջ��ջ��Ԫ�أ����ȣ�����ջ��ջ(�����ڣ������븨��ջ����С�������)��
Ҫ����Сջ����СԪ�أ���ʵ����������ջA������Ԫ��֮��С��ȥ����ջջ��Ԫ�ؼ��ɣ���ʱ����ջ�����ó�ջ��������
���磬��Ҫ������ջ5��3��6��2��1��6
��/��ջ����         Ԫ��        ����ջA������Ҷ��� ����ջB A������Ҷ���
1					5			5					5
2					3			5 3					5 3
3					6			5 3 6					5 3
4					2			5 3 6 2				5 3 2
5					1			5 3 6 2 1				5 3 2 1
6					6			5 3 6 2 1 6			5 3 2 1
���ڽ��г�ջ����3��
7					6			5 3 6 2 1				5 3 2 1
8					1			5 3 6 2				5 3 2
9					2			5 3 6 				5 3
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef  int  ElemType;
//ջ��˳��ṹ��ʾ 
typedef struct
{
	ElemType stack[MaxSize];
	int  top;
}SqStack;
typedef struct
{
	SqStack* data;
	SqStack* min;
}SqStack_Min;
//1.����һ����ջ 
void InitStack(SqStack* S)
{
	S->top = 0;
}
//��ʼ��һ����Сջ     �˺������������ 
void minStackCreate(SqStack_Min* S)
{
	S->data = (SqStack*)malloc(sizeof(SqStack));
	S->data->top = 0;
	S->min = (SqStack*)malloc(sizeof(SqStack));
	S->min->top = 0;
}

//2.�ж�˳��ջ�Ƿ�Ϊ��
int StackEmpty(SqStack* S)
{
	if (S->top <= 0)//��ջ����0 
		return 0;
	else
		return 1;
}
//3.���ջ 
int ClearStack(SqStack S)
{
	S.top = 0;
	return 1;
}
//4.ջ�ĳ��� 
int StackLength(SqStack S)
{
	return S.top;//Ҳ����ֱ�ӷ���S.top - S.base
}

//6.��ջ��Ԫ�� 
int GetTop(SqStack S, ElemType* e)
{
	if (S.top <= 0)
		return 0;
	else
		*e = S.stack[S.top - 1];
	//��1���˴�����1�д���
	return 1;
}
//��ȡ��Сջ--����ջջ��Ԫ�� 
void GetTop_Data(SqStack_Min S, ElemType* e) {
	GetTop(*(S.data), e);
}
//��ȡ��Сջ--��ǰջ��СԪ�� 
void GetTop_Min(SqStack_Min S, ElemType* e) {
	GetTop(*(S.min), e);
	//��2���˴�����1�д���
}

//7.ջ������Ԫ�� 
int Push(SqStack* S, ElemType e)
{
	if (S->top >= MaxSize)
	{
		return 0;
	}
	S->stack[S->top] = e;
	S->top++;

	//��3���˴�����2�д���
	return 1;
}
//��Сջջ������Ԫ�ؼ���ջ 
int Push_Min(SqStack_Min* S, ElemType e)
{
	ElemType x;
	Push(S->data, e);//����ջԪ����ջ 
	if (S->min->top == 0)		Push(S->min, e);//����ջΪ�յ���� 
	else {
		GetTop(*(S->min), &x);//ȡ����ջջ��Ԫ�� 
		if (x > e)Push(S->min, e);//�������ջ��ջԪ��e�ȸ���ջջ��Ԫ��С����e�븨��ջ 
	}
	return 1;
}

//8.ɾ��ջ��Ԫ�� 
int  Pop(SqStack* S, ElemType* e)
{
	if (S->top <= 0)
		return 0;
	else
	{
		S->top--;
		*e = S->stack[S->top];
		//˵�����˴�����ʹ���Ի�ʵ���ϴ�Ԫ�ز�û����ɾ��������S->top�У�
		//�����������Ԫ�أ��ͻᱻ���£�������ɾ����һ��
		return 1;
	}
}
//ɾ����Сջջ��Ԫ�أ�����ջ,��Сջ�ĳ�ջ����Ҳ�������֣���������ջA����ջ����ջ�Ȳ�������ͨջ��ͬ������ջ�����η������������ջΪ�գ�������������ջ��Ϊ�գ���Ƚ�����ջ�ĳ�ջԪ���븨��ջ��ջ��Ԫ�أ����ȣ�����ջ��ջ(�����ڣ�����chu����ջ����С�������)��
int Pop_Min(SqStack_Min* S, ElemType* e)
{
	if (S->data->top <= 0) {
		return 0;
	}
	*e = S->data->stack[S->data->top - 1];
	S->data->top = S->data->top - 1;
	if (S->min->top <= 0) {
		return 0;
	}
	if (S->min->stack[S->min->top - 1] < *e) {
		return 0;
	}
	if (S->min->stack[S->min->top - 1] < *e);
	if (S->min->stack[S->min->top - 1] == *e) {
		S->min->top = S->min->top - 1;
	}

	//��4���˴�������д���
}

//9.����ջ 
int StackTraverse(SqStack S)
{
	if (S.top < 0)
		return 0;
	if (S.top == 0)
		printf("ջ��û��Ԫ�ء���\n");
	int p;
	p = S.top;
	while (p)
	{
		p--;
		printf("%d ", S.stack[p]);
	}
	printf("\n");

	return 1;
}
//������Сջ 
int StackTraverse_Min(SqStack_Min S) {
	StackTraverse(*(S.data));//������Сջ������ջ
	StackTraverse(*(S.min));
	return 1;
	//��5��;������Сջ�ĸ���ջ
}

//������ 
int main() {
	SqStack stack;
	SqStack_Min minstack;
	int x, i;
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		InitStack(&stack);
		printf("%d\n", StackEmpty(&stack));
		for (i = 1; i <= 10; i++)
			Push(&stack, i);
		Push(&stack, 100);
		Push(&stack, 1000);
		Push(&stack, 10000);
		printf("%d\n", StackLength(stack));
		StackTraverse(stack);

		for (i = 1; i <= 5; i++)
			Pop(&stack, &x);

		GetTop(stack, &x);
		printf("%d\n", x);
		StackTraverse(stack);
		break;
	case 2: {
		ElemType x, y;
		minStackCreate(&minstack);
		Push_Min(&minstack, 500);
		Push_Min(&minstack, 300);
		Push_Min(&minstack, 600);
		Push_Min(&minstack, 200);
		Push_Min(&minstack, 100);
		Push_Min(&minstack, 600);
		GetTop_Min(minstack, &x);
		printf("%d\n", x);
		StackTraverse_Min(minstack);

		Pop_Min(&minstack, &y);
		GetTop_Min(minstack, &x);
		printf("%d\n", x);

		Pop_Min(&minstack, &y);
		GetTop_Min(minstack, &x);
		printf("%d\n", x);
		StackTraverse_Min(minstack);
		break;
	}
	case 3: {
		ElemType x, y;
		minStackCreate(&minstack);
		Push_Min(&minstack, 8);
		Push_Min(&minstack, 7);
		Push_Min(&minstack, 10);
		Push_Min(&minstack, 6);
		Push_Min(&minstack, 12);
		Push_Min(&minstack, 9);
		StackTraverse_Min(minstack);
		GetTop_Min(minstack, &x);
		printf("%d\n\n", x);

		Pop_Min(&minstack, &y);
		Pop_Min(&minstack, &y);
		Pop_Min(&minstack, &y);
		StackTraverse_Min(minstack);
		GetTop_Min(minstack, &x);
		printf("%d\n\n", x);

		Push_Min(&minstack, 4);
		Push_Min(&minstack, 13);
		Push_Min(&minstack, 11);
		Push_Min(&minstack, 5);
		StackTraverse_Min(minstack);
		GetTop_Min(minstack, &x);
		printf("%d\n\n", x);
		break;
	}

	}
	return 0;
}
/* ������������
1
0
13
10000 1000 100 10 9 8 7 6 5 4 3 2 1
8
8 7 6 5 4 3 2 1

2
100
600 100 200 600 300 500
100 200 300 500
100
200
200 600 300 500
200 300 500

3
9 12 6 10 7 8
6 7 8
6

10 7 8
7 8
7

5 11 13 4 10 7 8
4 7 8
4 */
