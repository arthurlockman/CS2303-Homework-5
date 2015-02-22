#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This program creates a node and adds data using the 
 * add_tnode function, which keeps all data in the proper
 * order. It then prints this in descending order. It 
 * then creates a node with random data and random
 * children, and prints that to verify the sort order.
 */
int main(void)
{
    srand(time(NULL));
    printf("Printing premade tree:\n");
    Tnode* root = add_tnode(NULL, "Mr. Frond"); 
    add_tnode(root, "Jimmy");
    add_tnode(root, "Bob");
    add_tnode(root, "Linda");
    add_tnode(root, "Gene");
    add_tnode(root, "Louise");
    add_tnode(root, "Tina");

    print_tnode(root);
    
    printf("\nPrinting random tree:\n");
    Tnode* root2 = add_tnode(NULL, make_random_string(10));
    int i;
    for (i = 0; i < 20; i++)
        add_tnode(root2, make_random_string(10));
    print_tnode(root2);

    printf("\nFreeing nodes...\n");
    free_tnode(root);
    free_tnode(root2);
}

