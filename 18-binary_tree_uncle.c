#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle
 *
 * This function finds and returns the uncle of the given node in a binary tre
 * The uncle of a node is the sibling of its parent node.
 * If the given node is NULL, has no parent, or its parent has no parent
 * the function returns NULL.
 * If the parent of the given node is the left child of its parent
 * the uncle is the right child of the grandparent, and vice versa.
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL, has no parent,
 * or its parent has no parent (grandparent)
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
