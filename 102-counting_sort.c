#include "sort.h"

/**
 * counting_sort - sort array by counting occurrence
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *output;
	size_t i, n, l;
	int j, k;

	if (size <= 1)
		return;

	max = array[0];
	for (l = 1; l < size; ++l)
	{
		if (array[l] > max)
			max = array[l];
	}

	count = calloc(max + 1, sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i < size; ++i)
		++count[array[i]];
	print_array(count, max + 1);
	for (j = 1; j <= max; ++j)
		count[j] += count[j - 1];
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (k = size - 1; k >= 0; --k)
	{
		output[count[array[k]] - 1] = array[k];
		--count[array[k]];
	}
	for (n = 0; n < size; ++n)
		array[n] = output[n];
	free(output);
	free(count);
}