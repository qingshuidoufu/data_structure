/* 4 堆栈—顺序栈及顺序最小栈
本题主要考查内容：
1/初始化顺序堆栈，求堆栈长度、获取栈顶元素等
2/顺序堆栈的入栈、出栈、遍历栈
3/初始化一个顺序最小栈
4/顺序最小栈的入栈、出栈、求栈中最小元素等
最小栈
最小栈的基本操作和普通栈相同，如入栈、出栈、获取栈顶元素都是O(1)时间；要求得普通栈中最小元素需要遍历整个栈（从栈顶至栈尾），O(n)时间，而最小栈只需O(1)时间。
实现方法如下：
最小栈由一个数据栈A（本站）和一个辅助栈B组成。
最小栈的入栈操作分两个部分，其中数据栈A的入栈、出栈等操作与普通栈相同，辅助栈则依次方法：如果辅助栈为空，则将元素入栈，如果辅助栈不为空，则比较入栈元素与辅助栈的栈顶元素，若小，则辅助栈入栈(若大于等于，则不用入辅助栈)。
最小栈的出栈操作也分两部分，其中数据栈A的入栈、出栈等操作与普通栈相同，辅助栈则依次方法：如果辅助栈为空，则出错，如果辅助栈不为空，则比较数据栈的出栈元素与辅助栈的栈顶元素，若等，则辅助栈出栈(若大于，则不用入辅助栈，若小，则出错)。
要求最小栈的最小元素，其实就是求数据栈A中所有元素之最小，去辅助栈栈顶元素即可（此时辅助栈并不用出栈操作）。
例如，先要依次入栈5，3，6，2，1，6
入/出栈次序         元素        数据栈A（左底右顶） 辅助栈B A（左底右顶）
1					5			5					5
2					3			5 3					5 3
3					6			5 3 6					5 3
4					2			5 3 6 2				5 3 2
5					1			5 3 6 2 1				5 3 2 1
6					6			5 3 6 2 1 6			5 3 2 1
现在进行出栈操作3次
7					6			5 3 6 2 1				5 3 2 1
8					1			5 3 6 2				5 3 2
9					2			5 3 6 				5 3
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef  int  ElemType;
//栈的顺序结构表示 
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
//1.构建一个空栈 
void InitStack(SqStack* S)
{
	S->top = 0;
}
//初始化一个最小栈     此函数需认真体会 
void minStackCreate(SqStack_Min* S)
{
	S->data = (SqStack*)malloc(sizeof(SqStack));
	S->data->top = 0;
	S->min = (SqStack*)malloc(sizeof(SqStack));
	S->min->top = 0;
}

//2.判断顺序栈是否为空
int StackEmpty(SqStack* S)
{
	if (S->top <= 0)//空栈返回0 
		return 0;
	else
		return 1;
}
//3.清空栈 
int ClearStack(SqStack S)
{
	S.top = 0;
	return 1;
}
//4.栈的长度 
int StackLength(SqStack S)
{
	return S.top;//也可以直接返回S.top - S.base
}

//6.求栈顶元素 
int GetTop(SqStack S, ElemType* e)
{
	if (S.top <= 0)
		return 0;
	else
		*e = S.stack[S.top - 1];
	//【1】此处填入1行代码
	return 1;
}
//获取最小栈--数据栈栈顶元素 
void GetTop_Data(SqStack_Min S, ElemType* e) {
	GetTop(*(S.data), e);
}
//获取最小栈--当前栈最小元素 
void GetTop_Min(SqStack_Min S, ElemType* e) {
	GetTop(*(S.min), e);
	//【2】此处填入1行代码
}

//7.栈顶插入元素 
int Push(SqStack* S, ElemType e)
{
	if (S->top >= MaxSize)
	{
		return 0;
	}
	S->stack[S->top] = e;
	S->top++;

	//【3】此处填入2行代码
	return 1;
}
//最小栈栈顶插入元素即入栈 
int Push_Min(SqStack_Min* S, ElemType e)
{
	ElemType x;
	Push(S->data, e);//数据栈元素入栈 
	if (S->min->top == 0)		Push(S->min, e);//辅助栈为空的情况 
	else {
		GetTop(*(S->min), &x);//取辅助栈栈顶元素 
		if (x > e)Push(S->min, e);//如果数据栈入栈元素e比辅助栈栈顶元素小，则e入辅助栈 
	}
	return 1;
}

//8.删除栈顶元素 
int  Pop(SqStack* S, ElemType* e)
{
	if (S->top <= 0)
		return 0;
	else
	{
		S->top--;
		*e = S->stack[S->top];
		//说明：此处容易使人迷惑，实际上此元素并没真正删除，仍在S->top中，
		//但是如果插入元素，就会被更新，就像是删除了一样
		return 1;
	}
}
//删除最小栈栈顶元素，即出栈,最小栈的出栈操作也分两部分，其中数据栈A的入栈、出栈等操作与普通栈相同，辅助栈则依次方法：如果辅助栈为空，则出错，如果辅助栈不为空，则比较数据栈的出栈元素与辅助栈的栈顶元素，若等，则辅助栈出栈(若大于，则不用chu辅助栈，若小，则出错)。
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

	//【4】此处填入多行代码
}

//9.遍历栈 
int StackTraverse(SqStack S)
{
	if (S.top < 0)
		return 0;
	if (S.top == 0)
		printf("栈中没有元素……\n");
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
//遍历最小栈 
int StackTraverse_Min(SqStack_Min S) {
	StackTraverse(*(S.data));//遍历最小栈的数据栈
	StackTraverse(*(S.min));
	return 1;
	//【5】;遍历最小栈的辅助栈
}

//主函数 
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
/* 【测试用例】
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
