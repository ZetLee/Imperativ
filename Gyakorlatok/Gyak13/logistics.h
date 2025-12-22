#ifndef LOGISTICS_H
#define LOGISTICS_H

void load_default(struct BTree *btree);
void insert_pkg(struct BTree *btree);
void print_tree(struct BTree *btree);
void get_manifest(struct BTree *btree);
void delete_pkg(struct BTree *btree);

#endif
