#include <stdio.h>

#include "utils.h"
#include "btree.h"

void load_default(struct BTree *btree)
{
    int data[10] = {5, 3, 4, 2, 7, 12, 8, 18, 6, 1};

    for (int i = 0; i < 10; ++i)
    {
        add_node(btree, data[i]);
    }

    puts("Successfully loaded defaults.");
}

void insert_pkg(struct BTree *btree)
{
    int key;
    char input_buffer[BUFFER_L];

    while (1)
    {
        puts("Please enter package key:");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        {
            printf("Error reading from standard input. Please try again\n");
            continue;
        }
        trim_newline(input_buffer);
        if (sscanf(input_buffer, "%d", &key) != 1)
        {
            printf("Error parsing input. Please try again.\n");
            continue;
        };
        if (key < 1)
        {
            printf("Value has to be positive integer. Please try again.\n");
            continue;
        }
        break;
    }

    add_node(btree, key);
    printf("Successfully added: %d\n", key);
}

static void print_node(struct Node *node, int depth)
{
    if (node == NULL)
    {
        return;
    }

    // traversing the tree in-order (left->node->right)
    // left
    if (node->left != NULL)
    {
        print_node(node->left, depth + 1);
    }

    // node
    for (int i = 0; i < depth; ++i)
    {
        putchar('\t');
    }
    printf("%d\n", node->value);

    // right
    if (node->right != NULL)
    {
        print_node(node->right, depth + 1);
    }
}

void print_tree(struct BTree *btree)
{
    if (btree->root == NULL)
    {
        printf("No packages yet. You can load defaults with 0) or add package with 1).\n");
        return;
    }

    print_node(btree->root, 0);
}

static void write_node(struct Node *node, FILE *file)
{
    if (node == NULL)
    {
        return;
    }

    // traversing the tree in-order (left->node->right)
    // left
    if (node->left != NULL)
    {
        write_node(node->left, file);
    }

    // node
    fprintf(file, "%p %d\n", (void *)node, node->value);

    // right
    if (node->right != NULL)
    {
        write_node(node->right, file);
    }
}

void get_manifest(struct BTree *btree)
{
    FILE *file = fopen("manifest", "w+");
    if (file == NULL)
    {
        puts("Error opening file. Please try again");
        return;
    }

    write_node(btree->root, file);

    fclose(file);

    puts("Successfully written to file `manifest`.");
}

void delete_pkg(struct BTree *btree)
{
    int key;
    char input_buffer[BUFFER_L];

    print_node(btree->root, 0);

    while (1)
    {
        puts("Please enter key to delete:");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        {
            printf("Error reading from standard input. Please try again\n");
            continue;
        }
        trim_newline(input_buffer);
        if (sscanf(input_buffer, "%d", &key) != 1)
        {
            printf("Error parsing input. Please try again.\n");
            continue;
        };

        break;
    }

    delete_node(btree->root, key);
    printf("Successfully deleted key %d (if it exists).", key);
}
