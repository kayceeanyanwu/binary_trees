#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node (once rotated), NULL (if failed)
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *tmp;

	if (!tree || !tree->right)
		return (NULL);

	parent = tree->parent;
	tmp = tree->right;

	tree->right = tmp->left ? tmp->left : NULL;
	tree->parent = tmp;
	tmp->left = tree;
	tmp->parent = parent;
	tree = tmp;
	return (tree);
}
