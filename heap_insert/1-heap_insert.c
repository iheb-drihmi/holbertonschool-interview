#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
	* heap_insert - a function that inserts a value into a Max Binary Heap
	* @root: is a pointer to the root node of the node to create
	* @value: is the value to put in the new node
	* Return: the new node
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *node;

	new_node = malloc(sizeof(heap_t));

	if (new_node == NULL)
	{
		return NULL;
	}

	node = *root;
	/* define the new node */
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (*root == NULL) /* if no root, new node become the root */
	{
		*root = new_node;
		return (new_node);
	}

	*root = node;
	while (node->left != NULL || node->right != NULL)
	{
		if (new_node->n < node->n) /* if value of new node < node value */
		{
			if (node->left == NULL) /* insert new node if left is empty */
			{
				node->left = new_node;
				new_node->parent = node;
			}
			else if (node->left != NULL && node->right == NULL)
			{
				node->right = new_node;
				new_node->parent = node;
			}
		}
		else /*value > node new node replace it & node at left*/
		{
			new_node->left = node;
			new_node->right = NULL;
			node->parent = new_node;
			node = new_node->left;
		}
		return (new_node);
	}
	if (node->left == NULL)
	{
		node->left = new_node;
	}
	else
	{
		node->right = new_node;
	}
	new_node->parent = node;
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		int temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}
return (new_node);

}
