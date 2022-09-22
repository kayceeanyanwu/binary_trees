#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_min_val - finds the smallest node from a Binary Search Tree
 * @root : pointer to the root node of the tree
 * Return: pointer to the smallest node
 */
bst_t *bst_min_val(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;
	return (min);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Description: once located, the node containing the value must be removed
 * and freed, if the node to be deleted has two children, it must be replaced
 * with its first in-order successor
 *
 * Return: pointer to the new root node after removal , other NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_min_val(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
