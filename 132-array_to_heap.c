#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created Max Binary Heap
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		heap_insert(&tree, array[i]);
	return (tree);
}
