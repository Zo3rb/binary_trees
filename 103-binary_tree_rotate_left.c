#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	new_root = tree->right;

	/* assigments of parents */
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (new_root->left)
		(new_root->left)->parent = tree;

	/* assigments of childs */
	tree->right = new_root->left;
	new_root->left = tree;

	return (new_root);
}
