#include "sort.h"
void swap(int *a, int *b);
int partiniorLomuto(int *array, int low, int high, size_t size);
void sorter(int *array, int low, int high, size_t size);
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partiniorLomuto - partitions an array of integers in ascending order
 * @array: array to sort
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: index of the pivot element
 */
int partiniorLomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	i++;
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);

	return (i);
}
/**
 * sorter - sorts an array of integers in ascending order using the
 * Lomuto partition scheme
 * @array: array to sort
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 */
void sorter(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partiniorLomuto(array, low, high, size);
		sorter(array, low, pivot - 1, size);
		sorter(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Lomuto partition scheme
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(array, 0, size - 1, size);
}
