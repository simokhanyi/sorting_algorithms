#include "sort.h"

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort_rec(array, 0, size - 1, size);
}
/**
 * _quick_sort_rec - prototype function to recursively sort
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _quick_sort_rec(int *a, int low, int high, int size)
{
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
}
