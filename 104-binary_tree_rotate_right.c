#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	new_root = tree->left;

	/* assigments of parents */
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (new_root->right)
		(new_root->right)->parent = tree;

	/* assigments of childs */
	tree->left = new_root->right;
	new_root->right = tree;

	return (new_root);
}
