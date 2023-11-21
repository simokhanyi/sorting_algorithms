#include "sort.h"

/**
 * shell_sort - function prototype that sorts an array
 * of integers in ascending order using the
 * Shell sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: nothing to return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		knut_shell_sort(array, size, n);
}
/**
 * knut_shell_sort -  function prototype for
 * shell_sort function
 * @a: input arrray
 * @size: size of the array
 * @n: intervale
 * Return: nothing to return
 */
  void knut_shell_sort(int *a, int size, int n)
{
	int tempo, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tempo = a[j];
				a[j] = a[j - n];
				a[j - n] = tempo;
			}
		}
	}
	print_array(a, size);
}
