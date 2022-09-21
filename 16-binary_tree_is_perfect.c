#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: height of the tree, 0 (if tree is NULL)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;
	height_l = height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the node of the tree to check
 *
 * Return: 1 (is full), 0 (is not or IS NULL)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = tree->left ? binary_tree_is_full(tree->left) : 0;
	right = tree->right ? binary_tree_is_full(tree->right) : 0;

	if ((!left && right) || (left && !right))
		return (0);
	return (1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Description: verify if balance factor is 0 and tree is full.
 * Return: 1 (tree is perfect), 0 (if not or IS NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right = tree->right ? (int)binary_tree_height(tree->right) : -1;
	if (left - right == 0)
		return (binary_tree_is_full(tree));
	return (0);
}
