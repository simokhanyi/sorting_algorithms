#include <stdio.h>
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
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 *
 * Description: This function partitions the array using the Lomuto scheme
 * for the Quick Sort algorithm. It selects the last element as the pivot,
 * rearranges the array so that elements smaller than the pivot are placed
 * before the pivot and elements greater than the pivot are placed after it.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Description: This function is a recursive implementation of the Quick Sort
 * algorithm. It selects a pivot using Lomuto's partitioning scheme, and then
 * recursively sorts the sub-arrays before and after the pivot.
 */

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order.
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description: This function initiates the Quick Sort algorithm.
 * It checks for base cases (array is NULL or has fewer than 2 elements)
 * and then calls the recursive quicksort function to sort the entire array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quicksort(array, 0, size - 1, size);
	print_array(array, size);
}
