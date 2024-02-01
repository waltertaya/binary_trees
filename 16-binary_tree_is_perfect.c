#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_is_full(tree) == 0)
		return (0);
	if (binary_tree_is_leaf(tree) == 1)
		return (1);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height == right_height)
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	return (0);
}
