#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through
 * a binary tree using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/*traversing the left subtree*/
	binary_tree_postorder(tree->left, func);
	/*traversing the right subtree*/
	binary_tree_postorder(tree->right, func);
	/*the value in the node is passed as a parameter to this function*/
	func(tree->n);
}
