#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * This function measures the balance factor of the binary tree starting from
 * the provided root node. The balance factor of a node is the difference
 * between the height of its left subtree and the height of its right subtree.
 * If the tree is empty (root node is NULL), the balance factor is considered 0
 *
 * Return: Balance factor of the binary tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * This function measures the height of the binary tree starting from
 * the provided root node. The height of a binary tree is the maximum
 * depth of any leaf node in the tree.
 * If the tree is empty (root node is NULL), the height is considered 0.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
