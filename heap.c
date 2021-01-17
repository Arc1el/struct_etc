#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

typedef struct element {
	int key;
}element;

typedef struct heap {
	struct element heap[MAX_ELEMENT];
	int heap_size;
}heap;

heap h;

void insert_max_heap(heap* h, element item)
{
	h->heap_size++;
	int i = h->heap_size;

	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int main()
{
	return 0;
}
