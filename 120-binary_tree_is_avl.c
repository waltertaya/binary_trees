#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	if (binary_tree_is_balanced(tree, &height_diff) == 0)
		return (0);
	return (1);
}
