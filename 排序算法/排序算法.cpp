#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDNUM 10000 //������ĸ���

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
//ð������
	int i, j, k;
	for (i = 0; i < RANDNUM; i++) {
		for (j = 0; j < RANDNUM - i - 1; j++) {			//��1����Խ�� 
			if (iRandNum[j] > iRandNum[j + 1]) {
				k = iRandNum[j];
				iRandNum[j] = iRandNum[j + 1];
				iRandNum[j + 1] = k;
			}
		}
	}

	second = clock();//����ʱ��
	double the_time;
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("ð������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��


	for (i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //��ʼʱ��
	//�˴����������㷨����
//ѡ������
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
		iRandNum[k] = t;				//ע������һ��Ҫ����iRandNum[i]���в��� 
							//i����ѡ�񻻵��Ǹ�����j���������б���Ѱ��k�� 
	}

	second = clock();//����ʱ��
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("ѡ������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��

	for (i = 0; i < RANDNUM; i++)
	{//����1��������
		iRandNum[i] = rand() % RANDNUM;
	}
	first = clock(); //��ʼʱ��
   //�˴����������㷨����
//��������

	int tem;
	for (i = 0; i < RANDNUM - 1; i++) { //iǰ����Ϊ����
		tem = iRandNum[i + 1]; //i���һ����Ϊ��Ҫ�������
		j = i;        //�����������Ѱ��Ҫ����ĵ�
		while (j > -1 && tem < iRandNum[i]) {    //Ѱ�ҵ��±겻Խ����м�tem����ĳ����
			iRandNum[j + 1] = iRandNum[j];    //����ƶ������ڳ��ռ�
			j--;                              //j�ƶ����м�tem���ڵ��Ǹ���
		}
		iRandNum[j + 1] = tem;    //���뵽�Ǹ�������
	}
	second = clock();//����ʱ��
	the_time = (double)(second - first) / CLOCKS_PER_SEC;
	printf("��������ʹ�õ�ʱ��Ϊ:%lf��\n", the_time);//��ʾ�����㷨���õ�ʱ��
	printf("\nw���!");
	return 0;
}
