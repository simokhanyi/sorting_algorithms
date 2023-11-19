#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to a pointer to the head of the list
 *
 * Description: Insertion Sort algorithm on a doubly linked list.
 *              It sorts the list in ascending order by traversing the list
 *              while rearranging the nodes based on their integer values.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	
	while (current != NULL)
	{
		listint_t *back = current->prev;
		int value = current->n;

		while (back != NULL && back->n > value)
		{
			back->next->n = back->n;
			back = back->prev;
			if (back != NULL)
			{
				back->next->n = value;
				print_list(*list);
			}
		}
		if (back == NULL)
		{
			(*list)->n = value;
			print_list(*list);
		} else
		{
			back->next->n = value;
			print_list(*list);
		}
		current = current->next;
	}
}
