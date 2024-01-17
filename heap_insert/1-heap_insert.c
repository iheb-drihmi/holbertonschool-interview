#include "binary_trees.h"


/**
 * swap - Swap the values of two nodes
 *
 * @a: First node
 * @b: Second node
 */
void swap(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_up - Reorganizes the heap,
 * starting from a given node, until the max heap
 * property is respected.
 *
 * @node: Pointer to the inserted node
 * Return: Node at the correct position
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * breadth_first_insert - Inserts a new node in widthwise order.
 * It uses a queue to store the nodes to be visited, and inserts
 * the new node at the first available location following this order.
 *
 * @root: Root of the heap
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *breadth_first_insert(heap_t *root, int value)
{
	heap_t **queue, *node, *new_node = NULL;
	size_t front = 0, rear = 0, q_capacity = 1024;

	queue = malloc(sizeof(*queue) * q_capacity);
	if (!queue)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		node = queue[front++];
		if (!node->left || !node->right)
		{
			new_node = binary_tree_node(node, value);
			if (!node->left)
			{
				node->left = new_node;
			}
			else
			{
				node->right = new_node;
			}
			break;
		}

		if (rear + 2 >= q_capacity)
		{
			q_capacity *= 2;
			queue = realloc(queue, sizeof(*queue) * q_capacity);
			if (!queue)
				return (NULL);
		}

		queue[rear++] = node->left;
		queue[rear++] = node->right;
	}

	free(queue);
	return (new_node);
}

/**
 * heap_insert - inserts a new node into the heap.
 * If the heap is empty, the new node becomes the root.
 * Otherwise, it uses breadth_first_insert to insert the new node,
 * then heapify_up to reorganize the heap.
 *
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	heap_t *inserted_node = breadth_first_insert(*root, value);

	return (heapify_up(inserted_node));
}
