#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: if parent already has a right-child, then new node must take
 * its place, and the old right-child set as the right-child of the new node.
 *
 * Return: pointer to the created node or NULL if failed.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return NULL;

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = parent->right;
	if (new_node->right)
		new_node->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}
