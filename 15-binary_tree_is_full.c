#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively
 * @tree: Pointer to the root node of the tree to check
 *
 * This function checks recursively if the given binary tree is full,
 * meaning that every node in the tree has either 0 or 2 children.
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * This function checks if the given binary tree is full, meaning
 * that every node in the tree has either 0 or 2 children. If the
 * tree is empty (root node is NULL), it's considered not full.
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
