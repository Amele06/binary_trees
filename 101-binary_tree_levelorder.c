#include "binary_trees.h"

levelorder_queue_t *create_queue_node(binary_tree_t *node);
void destroy_queue(levelorder_queue_t *head);
void push_queue(binary_tree_t *node, levelorder_queue_t *head, levelorder_queue_t **tail, void (*func)(int));
void dequeue(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_queue_node - Creates a new node for the level order queue.
 * @node: Pointer to the binary tree node to be stored in the new queue node.
 *
 * Return: Pointer to the newly created queue node, or NULL on failure.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
    levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
    if (new_node == NULL)
        return NULL;

    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/**
 * destroy_queue - Frees memory allocated for a level order queue.
 * @head: Pointer to the head of the queue.
 */
void destroy_queue(levelorder_queue_t *head)
{
    while (head != NULL)
    {
        levelorder_queue_t *temp = head;
		
        head = head->next;
        free(temp);
    }
}

/**
 * push_queue - Pushes a binary tree node onto a level order queue and applies a function to it.
 * @node: Pointer to the binary tree node to be pushed.
 * @head: Pointer to the head of the queue.
 * @tail: Pointer to the tail of the queue.
 * @func: Pointer to the function to be applied to the node.
 */
void push_queue(binary_tree_t *node, levelorder_queue_t *head, levelorder_queue_t **tail, void (*func)(int))
{
    if (node == NULL)
        return;

    func(node->n);

    if (node->left != NULL)
    {
        *tail = (*tail)->next = create_queue_node(node->left);
        if (*tail == NULL)
        {
            destroy_queue(head);
            exit(EXIT_FAILURE);
        }
    }

    if (node->right != NULL)
    {
        *tail = (*tail)->next = create_queue_node(node->right);
        if (*tail == NULL)
        {
            destroy_queue(head);
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * dequeue - Removes the front node from a level order queue.
 * @head: Pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
    if (*head == NULL)
        return;

    levelorder_queue_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level order, applying a function to each node.
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to the function to be applied to each node.
 */
void traverse_level_order(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    levelorder_queue_t *head = create_queue_node((binary_tree_t *)tree);
    if (head == NULL)
        return;

    levelorder_queue_t *tail = head;

    while (head != NULL)
    {
        push_queue(head->node, head, &tail, func);
        dequeue(&head);
    }

    destroy_queue(head);
}
