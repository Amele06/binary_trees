#include "binary_trees.h"

/**
 * binary_tree_balance - computes the balance factor of the binary tree.
 * @tree: pointer to the root node of the tree to be measured
 *
 * Return: return 0 if tree is NULL, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree!= NULL)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - keeps count of the binary tree height.
 * @tree: pointer to the root node of the tree.
 *
 * Return: returns 0 when tree is NULL, otherwise, it returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        return (l > r ? l : r);
	}
	return (0);
}
