#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root node in a binary tree
 * @node: Pointer to the node to check
 *
 * This function checks if the given node is a root node in a binary tree.
 * A root node is a node with no parent.
 *
 * Return: 1 if the node is a root, 0 otherwise or if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
