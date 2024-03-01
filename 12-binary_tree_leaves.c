#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count leaves
 *
 * This function counts the number of leaf nodes in the binary tree
 * the provided root node. A leaf node is a node with no children (both left
 * right pointers are NULL).
 * If the tree is empty (root node is NULL), the number of leaves
 *
 * Return: Number of leaf nodes in the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
