#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as
 * the right-child of another node
 * @parent: Pointer to the parent node to insert the right-child node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
