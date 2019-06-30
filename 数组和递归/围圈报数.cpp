//【编程题】回文专题十三（围圈报数）//填空题
//题目ID：1145
//【问题描述】
//新生军训开始了，1班n位同学给自己班级战队取名为“1level1”，呵呵，他们的战队名是一个回文串。汇报表演开始了，n位同学围成一圈，并顺序编号为1~n。1班准备了7面旗帜，分别写上了1, l, e, v, e, l, 1。他们从第一个人开始报数（从1到m报数），凡报数为m的人恰好手上举着一个写着字母（数字）的旗帜并退出圈子。依次退出了7个人（1level1的长度为7），按照退出的先后顺序排成一排，旗帜上的字母依次正好组成了1level1。
//你是班长，肯定知道班级有多少人，现在知道汇演口令是从1到m报数，怎么去安排哪7人分别拿哪个旗帜？
//【输入形式】一行两数，用空格隔开，分别表示人数n和报数m
//【输出形式】若干行，每行两数，分别表示“第几人”和“旗帜上的字符”
//
//【测试用例】
//1）
//输入：
//67 3
//输出：
//3 1
//6 l
//9 e
//12 v
//15 e
//18 l
//21 1
//
//2）
//输入：
//67 5
//输出：
//5 1
//10 l
//15 e
//20 v
//25 e
//30 l
//35 1
//
//3）
//输入：
//13 4
//输出：
//1 l
//3 v
//4 1
//7 1
//8 l
//9 e
//12 e
//
//4）
//输入：
//33 2
//输出：
//2 1
//4 l
//6 e
//8 v
//10 e
//12 l
//14 1
//
//5）
//输入：
//7 1
//输出：
//1 1
//2 l
//3 e
//4 v
//5 e
//6 l
//7 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct person {
	int number;
	char ch;
};
int main() {
	char str[20] = "1level1";
	struct person persons[100];
	int i, n, m, count = 0, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		persons[i].number = i + 1;
		persons[i].ch = '*';
	}
	i = 0;//i为每次循环的计数变量
	k = 0;//k为1，2，3...计数的变量；
	count = 0;//退出者的计数变量 
	while (count < strlen(str)) {
		if (persons[i].ch == '*')k++;;//此位置之人没有退出
		if (k == m) {//报数为m的人做以下处理

			persons[i].ch = str[count];
			k = 0;
			count++;

		}
		i++;
		if (i == n)i = 0;
	}

	for (i = 0; i < n; i++) {
		if (persons[i].ch != '*')
			printf("%d %c \n", persons[i].number, persons[i].ch);
	}
	return 0;
}