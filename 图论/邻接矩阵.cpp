#include <stdio.h>
#include "AMap.h"


int  main() {
	MatrixGraph g1;
	ElemType a[] = { 'G','T','M','L','P','C','A','D' };
	RowColWeight rcw[] = { {0,1,3},{0,2,7},{1,0,3},{1,3,4},{1,4,3},{2,0,7},{2,5,6},{2,6,5},{3,1,4},{3,7,2},
						{4,1,3},{4,7,1},{5,2,6},{5,6,1},{6,2,5},{6,5,1},{7,3,2},{7,4,1}
	};
	int n = 8, e = 18;

	CreateGraph(&g1, a, n, rcw, e);
	graph_print(g1, g1.Virtices.length);


	printf("深度优先遍历为:\n");
	DepthFirstSearch(g1);
	printf("\n");
	printf("广度优先遍历为:\n");
	BroadFirstSearch(g1);
	return 0;
}