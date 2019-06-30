/* 10 中缀表达式转换为后缀表达式
栈不仅可以用来计算后缀表达式的值，而且还可以用来将一个标准型的表达式（或者叫做中缀表达式(infix)）转换成后缀表达式。
假设1)表达式是合法的；2)只允许操作符“+ - * / ( )”；3)普通的运算符优先。按照上述三个假设将普通问题浓缩成小规模问题。欲将中缀表达式a + b * c + ( d * e + f ) * g 转换成后缀表达式，正确的答案是a b c * + d e * f + g * +。
当读到一个操作数的时候，立即把它放到输出中。操作符不立即输出，从而必须先存在某个地方。正确的做法是将已经见过的操作符放进栈中而不是放到输出中；当遇到左圆括号时我们也要将其推入栈中。算法是从一个初始化为空的栈开始。
如果遇到一个右括号，那么久将栈元素弹出，将符号写出直到遇到一个（对应的）左括号，这个左括号只是被弹出并不写出。
如果遇到任何其他的符号“+ - * / (”，那么从栈中弹出栈元素直到发现优先级更低的元素为止。有一个例外：除非是在处理“)”的时候，否则绝不从栈中移走”(”。对于这种操作，“+”的优先级更加低，而”(”的优先级更加高。当从栈中弹出元素的工作完成后，我们再将操作符压入栈中。
最后，如果读到输入的末尾，将栈元素弹出直到该栈变成空栈，将符号写到输出中。
这个算法的思想是，当遇到一个操作符的时候，把它放到栈中，栈代表挂起的操作符。然而，当栈中那些具有高优先级的操作符完成使用时，就不需要再被挂起而是应该被弹出。这样，在把当前操作符放入栈中之前，那些栈中在使用当前操作符之前将要挂起完成使用的操作符被弹出。请看例子：
表达式	处理第三个操作符时的栈	动作
a*b-c+d	-	-完成，+进栈
a/b+c*d	+	没有操作符完成操作，*进栈
a-b*c/d	- *	*完成，/进栈
a-b*c+d	- *	*和-完成，+进栈
圆括号将问题变得更复杂。当左括号是一个输入符号时可以把它看成是一个高优先级的操作符（使得挂起的操作符仍是挂起的），而当它在栈中时把它看成是低优先级的操作符（从而不会被操作符意外地删除）。将右括号看成特殊的情况。
为了理解这种算法的运行机制，我们将中缀表达式a - b * c + ( d * e + f ) * g转换成后缀表达式a b c * - d e * f + g * +。
a - b * c + ( d * e + f ) * g
状态表如下：

输入串	栈	输出	说明
a - b * c + ( d * e + f ) * g		a	读入输入串最左符号a，直接放输出
- b * c + ( d * e + f ) * g	-	a	操作符 - 入栈
b * c + ( d * e + f ) * g	-	a b	符号b直接放输出
* c + ( d * e + f ) * g	- *	a b 	*比栈顶符号 – 优先及高，入栈
c + ( d * e + f ) * g	- *	a b c
+ ( d * e + f ) * g	+	a b c * -	*- 优先级大于等于+，*-依次出栈，+入栈
( d * e + f ) * g	+(	a b c * -	(直接入栈
d * e + f ) * g	+(	a b c * - d
* e + f ) * g	+( *	a b c * - d	*入栈
e + f ) * g	+( *	a b c * - d e
+ f ) * g	+(+	a b c * - d e *	+优先级小，*出栈，+入栈
f ) * g	+(+	a b c * - d e * f
) * g	+	a b c * - d e * f +	+出栈，直至遇到(
* g	+ *	a b c * - d e * f +
g	+ *	a b c * - d e * f + g
		a b c * - d e * f + g * +

请编写一个程序，中缀表达式转换为后缀表达式。
为了简化操作，我们假定操作数均为个位整数，操作符只有‘+’、‘-’、‘*’、和‘/’四种，括号符只有‘(’和‘)’。程序输入：一行由操作数、括号符与操作符组成的字符串，以回车表示结束。无需考虑其他非法字符。
输出：一行字符，其值为后缀表达式。
样例1：
输入：3*(5+8)
输出：358+*
样例2：
输入：8/(5+2)-6
输出：852+/6-
样例3：
输入：(1+2)*3-7/(4+6/2)-1
输出： 12+3*7462/+/1—
样例4：
	输入：3+(5*6-7/1*7)*9
	输出：356*71/7*-9*+
样例5：
	输入：(1+2)*(3-7)/((4+6)/2-1)
	输出：12+37-*46+2/1-/


 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
	char a[100];
	int top;
}mystack;
mystack* init_stack(mystack** ms) {
	(*ms) = (mystack*)malloc(sizeof(mystack));
	(*ms)->top = 0;
	return (*ms);
}
int is_empty_stack(mystack ms) {
	return (ms.top == 0);
}
int push_stack(mystack* ms, char x) {
	if (ms->top >= 100) {
		return 0;
	}
	else {
		ms->a[ms->top] = x;
		ms->top++;
		return 1;
	}

}
int pop_stack(mystack* ms) {
	if (is_empty_stack(*ms)) {
		return 0;
	}
	else {
		ms->top = ms->top - 1;
		return 1;
	}
}
char get_top_stack(mystack ms) {
	return (ms.a[ms.top - 1]);
}
int main()
{
	mystack* mystack = init_stack(&mystack);
	char c='\0';
	while (c != '\n') {
		scanf("%c", &c);
		if (c >= '0' && c <= '9') {
			printf("%c", c);
		}
		else if ('(' == c) {
			push_stack(mystack, c);
		}
		else if (')' == c) {
			char tem;
			do {
				tem = get_top_stack(*mystack);
				if ('(' == tem) {
					break;
				}
				pop_stack(mystack);
				printf("%c", tem);
			} while (tem != '(');
			pop_stack(mystack);
		}
		else if ('+' == c || '-' == c) {
			if (is_empty_stack(*mystack)) {
				push_stack(mystack, c);
			}
			else {
				char tem;
				do {
					if (is_empty_stack(*mystack)) {
						break;
					}
					tem = get_top_stack(*mystack);
					if ('(' == tem) {
						break;
					}
					printf("%c", tem);
					pop_stack(mystack);
				} while ('(' != tem);
				push_stack(mystack, c);
			}
		}
		else if ('*' == c || '/' == c) {

			if (is_empty_stack(*mystack)) {
				push_stack(mystack, c);
			}
			else {
				char tem;

				do {
					tem = get_top_stack(*mystack);
					if (tem == '(' || tem == '-' || tem == '+') {
						break;
					}
					printf("%c", tem);
					pop_stack(mystack);
					if (is_empty_stack(*mystack)) {
						break;
					}
				} while ('*' == tem || '/' == tem);
				push_stack(mystack, c);
			}

		}
	}
	while (!is_empty_stack(*mystack)) {
		char tem = get_top_stack(*mystack);
		printf("%c", tem);
		pop_stack(mystack);
	}
	return 0;
}
