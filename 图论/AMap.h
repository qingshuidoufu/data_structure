#pragma once
#pragma once
#define Max_Virtices 100
#define MaxWeight 100
#include"seq_list.h"
#include "queue.h"
typedef struct {
	SqList Virtices;	//顶点的顺序表
	int edge[Max_Virtices][Max_Virtices];		//存边的邻接矩阵
	int numOfEdge;			//边的条数
}MatrixGraph;

//初始化
void initate(MatrixGraph* G, int n) {//
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				G->edge[i][j] = 0;
			}
			else {
				G->edge[i][j] = MaxWeight;  //MaxWeight 表示最大化
			}
		}
	}
	G->numOfEdge = 0;
	InitList(G->Virtices);
}
//插入顶点
void InsertVertex(MatrixGraph* G, ElemType Vertex) {			//图G中插入顶点vertex
	ListInsert(G->Virtices, G->Virtices.length + 1, Vertex);  //顺序表的尾部插入
}
//插入一条边
void InsertEdge(MatrixGraph* G, int v1, int v2, int weight) {		//在G中插入边<v1,v2>,v2的权为weight
	if (v1<0 || v1>G->Virtices.length || v2 < 0 || v2>G->Virtices.length)
	{
		printf("参数v1或v2越界出错!");
		exit(1);
	}
	G->edge[v1][v2] = weight;
	G->numOfEdge++;
}
//删除边
void DeleteEdge(MatrixGraph* G, int v1, int v2) {		//在图中删除边<v1,v2>
	if (v1<0 || v1>G->Virtices.length || v2<0 || v2>G->Virtices.length) {
		printf("参数v1或v2越界出错!");
		exit(1);
	}
	G->edge[v1][v2] = MaxWeight;
	G->numOfEdge--;
}
//删除顶点
void DeleteVertex(MatrixGraph* G, int v) {			//删除节点
	int n = G->Virtices.length, i, j;
	ElemType x;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((i == v || j == v) && G->edge[i][j] > 0 && G->edge[i][j] < MaxWeight) {
				G->numOfEdge--;			//被删除边计数
			}
		}
	}
	for (i = v; i < n; i++) {
		for (j = 0; j < n; j++) {
			G->edge[i][j] = G->edge[i + 1][j];  //删除第V行
		}
	}
	for (i = 0; i < n; i++) {
		for (j = v; j < n; j++) {
			G->edge[i][j] = G->edge[i][j + 1];		//删除第v列
		}
	}
	ListDelete(G->Virtices, v, x);
}
//取第一个邻接点顶点
int GetFirstVex(MatrixGraph G, int v) {
	//在图中寻找序号为v的顶点的第一个邻接点
	//如果这样的邻接点存在则返回该邻接点的序号,否则返回-1
	int col;
	if (v < 0 || v>G.Virtices.length) {
		printf("参数v1越界出错!");
		exit(1);
	}
	for (col = 0; col < G.Virtices.length; col++) {
		if (G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight) {
			return col;
		}
	}
	return -1;
}
//取下一个邻接顶点
int GetNextVex(MatrixGraph G, int v1, int v2) {
	//在图G中寻找v1顶点的邻接顶点v2的下一个邻接顶点,如果这样的邻接顶点存在则返回邻接顶点的序号,否则返回-1,,这里v1和v2都是对应顶点的序号
	//取经过v1的邻接顶点v2之外的下一个邻接顶点,也就是邻接矩阵中的顶点v1中从v2+1个矩阵元素开始的非0且非无穷大的顶点
	int col;
	if (v1<0 || v1>G.Virtices.length || v2<0 || v2>G.Virtices.length) {
		printf("参数v1或v2越界出错!");
		exit(1);
	}
	for (col = v2 + 1; col <= G.Virtices.length; col++) {
		if (G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight) {
			return col;
		}
	}
	return -1;
}
typedef struct {
	int row;
	int col;
	int weight;
}RowColWeight;
void CreateGraph(MatrixGraph* G, ElemType V[], int n, RowColWeight E[], int e) {
	//在图G中插入n个顶点信息V和e条边信息E
	int i, k;
	initate(G, n);   //顶点顺序初始化
	for (i = 0; i < n; i++) {
		InsertVertex(G, V[i]);		//顶点插入
	}
	for (k = 0; k < e; k++) {
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);  //边插入
	}
}
void graph_print(MatrixGraph g1, int n) {
	//邻接矩阵打印图
	int i, j;
	printf("说明:其中字母分别表示 G:大门 T:教学楼 M:后山 L:图书馆 P:人工湖 C:饭堂 A:学生活动中心 D:学生宿舍\n");
	printf("点集合为:\n");
	for (i = 0; i < g1.Virtices.length; i++) {
		printf("%5c", g1.Virtices.elem[i]);
	}
	printf("\n");
	printf("\n");
	printf("边集矩阵表示:\n");
	for (i = 0; i < g1.Virtices.length; i++) {
		for (j = 0; j < g1.Virtices.length; j++) {
			printf("%5d", g1.edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
//连通图的深度优先算法
void DepthFSearch(MatrixGraph G, int v, int visited[]) {
	//连通图以v为起始点的深度优先遍历(非连通图只能遍历出来一个,会剩下一部分节点没能遍历出来)
	//数组visited标记了相应顶点是否已访问过,0表示未访问,1表示已访问
	int w;		//标记下一个节点
	printf("%5c", G.Virtices.elem[v]);
	visited[v] = 1;     // 标记已经访问过
	w = GetFirstVex(G, v);    //获得下一个节点
	while (w != -1) {      //直到不能获得下一个节点 ,节点未访问过递归深搜
		if (!visited[w]) {
			DepthFSearch(G, w, visited);
		}
		w = GetNextVex(G, v, w);      //回溯过程中寻找下一个节点;

	}
}

//非连通图的深度优先遍历
void DepthFirstSearch(MatrixGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * G.Virtices.length);
	for (i = 0; i < G.Virtices.length; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < G.Virtices.length; i++) {  //对每一个节点都应用一次DepthFSearch方法,做到非连通图不遗漏节点
		if (!visited[i]) {
			DepthFSearch(G, i, visited);   //在递归中遍历到的部分连通图的节点的辅助数组会被标记为1,下次不能从这个节点开始
		}
	}
	free(visited);
}

//连通图的广度优先算法
void BroadFSearch(MatrixGraph G, int v, int visited[]) {
	//连通图G以v为初始顶点的广度优先遍历
	//数组visited标记相应顶点是否已访问过,0表示未访问,1表示已访问
	int u, w;   //u表示顶点,w表示顶点的邻接点
	my_queue* q;
	printf("%5c", G.Virtices.elem[v]); //输出顶点字符
	visited[v] = 1;
	q = queue_init();
	queue_push(q, v);   //顶点的索引加入队列
	while (!is_empty(*q)) {
		queue_pop(q, &u);			//出队
		w = GetFirstVex(G, u);		//获得第一个邻接顶点
		while (w != -1) {
			if (!visited[w]) {
				printf("%5c", G.Virtices.elem[w]);  //输出
				visited[w] = 1;
				queue_push(q, w);    //先访问再入队,像树的层次遍历一样,把出了队的邻接点入队
			}
			w = GetNextVex(G, u, w); //获得除了u节点的邻接点w的下一个节点
		}
	}
}

//非连通图的广度优先算法
void BroadFirstSearch(MatrixGraph G) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * G.Virtices.length);
	for (i = 0; i < G.Virtices.length; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < G.Virtices.length; i++) {
		if (!visited[i]) {
			BroadFSearch(G, i, visited);  //调用BroadFSearch来搜索非连通图
		}
	}
	free(visited);
}