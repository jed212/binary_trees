#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	if (parent == NULL)
		return (NULL);

	new_n = malloc(sizeof(binary_tree_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = value;
	new_n->parent = parent;
	new_n->left = parent->left;
	new_n->right = NULL;

	if (parent->left != NULL)
		parent->left->parent = new_n;

	parent->left = new_n;

	return (new_n);
}
