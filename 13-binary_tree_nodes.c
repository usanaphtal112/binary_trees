#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * This function counts the number of nodes in the binary tree starting from
 * the provided root node that have at least one child. A node with at least
 * one child has either a left child, a right child, or both.
 * If the tree is empty (root node is NULL), the number of such nodes
 *
 * Return: Number of nodes with at least one child in the binary
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
