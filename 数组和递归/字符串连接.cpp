//��Ŀ5��
//������⡿�Աຯ��ʵ���ַ������ӣ���̬�����ȡ�ַ�����
//��ĿID��1146
//������������cat(s1, s2)����ʵ���ַ��������ӣ�����s1���ַ��������ַ������s2�������ַ����������ַ���������cat()�������ַ���s2���ӵ��ַ���s1�ĺ��棬��ʱ��s1��ԭ�еĽ�������\0���������õ����Ӻ�Ľ���λ�á�������ƶ�̬��������ȡ�ַ�������
//����ԭ����void * cat(char* s, char* t)��ע�ⷵ�ص���һ���ַ�ָ�롣
//��������ʽ��2�У���һ��Ϊ�ַ���s1���ڶ���Ϊ�ַ���s2��s1��s2���Իس�������
//�������ʽ��1�У�һ���ַ�������ʾ���Ӻ�����ַ�����
//���������롿
//�����������
//
//������˵����������У���һ�����ַ���S1��123 456�����ڶ������ַ���S2��1111111��
//���һ�У���123 456111111��
//������������
//1��
//���룺
//123456789
//qazwsxedc
//�����
//123456789qazwsxedc
//2��
//���룺
//poiuy trewq 12345
//12345 ertdfg
//�����
//poiuy trewq 1234512345 ertdfg
//
//3��
//���룺
//123
//234
//�����
//123234
//
//4��
//���룺
//i am a boy!
//you are a girl!
//�����
//i am a boy!you are a girl!
//
//5��
//���룺
//QWERTYYU RTYUI ~!@#$
//098776665
//�����
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