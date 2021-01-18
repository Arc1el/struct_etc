#include<stdio.h>
#include<stdlib.h>

#define INDEX_SIZE  256

typedef struct itable {
	int key;
	int index;
}itable;

int list[5] = { 10,20,30,40,50 };

itable index_list[INDEX_SIZE];

int seq_serch(int key, int low, int high)
{
	int i;
	list[high + 1] = key;

	for (i = low; list[i] != key; i++)
		;

	if (i == (high + 1))
		return -1;

	return i;
	
}

int idx_search(int key, int n)
{
	int i, low, high;

	if (key<i || key>list[n - 1])
		return -1;

	for (i = 0; i < INDEX_SIZE; i++)
	{
		if (index_list[i].key <= key && index_list[i + 1].key > key)
			break;
		if (i == INDEX_SIZE)
		{
			low = index_list[i - 1].index;
			high = n;
		}
		else
		{
			low = index_list[i].index;
			high = index_list[i + 1].index;
		}
		return seq_serch(key, low, high);
	}
}
