#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * This function finds and returns the lowest common ancestor of two nodes
 * in a binary tree. If either of the nodes is NULL, the function returns NULL.
 * If the first and second nodes are the same, the function returns that node.
 * If the nodes are not directly related (i.e., one is not an ancestor of the other),
 * the function calculates the depths of the nodes and then moves up to the same
 * depth from their respective parent nodes, checking for equality to find the
 * lowest common ancestor.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if one of the nodes
 * is NULL or if they are not part of the same binary tree
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;
	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * This function measures the depth of the given node in a binary tree.
 * The depth of a node is the number of edges from the node to the tree's
 * root node. If the node is NULL or if it has no parent,
 * its depth is considered 0.
 *
 * Return: Depth of the node, or 0 if tree is NULL or node has no parent
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
