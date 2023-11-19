#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble Sort.
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 *
 * Description: This function implements the Bubble Sort algorithm to sort
 *              the array of integers in ascending order. It continuously
 *              iterates through the array and swaps adjacent elements if
 *              they are in the wrong order until the entire array is sorted.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1;

				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
