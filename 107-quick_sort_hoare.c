#include "sort.h"

/**
 * _swap - Swaps two values in an array
 *
 * @array: Data to sort
 * @i: First value
 * @j: Ssecond value
 *
 * Return: No Return
 */
void _swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - Sorts a partition of data in relation to a pivot
 *
 * @array: Data to sort
 * @min: Left wall
 * @max: Right wall
 * @size: Size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max];

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		_swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort -  Sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: Data to sort
 * @min: Left wall
 * @max: Right wall
 * @size: Size of data
 *
 * Return: No Return
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare -  Sorts an array of integers in ascending order using
 * the Quick sort algorithm Hoare partition scheme
 *
 * @array: Data to sort
 * @size: Size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
