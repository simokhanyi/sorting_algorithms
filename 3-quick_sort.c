#include "sort.h"

/**
 * swap - Swaps two integer values
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Description: This function swaps the values of two integers.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto's partitioning scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 *
 * Description: This function selects a pivot from the array using Lomuto's
 * partitioning scheme, partitions the array around the pivot, and returns the
 * index of the pivot element.
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * _quick_sort_rec - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Description: This function is a recursive implementation of the Quick Sort
 * algorithm. It selects a pivot using Lomuto's partitioning scheme, and then
 * recursively sorts the sub-arrays before and after the pivot.
 */

void _quick_sort_rec(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high);

		_quick_sort_rec(array, low, pi - 1);
		_quick_sort_rec(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description: This function initiates the Quick Sort algorithm. It checks for
 * base cases (array is NULL or has fewer than 2 elements) and then calls the
 * recursive quicksort function to sort the entire array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

    _quick_sort_rec(array, 0, size - 1);
}
