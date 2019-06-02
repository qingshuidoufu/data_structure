//#include <stdio.h>
//#include "LMap.h"
//
//int  main() {
//	ListGraph g1;
//	ElemType a[] = { '0','1','2','3','4','5','6' };
//	RowCol v[] = { {0,0},{1,2},{2,3},{2,4},{3,5},{5,6},{6,3} };
//	int n = 6, e = 6;
////
//	CreateGraph(&g1, a, n, v, e);
//
//	int visited[MaxVertices];
//	for (int i = 1; i <= g1.numOfVerts; i++) {
//		visited[i] = 0;
//	}
//	DepthFSearch(g1, 1, visited);
//	printf("\n");
//	DepthFirstSearch(g1);
//	printf("\n");
//	for (int i = 1; i <= n; i++) {
//		visited[i] = 0;
//	}
//	BroadFSearch(g1, 1, visited);
//	printf("\n");
//	BroadFirstSearch(g1);
//	return 0;
//}