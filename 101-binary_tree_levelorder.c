#include "binary_trees.h"

void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - traverse through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a print function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree);
	for (level = 0; level <= maxlevel; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - goes through a binary tree using post-order traverse
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a print function
 * @level: level of the tree to call func upon
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!level)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
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
