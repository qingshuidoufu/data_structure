#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary_tree.h"


int main() {
	printf("����ǰ������:");
	//����������
	binary_tree* root;
	root = create_tree();
	//�������
	printf("�������:");
	recursion_by_first(root);
	printf("\n");
	//�������
	printf("�������:");
	recursion_by_middle(root);
	printf("\n");
	//�������
	printf("�������:");
	recursion_by_last(root);
	printf("\n");

	//����Ԫ��
	int is_the_num = 0;
	char ele;
	getc(stdin);
	printf("Ҫ���ҵ�Ԫ����: ");
	ele = getc(stdin);
	find_elem(root, ele, &is_the_num);
	if (is_the_num) {
		printf("�Ƿ���ҵ�Ԫ��%c: ��\n");
	}
	else {
		printf("�Ƿ���ҵ�Ԫ��%c: ��\n");
	}

	getc(stdin);
	is_the_num = 0;
	printf("Ҫ���ҵ�Ԫ����: ");
	ele = getc(stdin);
	find_elem(root, ele, &is_the_num);
	if (is_the_num) {
		printf("�Ƿ���ҵ�Ԫ��%c: ��\n");
	}
	else {
		printf("�Ƿ���ҵ�Ԫ��%c: ��\n");
	}

	//ͳ��Ҷ�ӽڵ��������ӡ
	int leaf_count;
	leaf_count = 0;
	printf("Ҷ�ӽڵ�Ϊ:");
	leaf_summing_and_print(root, &leaf_count);
	printf("\nҶ�ӽڵ����Ϊ:%d\n", leaf_count);


	//�������ķǵݹ��ӡ
	printf("�ǵݹ��������:");
	non_recursion_by_first(root);
	printf("\n");
	printf("�ǵݹ��������:");
	non_recursion_by_middle(root);
	printf("\n");
	printf("�ǵݹ�������:");
	non_recursion_by_last(root);
	printf("\n");
	system("pause");
	return 0;

}
