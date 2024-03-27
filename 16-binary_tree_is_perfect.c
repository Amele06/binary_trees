#include "binary_trees.h"

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: root node of the tree
* Return: 1 if tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree
* Return: height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
