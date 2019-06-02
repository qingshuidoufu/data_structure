#pragma once
#define _CRT_SECURE_NO_WARNINGS
//��0��1�����ֱ�ʾ
#define MY_FALSE 0

#define MY_TRUE 1
;
#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"			//��ջͷ��
//�������ڵ�ṹ
typedef struct binary_tree {
	char x;
	struct binary_tree* lchild;
	struct binary_tree* rchild;
}binary_tree;



//�õݹ鴴��������
binary_tree* create_tree() {
	char ch;
	fflush(stdin);
	scanf("%c", &ch);
	binary_tree* root;
	if (ch == '#') {
		root = NULL;
	}
	else {
		root = (binary_tree*)malloc(sizeof(binary_tree));
		root->x = ch;
		root->lchild = create_tree();
		root->rchild = create_tree();
	}
	return root;

}
//�������
void recursion_by_first(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->x);
	recursion_by_first(root->lchild);
	recursion_by_first(root->rchild);
}
//�������
void recursion_by_middle(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_middle(root->lchild);
	printf("%c ", root->x);
	recursion_by_middle(root->rchild);
}
//�������
void recursion_by_last(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_last(root->lchild);
	recursion_by_last(root->rchild);
	printf("%c ", root->x);
}
//����Ԫ��

void find_elem(binary_tree* root, char ele, int* i) {
	if (root == NULL) {
		return;
	}
	if (root->x == ele) {
		;
		*i = 1;

	}
	else {
		find_elem(root->lchild, ele, i);
		find_elem(root->rchild, ele, i);
	}
}



//ͳ��Ҷ�ӽڵ��������ӡ
void leaf_summing_and_print(binary_tree* root, int* leaf_count) {
	if (root == NULL) {
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		(*leaf_count) = (*leaf_count) + 1;
		printf("%c", root->x);
	}
	else {
		leaf_summing_and_print(root->lchild, leaf_count);
		leaf_summing_and_print(root->rchild, leaf_count);
	}
	return;
}
//ջ�зŵĶ���������װ����
typedef struct BITREESTACKNODE {
	binary_tree* root;  //��ǰ���������ڵ�
	int flag;			//״̬
}BiTreeStackNode;

//����ջ�еĽڵ�
BiTreeStackNode* CreateBiTreeStackNode(binary_tree* node, int flag) {
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}

//�ǵݹ��������
void non_recursion_by_first(binary_tree* root) {
	//����ջ
	my_stack* stack = init();
	//���ڵ�Ž�ȥջ
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node->root == NULL) {
			continue;
		}
		//�жϽڵ�ı�־
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//�ҽڵ���ջ
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//��ڵ���ջ
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
			//��ǰ�ڵ���ջ
			node->flag = MY_TRUE;
			push(stack, node);
		}
	}
}
//�ǵݹ��������
void non_recursion_by_middle(binary_tree* root) {
	//����ջ
	my_stack* stack = init();
	//���ڵ�Ž�ȥջ
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node->root == NULL) {
			continue;
		}
		//�жϽڵ�ı�־
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//�ҽڵ���ջ
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//��ǰ�ڵ���ջ
			node->flag = MY_TRUE;
			push(stack, node);
			//��ڵ���ջ
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
		}
	}
}
//�ǵݹ�������
void non_recursion_by_last(binary_tree* root) {
	//����ջ
	my_stack* stack = init();
	//���ڵ�Ž�ȥջ
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node->root == NULL) {
			continue;
		}
		//�жϽڵ�ı�־
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//��ǰ�ڵ���ջ
			node->flag = MY_TRUE;
			push(stack, node);
			//�ҽڵ���ջ
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//��ڵ���ջ
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
		}
	}
}
