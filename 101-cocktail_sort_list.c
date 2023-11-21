#include "sort.h"
/**
 * swap - Swaps two nodes in a doubly linked list
 * @list: Pointer to the pointer of the head of the list
 * @left: Pointer to the left node to be swapped
 * @right: Pointer to the right node to be swapped
 */
void swap(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	if (right->next != NULL)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the pointer of the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *start = NULL, *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (current = (*list)->next; current != end; current = current->next)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				swapped = 1;
			}
		}
		end = current->prev;
		if (!swapped)
			break;
		swapped = 0;
		for (current = current->prev; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				swapped = 1;
			}
		}
		start = current;
	} while (swapped);
}
