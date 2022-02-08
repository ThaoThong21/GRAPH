//
//  min_heap.h
//  temp
//
//  Created by K Nguyen on 12/4/18.
//  Copyright © 2018 K Nguyen. All rights reserved.
//

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define MAX_HEAP_SIZE 50000

#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HEAP_ITEM;

typedef struct {
    int size;
    HEAP_ITEM *data;
    int *key_positions;
} MIN_HEAP;

MIN_HEAP* create_min_heap(void);

void delete_min_heap(MIN_HEAP *heap);

HEAP_ITEM min_heap_extract_top(MIN_HEAP *heap);

void min_heap_update(MIN_HEAP *heap, int key, int value);

#endif /* MIN_HEAP_H */
