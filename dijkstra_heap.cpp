// 17/12/2018 17h40
#include <limits.h>

#include "GRAPH.h"
#include "min_heap.h"

int dijkstra_heap(int n, int start, int end, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size, int *d, int *f,int *map_table) {
	MIN_HEAP *min_heap = create_min_heap();
	start--;
	end--;
	for (int i = 0; i < n; ++i) {
		d[i] = INT_MAX;
		f[i] = 1;//? mark free
		map_table[i] = -1;//____
		min_heap->data[i].key = i;
		min_heap->data[i].value = d[i];
		min_heap->key_positions[i] = i;
	}

	d[start] = 0;
	min_heap_update(min_heap, start, d[start]);

	min_heap->size = n; 

		while (min_heap->size > 0) {
			HEAP_ITEM item = min_heap_extract_top(min_heap);
			int v = item.key;
			if (v == end) {
				break;
			}
			f[v] = 0;
			for (int i = 0, n_a = adjacency_list_size[v]; i < n_a; ++i) {
				ADJACENCY_LIST_ITEM item = adjacency_list[v][i];
				if (f[item.vertex] && d[item.vertex] > d[v] + item.weight) {
					d[item.vertex] = d[v] + item.weight;
					map_table[item.vertex] = v;//___
					min_heap_update(min_heap, item.vertex, d[item.vertex]);
				}
			}
		}
	int result =-1;
	if (d[end] != INT_MAX) result = d[end];
	delete_min_heap(min_heap);
	return result;
}
