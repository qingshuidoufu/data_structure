//����->��ÿһ����в�������
//������ѧ�о�,ÿ����increasement/3+1���µݼ�����Դﵽ��Ч��
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

//��С�������ϣ������
void shell_sort(int *arr,int length) {
	int increasement = length;  
	int i, j,k;
	do {
		//ȷ����������
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