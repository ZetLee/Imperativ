#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

static struct Node *init_node(void)
{
    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
    {
        printf("Error allocating memory.\n");
        return NULL;
    }

    return node;
}

void free_node(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    // NOTE:    We are just freeing up memory, we don't have to handle the parent's
    //          left/right pointers dangling, since nothing dereferences them once the
    //          memory is freed up.
    //          The recursive call order ensures that the deepest, left-most node is
    //          freed up one after the other. E.g. for {8, 10, 3, 14, 1, 13, 6, 4, 7}
    //          the call order is 1 -> 4 -> 7 -> 6 -> 3 -> 13 -> 14 -> 10 -> 8.
    //          This will traverse the tree and free all nodes.
    //
    // traversing the tree post-order (node->left->right)
    free_node(node->left);
    free_node(node->right);

    free(node);
}

struct BTree *init_btree(void)
{
    struct BTree *btree = calloc(1, sizeof(struct BTree));
    if (btree == NULL)
    {
        printf("Error allocating memory.\n");
        return NULL;
    }

    return btree;
}

void free_btree(struct BTree *btree)
{
    if (btree == NULL)
    {
        return;
    }

    if (btree->root != NULL)
    {
        free_node(btree->root);
    }

    free(btree);
}

static void insert_node(struct Node *node, struct Node *tree_node)
{
    struct Node *left = tree_node->left;
    struct Node *right = tree_node->right;

    // NOTE:    We ignore the `node->value == tree_node->value` case
    //          because that value then is already a member of the tree
    //
    // move left
    if (node->value < tree_node->value && left != NULL)
    {
        insert_node(node, left);
    }

    // insert left
    if (node->value < tree_node->value && left == NULL)
    {
        tree_node->left = node;
        return;
    }

    // move right
    if (tree_node->value < node->value && right != NULL)
    {
        insert_node(node, right);
    }

    // insert right
    if (tree_node->value < node->value && right == NULL)
    {
        tree_node->right = node;
        return;
    }
}

void add_node(struct BTree *btree, int value)
{
    struct Node *node = init_node();
    node->value = value;

    if (btree->root == NULL)
    {
        btree->root = node;
        return;
    }

    insert_node(node, btree->root);
}

static struct Node *find_min_succ(struct Node *node)
{
    while (node != NULL && node->left != NULL)
    {
        node = node->left;
    }

    return node;
}

struct Node *delete_node(struct Node *node, int key)
{
    if (node == NULL)
    {
        // no key value in tree runs into this
        return NULL;
    }

    // find node with key value
    if (key < node->value)
    {
        node->left = delete_node(node->left, key);
    }
    else if (node->value < key)
    {
        node->right = delete_node(node->right, key);
    }
    else
    {
        // no child
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        // single child
        else if (node->left == NULL)
        {
            struct Node *tmp = node->right;
            free(node);
            return tmp;
        }
        else if (node->right == NULL)
        {
            struct Node *tmp = node->left;
            free(node);
            return tmp;
        }
        // two children
        struct Node *tmp = find_min_succ(node->right);
        node->value = tmp->value;
        node->right = delete_node(node->right, tmp->value);
    }

    return node;
}
