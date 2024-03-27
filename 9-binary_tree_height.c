#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* If both left and right subtrees are NULL, return 0 */
	if (left_height == 0 && right_height == 0)
		return (0);
	/* Return the height of the taller subtree, plus 1 for the current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}
