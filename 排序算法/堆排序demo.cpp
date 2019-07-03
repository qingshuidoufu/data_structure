#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void print_arry(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}
void swap(int arr[], int max, int index) {
	int temp = arr[max];
	arr[max] = arr[index];
	arr[index] = temp;
}
//@param arr[] ������������
//@param index �������Ľڵ���±�
//@param len ���鳤��
void heap_adjust(int arr[],int  index,int len) {
	//�ȱ��浱ǰ�ڵ���±�
	int max = index; 
	//�����0��ʼ,�Ѵ�1��ʼ,��Ҫ��1,(�����Ļ�������ȫ��������֪����)����ͬ��;
	//�������Һ��ӵ������±�
	int lchild = index * 2 + 1;  
	int rchild = index * 2 + 2;
	if (lchild<len && arr[lchild]>arr[max]) {
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max]) {
		max = rchild;
	}
	if (max != index) {  //��Ľڵ㽻��,����Ҳ�����жϵݹ����(max������)
		swap(arr, max, index);
		heap_adjust(arr, max, len);//����֮��maxλ�ÿ��ܲ�������󶥶�,�ʵ��õݹ��������������
	}
}



//1,��ʼ����,�󶥶�,��С����,
//


void heap_sort(int arr[], int len) {
	//�����һ����Ҷ�ӽڵ㿪ʼ,�����0��ʼ��Ҫ-1;
	//���������ϳ�ʼ����
  	for (int i = len / 2 - 1; i >= 0; i--) {
		heap_adjust(arr, i, len);
	}
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	for (int i = len  - 1; i >= 0; i--) {
		swap(arr, 0, i);
		//����ͷ��ʼ������(ͷ��β���˺�ͷ������������)
		heap_adjust(arr, 0, i);  //��i����len����ΪҪ�ų������Ľ������˵�
	}
	
	
}
int main(void) {
	int my_arr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(my_arr )/ sizeof(int);
	heap_sort(my_arr, len);
	 print_arry(my_arr, len);
	//������
	
	return 0;
}