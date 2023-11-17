#include "sort.h"
/**
 * swap - changing the vlaues of 2 elements
 * @a: first to swap
 * @b: second to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - sorting using bubble algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swaps;
	size_t i;

	if (array == NULL || size < 2)
		return;
	while (1)
	{
		swaps = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swaps += 1;
				print_array(array, size);
			}
		}
		if (swaps == 0)
			break;
	}
}
