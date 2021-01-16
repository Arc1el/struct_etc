#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct arrlist {
	element arr[MAX_LIST_SIZE];
	int size;
}arrlist;

void init_l(arrlist *l)
{
	l->size = 0;
}

int is_empty(arrlist *l)
{
	return(l->size == 0);
}

int is_full(arrlist *l)
{
	return(l->size == MAX_LIST_SIZE);
}

element get_entry(arrlist *l, int pos)
{
	if (pos < 0 && pos >= l->size)
		fprintf(stderr, "pos error");
	else
	{
		return l->arr[pos];
	}
}

void print_list(arrlist *l)
{
	int i;
	for (i = 0; i < l->size; i++)
	{
		printf("%d ->", l->arr[i]);
	}
	printf("\n");
}

void insert_last(arrlist *l, element item)
{
	if (is_full(l))
	{
		fprintf(stderr, "list is full");
	}
	else
	{
		l->size++;
		l->arr[l->size] = item;
	}
}

void insert(arrlist *l, element item, int pos)
{
	if (!is_full(l) && pos > 0 && pos <= l->size)
	{
		int i;
		for (i = l->size - 1; i >= pos; i--)
		{
			l->arr[i + 1] = l->arr[i];
		}
		l->arr[pos] = item;
		l->size++;
	}
}

element delist(arrlist *l, int pos)
{
	if (!is_empty(l) && pos > 0 && pos <= l->size)
	{
		int i;
		element item = l->arr[pos];
		for (i = pos; i <= l->size-1; i++)
		{
			l->arr[i] = l->arr[i + 1];
		}
		l->size++;
		return item;
	}
}
