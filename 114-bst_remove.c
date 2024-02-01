#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			node = root->right;
			free(root);
			return (node);
		}
		else if (root->right == NULL)
		{
			node = root->left;
			free(root);
			return (node);
		}
		node = root->right;
		while (node->left != NULL)
			node = node->left;
		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
	}
	return (root);
}
