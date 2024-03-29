#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *pivot_pnt;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot_pnt = tree->right;
	temp = pivot_pnt->left;
	pivot_pnt->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivot_pnt;
	pivot_pnt->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivot_pnt;
		else
			temp->right = pivot_pnt;
	}

	return (pivot_pnt);
}
