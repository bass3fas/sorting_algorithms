#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL, *current = NULL, *next = NULL, *temp = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted = NULL;
    current = *list;
    while (current != NULL)
    {
        next = current->next;
        temp = sorted;

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;

            temp->next = current;
            current->prev = temp;
        }

        current = next;
    }

    *list = sorted;
}
