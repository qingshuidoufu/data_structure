#pragma once
#define _CRT_SECURE_NO_WARNINGS
//将0和1用文字表示
#define MY_FALSE 0

#define MY_TRUE 1
;
#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"			//链栈头文
//二叉树节点结构
typedef struct binary_tree {
	char x;
	struct binary_tree* lchild;
	struct binary_tree* rchild;
}binary_tree;



//用递归创建二叉树
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
//先序遍历
void recursion_by_first(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->x);
	recursion_by_first(root->lchild);
	recursion_by_first(root->rchild);
}
//中序遍历
void recursion_by_middle(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_middle(root->lchild);
	printf("%c ", root->x);
	recursion_by_middle(root->rchild);
}
//后序遍历
void recursion_by_last(binary_tree* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_last(root->lchild);
	recursion_by_last(root->rchild);
	printf("%c ", root->x);
}
//查找元素

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



//统计叶子节点个数并打印
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
//栈中放的二叉树结点包装起来
typedef struct BITREESTACKNODE {
	binary_tree* root;  //当前二叉树根节点
	int flag;			//状态
}BiTreeStackNode;

//创建栈中的节点
BiTreeStackNode* CreateBiTreeStackNode(binary_tree* node, int flag) {
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}

//非递归先序遍历
void non_recursion_by_first(binary_tree* root) {
	//创建栈
	my_stack* stack = init();
	//根节点放进去栈
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//判断弹出的节点是否为空
		if (node->root == NULL) {
			continue;
		}
		//判断节点的标志
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//右节点入栈
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//左节点入栈
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
			//当前节点入栈
			node->flag = MY_TRUE;
			push(stack, node);
		}
	}
}
//非递归中序遍历
void non_recursion_by_middle(binary_tree* root) {
	//创建栈
	my_stack* stack = init();
	//根节点放进去栈
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//判断弹出的节点是否为空
		if (node->root == NULL) {
			continue;
		}
		//判断节点的标志
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//右节点入栈
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//当前节点入栈
			node->flag = MY_TRUE;
			push(stack, node);
			//左节点入栈
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
		}
	}
}
//非递归后序遍历
void non_recursion_by_last(binary_tree* root) {
	//创建栈
	my_stack* stack = init();
	//根节点放进去栈
	BiTreeStackNode* rootnode = (BiTreeStackNode*)CreateBiTreeStackNode(root, MY_FALSE);
	push(stack, rootnode);

	while (!is_empty(stack)) {
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)get_top_(stack);
		pop(stack);
		//判断弹出的节点是否为空
		if (node->root == NULL) {
			continue;
		}
		//判断节点的标志
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->x);
		}
		else {
			//当前节点入栈
			node->flag = MY_TRUE;
			push(stack, node);
			//右节点入栈
			BiTreeStackNode* rnode = CreateBiTreeStackNode(node->root->rchild, MY_FALSE);
			push(stack, rnode);
			//左节点入栈
			BiTreeStackNode* lnode = CreateBiTreeStackNode(node->root->lchild, MY_FALSE);
			push(stack, lnode);
		}
	}
}
