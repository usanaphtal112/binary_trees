#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: Pointer to the node to find the sibling
 *
 * This function finds and returns the sibling of the given node in a binary t
 * The sibling of a node is another node in the tree that shares the same par
 * If the given node is NULL or if it has no parent, the function returns NULL.
 * If the node is the left child of its parent, its sibling is the right child
 * and vice versa.
 *
 * Return: Pointer to the sibling node, or NULL if node is NULL or has no pare
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
