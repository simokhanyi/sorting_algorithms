#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count = NULL, *output =NULL;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)max; ++i)
		count[i] = 0;

	for (j = 0; j < size; ++j)
		++count[array[j]];

	for (i = 1; i <= (size_t)max; ++i)
		count[i] += count[i - 1];

	if (output == NULL)
	{
		free(count);
		return;
	}
	for (j = size - 1; (int)j >= 0; --j)
	{
		output[count[array[j]] - 1] = array[j];
		--count[array[j]];
	}
	for (i = 0; i < size; ++i)
		array[i] = output[i];

	free(output);
	free(count);
}
