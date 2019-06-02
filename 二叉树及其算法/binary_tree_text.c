#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary_tree.h"


int main() {
	printf("输入前序序列:");
	//创建二叉树
	binary_tree* root;
	root = create_tree();
	//先序遍历
	printf("先序遍历:");
	recursion_by_first(root);
	printf("\n");
	//中序遍历
	printf("中序遍历:");
	recursion_by_middle(root);
	printf("\n");
	//后序遍历
	printf("后序遍历:");
	recursion_by_last(root);
	printf("\n");

	//查找元素
	int is_the_num = 0;
	char ele;
	getc(stdin);
	printf("要查找的元素是: ");
	ele = getc(stdin);
	find_elem(root, ele, &is_the_num);
	if (is_the_num) {
		printf("是否查找到元素%c: 是\n");
	}
	else {
		printf("是否查找到元素%c: 否\n");
	}

	getc(stdin);
	is_the_num = 0;
	printf("要查找的元素是: ");
	ele = getc(stdin);
	find_elem(root, ele, &is_the_num);
	if (is_the_num) {
		printf("是否查找到元素%c: 是\n");
	}
	else {
		printf("是否查找到元素%c: 否\n");
	}

	//统计叶子节点个数并打印
	int leaf_count;
	leaf_count = 0;
	printf("叶子节点为:");
	leaf_summing_and_print(root, &leaf_count);
	printf("\n叶子节点个数为:%d\n", leaf_count);


	//二叉树的非递归打印
	printf("非递归先序遍历:");
	non_recursion_by_first(root);
	printf("\n");
	printf("非递归中序遍历:");
	non_recursion_by_middle(root);
	printf("\n");
	printf("非递归后序遍历:");
	non_recursion_by_last(root);
	printf("\n");
	system("pause");
	return 0;

}
