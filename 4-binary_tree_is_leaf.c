#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf node in a binary tree
 * @node: Pointer to the node to check
 *
 * This function checks if the given node is a leaf node in a binary tree.
 * A leaf node is a node with no children (both left and
 * right pointers are NULL).
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
