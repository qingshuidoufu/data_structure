//题目12：
//【编程题】幂运算三（递归函数）
//题目ID：1137
//【问题描述】    求x^ n。
//【输入形式】一行2个数，第一个整数表示x，第二个大于等于零的整数表示n，二数之间用空格分隔。
//【输出形式】一行一个整数，表示x的n次方
//【样例输入】2 3
//【样例输出】8

//普通递归
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long my_pow1(long x, int n) {
	if (n == 0) return 1;      //递归出口
	return x * (my_pow1(x, --n));  //除了调用自身外还乘多了个x,即一般的递归
}
int main() {
	long  x;
	int  n;
	scanf("%ld%d", &x, &n);
	printf("%ld\n", my_pow1(x, n));
	return 0;
}