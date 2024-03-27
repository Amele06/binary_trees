#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = malloc(sizeof(binary_tree_t));

	right_child->n = value;
	right_child->parent = parent;
	right_child->right = parent->right;
	right_child->left = NULL;

	/*If parent already has a right-child, the new node must take its place*/
	if (parent->right != NULL)
		parent->right->parent = right_child;
	/*the old right-child set as the right-child of the new node*/
	parent->right = right_child;

	return (right_child);
}
