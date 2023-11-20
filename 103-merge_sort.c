#include "sort.h"
/**
 * merge - Merge two sub-arrays into a single sorted array
 * @array: The original array containing the two sub-arrays.
 * @size: The size of the array.
 * @left: The left sub-array.
 * @right: The right sub-array.
 * @left_size: size of left array
 * @right_size: size of right array
 */
void merge(int *array, size_t size, int *left, size_t left_size,
	   int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		free(temp);
		return;
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm (top-down approach).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, mid);
		merge_sort(right, size - mid);

		merge(array, size, left, mid, right, size - mid);
	}
}
