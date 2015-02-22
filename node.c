#include "node.h"

/**
 * @brief This function inserts a node at a specific point in a
 * tree of Tnodes. If the pointer in current_tnode is null, the
 * function will allocate and return a new node. If not null, it
 * will insert the node at the appropriate position in the tree
 * and return the root pointer of the tree. If the data is already
 * in the tree, it will not be added again.
 *
 * @param current_tnode The node to add to.
 * @param value The string to add to the node.
 *
 * @return The root node if current_tnode is non-null, or a new
 * pointer to a node if current_tnode is null.
 */
Tnode *add_tnode(Tnode *current_tnode, char* value)
{
    if (current_tnode == NULL)
    {
        Tnode* new_node = (Tnode*)malloc(sizeof(Tnode));
        new_node->data = strdup(value);
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else
    {
        if (strcmp(current_tnode->data, value) > 0)
            current_tnode->left = add_tnode(current_tnode->left, value);
        else if (strcmp(current_tnode->data, value) < 0)
            current_tnode->right = add_tnode(current_tnode->right, value);
    }
    return current_tnode;
}

/**
 * @brief Prints a tnode and all sub-nodes in descending order.
 * Uses in-order traversal.
 *
 * @param current_tnode The node to print.
 */
void print_tnode(Tnode *current_tnode)
{
    if (current_tnode->left != NULL) print_tnode(current_tnode->left);
    printf("%s\n", current_tnode->data);
    if (current_tnode->right != NULL) print_tnode(current_tnode->right);
}

/*
 * @brief Gets a random string of specified length.
 * Returns a string that contains only the capital;
 * letters A-Z.
 *
 * @param length The length of the random string.
 *
 * @return A pointer to the random string.
 */
char* make_random_string(size_t length)
{
    char* rand_str = (char *)malloc(length + 1);
    size_t i;
    for (i = 0; i < length; i++)
    {
        *(rand_str + i) = get_random_char();
    }
    *(rand_str + length) = '\0';
    return rand_str;
}

/**
 * @brief Gets a random character from A-Z.
 *
 * @return The random character.
 */
char get_random_char()
{
    double randd = (double)rand() / RAND_MAX;
    return (char)(26 * randd + 65);
}

