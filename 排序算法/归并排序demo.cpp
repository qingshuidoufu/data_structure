//�ֶ�ģ��鲢����˼·:
//1.��������Ϊ����Ԫ��
//2.�ϲ��������������ڶ���Ŀռ�
//3.����Ŀռ�ϲ���ԭ�ռ���
//4.2->3һֱѭ����ȥֱ�������ź�
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>
using namespace std;
#define MAX 10
int* create_arry() {
	srand((unsigned int)time(NULL));
	int* arr = (int *)malloc(sizeof (int)*MAX);
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	return arr;
}
void print_arry(int *arr,int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�ϲ��㷨(��С����)
int merge(int arr[], int start, int end, int mid, int* temp) {
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	//��ʾ�����ռ��ж���Ԫ��
	int length = 0;
	//�ϲ�������������
	while (i_start <= i_end && j_start <= j_end) {
		if (arr[i_start] < arr[j_start]) {
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else {
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}
	}
	//����ʣ��һ��Ԫ��:i����
	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		i_start++;
		length++;

	}
	//����ʣ��һ��Ԫ��: j����
	while (j_start <= j_end) {
		temp[length] = arr[j_start];
 		j_start++;
		length++;
	}

	//�����ռ串�ǵ�ԭ�ռ�
	for (int i = 0; i < length;i++) {
		arr[start + i] = temp[i];//ԭ�ռ�start+i��ʼ,�������
	}
	return 0;
}


//�����漰���ݹ�
void merge_sort(int* arr, int start, int end, int* temp) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	//�ݹ����
	//����
	merge_sort(arr, start, mid, temp);
	//�Ұ��
	merge_sort(arr, mid + 1, end,temp);

	//�ϲ�
	merge(arr,start,end,mid,temp);
}
int main(){
	int* arr = create_arry();
	//�����ռ�
	int* temp = (int*)malloc(sizeof(int) * MAX);
	print_arry(arr, MAX);
	merge_sort(arr, 0, MAX - 1,temp);
	print_arry(arr, MAX);
	//�ͷſռ�
	free(temp);
	free(arr);
	return 0;
}