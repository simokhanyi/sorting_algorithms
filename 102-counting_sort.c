#include "sort.h"
<<<<<<< HEAD

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
=======
/**
 * counting_sort -counts an arrayof integers
 * in ascending order using the
 * Counting sort algorithm
 * @array: array
 * @size: size
 * Return: nothing to return
 */
void counting_sort(int *array, size_t size)
{
	int n, m;
	int *buffer, *y;

	if (size < 2)
		return;

	for (n = m = 0; m < (int)size; m++)
		if (array[m] > n)
			n = array[m];

	buffer = malloc(sizeof(int) * (n + 1));
	if (!buffer)
		return;

	for (m = 0; m <= n; m++)
		buffer[m] = 0;
	for (m = 0; m < (int)size; m++)
		buffer[array[m]] += 1;
	for (m = 1; m <= n; m++)
		buffer[m] += buffer[m - 1];

	print_array(buffer, (n + 1));
	y = malloc(sizeof(int) * (size + 1));

	if (!y)
	{
		free(buffer);
		return;
	}
	for (m = 0; m < (int)size; m++)
	{
		y[buffer[array[m]] - 1] = array[m];
		buffer[array[m]] -= 1;
	}
	for (m = 0; m < (int)size; m++)
		array[m] = y[m];

	free(buffer);
	free(y);
>>>>>>> bb0762458430d69b756c4f6c639f971995299546
}
