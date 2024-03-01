#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * This function measures the depth of the given node in a binary tree.
 * The depth of a node is the number of edges from
 * the node to the tree's root node.
 * If the node is NULL or if it has no parent, its depth is considered 0.
 *
 * Return: Depth of the node, or 0 if tree is NULL or node has no parent
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
