#include "binary_trees.h"

/**
 * greater_than - check if all values in the tree are greater than a value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return 1 (if true), 0 (if false)
 */
int greater_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (!tree)
		return (1);
	if (tree->n > val)
	{
		l = greater_than(tree->left, val);
		r = greater_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * less_than - check if all values in the tree are less than a specific value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return 1 (if true), 0 (if false)
 */
int less_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (!tree)
		return (1);
	if (tree->n < val)
	{
		l = less_than(tree->left, val);
		r = less_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

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
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Description: An AVL Tree is a BST with balance factor of not more than one
 * Return: 1 (is a valid AVL Tree), 0 (is not or IS NULL)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (left - right > 1 || right - left > 1)
		return (0);

	if (less_than(tree->left, tree->n) &&
			greater_than(tree->right, tree->n))
		if ((!tree->left || binary_tree_is_avl(tree->left)) &&
				(!tree->right || binary_tree_is_avl(tree->right)))
			return (1);
	return (0);
}
