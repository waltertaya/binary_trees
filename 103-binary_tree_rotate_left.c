#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}
	tree->parent = new_root;
	new_root->left = tree;
	return (new_root);
}
