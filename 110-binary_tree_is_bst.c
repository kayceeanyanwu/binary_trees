#include "binary_trees.h"
#include "limits.h"

int btib_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 (tree is a valid BST), 0 (is not or IS NULL)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - binary_tree_is_bst helper function
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 (tree is a valid BST), 0 (otherwise)
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);
	/* -1 and +1 stem from "There must be no duplicate vaues" req */
	return (btib_helper(tree->left, min, tree->n - 1) &&
			btib_helper(tree->right, tree->n + 1, max));
}
