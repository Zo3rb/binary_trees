#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the size of @tree, otherwise 0 if is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
	return (size);
}

/**
 * is_complete - algorithm of binary_tree_is_complete function
 * @tree: pointer to the root node
 * @index: index of the node
 * @nb_nodes: size of the binary tree
 *
 * Return: 1 if the binary tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nb_nodes)
{
	int left_complete, right_complete;

	if (!tree)
		return (1);
	if (index >= nb_nodes)
		return (0);
	left_complete = is_complete(tree->left, 2 * index + 1, nb_nodes);
	right_complete = is_complete(tree->right, 2 * index + 2, nb_nodes);
	return (left_complete && right_complete);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if the binary tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nb_nodes;

	if (!tree)
		return (0);

	nb_nodes = binary_tree_size(tree);
	return (is_complete(tree, 0, nb_nodes));
}
