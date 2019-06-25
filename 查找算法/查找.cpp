#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElemType {
	int key;   //��������
	char b[5];  //���ַ���
}ElemType;
typedef struct node {
	ElemType data;        //��������
	struct node* lchild, * rchild; //���ҽڵ�

}binary_tree_node;

typedef binary_tree_node *bi_tree;    
//��̬���뽨������������
binary_tree_node* insert_bi_tree(binary_tree_node *root, ElemType x)          //����ֵΪһ���ڵ�
{
	binary_tree_node* current, * parent = NULL, * p;    //��¼��ǰ�ڵ�,˫�׽ڵ�,�Ͷ�̬����Ľڵ�
	current = root;									//��ǰ�ڵ���Ϊ���ڵ�
	while (current != NULL) {          //Ѱ��current��Ӧ�ڵ�λ��
		if (current->data.key == x.key)  //��Ȳ���Ҫ����
			return NULL;
		parent = current;     //�ҵ�˫�׽ڵ㱣������
		if (current->data.key < x.key) {    //������ұ��Ҵ��
			current = current->rchild;
		}
		else {
			current = current->lchild;   //���ұ���С��
		}
	}
	p = (binary_tree_node*)malloc(sizeof(binary_tree_node));  //��̬����p
	if (p == NULL) {
		printf("�ռ䲻��");
		exit(1);
	}
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (parent == NULL) {    //�������ĵ�һ�β���
		root = p;
	}
	else if (x.key < parent->data.key) {    //��parent�������
		parent->lchild = p;
	}
	else {
		parent->rchild = p;        //��parent���Ҳ���
	}
	return root;  //���ظ��ڵ�
}
//�������
void recursion_by_middle(binary_tree_node* root) {
	if (root == NULL) {
		return;
	}
	recursion_by_middle(root->lchild);
	printf("%s ", root->data.b);
	recursion_by_middle(root->rchild);
}
//�����㷨
int find_elem(binary_tree_node* root, ElemType x) {
	binary_tree_node* current;
	if (root != NULL) {
		current = root;
		while (current != NULL) {
			if (current->data.key==x.key) {
				return 1;  //���ҳɹ�
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
		tree=insert_bi_tree(tree, a[i]);   //ÿ�β��������
	}
	printf("�����ӡΪ:\n");
	recursion_by_middle(tree);  //�����ӡ
	printf("\n");
	ElemType tem = { 1,"Jan" };
	if (find_elem(tree, tem)==1) {
		printf("�ɹ��ҵ�Jan\n");
	}
	else {
		printf("�Ҳ���Jan\n");
	}
	tem = { 13,"xxx" };
	if (find_elem(tree, tem) == 1) {
		printf("�ɹ��ҵ�xxx\n");
	}
	else {
		printf("�Ҳ���xxx\n");
	}
	return 0;
}