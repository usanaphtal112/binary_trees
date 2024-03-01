#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * This function performs a pre-order traversal on the binary tree starting
 * the provided root node. For each node visited, the function specified @func
 * is called with the value of the node as its parameter. If either @tree @func
 * is NULL, the function does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
