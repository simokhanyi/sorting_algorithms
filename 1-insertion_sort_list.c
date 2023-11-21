#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly linked list of
* integers in ascending order
*
* @list: Pointer to the pointer of the head of the list
* Return: void, nothin to return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		tmp = current;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{

			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			print_list(*list);
		}
	}
}
