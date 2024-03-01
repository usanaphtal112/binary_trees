#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the binary tree
 * @func: Pointer to the function to call for each node
 *
 * This function performs a level-order traversal on the given binary tree,
 * calling the specified function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Performs a level-order traversal recursively
 * @head: Pointer to the head of the linked list
 * @func: Pointer to the function to call for each node
 *
 * This function performs a level-order traversal recursively using
 * a linked list to store the nodes at each level. It calls the
 * specified function for each node.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Gets the children of a binary tree node
 * @head: Pointer to the head of the linked list
 * @parent: Pointer to the parent binary tree node
 *
 * This function appends the children of the given parent node to the end
 * of the linked list.
 *
 * Return: Pointer to the head of the updated linked list
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Appends a new node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @btnode: Pointer to the binary tree node to append
 *
 * This function appends a new node containing the given binary tree node
 * to the end of the linked list. If the linked list is empty, the new node
 * becomes the head of the list.
 *
 * Return: Pointer to the head of the updated linked list
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - Frees a linked list
 * @head: Pointer to the head of the linked list
 *
 * This function frees the memory allocated for each node in the linked list,
 * starting from the head node and continuing until the end of the list.
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
