//��Ŀ12��
//������⡿�����������ݹ麯����
//��ĿID��1137
//������������    ��x^ n��
//��������ʽ��һ��2��������һ��������ʾx���ڶ������ڵ������������ʾn������֮���ÿո�ָ���
//�������ʽ��һ��һ����������ʾx��n�η�
//���������롿2 3
//�����������8

//��ͨ�ݹ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long my_pow1(long x, int n) {
	if (n == 0) return 1;      //�ݹ����
	return x * (my_pow1(x, --n));  //���˵��������⻹�˶��˸�x,��һ��ĵݹ�
}
int main() {
	long  x;
	int  n;
	scanf("%ld%d", &x, &n);
	printf("%ld\n", my_pow1(x, n));
	return 0;
}