//VS���޷�����,vscode�п�����,��Ϊgets��vs���Ѿ�����ȫ�ĺ����滻��!!!!!!!!!!!
//��ĿID��1141
//������������
//����Ļ�������ĸΪ��λ�ģ�Ҳ�����Դ�Ϊ��λ���γɻ��ġ�
//��1��       You can cage a swallow, can��t you, but you can��t swallow a cage, can you ?
//���ܰ�һ�����ӹؽ����ӣ������𣿵�����ȴ��������һ�����ӣ�������
//��2��       Girl bathing on bikini, eyeing boy, finds boy eyeing bikini on bathing girl.
//���Ȼ���Ӿװϴ��Ĺ��￴С���ӣ�����С�������ڿ�ϴ��Ĺ��ﴩ�ıȻ��ᡣ
//����һ���ַ����ж��Ƿ�Ϊ���ľ䡣
//��������ʽ��һ���ַ������Իس�����
//�������ʽ��YES����NO���ֱ�����ǻ��ľ���ǻ��ľ�
//1��
//���룺
//girl bathing on bikini, eyeing boy, finds boy eyeing bikini on bathing girl.
//�����
//YES
//2��
//���룺
//I am a a am I
//�����
//YES
//
//3��
//���룺
//123 456 789 456 123
//�����
//YES
//
//4��
//���룺
//qaz wsx wsx edc
//�����
//NO
//
//5��
//���룺
//qaz wsx edc
//�����
//NO

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int is_huiwen_setence(char** word, int n) {
	int i;
	for (i = 0; i < n / 2; i++)
		if (strcmp(word[i], word[n-- - 1]) != 0)//���ʲ���� 
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
	n = 0;//ָ������ĳ�ʼ�±� 
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9' || str[i] == '\'') {
			tmp[current++] = str[i];
		}
		else {//�����ָ�� 
			if (current != 0) { //���ʽ���δ���� 
				tmp[current] = '\0';
				word[n] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
				strcpy(word[n], tmp);
				current = 0;
				n++;

			}
		}
		i++;
	}
	if (current != 0) {//���һ�����ʺ������û�зָ���  
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

