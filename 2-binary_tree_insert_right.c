#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_insert - inserts a node as the right-child of anothernode
 * @parent: A pointer to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node or NULL on failure,
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	if (parent == NULL)
		return (NULL);

	new_n = malloc(sizeof(binary_tree_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = value;
	new_n->parent = parent;
	new_n->left = NULL;
	new_n->right = parent->right;

	if (parent->right != NULL)
		parent->right->parent = new_n;

	parent->right = new_n;

	return (new_n);
}
