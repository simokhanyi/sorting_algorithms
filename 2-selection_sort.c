#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 *
 * Description: This function implements the Selection Sort algorithm to sort
 *              the array of integers in ascending order. It repeatedly finds
 *              the minimum element from the unsorted part and swaps it with
 *              the first unsorted element until the entire array is sorted.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
