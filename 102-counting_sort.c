#include "sort.h"
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
}
