#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Moves the element at index 'root' down so that
 *             the subtree rooted at index 'root' becomes a heap
 * @array: The array to be sorted
 * @root: Index of the root
 * @end: Last index of the heap
 */

void sift_down(int *array, size_t root, size_t end)
{
	int temp;
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;

		print_array(array, end);
		sift_down(array, max, end);
	}
}

/**
 * heapify - Builds a max heap from the array
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (size < 2)
		return;

	heapify(array, size);

	for (int i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		if (i != 1)
		{
			print_array(array, size);
			sift_down(array, 0, i);
		}
	}
}
