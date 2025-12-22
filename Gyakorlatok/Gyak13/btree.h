#ifndef BTREE_H
#define BTREE_H

struct Node
{
    int value;
    struct Node *left;  // has smaller value
    struct Node *right; // has bigger value
};

struct BTree
{
    struct Node *root;
};

struct BTree *init_btree(void);
void free_btree(struct BTree *btree);

void add_node(struct BTree *btree, int value);
struct Node *delete_node(struct Node *node, int key);

#endif
