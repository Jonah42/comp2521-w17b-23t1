#include "Graph.h"
#include <stdlib.h>

// assume path is valid
bool isEulerPath(Graph g, Edge e[], int nE) {
	// 1. number of edges is the same as the number of edges in the graph
	int nV = GraphNumVertices(g);
	int count = 0;
	for (Vertex v = 0; v < nV; v++) {
		for (Vertex w = 0; w < nV; w++) {
			if (GraphIsAdjacent(g, v, w)) {
				count++;
			}
		}
	}
	count = count/2;
	if (count != nE) return false;
	// 2. Check that no edge appears twice
	int **seen = malloc(nV*sizeof(int*));
	for (int i = 0; i < nV; i++) {
		seen[i] = calloc(nV, sizeof(int));
	}
	for (int i = 0; i < nE; i++) { // for each edge
		if (seen[e[i].v][e[i].w] == 1) return false; // freee seen
		seen[e[i].v][e[i].w] = 1;
		seen[e[i].w][e[i].v] = 1;
	}
	// free seen
	return true;
}

int main(void) {
	Graph g = GraphRead();
	int nE;
	Edge* e = EdgeRead(&nE);
	printf("Is Euler path? %s\n", isEulerPath(g, e, nE) ? "True" : "False");
	GraphFree(g);
	free(e);
	return 0;
}