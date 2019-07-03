//分组->对每一组进行插入排序
//经过科学研究,每次让increasement/3+1向下递减则可以达到高效率
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

//从小到大进行希尔排序
void shell_sort(int *arr,int length) {
	int increasement = length;  
	int i, j,k;
	do {
		//确定分组增量
		increasement = increasement / 3 + 1;
		for ( i = 0; i < increasement; i++) {
			for (j = i + increasement; j < length; j += increasement) {
				int temp = arr[j];
				if (arr[j] < arr[j - increasement]) {
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}
int  main(void) {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10;
	}
	shell_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}