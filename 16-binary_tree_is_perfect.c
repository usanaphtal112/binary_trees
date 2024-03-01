#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf node
 * @node: Pointer to the node to check
 *
 * This function checks if the given node is a leaf node, meaning it has
 * no children (both left and right pointers are NULL).
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 */
unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf node
 * @node: Pointer to the node to check
 *
 * This function checks if the given node is a leaf node, meaning it has
 * no children (both left and right pointers are NULL).
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * This function measures the depth of the given node in a binary tree.
 * The depth of a node is the number of edges from the node to the tree's
 * root node. If the node is NULL or if it has no parent,
 *
 * Return: Depth of the node, or 0 if tree is NULL or node has no parent
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Finds the leaf node in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function finds and returns the first leaf node encountered
 * while traversing the binary tree in a left-to-right manner.
 *
 * Return: Pointer to the first leaf node encountered, or NULL if tree is NULL
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively
 * @tree: Pointer to the root node of the tree to check
 * @leaf_depth: Depth of the leaf nodes in the tree
 * @level: Current level of the tree
 *
 * This function checks recursively if the given binary tree is perfect,
 * meaning that all internal nodes have exactly two children and all leaf
 * nodes are at the same level.
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * This function checks if the given binary tree is perfect, meaning that
 * all internal nodes have exactly two children and all leaf nodes are at
 * the same level.
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
