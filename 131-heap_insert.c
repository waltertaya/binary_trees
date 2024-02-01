#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (new_node);
	}
	new_node = binary_tree_insert(*root, value);
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}
