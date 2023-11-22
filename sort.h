#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
void quick_sort(int *array, size_t size);
void _quick_sort_rec(int *a, int low, int high);
void shell_sort(int *array, size_t size);
void knut_shell_sort(int *a, int size, int n);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t root, size_t end);
void heapify(int *array, size_t size);
void merge_sort_helper(int *array, int *tmp, size_t left, size_t right);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t isize);
int lomuto_partition(int *array, int low, int high);
listint_t *swap_node(listint_t *node, listint_t **list);
void print_array(const int *array, size_t size);

#endif/* SORT_H */
