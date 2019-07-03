#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDNUM 10000//随机数的个数

int quick_sort(int a[],int left,int right) {
	int i, j, temp, t;
	if (left > right) {    //递归结束条件是left>right(递归的参数) 

	}
	else {
		i = left;
		j = right;
		temp = a[left];		//设置基准数为第一个数; 
		while (i != j) {		//大于基准数的数与小于基准数的数交换,大于小于分别从左右读取; i!=j而不是i<j,因为j可能到i的左边； 
			for (; i < j && a[j] >= temp; j--);					//注意得先找出右边的下标,(因为右边是找小的,考虑相遇的时,j找到第一个小于基准的,i找不到大于基准的,此时i和j指向相同,交换基准和这个小的..若i先走,则是找大于基准的,i找到第一个,j找不到,ij指向的同一个大于基准的,与基准交换则出错),别忘了添加i<j的条件，否则出错； 
																					//参考https://blog.csdn.net/zcpvn/article/details/78150692
			for (; i < j && a[i] <= temp; i++);					//循环找出每次大于/小于基准数的数的下标 ; 利用空的循环,跳出时得出下标; 

			if (i < j) { 			//通过下标进行左右交换 	//需要添加判断条件，因为j可能跑到左边去。
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		a[left] = a[i];			//将基准数与中点的某值(左右读到相遇的那个)进行交换; 
		a[i] = temp;
		quick_sort(a,  left, i - 1);		//排除已经排好的基准数,递归分左右继续执行上面过程; 
		quick_sort(a, i + 1, right);
	}
	return 0;
}
// 希尔排序对数据量大的时候效率特别高
//基本思路:分组->对每一组进行插入排序
//研究表明:希尔排序的增量为increasement=increasement/3+1的时候最高效
//从小到大进行希尔排序
void shell_sort(int* arr, int length) {
	int increasement = length;  //假设增量为数组长度
	int i, j, k;
	do {
		
		increasement = increasement / 3 + 1;   //确定分组增量
		for (i = 0; i < increasement; i++) {  //确定第一个增量范围内的元素与增量外的元素匹配
			for (j = i + increasement; j < length; j += increasement) { //j继承i的位置,找到第一个增量外的元素
				int temp = arr[j];  //保存增量分的组中要插入的元素
				if (arr[j] < arr[j - increasement]) {   //分组的元素通过增量来比较
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {  //通过增量来交换移位
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;   //移完了后吧插入的元素插入进去
				}
			}
		}
	} while (increasement > 1); //直到增量减到1时不再排序
}
int insert_sort(int iRandNum[]) {
	int tem, i, j;
	for (i = 0; i < RANDNUM - 1; i++) { //i前的数为有序
		tem = iRandNum[i + 1]; //i后的一个数为将要插入的数
		j = i;        //在有序的数中寻找要插入的点
		while (j > -1 && tem < iRandNum[i]) {    //寻找到下标不越界和中间tem大于某个数
			iRandNum[j + 1] = iRandNum[j];    //向后移动数组腾出空间
			j--;                              //j移动到中间tem大于的那个数
		}
		iRandNum[j + 1] = tem;    //插入到那个数后面
	}
	return 0;
}
int bubble_sort(int a[]) {
	//冒泡排序
	int i, j, k;
	for (i = 0; i < RANDNUM; i++) {
		for (j = 0; j < RANDNUM - i - 1; j++) {			//少1避免越界 
			if (a[j] > a[j + 1]) {
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
	}
	return 0;
}
int select_sort(int iRandNum[]) {
	int t, i, j,k;
	for (i = 0; i < RANDNUM; i++) {
		k = i;
		for (j = i; j < RANDNUM; j++) {
			if (iRandNum[j] < iRandNum[k]) {
				k = j;
			}
		}
		t = iRandNum[i];
		iRandNum[i] = iRandNum[k];
		iRandNum[k] = t;				//注意这里一定要是用iRandNum[i]进行操作 
							//i代表选择换的那个数，j是用来进行遍历寻找k的 
	}
	return 0;
}

int  main()
{
	int iRandNum[RANDNUM];//存放随机数
	clock_t first, second; //记录开始和结束时间（以毫秒为单位）
	printf("数据量:%d\n", RANDNUM);
	for (int i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}

	first = clock(); //开始时间;
	//此处加入排序算法程序

	bubble_sort(iRandNum);//冒泡排序

	second = clock();//结束时间
	double the_time;
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("冒泡排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");


	for (int i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //开始时间
	//此处加入排序算法程序

	select_sort(iRandNum);//选择排序

	second = clock();//结束时间
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("选择排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");

	for (int i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //开始时间
   //此处加入排序算法程序


	select_sort(iRandNum);//插入排序
	second = clock();//结束时间
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("插入排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");


	for (int i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //开始时间
   //此处加入排序算法程序


	quick_sort(iRandNum,0,RANDNUM-1);//快速排序
	second = clock();//结束时间
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("快速排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间
	/*for (int i = 0; i < RANDNUM; i++) {
		printf("%5d", iRandNum[i]);
	}
	printf("\n");*/
	printf("\nw完成!");
	return 0;
}
