/* 3 堆栈—链式栈及符号平衡
本题主要考察内容
1/链式堆栈的初始化
2/获取栈顶元素与打印栈内容（从栈顶至栈底）
3/链式栈的入栈与出栈
4/栈在符号平衡问题上的应用

栈在符号平衡问题上的应用
编译器检查程序的语法错误，但是常常由于缺少一个符号（如遗漏一个花括号或是注释起始符）导致编译器列出上百行的错误，而真正的错误却并没有找出。
在这种情况下，一个有用的工具就是检验是否所有的东西都成对出现的程序。于是，每一个右花括号、右方括号级右圆括号必然对应其相应的左半部分。[()]是合法的，但是[(])就是错误的。显然，不值得为此编写一个大型程序，但是这说明了这样的检验时很容易实现的。为简单起见，我们仅就圆括号、方括号和花括号进行检验并忽略出现的任何其他字符。
这个简单的算法用到一个栈，叙述如下：
建立一个空栈，读入字符直至文件尾。如果字符是一个开放符号，则将其压入栈中。如果字符是一个封闭符号，那么：1）若栈为空，则报错；2）若栈不为空，则将栈顶元素弹出，如果弹出的符号不是对应的开放符号，则报错；3）在文件尾，如果栈非空则报错。
可以确信。这个算法是可以正确运行的。很清楚，算法是线性的，事实上它只需对输入进行一次检验。因此，它是联机（on-line）的并且相当快。可以做一些附加的工作来决定当检查出错误时如何处理----例如判断可能的原因。
伪代码如下：//若有错误或有歧义，请联系老师改正
输入符号串一字符‘@’结束，首先假设是符号平衡的（flag=1）
1依次读入符号，直至遇到结束符
2处理此符号
2.1符号不为操作符，转5
2.2读入符号为操作符
2.2.1是左操作符，入栈
2.2.2是右操作符
2.2.2.1检查堆栈，如果栈为空，出错flag=0，break
2.2.2.2检查堆栈，栈不为空，获取栈顶元素
	2.2.2.2.1 栈顶元素为对应左操作符，出栈
	2.2.2.2.2	栈顶元素不为对应左操作符，出错flag=0，break
0	转1
4 栈空且flag==1  成功
5栈非空 或 flag==0  失败
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LiStack, * PointStack;
/****************初始化链栈********************/

void InitStack(LiStack** s)//请体会，函数参数是指向指针的指针，这样才能影响
//主调函数传过来的实参（实参是指向linknode类型的指针） 
{
	//请注意“(*s)” 的使用！！！ 
	(*s) = (LiStack*)malloc(sizeof(LiStack));
	(*s)->next = NULL;
}

/****************销毁链栈********************/
void DestroyStack(LiStack* s)
{
	LiStack* p = s->next, * q = s;
	while (p != NULL)
	{
		free(q);
		q = p;
		p = p->next;
	}
	free(p);
}
/****************判断链栈是否为空********************/
int StackEmpty(LiStack* s)
{
	return (s->next == NULL);
}
/****************进栈********************/
void Push(LiStack* s, ElemType e)
{

	LiStack* newNode = (LiStack*)malloc(sizeof(LiStack));
	newNode->data = e;
	newNode->next = s->next;
	s->next = newNode;
	//【1】请填写多行代码
}
/****************出栈********************/
int Pop(LiStack* s, ElemType* e)
{
	LiStack* p = s->next;
	if (s->next == NULL)
		return 0;
	else
	{
		*e = p->data;
		s->next = p->next;
		free(p);
		// 【2】请填写多行代码

		return 1;
	}
}
/****************得到栈顶元素********************/
int GetTop(LiStack* s, ElemType* e)
{
	LiStack* p = s->next;
	if (s->next == NULL)
		return 0;
	*e = p->data;
	//【3】请填写一行代码
	return 1;
}
/****************输出链栈元素********************/
void PrintStack(LiStack* s)
{
	LiStack* p = s->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LiStack* stack=NULL, * p;
	int switch_num;
	char x, y;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		InitStack(&stack);
		Push(stack, '1');
		Push(stack, '2');
		Push(stack, '3');
		PrintStack(stack);
		GetTop(stack, &x);
		printf("%c\n", x);
		Pop(stack, &x);
		Pop(stack, &x);
		PrintStack(stack);
		Push(stack, 'a');
		Push(stack, 'b');
		Push(stack, 'c');
		Pop(stack, &x);
		Push(stack, 'd');
		PrintStack(stack);
		break;
	case 2: {
		InitStack(&stack);
		int flag = 1;//首先假设符号是平衡的 
		getchar();
		while ((x = getchar()) != '@') {//输入符号串以‘@’符号结束 

			switch (x)
			{
			case'(':case'[':case'{':Push(stack, x); break;//2.2.1如果为左操作符,读入栈中
			case ')': case ']': case '}':      //2.2.2如果为右操作符,执行以下操作
			{
				if (!StackEmpty(stack))                //判断栈是否为空
				{
					GetTop(stack, &y);         //2.2.2.2获取栈顶元素                
					if (x == ')' && y == '(' || x == ']' && y == '[' || x == '}' && y == '{') {      //2.2.2.2.1判断是否符号对应
						Pop(stack, &y);          //2.2.2.2.1出栈
					}
					else          //2.2.2.2.2 符号不对应,改flag为0,跳出判断flag
					{
						flag = 0;
					}
				}
				else
				{
					flag = 0;
				}
			}break;
			default:break;          //2.1不为操作符,则默认不处理,跳出switch,继续循环读x
			}
			if (flag == 0)         //续2.2.2.1和2.2.2.2.2,flag为0则出事了,直接failure吧
			{
				break;
			}

			//【4】请填写多行代码
		}
		if (!StackEmpty(stack)) flag = 0;
		if (flag)printf("Success\n");
		else printf("Failure\n");
		break;
	}
	}
	DestroyStack(stack);
	return 0;
}
/* 【测试用例】
1
3 2 1
3
1
d b a 1

2
[(3-1)/5-4]-[(2-2)*(2-2)-1]@
Success

2
[5-4-(3*3))-1]@
Failure
 */