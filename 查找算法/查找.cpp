#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElemType {
	int key;   //数据类型
	char b[5];  //放字符串
}ElemType;
typedef struct node {
	ElemType data;        //数据类型
	struct node* lchild, * rchild; //左右节点

}binary_tree_node;

typedef binary_tree_node *bi_tree;    
//动态插入建立二叉排序树
binary_tree_node* insert_bi_tree(binary_tree_node *root, ElemType x)          //传出值为一个节点
{
	binary_tree_node* current, * parent = NULL, * p;    //记录当前节点,双亲节点,和动态分配的节点
	current = root;									//当前节点置为根节点
	while (current != NULL) {          //寻找current所应在的位置
		if (current->data.key == x.key)  //相等不需要插入
			return NULL;
		parent = current;     //找到双亲节点保存下来
		if (current->data.key < x.key) {    //左边往右边找大的
			current = current->rchild;
		}
		else {
			current = current->lchild;   //往右边找小的
		}
	}
	p = (binary_tree_node*)malloc(sizeof(binary_tree_node));  //动态分配p
	if (p == NULL) {
		printf("空间不足");
		exit(1);
	}
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (parent == NULL) {    //二叉树的第一次插入
		root = p;
	}
	else if (x.key < parent->data.key) {    //往parent的左插入
		parent->lchild = p;
	}
	else {
		parent->rchild = p;        //往parent的右插入
	}
	return root;  //返回根节点
}
//中序遍历
void recursion_by_middle(binary_tree_node* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_middle(root->lchild);
	printf("%s ", root->data.b);
	recursion_by_middle(root->rchild);
}
//查找算法
int find_elem(binary_tree_node* root, ElemType x) {
	binary_tree_node* current;
	if (root != NULL) {
		current = root;
		while (current != NULL) {
			if (current->data.key==x.key) {
				return 1;  //查找成功
			}
			if (x.key>current->data.key) {
				current = current->rchild;   
			}
			else {
				current = current->lchild;
			}
		}
	}
	return -1;
}
int main() {
	binary_tree_node* tree = NULL;
	ElemType a[12];
	a[0] = { 12,"Dec" };
	a[1] = {2,"Feb"};
	a[2] = {11,"Nov"};
	a[3] = {10,"Oct"};
	a[4] = { 6,"Jun" };
	a[5] = { 9,"Sept" };
	a[6] = { 8,"Aug" };
	a[7] = { 4,"Apr" };
	a[8] = { 5,"May" };
	a[9] = { 7,"July" };
	a[10] = { 1,"Jan" };
	a[11] = { 3,"Mar" };
	for (int i = 0; i < 12; i++) {
		tree=insert_bi_tree(tree, a[i]);   //每次插入更新树
	}
	printf("中序打印为:\n");
	recursion_by_middle(tree);  //中序打印
	printf("\n");
	ElemType tem = { 1,"Jan" };
	if (find_elem(tree, tem)==1) {
		printf("成功找到Jan\n");
	}
	else {
		printf("找不到Jan\n");
	}
	tem = { 13,"xxx" };
	if (find_elem(tree, tem) == 1) {
		printf("成功找到xxx\n");
	}
	else {
		printf("找不到xxx\n");
	}
	return 0;
}