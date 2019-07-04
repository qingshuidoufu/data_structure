//手动模拟归并排序思路:
//1.拆分数组成为单个元素
//2.合并成有序的数组放在额外的空间
//3.额外的空间合并到原空间里
//4.2->3一直循环下去直到所有排好
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

//合并算法(从小到大)
int merge(int arr[], int start, int end, int mid, int* temp) {
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	//表示辅助空间有多少元素
	int length = 0;
	//合并两个有序序列
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
	//序列剩下一个元素:i序列
	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		i_start++;
		length++;

	}
	//序列剩下一个元素: j序列
	while (j_start <= j_end) {
		temp[length] = arr[j_start];
 		j_start++;
		length++;
	}

	//辅助空间覆盖到原空间
	for (int i = 0; i < length;i++) {
		arr[start + i] = temp[i];//原空间start+i开始,否则会乱
	}
	return 0;
}


//分组涉及到递归
void merge_sort(int* arr, int start, int end, int* temp) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	//递归分组
	//左半边
	merge_sort(arr, start, mid, temp);
	//右半边
	merge_sort(arr, mid + 1, end,temp);

	//合并
	merge(arr,start,end,mid,temp);
}
int main(){
	int* arr = create_arry();
	//辅助空间
	int* temp = (int*)malloc(sizeof(int) * MAX);
	print_arry(arr, MAX);
	merge_sort(arr, 0, MAX - 1,temp);
	print_arry(arr, MAX);
	//释放空间
	free(temp);
	free(arr);
	return 0;
}