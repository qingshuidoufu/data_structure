//大根堆手动模拟思路:
//1.数组按照完全二叉树形式写下
//2.找到最后一个非叶子节点,进行交换调整最大的在上面,往上面循环(换后子树可能出现非大根堆要对子树往下调整)直到根节点
//3.最大的数在根节点,把根节点和尾节点交换(排除掉已经排好的尾节点)
//4.根节点开始,继续往下调整大根堆(仍要考虑子树换后不是大根堆),直到排除好的尾节点前一个节点
//5.循环3-4步



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
//@param arr[] 待调整的数组
//@param index 待调整的节点的下标
//@param len 数组长度
void heap_adjust(int arr[],int  index,int len) {
	//先保存当前节点的下标
	int max = index; 
	//数组从0开始,堆从1开始,故要加1,(不理解的话画出完全二叉树就知道了)下面同理;
	//保存左右孩子的数组下标
	int lchild = index * 2 + 1;  
	int rchild = index * 2 + 2;
	if (lchild<len && arr[lchild]>arr[max]) {
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max]) {
		max = rchild;
	}
	if (max != index) {  //大的节点交换,这里也用来判断递归出口(max不变了)
		swap(arr, max, index);
		heap_adjust(arr, max, len);//交换之后max位置可能不再满足大顶堆,故调用递归给子树继续调整
	}
}



//1,初始化堆,大顶堆,从小到大,

void heap_sort(int arr[], int len) {
	//从最后一个非叶子节点开始,数组从0开始故要-1;
	//从下面往上初始化堆
  	for (int i = len / 2 - 1; i >= 0; i--) { //从后(len/2-1位置往前)
		heap_adjust(arr, i, len);//初始化堆(调整)
	}
	//交换堆顶元素和最后一个元素
	for (int i = len  - 1; i >= 0; i--) {  //同时也再次调整(从堆顶往下开始)
		swap(arr, 0, i);
		//又重头开始调整堆(头和尾换了后头不再满足最大堆)
		heap_adjust(arr, 0, i);  //是i不是len是因为要排除最后面的交换好了的
	}
	
	
}
int main(void) {
	int my_arr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(my_arr )/ sizeof(int);
	heap_sort(my_arr, len);
	 print_arry(my_arr, len);
	//堆排序
	
	return 0;
}