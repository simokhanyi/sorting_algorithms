#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to a pointer to the head of the list
 *
 * Description: Implements Insertion Sort algorithm on a doubly linked list.
 *              It sorts the list in ascending order by rearranging the nodes
 *              based on their integer values.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (node != NULL)
	{
		while (node->prev != NULL && node->prev->n > node->n)
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_node - Swaps a node with its previous node in a doubly linked list
 * @node: Node to be swapped
 * @list: Pointer to the head of the list
 * Return: Pointer to the node after swapping
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev;
	listint_t *next = node->next;

	prev->next = next;

	if (node == NULL || *list == NULL || node->prev == NULL)
	{
		return (NULL);
	}

	if (next != NULL)
	{
		next->prev = prev;
	}
	node->prev = prev->prev;
	node->next = prev;

	if (node->prev != NULL)
	{
		node->prev->next = node;
	} else
	{
		*list = node;
	}
	prev->prev = node;

	return (node);
}
