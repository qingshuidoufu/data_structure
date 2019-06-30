/* 题目13：
【程序片段题】幂运算四（快速幂，递归函数）
题目ID：1138
【问题描述】    求x^n。
【输入形式】一行2个数，一个整数一个大于等于零的整数，用空格进行分割
【输出形式】一行1个整数
【样例输入】2 3
【样例输出】8

【样例说明】2的3次方结果为8
【评分标准】5组测试用例，每组2分，共计10分
【程序片段】 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long my_pow2(long x, int n) {
	if (n <= 0) return 1;
	if (n % 2 == 0)
		return my_pow2(x * x, n / 2);//x^n = (x*x)^(n/2)  
	else
		return x * my_pow2(x * x, n / 2);//奇数时
}
int main() {
	long  x;
	int  n;
	scanf("%ld%d", &x, &n);
	printf("%ld\n", my_pow2(x, n));
	return 0;
}
/* 【测试用例】
1）
输入：
2 3
输出：
8
2）
输入：
-5 0
输出：
1

3）
输入：
-3 3
输出：
27

4）
输入：
-55 3
输出：
-166375

5）
输入：
233 3
输出：
12649337
 */