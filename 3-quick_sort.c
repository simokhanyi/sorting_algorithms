#include "sort.h"

/**
<<<<<<< HEAD
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
=======
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
>>>>>>> bb0762458430d69b756c4f6c639f971995299546
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort_rec(array, 0, size - 1, size);
}
/**
<<<<<<< HEAD
 * quicksort - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Description: This function is a recursive implementation of the Quick Sort
 * algorithm. It selects a pivot using Lomuto's partitioning scheme, and then
 * recursively sorts the sub-arrays before and after the pivot.
=======
 * _quick_sort_rec - prototype function to recursively sort
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
>>>>>>> bb0762458430d69b756c4f6c639f971995299546
 */
void _quick_sort_rec(int *a, int low, int high, int size)
{
<<<<<<< HEAD
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
=======
	int r, s, i;
	int tempo;

	if (low < high)
	{
		r = high;
		s = low;
		for (i = low; i < high; i++)
		{
			if (a[i] < a[r])
			{
				if (i != s)
				{
					tempo = a[i];
					a[i] = a[s];
					a[s] = tempo;
					print_array(a, size);
				}
				s++;
			}
		}
		if (s != r && a[s] != a[r])
		{
			tempo = a[s];
			a[s] = a[r];
			a[r] = tempo;
			print_array(a, size);
		}
		_quick_sort_rec(a, low, s - 1, size);
		_quick_sort_rec(a, s + 1, high, size);
	}
>>>>>>> bb0762458430d69b756c4f6c639f971995299546
}
