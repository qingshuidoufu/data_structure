/* 10 ��׺���ʽת��Ϊ��׺���ʽ
ջ�����������������׺���ʽ��ֵ�����һ�����������һ����׼�͵ı��ʽ�����߽�����׺���ʽ(infix)��ת���ɺ�׺���ʽ��
����1)���ʽ�ǺϷ��ģ�2)ֻ�����������+ - * / ( )����3)��ͨ����������ȡ����������������轫��ͨ����Ũ����С��ģ���⡣������׺���ʽa + b * c + ( d * e + f ) * g ת���ɺ�׺���ʽ����ȷ�Ĵ���a b c * + d e * f + g * +��
������һ����������ʱ�����������ŵ�����С�������������������Ӷ������ȴ���ĳ���ط�����ȷ�������ǽ��Ѿ������Ĳ������Ž�ջ�ж����Ƿŵ�����У���������Բ����ʱ����ҲҪ��������ջ�С��㷨�Ǵ�һ����ʼ��Ϊ�յ�ջ��ʼ��
�������һ�������ţ���ô�ý�ջԪ�ص�����������д��ֱ������һ������Ӧ�ģ������ţ����������ֻ�Ǳ���������д����
��������κ������ķ��š�+ - * / (������ô��ջ�е���ջԪ��ֱ���������ȼ����͵�Ԫ��Ϊֹ����һ�����⣺�������ڴ���)����ʱ�򣬷��������ջ�����ߡ�(�����������ֲ�������+�������ȼ����ӵͣ�����(�������ȼ����Ӹߡ�����ջ�е���Ԫ�صĹ�����ɺ������ٽ�������ѹ��ջ�С�
���������������ĩβ����ջԪ�ص���ֱ����ջ��ɿ�ջ��������д������С�
����㷨��˼���ǣ�������һ����������ʱ�򣬰����ŵ�ջ�У�ջ�������Ĳ�������Ȼ������ջ����Щ���и����ȼ��Ĳ��������ʹ��ʱ���Ͳ���Ҫ�ٱ��������Ӧ�ñ��������������ڰѵ�ǰ����������ջ��֮ǰ����Щջ����ʹ�õ�ǰ������֮ǰ��Ҫ�������ʹ�õĲ��������������뿴���ӣ�
���ʽ	���������������ʱ��ջ	����
a*b-c+d	-	-��ɣ�+��ջ
a/b+c*d	+	û�в�������ɲ�����*��ջ
a-b*c/d	- *	*��ɣ�/��ջ
a-b*c+d	- *	*��-��ɣ�+��ջ
Բ���Ž������ø����ӡ�����������һ���������ʱ���԰���������һ�������ȼ��Ĳ�������ʹ�ù���Ĳ��������ǹ���ģ�����������ջ��ʱ���������ǵ����ȼ��Ĳ��������Ӷ����ᱻ�����������ɾ�������������ſ�������������
Ϊ����������㷨�����л��ƣ����ǽ���׺���ʽa - b * c + ( d * e + f ) * gת���ɺ�׺���ʽa b c * - d e * f + g * +��
a - b * c + ( d * e + f ) * g
״̬�����£�

���봮	ջ	���	˵��
a - b * c + ( d * e + f ) * g		a	�������봮�������a��ֱ�ӷ����
- b * c + ( d * e + f ) * g	-	a	������ - ��ջ
b * c + ( d * e + f ) * g	-	a b	����bֱ�ӷ����
* c + ( d * e + f ) * g	- *	a b 	*��ջ������ �C ���ȼ��ߣ���ջ
c + ( d * e + f ) * g	- *	a b c
+ ( d * e + f ) * g	+	a b c * -	*- ���ȼ����ڵ���+��*-���γ�ջ��+��ջ
( d * e + f ) * g	+(	a b c * -	(ֱ����ջ
d * e + f ) * g	+(	a b c * - d
* e + f ) * g	+( *	a b c * - d	*��ջ
e + f ) * g	+( *	a b c * - d e
+ f ) * g	+(+	a b c * - d e *	+���ȼ�С��*��ջ��+��ջ
f ) * g	+(+	a b c * - d e * f
) * g	+	a b c * - d e * f +	+��ջ��ֱ������(
* g	+ *	a b c * - d e * f +
g	+ *	a b c * - d e * f + g
		a b c * - d e * f + g * +

���дһ��������׺���ʽת��Ϊ��׺���ʽ��
Ϊ�˼򻯲��������Ǽٶ���������Ϊ��λ������������ֻ�С�+������-������*�����͡�/�����֣����ŷ�ֻ�С�(���͡�)�����������룺һ���ɲ����������ŷ����������ɵ��ַ������Իس���ʾ���������迼�������Ƿ��ַ���
�����һ���ַ�����ֵΪ��׺���ʽ��
����1��
���룺3*(5+8)
�����358+*
����2��
���룺8/(5+2)-6
�����852+/6-
����3��
���룺(1+2)*3-7/(4+6/2)-1
����� 12+3*7462/+/1��
����4��
	���룺3+(5*6-7/1*7)*9
	�����356*71/7*-9*+
����5��
	���룺(1+2)*(3-7)/((4+6)/2-1)
	�����12+37-*46+2/1-/


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
