#include "sort.h"
/**
 * counting_sort - sort array by counting occurance
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = array[0];
	size_t i;
	int *count_array;
	int *sorted_array;

	if (array == NULL || size <= 1)
		return;
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max_value; ++i)
		count_array[i] = 0;
	for (i = 0; i < size; ++i)
		count_array[array[i]]++;
	for (i = 1; i <= max_value; ++i)
		count_array[i] += count_array[i - 1];
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = size - 1; i < size; --i)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; ++i)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
