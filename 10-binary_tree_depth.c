#include "binary_trees.h"

/**
 * binary_tree_depth - Function to measure the depth of
 * a node in a binary tree.
 * @tree: pointer to the node to be measured.
 *
 * Return: when tree is NULL, returns 0, else the depth as measured.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    /*traversing the tree until the root is reached*/
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
