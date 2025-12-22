#include <stdio.h>

#include "utils.h"
#include "btree.h"
#include "logistics.h"

int main(void)
{
    int choice;
    char input_buffer[BUFFER_L];

    struct BTree *btree = init_btree();

    printf("\n"
           "Welcome to the \"package sorting\" (binary tree) app.\n"
           "Please see the menu for what you can do.\n");

    while (1)
    {
        printf("\n"
               "\n"
               "=== MENU ===\n"
               // TODO
               "0) Load example\t\t- adds packages {5, 3, 4, 2, 7, 12, 8, 18, 6, 1} to your current tree\n"
               "1) Add package\t\t- insert package into tree\n"
               "2) Print\t\t- print tree\n"
               "3) Get manifest\t\t- write list of packages to file\n"
               "4) Delete package\t- remove package from tree\n"
               "5) Exit\t\t\t- safely exit the program\n"
               "\n"
               "Enter your choice:\n");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("EOF detected, exiting.\n");
                return 0;
            }
            else
            {
                printf("Error reading from standard input, exiting with error.\n");
                return 1;
            }
        }
        trim_newline(input_buffer);
        if (sscanf(input_buffer, "%d", &choice) != 1)
        {
            printf("Error parsing input. Please try again.\n");
            continue;
        };

        switch (choice)
        {
        case 0:
            load_default(btree);
            break;
        case 1:
            insert_pkg(btree);
            break;
        case 2:
            print_tree(btree);
            break;
        case 3:
            get_manifest(btree);
            break;
        case 4:
            delete_pkg(btree);
            break;
        case 5:
            free_btree(btree);
            printf("Exiting. Bye!\n");
            return 0;
        default:
            printf("%d not an option. Please try again.\n", choice);
            break;
        }
    }

    return 0;
}
