
//题目1：
//【编程题】字符串逆序保存
//题目ID：1147
//【问题描述】
//字符串逆序保存，例如原字符串数组s1的内容为abcdefg，将其逆序后仍然保存在字符串数组s1中，内容为gfedcba。s1中原有的结束符’\0’不变化。
//请定义并调用一个递归函数（请注意，是递归函数！！！），原型如：char * reverse(可以定义多个参数)，请注意函数返回的是一个字符指针。
//【输入形式】1行，表示字符串s1，以回车结束。
//【输出形式】1行，一个字符串，表示逆序后的新字符串
//
//【样例说明】输入字符串为” 123”，输出逆序后的字符串为” 321”
//【测试用例】
//1）
//输入：
//1234567890
//输出：
//0987654321
//2）
//输入：
//abced fghij
//输出：
//jihgf decba
//3）
//输入：
//5level5
//输出：
//5level5
//4）
//输入：
//~!@#$ % ^&*()_ +
//输出：
//+ _)(*&^%$#@!~
//5）
//输入：
//qwerty 123456
//输出：
//654321 ytrewq
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
char* reverse(char s[100], int i, int len) {
	if (i >= len) {
		return 0;
	}
	else {
		char t;
		t = s[i];
		s[i] = s[len];
		s[len] = t;
		reverse(s, i + 1, len - 1);   //左右向中间移动
	}
}
int main()
{
	int i = 0;
	int len = 0;
	char s1[100];
	fgets(s1, 100, stdin);
	len = strlen(s1);
	s1[len - 1] = '\0';      //回车改为'\0'
	len = strlen(s1);      //重测s1长度
	reverse(s1, i, len - 1);        //递归调用
	for (i = 0; i < len; i++) {        //输出
		printf("%c", s1[i]);
	}
	return 0;
}