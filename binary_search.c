#define _SRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arr[9] = { 1,3,5,6,7,9,11,20,30 };

int bin_search(int key, int low, int high)
{
	int middle;
	if (low <= high)
	{
		middle = (low + high) / 2;
		if (key == arr[middle])
			return middle;
		else if (key > arr[middle])
			return bin_search(key, middle + 1, high);
		else
			return bin_search(key, low, middle - 1);
	}
	return -1;

}

int bs_iter(int key, int low, int high)
{
	int middle;
	while (low < high)
	{
		middle = (low + high) / 2;

		if (arr[middle] == key)
			return middle;
		else if (key > arr)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}
