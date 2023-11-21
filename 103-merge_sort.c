#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @tmp: Temporary array for merging
 * @left: Start index of the left subarray
 * @mid: Mid index of the array
 * @right: End index of the right subarray
 */

void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];
	for (i = left; i <= right; ++i)
		array[i] = tmp[i];
	printf("[Done]: ");
		print_array(array + left, right - left + 1);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(size * sizeof(int));

	if (tmp == NULL)
		return;

	if (size <= 1)
	{
		free(tmp);
		return;
	}
	merge_sort_helper(array, tmp, 0, size - 1);
	free(tmp);
}

/**
 * merge_sort_helper - Helper function to perform Merge sort
 * @array: The array to be sorted
 * @tmp: Temporary array for merging
 * @left: Start index of the left subarray
 * @right: End index of the right subarray
 */

void merge_sort_helper(int *array, int *tmp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_helper(array, tmp, left, mid);
		merge_sort_helper(array, tmp, mid + 1, right);
		merge(array, tmp, left, mid, right);
	}
}
