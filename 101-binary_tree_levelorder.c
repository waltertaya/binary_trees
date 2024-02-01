#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = binary_tree_height(tree);
	int i;

	for (i = 1; i <= h; i++)
		binary_tree_levelorder_recursion(tree, i, func);
}
