#include "binary_trees.h"

/**
 * binary_tree_uncle - searches for a node's uncle in B. tree.
 * @node: pointer to the node who's uncle is being searched.
 *
 * Return: returns NULL if the node is NULL or has no uncle.
 * ELSE, a pointer to the uncle node is returned.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
