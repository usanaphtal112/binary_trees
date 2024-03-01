#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * This function recursively deletes each node in the binary tree start from
 * the provided root node. It first deletes the left subtree,
 * then the right subtree, and finally frees the memory allocated
 * for the current node. If the tree is empty
 * (root node is NULL), this function does nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
