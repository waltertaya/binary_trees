#include "binary_trees.h"

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the value
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;

	if (root == NULL)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			node = root->left ? root->left : root->right;
			if (node == NULL)
			{
				node = root;
				root = NULL;
			}
			else
				*root = *node;
			free(node);
		}
		else
		{
			node = avl_find_min(root->right);
			root->n = node->n;
			root->right = avl_remove(root->right, node->n);
		}
	}
	if (root == NULL)
		return (root);
	root->height = 1 + MAX(avl_height(root->left), avl_height(root->right));
	return (avl_balance(root));
}
