#ifndef GRAPH_H
#define GRAPH_H

#define MAX_N 10000
#include <limits.h>
#include<fstream>
typedef struct {
	int vertex;
	int weight;
} ADJACENCY_LIST_ITEM;


int addEdge(int &n, int start, int end, int weight, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size);
int deleteEdge(int n, int u, int v, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size);
int dijkstra_heap(int n, int start, int end, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size, int *d, int *f,int *map_table);
void PrintPath(int start, int end, int *map_table, std::ofstream &fout);
#endif /* GRAPH_H */
