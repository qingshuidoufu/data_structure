#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDNUM 10000 //随机数的个数

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
//冒泡排序
	int i, j, k;
	for (i = 0; i < RANDNUM; i++) {
		for (j = 0; j < RANDNUM - i - 1; j++) {			//少1避免越界 
			if (iRandNum[j] > iRandNum[j + 1]) {
				k = iRandNum[j];
				iRandNum[j] = iRandNum[j + 1];
				iRandNum[j + 1] = k;
			}
		}
	}

	second = clock();//结束时间
	double the_time;
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("冒泡排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间


	for (i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //开始时间
	//此处加入排序算法程序
//选择排序
	int t;
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

	second = clock();//结束时间
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("选择排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间

	for (i = 0; i < RANDNUM; i++)
	{//产生1万个随机数
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //开始时间
   //此处加入排序算法程序
//插入排序

	int tem;
	for (i = 0; i < RANDNUM - 1; i++) { //i前的数为有序
		tem = iRandNum[i + 1]; //i后的一个数为将要插入的数
		j = i;        //在有序的数中寻找要插入的点
		while (j > -1 && tem < iRandNum[i]) {    //寻找到下标不越界和中间tem大于某个数
			iRandNum[j + 1] = iRandNum[j];    //向后移动数组腾出空间
			j--;                              //j移动到中间tem大于的那个数
		}
		iRandNum[j + 1] = tem;    //插入到那个数后面
	}
	second = clock();//结束时间
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("插入排序使用的时间为:%lf秒\n", the_time);//显示排序算法所用的时间
	printf("\nw完成!");
	return 0;
}
