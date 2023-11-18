#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of intege
 * using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && temp->n < prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = temp;

			prev->next = temp->next;
			temp->prev = prev->prev;

			prev->prev = temp;
			temp->next = prev;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
			prev = temp->prev;
		}

		current = current->next;
	}
}
