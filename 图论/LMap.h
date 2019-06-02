#pragma once
#pragma once
//Ϊ�˲�������,�ڽӱ�Ĵ�Ŷ���������0λ�ò�ʹ��
#define ElemType char
#define MaxVertices 100
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct Node {   //�߽ṹ��
	int adjvex; //�ڽӱ�ļ�ͷ�������
	struct Node* next;  //���������һ���ڵ�ָ��
}Edge;

typedef struct {  //����ṹ��
	ElemType data;  //��������Ԫ��
	int source;		//�������
	Edge* adj;		//�ڽӱߵļ�ͷָ��
}AdjLHeight;

typedef struct {   //ͼ�ṹ��
	AdjLHeight a[MaxVertices]; //�ڽӱ�����
	int numOfVerts;			//�������
	int numOfEdges;		//�߸���
}ListGraph;

//��ʼ��ͼ
void AdjInitiate(ListGraph* G) {
	int i;
	G->numOfVerts = 0;
	G->numOfEdges = 0;
	for (i = 0; i < MaxVertices; i++) {
		G->a[i].source = i;
		G->a[i].adj = NULL;
	}
}
//���붥��
void InsertVertrix(ListGraph* G, int i, ElemType vertex) {
	if (i > 0 && i < MaxVertices) {
		G->a[i].data = vertex;
		G->numOfVerts++;
	}
	else printf("����Խ��");
}

//�����
void InsertEdge(ListGraph* G, int v1, int v2) {
	Edge* p;
	if (v1 <= 0 || v1 > G->numOfVerts || v2 <= 0 || v2 > G->numOfVerts) {
		printf("����v1��v2Խ�����");
		exit(0);
	}
	p = (Edge*)malloc(sizeof(Edge));
	p->adjvex = v2;  //�ڽӱ�ָ������
	p->next = G->a[v1].adj;		//����ָ�������ֵ��p->next
	G->a[v1].adj = p;			//p��ֵ������ָ�����(�൱��ͷ�巨)
	G->numOfEdges++;
}

//ɾ����
void DeleteEdge(ListGraph* G, int v1, int v2) {
	Edge* cur, * pre;
	if (v1 <= 0 || v1 > G->numOfVerts || v2 <= 0 || v2 > G->numOfVerts) {
		printf("����Խ�����");
		exit(0);
	}
	pre = NULL;
	cur = G->a[v1].adj;
	while (cur != NULL && cur->adjvex != v2) {
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL && cur->adjvex == v2 && pre == NULL) {  //��һ��������,��pre=NULL
		G->a[v1].adj = cur->next;  //ֱ�Ӷ����ָ��ָ��cur����һ��;
		free(cur);
		G->numOfEdges--;
	}
	else if (cur != NULL && cur->adjvex == v2 && pre != NULL) {
		pre->next = cur->next;		//����cur�ڵ�
		free(cur);
		G->numOfEdges--;
	}
	else {
		printf("��<v1,v2>������");
	}
}
//ȡ��һ���ڽӽڵ�
int GetFirstvex(ListGraph G, int v) {
	Edge* p;
	if (v <= 0 || v > G.numOfVerts) {
		printf("����v1��v2Խ�����");
		exit(0);
	}
	p = G.a[v].adj;
	if (p != NULL) {
		return p->adjvex;
	}
	else {
		return -1;
	}
}
//ȡ��һ���ڽӶ���
int  GetNextVex(ListGraph G, int v1, int v2) {
	//ȡv1���ڽӶ���v2֮���һ���ڽӶ���(v1�����v2֮���һ���ڽӶ���)
	Edge* p;
	if (v1 <= 0 || v1 > G.numOfVerts || v2 <= 0 || v2 > G.numOfVerts) {
		printf("����v1��v2Խ�����");
		exit(0);
	}
	p = G.a[v1].adj;  //��ʼ����
	while (p != NULL) {
		if (p->adjvex != v2) {  //�ҵ�ָ��v2�ı�
			p = p->next;
			continue;
		}
		else {
			break;
		}
	}

	p = p->next;	//pΪv2����һ��
	if (p != NULL) {
		return p->adjvex;
	}
	else {
		return -1;

	}
}
//����(
void AdjDestroy(ListGraph* G) {
	int i;
	Edge* p, * q;
	for (i = 1; i <= G->numOfVerts; i++) {
		p = G->a[i].adj; //����ʼ��
		while (p != NULL) {
			q = p->next; //��������p����һ��
			free(p);		//����p
			p = q;		//q���¸�ֵ��p
		}
	}
}

//����ͼ
typedef struct {
	int row;
	int col;

}RowCol;

void CreateGraph(ListGraph* G, ElemType v[], int n, RowCol d[], int e) {
	int i, k;
	AdjInitiate(G);
	for (i = 1; i <= n; i++) {
		InsertVertrix(G, i, v[i]);
	}
	for (k = 1; k <= e; k++) {
		InsertEdge(G, d[k].row, d[k].col);
	}
}

//��ͨͼ������ȱ���(���ڽӾ�����㷨һ��)
void DepthFSearch(ListGraph G, int v, int visited[]) {
	int w;//wΪ��һ���ڵ�
	printf("%5c", G.a[v]);
	visited[v] = 1;  //��������
	w = GetFirstvex(G, v); //v����һ������w
	while (w != -1) {
		if (!visited[w]) {   //w�������δ���ʹ�
			DepthFSearch(G, w, visited);
		}
		w = GetNextVex(G, v, w);  //���ݹ�����vΪ�������w����һ���ڵ�
	}
}

//����ͨͼ��������ȱ���
void DepthFirstSearch(ListGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * (G.numOfVerts + 1));
	for (i = 1; i <= G.numOfVerts; i++) {
		visited[i] = 0;
	}
	for (i = 1; i <= G.numOfVerts; i++) {  //��ÿһ���ڵ㶼Ӧ��һ��DepthFSearch����,��������ͨͼ����©�ڵ�
		if (!visited[i]) {
			DepthFSearch(G, i, visited);   //�ڵݹ��б������Ĳ�����ͨͼ�Ľڵ�ĸ�������ᱻ���Ϊ1,�´β��ܴ�����ڵ㿪ʼ
		}
	}
	free(visited);
}

//��ͨͼ�Ĺ�������㷨
void BroadFSearch(ListGraph G, int v, int visited[]) {
	//��ͨͼG��vΪ��ʼ����Ĺ�����ȱ���
	//����visited�����Ӧ�����Ƿ��ѷ��ʹ�,0��ʾδ����,1��ʾ�ѷ���
	int u, w;   //u��ʾ����,w��ʾ������ڽӵ�
	my_queue* q;
	printf("%5c", G.a[v]); //��������ַ�
	visited[v] = 1;
	q = queue_init();
	queue_push(q, v);   //����������������
	while (!is_empty(*q)) {
		queue_pop(q, &u);			//����
		w = GetFirstvex(G, u);		//��õ�һ���ڽӶ���
		while (w != -1) {
			if (!visited[w]) {
				printf("%5c", G.a[w]);  //���
				visited[w] = 1;
				queue_push(q, w);    //�ȷ��������,�����Ĳ�α���һ��,�ѳ��˶ӵ��ڽӵ����
			}
			w = GetNextVex(G, u, w); //��ó���u�ڵ���ڽӵ�w����һ���ڵ�
		}
	}
}

//����ͨͼ�Ĺ�������㷨
void BroadFirstSearch(ListGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * (G.numOfVerts + 1));
	for (i = 1; i <= G.numOfVerts; i++) {
		visited[i] = 0;
	}
	for (i = 1; i <= G.numOfVerts; i++) {
		if (!visited[i]) {
			BroadFSearch(G, i, visited);  //����BroadFSearch����������ͨͼ
		}
	}
	free(visited);
}
