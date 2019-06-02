#pragma once
#pragma once
//为了操作方便,邻接表的存放顶点的数组的0位置不使用
#define ElemType char
#define MaxVertices 100
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct Node {   //边结构体
	int adjvex; //邻接表的箭头顶点序号
	struct Node* next;  //单链表的下一个节点指针
}Edge;

typedef struct {  //顶点结构体
	ElemType data;  //顶点数据元素
	int source;		//顶点序号
	Edge* adj;		//邻接边的箭头指针
}AdjLHeight;

typedef struct {   //图结构体
	AdjLHeight a[MaxVertices]; //邻接表数组
	int numOfVerts;			//顶点个数
	int numOfEdges;		//边个数
}ListGraph;

//初始化图
void AdjInitiate(ListGraph* G) {
	int i;
	G->numOfVerts = 0;
	G->numOfEdges = 0;
	for (i = 0; i < MaxVertices; i++) {
		G->a[i].source = i;
		G->a[i].adj = NULL;
	}
}
//插入顶点
void InsertVertrix(ListGraph* G, int i, ElemType vertex) {
	if (i > 0 && i < MaxVertices) {
		G->a[i].data = vertex;
		G->numOfVerts++;
	}
	else printf("顶点越界");
}

//插入边
void InsertEdge(ListGraph* G, int v1, int v2) {
	Edge* p;
	if (v1 <= 0 || v1 > G->numOfVerts || v2 <= 0 || v2 > G->numOfVerts) {
		printf("参数v1或v2越界出错");
		exit(0);
	}
	p = (Edge*)malloc(sizeof(Edge));
	p->adjvex = v2;  //邻接边指向的序号
	p->next = G->a[v1].adj;		//顶点指向的链赋值给p->next
	G->a[v1].adj = p;			//p赋值给顶点指向的链(相当于头插法)
	G->numOfEdges++;
}

//删除边
void DeleteEdge(ListGraph* G, int v1, int v2) {
	Edge* cur, * pre;
	if (v1 <= 0 || v1 > G->numOfVerts || v2 <= 0 || v2 > G->numOfVerts) {
		printf("数组越界出错");
		exit(0);
	}
	pre = NULL;
	cur = G->a[v1].adj;
	while (cur != NULL && cur->adjvex != v2) {
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL && cur->adjvex == v2 && pre == NULL) {  //第一个就是了,故pre=NULL
		G->a[v1].adj = cur->next;  //直接顶点的指针指向cur的下一个;
		free(cur);
		G->numOfEdges--;
	}
	else if (cur != NULL && cur->adjvex == v2 && pre != NULL) {
		pre->next = cur->next;		//跳过cur节点
		free(cur);
		G->numOfEdges--;
	}
	else {
		printf("边<v1,v2>不存在");
	}
}
//取第一个邻接节点
int GetFirstvex(ListGraph G, int v) {
	Edge* p;
	if (v <= 0 || v > G.numOfVerts) {
		printf("参数v1或v2越界出错");
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
//取下一个邻接顶点
int  GetNextVex(ListGraph G, int v1, int v2) {
	//取v1的邻接顶点v2之后的一个邻接顶点(v1顶点的v2之外的一个邻接顶点)
	Edge* p;
	if (v1 <= 0 || v1 > G.numOfVerts || v2 <= 0 || v2 > G.numOfVerts) {
		printf("参数v1或v2越界出错");
		exit(0);
	}
	p = G.a[v1].adj;  //起始顶点
	while (p != NULL) {
		if (p->adjvex != v2) {  //找到指向v2的边
			p = p->next;
			continue;
		}
		else {
			break;
		}
	}

	p = p->next;	//p为v2的下一个
	if (p != NULL) {
		return p->adjvex;
	}
	else {
		return -1;

	}
}
//撤消(
void AdjDestroy(ListGraph* G) {
	int i;
	Edge* p, * q;
	for (i = 1; i <= G->numOfVerts; i++) {
		p = G->a[i].adj; //定起始点
		while (p != NULL) {
			q = p->next; //保存起来p的下一个
			free(p);		//销毁p
			p = q;		//q重新赋值给p
		}
	}
}

//创建图
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

//连通图深度优先遍历(与邻接矩阵的算法一样)
void DepthFSearch(ListGraph G, int v, int visited[]) {
	int w;//w为下一个节点
	printf("%5c", G.a[v]);
	visited[v] = 1;  //遍历过了
	w = GetFirstvex(G, v); //v的下一个顶点w
	while (w != -1) {
		if (!visited[w]) {   //w这个顶点未访问过
			DepthFSearch(G, w, visited);
		}
		w = GetNextVex(G, v, w);  //回溯过程以v为基础获得w的下一个节点
	}
}

//非连通图的深度优先遍历
void DepthFirstSearch(ListGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * (G.numOfVerts + 1));
	for (i = 1; i <= G.numOfVerts; i++) {
		visited[i] = 0;
	}
	for (i = 1; i <= G.numOfVerts; i++) {  //对每一个节点都应用一次DepthFSearch方法,做到非连通图不遗漏节点
		if (!visited[i]) {
			DepthFSearch(G, i, visited);   //在递归中遍历到的部分连通图的节点的辅助数组会被标记为1,下次不能从这个节点开始
		}
	}
	free(visited);
}

//连通图的广度优先算法
void BroadFSearch(ListGraph G, int v, int visited[]) {
	//连通图G以v为初始顶点的广度优先遍历
	//数组visited标记相应顶点是否已访问过,0表示未访问,1表示已访问
	int u, w;   //u表示顶点,w表示顶点的邻接点
	my_queue* q;
	printf("%5c", G.a[v]); //输出顶点字符
	visited[v] = 1;
	q = queue_init();
	queue_push(q, v);   //顶点的索引加入队列
	while (!is_empty(*q)) {
		queue_pop(q, &u);			//出队
		w = GetFirstvex(G, u);		//获得第一个邻接顶点
		while (w != -1) {
			if (!visited[w]) {
				printf("%5c", G.a[w]);  //输出
				visited[w] = 1;
				queue_push(q, w);    //先访问再入队,像树的层次遍历一样,把出了队的邻接点入队
			}
			w = GetNextVex(G, u, w); //获得除了u节点的邻接点w的下一个节点
		}
	}
}

//非连通图的广度优先算法
void BroadFirstSearch(ListGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * (G.numOfVerts + 1));
	for (i = 1; i <= G.numOfVerts; i++) {
		visited[i] = 0;
	}
	for (i = 1; i <= G.numOfVerts; i++) {
		if (!visited[i]) {
			BroadFSearch(G, i, visited);  //调用BroadFSearch来搜索非连通图
		}
	}
	free(visited);
}
