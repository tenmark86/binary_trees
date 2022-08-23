#include "binary_trees.h"

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: pointer to the parent node of the node to create
 *@value: is the value to put in the new node
 *Return: poiter to the new node or NULL in failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = NULL;

	if (parent == NULL)
		return (NULL);

	temp = (binary_tree_t *) malloc(sizeof(binary_tree_t));

	if (!value)
		return (NULL);

	if (temp == NULL)
		return (NULL);

	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;

	if (parent->right != NULL)
	{
		temp->right = parent->right;
		parent->right->parent = temp;
		parent->right = temp;
		temp->parent = parent;
	}
	else
	{
		temp->parent = parent;
		parent->right = temp;
	}
	return (temp);
}
