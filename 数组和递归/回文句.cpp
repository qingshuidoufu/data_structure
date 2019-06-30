//VS中无法运行,vscode中可运行,因为gets在vs中已经被安全的函数替换了!!!!!!!!!!!
//题目ID：1141
//【问题描述】
//经典的回文以字母为单位的，也可以以词为单位来形成回文。
//（1）       You can cage a swallow, can’t you, but you can’t swallow a cage, can you ?
//你能把一致燕子关进笼子，不是吗？但是你却不能吞下一个笼子，你能吗？
//（2）       Girl bathing on bikini, eyeing boy, finds boy eyeing bikini on bathing girl.
//穿比基尼泳装洗澡的姑娘看小伙子，发现小伙子正在看洗澡的姑娘穿的比基尼。
//输入一行字符，判断是否为回文句。
//【输入形式】一行字符串，以回车结束
//【输出形式】YES或者NO，分别代表是回文句或不是回文句
//1）
//输入：
//girl bathing on bikini, eyeing boy, finds boy eyeing bikini on bathing girl.
//输出：
//YES
//2）
//输入：
//I am a a am I
//输出：
//YES
//
//3）
//输入：
//123 456 789 456 123
//输出：
//YES
//
//4）
//输入：
//qaz wsx wsx edc
//输出：
//NO
//
//5）
//输入：
//qaz wsx edc
//输出：
//NO

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int is_huiwen_setence(char** word, int n) {
	int i;
	for (i = 0; i < n / 2; i++)
		if (strcmp(word[i], word[n-- - 1]) != 0)//单词不相等 
			return 0;
	return 1;
}
int main() {
	char str[80], tmp[80];
	char* word[20];
	int current = 0, i, n;
	int is_start, is_end;
	gets(str);
	i = 0;
	n = 0;//指针数组的初始下标 
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9' || str[i] == '\'') {
			tmp[current++] = str[i];
		}
		else {//遇到分割符 
			if (current != 0) { //单词结束未处理 
				tmp[current] = '\0';
				word[n] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
				strcpy(word[n], tmp);
				current = 0;
				n++;

			}
		}
		i++;
	}
	if (current != 0) {//最后一个单词后面可能没有分隔符  
		tmp[current] = '\0';
		current = 0;
		word[n] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(word[n], tmp);
		n++;
	}
	if (is_huiwen_setence(word, n))
		printf("YES");
	else
		printf("NO");
	return 0;
}

