#ifndef NODE_H
#define NODE_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Tnode Tnode;

struct Tnode
{
    char* data;
    Tnode* left;
    Tnode* right;
};

Tnode *add_tnode(Tnode *current_tnode, char* value);
void print_tnode(Tnode *current_tnode);
char* make_random_string(size_t length);
char get_random_char();
void free_tnode(Tnode *current_tnode);

#endif

