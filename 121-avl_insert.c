#include "binary_trees.h"

avl_t *avli_helper(avl_t **tree, avl_t *parent, avl_t **new, int value);

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL if failed
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avli_helper(tree, *tree, &new, value);
	return (new);
}

/**
 * avli_helper - avl_insert helper function
 * @tree: double pointer to the root node of the AVL tree for inserting value
 * @parent: parent of the node to be created
 * @new: node to created
 * @value: value to be inserted
 *
 * Return: a pointer to the created node, or NULL if failed
 */
avl_t *avli_helper(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bf;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avli_helper(&(*tree)->left, *tree, new, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avli_helper(&(*tree)->right, *tree, new, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	bf = binary_tree_balance(*tree);
	if (bf > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bf < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bf > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bf < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_left((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
