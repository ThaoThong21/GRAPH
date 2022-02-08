//
//  min_heap.cpp
//  temp
//
//  Created by K Nguyen on 12/4/18.
//  Copyright © 2018 K Nguyen. All rights reserved.
//

#include "min_heap.h"

MIN_HEAP* create_min_heap() {
	MIN_HEAP *result = (MIN_HEAP*)malloc(sizeof(MIN_HEAP));
	result->size = 0;
	result->data = (HEAP_ITEM*)calloc(MAX_HEAP_SIZE, sizeof(HEAP_ITEM));
	result->key_positions = (int*)calloc(MAX_HEAP_SIZE, sizeof(int));
	return result;
}

void delete_min_heap(MIN_HEAP *heap) {
	free(heap->data);
	free(heap);
}

void heapify(MIN_HEAP *heap, int i)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < heap->size && heap->data[l].value < heap->data[smallest].value) {
		smallest = l;
	}

	if (r < heap->size && heap->data[r].value < heap->data[smallest].value) {
		smallest = r;
	}

	if (smallest != i)
	{
		heap->key_positions[heap->data[smallest].key] = i;
		heap->key_positions[heap->data[i].key] = smallest;

		HEAP_ITEM temp = heap->data[i];
		heap->data[i] = heap->data[smallest];
		heap->data[smallest] = temp;

		heapify(heap, smallest);
	}
}

HEAP_ITEM min_heap_extract_top(MIN_HEAP *heap) {
	HEAP_ITEM result;
	result.key = -1;
	if (heap->size == 0) {
		return result;
	}
	result = heap->data[0];
	HEAP_ITEM last_item = heap->data[heap->size - 1];
	heap->data[0] = last_item;

	heap->key_positions[result.key] = heap->size;
	heap->key_positions[last_item.key] = 0;

	--heap->size;

	heapify(heap, 0);
	return result;
}

void min_heap_update(MIN_HEAP *heap, int key, int value) {
	int i = heap->key_positions[key];
	heap->data[i].value = value;

	int parent = (i - 1) / 2;
	while (i - 1 >= 0 && heap->data[i].value < heap->data[parent].value)
	{
		heap->key_positions[heap->data[i].key] = parent;
		heap->key_positions[heap->data[parent].key] = i;

		HEAP_ITEM temp = heap->data[i];
		heap->data[i] = heap->data[parent];
		heap->data[parent] = temp;

		i = parent;
		parent = (i - 1) / 2;
	}
}
