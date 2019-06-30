/* 7 最小栈的顺序实现
本题主要考察内容
1/自定义最小栈的数据结构
2/不调用普通栈的操作方法函数，重构最小栈的操作方法函数
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//初始化时给定栈大小为20000
	ElemType min[MaxSize];//同时让min的大小也为20000，防止压入data的全是一样的数据
	int top;//data的栈顶指针
	int mintop;//min的栈顶指针
} MinStack;

void minStackCreate(MinStack* stack) {//栈的大小初始化已经在创建栈的时候给定了，本人设置的是20000大小，不用管maxSize

	stack->top = 0;
	stack->mintop = 0;
}
int Push_Min(MinStack* S, ElemType e)//成功入栈返回1，否则返回0
{
	S->data[S->top] = e;
	S->top++;
	if (S->mintop == 0)
	{
		S->min[S->mintop] = e;
		S->mintop++;
	}
	else
	{
		if (e < S->min[S->mintop - 1])
		{
			S->min[S->mintop] = e;
			S->mintop++;
		}
	}
	return 1; //【1】请填入多行代码
}
int Pop_Min(MinStack* S, ElemType* e) {//成功出栈返回1，否则返回0
	if (S->top <= 0 || S->mintop <= 0)
		return 0;
	else
	{
		*e = S->data[S->top - 1]; S->top--;
		if (S->min[S->mintop - 1] == *e) {
			S->mintop--;
		}
		if (S->min[S->mintop - 1] < S->data[S->top - 1])
		{
			return 0;
		}//【2】请填入多行代码
		return 1;
	}
}
int GetMin(MinStack S, ElemType* e)
{
	if (S.top <= 0)
		return 0;
	else
		*e = S.min[S.mintop - 1];
}
int StackTraverse_Min(MinStack S)
{
	if (S.top < 0 || S.mintop < 0)
		return 0;
	if (S.top == 0 || S.mintop == 0)
		printf("栈中没有元素……\n");
	int p;
	p = S.top;
	while (p)
	{
		p--;
		printf("%d ", S.data[p]);
	}
	printf("\n");
	p = S.mintop;
	while (p)
	{
		p--;
		printf("%d ", S.min[p]);
	}
	printf("\n");
	return 1;
}

int main() {
	MinStack minstack;
	int x, i;
	int switch_num;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 2: {
		ElemType x, y;
		minStackCreate(&minstack);
		Push_Min(&minstack, 500);
		Push_Min(&minstack, 300);
		Push_Min(&minstack, 600);
		Push_Min(&minstack, 200);
		Push_Min(&minstack, 100);
		Push_Min(&minstack, 600);
		GetMin(minstack, &x);
		printf("%d\n", x);
		StackTraverse_Min(minstack);

		Pop_Min(&minstack, &y);
		GetMin(minstack, &x);
		printf("%d\n", x);

		Pop_Min(&minstack, &y);
		GetMin(minstack, &x);
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
		GetMin(minstack, &x);
		printf("%d\n\n", x);

		Pop_Min(&minstack, &y);
		Pop_Min(&minstack, &y);
		Pop_Min(&minstack, &y);
		StackTraverse_Min(minstack);
		GetMin(minstack, &x);
		printf("%d\n\n", x);

		Push_Min(&minstack, 4);
		Push_Min(&minstack, 13);
		Push_Min(&minstack, 11);
		Push_Min(&minstack, 5);
		StackTraverse_Min(minstack);
		GetMin(minstack, &x);
		printf("%d\n\n", x);
		break;
	}

	}
	return 0;
}
/* 【测试用例】
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
4
 */