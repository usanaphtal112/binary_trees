#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * This function performs an in-order traversal on the binary tree starting
 * the provided root node. For each node visited, the function specified
 * is called with the value of the node as its parameter. If either @tree
 * is NULL, the function does nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
