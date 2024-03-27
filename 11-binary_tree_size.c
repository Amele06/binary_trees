#include "binary_trees.h"

/**
 * binary_tree_size - Would measre the size of the binary tree.
 * @tree: points to the root node to be measured
 *
 * Return: returns size of the tree, else 0 the node passed is NULL. 
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_count = 0;
	if (tree != NULL)
	{
		size_count += 1;
		size_count += binary_tree_size(tree->left);
		size_count += binary_tree_size(tree->right);
	}
	return (size_count);
}