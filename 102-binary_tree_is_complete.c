#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_is_perfect(tree) == 1)
		return (1);
	if (binary_tree_is_full(tree) == 1)
		return (1);
	return (0);
}
