#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * This function finds and returns the lowest common ancestor of two nodes
 * in a binary tree. If either of the nodes is NULL, the function returns NULL
 * If the first and second nodes are the same, the function returns that node.
 * If the nodes are not directly related
 * the function recursively finds their ancestors
 * until it finds their lowest common ancestor.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if one of the
 * is NULL or if they are not part of the same binary tree
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pop));
}
