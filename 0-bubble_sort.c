#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 *
 * Description: This function implements the Bubble Sort algorithm to sort
 *              the array of integers in ascending order.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2 || array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
