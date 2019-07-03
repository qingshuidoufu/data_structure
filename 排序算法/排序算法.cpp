#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDNUM 10000//������ĸ���

int quick_sort(int a[],int left,int right) {
	int i, j, temp, t;
	if (left > right) {    //�ݹ����������left>right(�ݹ�Ĳ���) 

	}
	else {
		i = left;
		j = right;
		temp = a[left];		//���û�׼��Ϊ��һ����; 
		while (i != j) {		//���ڻ�׼��������С�ڻ�׼����������,����С�ڷֱ�����Ҷ�ȡ; i!=j������i<j,��Ϊj���ܵ�i����ߣ� 
			for (; i < j && a[j] >= temp; j--);					//ע������ҳ��ұߵ��±�,(��Ϊ�ұ�����С��,����������ʱ,j�ҵ���һ��С�ڻ�׼��,i�Ҳ������ڻ�׼��,��ʱi��jָ����ͬ,������׼�����С��..��i����,�����Ҵ��ڻ�׼��,i�ҵ���һ��,j�Ҳ���,ijָ���ͬһ�����ڻ�׼��,���׼���������),���������i<j��������������� 
																					//�ο�https://blog.csdn.net/zcpvn/article/details/78150692
			for (; i < j && a[i] <= temp; i++);					//ѭ���ҳ�ÿ�δ���/С�ڻ�׼���������±� ; ���ÿյ�ѭ��,����ʱ�ó��±�; 

			if (i < j) { 			//ͨ���±�������ҽ��� 	//��Ҫ����ж���������Ϊj�����ܵ����ȥ��
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		a[left] = a[i];			//����׼�����е��ĳֵ(���Ҷ����������Ǹ�)���н���; 
		a[i] = temp;
		quick_sort(a,  left, i - 1);		//�ų��Ѿ��źõĻ�׼��,�ݹ�����Ҽ���ִ���������; 
		quick_sort(a, i + 1, right);
	}
	return 0;
}
// ϣ����������������ʱ��Ч���ر��
//����˼·:����->��ÿһ����в�������
//�о�����:ϣ�����������Ϊincreasement=increasement/3+1��ʱ�����Ч
//��С�������ϣ������
void shell_sort(int* arr, int length) {
	int increasement = length;  //��������Ϊ���鳤��
	int i, j, k;
	do {
		
		increasement = increasement / 3 + 1;   //ȷ����������
		for (i = 0; i < increasement; i++) {  //ȷ����һ��������Χ�ڵ�Ԫ�����������Ԫ��ƥ��
			for (j = i + increasement; j < length; j += increasement) { //j�̳�i��λ��,�ҵ���һ���������Ԫ��
				int temp = arr[j];  //���������ֵ�����Ҫ�����Ԫ��
				if (arr[j] < arr[j - increasement]) {   //�����Ԫ��ͨ���������Ƚ�
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {  //ͨ��������������λ
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;   //�����˺�ɲ����Ԫ�ز����ȥ
				}
			}
		}
	} while (increasement > 1); //ֱ����������1ʱ��������
}
int insert_sort(int iRandNum[]) {
	int tem, i, j;
	for (i = 0; i < RANDNUM - 1; i++) { //iǰ����Ϊ����
		tem = iRandNum[i + 1]; //i���һ����Ϊ��Ҫ�������
		j = i;        //�����������Ѱ��Ҫ����ĵ�
		while (j > -1 && tem < iRandNum[i]) {    //Ѱ�ҵ��±겻Խ����м�tem����ĳ����
			iRandNum[j + 1] = iRandNum[j];    //����ƶ������ڳ��ռ�
			j--;                              //j�ƶ����м�tem���ڵ��Ǹ���
		}
		iRandNum[j + 1] = tem;    //���뵽�Ǹ�������
	}
	return 0;
}
int bubble_sort(int a[]) {
	//ð������
	int i, j, k;
	for (i = 0; i < RANDNUM; i++) {
		for (j = 0; j < RANDNUM - i - 1; j++) {			//��1����Խ�� 
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
		iRandNum[k] = t;				//ע������һ��Ҫ����iRandNum[i]���в��� 
							//i����ѡ�񻻵��Ǹ�����j���������б���Ѱ��k�� 
	}
	return 0;
}

int  main()
{
	int iRandNum[RANDNUM];//��������
	clock_t first, second; //��¼��ʼ�ͽ���ʱ�䣨�Ժ���Ϊ��λ��
	printf("������:%d\n", RANDNUM);
	for (int i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}

	first = clock(); //��ʼʱ��;
	//�˴����������㷨����

	bubble_sort(iRandNum);//ð������

	second = clock();//����ʱ��
	double the_time;
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("ð������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");


	for (int i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //��ʼʱ��
	//�˴����������㷨����

	select_sort(iRandNum);//ѡ������

	second = clock();//����ʱ��
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("ѡ������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");

	for (int i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //��ʼʱ��
   //�˴����������㷨����


	select_sort(iRandNum);//��������
	second = clock();//����ʱ��
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("��������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��
	//for (int i = 0; i < RANDNUM; i++) {
	//	printf("%5d", iRandNum[i]);
	//}
	//printf("\n");


	for (int i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //��ʼʱ��
   //�˴����������㷨����


	quick_sort(iRandNum,0,RANDNUM-1);//��������
	second = clock();//����ʱ��
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("��������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��
	/*for (int i = 0; i < RANDNUM; i++) {
		printf("%5d", iRandNum[i]);
	}
	printf("\n");*/
	printf("\nw���!");
	return 0;
}
