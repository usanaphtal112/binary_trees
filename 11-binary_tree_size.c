#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * This function measures the size of the binary tree starting from
 * the provided root node. The size of a binary tree is the total
 * number of nodes in the tree.
 * If the tree is empty (root node is NULL), the size is considered 0.
 *
 * Return: Size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
