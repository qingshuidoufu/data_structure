//题目5：
//【编程题】自编函数实现字符串连接（动态数组存取字符串）
//题目ID：1146
//【问题描述】cat(s1, s2)函数实现字符串的链接，参数s1是字符数组基地址，参数s2可以是字符数组名或字符串常量。cat()函数将字符串s2连接到字符串s1的后面，此时，s1中原有的结束符’\0’将被放置到连接后的结束位置。（请设计动态数组来存取字符串）。
//函数原型如void * cat(char* s, char* t)，注意返回的是一个字符指针。
//【输入形式】2行，第一行为字符串s1，第二行为字符串s2，s1和s2都以回车结束。
//【输出形式】1行，一个字符串，表示连接后的新字符串。
//【样例输入】
//【样例输出】
//
//【样例说明】输入二行，第一行是字符串S1”123 456”，第二行是字符串S2”1111111”
//输出一行，”123 456111111”
//【测试用例】
//1）
//输入：
//123456789
//qazwsxedc
//输出：
//123456789qazwsxedc
//2）
//输入：
//poiuy trewq 12345
//12345 ertdfg
//输出：
//poiuy trewq 1234512345 ertdfg
//
//3）
//输入：
//123
//234
//输出：
//123234
//
//4）
//输入：
//i am a boy!
//you are a girl!
//输出：
//i am a boy!you are a girl!
//
//5）
//输入：
//QWERTYYU RTYUI ~!@#$
//098776665
//输出：
//QWERTYYU RTYUI ~!@#$098776665

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void* cat(char* s, char* t)
{
	int len;
	len = strlen(s) + strlen(t);
	char* c;
	c = (char*)malloc(sizeof(char) * (len + 1));
	int i, j;
	for (i = 0; i < strlen(s); i++) {
		c[i] = s[i];
	}
	for (i = strlen(s), j = 0; i < len, j < strlen(t); i++, j++) {
		c[i] = t[j];
	}
	c[i] = '\0';
	return c;
}
void destroy(char* c)
{
	free(c);
}
int main()
{
	char a[100], b[100];
	fgets(a, 99, stdin);
	a[strlen(a) - 1] = '\0';
	fgets(b, 99, stdin);
	b[strlen(b) - 1] = '\0';
	int len;
	len = strlen(a) + strlen(b);
	char* c;
	c = (char*)cat(a, b);
	int i;
	for (i = 0; i < strlen(c); i++) {
		putchar(c[i]);
	}
	destroy(c);
	return 0;
}