#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct
{
    int x;
    double y;
} Foo; // Just some arbitrary struct


int main()
{
    const int max_entries = 5; // size of stack
    Foo* new_foo1;
    Foo* new_foo2;
    Foo* new_foo3;
    Foo* new_foo4;
    Foo* returned_foo;

    // First, create a stack
    Stack *new_stack = create_stack(max_entries);

    // Allocate a Foo and push it onto the stack.
    new_foo1 = (Foo *) malloc(sizeof(Foo));
    new_foo1->x = 6;
    new_foo1->y = 14.79;
    printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
    push(new_stack, (void *) new_foo1);

    // Allocate another Foo and push it onto the stack.
    new_foo2 = (Foo *) malloc(sizeof(Foo));
    new_foo2->x = 217;
    new_foo2->y = 3.14159;
    printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
    push(new_stack, (void *) new_foo2);

    // Peek at the top of the stack
    returned_foo = (Foo *) peek(new_stack);
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

    // Retrieve the Foos and print them.
    returned_foo = (Foo *) pop(new_stack);
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
    returned_foo = (Foo *) pop(new_stack);
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

    //Testing stack ordering
    new_foo3 = (Foo *)malloc(sizeof(Foo));
    new_foo4 = (Foo *)malloc(sizeof(Foo));
    new_foo3->x = 34;
    new_foo3->y = 34.0;
    new_foo4->x = 5023;
    new_foo4->y = 10.0;

    printf("\nVerifying push and pop order.\n");
    if (push(new_stack, new_foo3) == 0)
        printf("Pushed:  x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
    if (push(new_stack, new_foo4) == 0)
        printf("Pushed:  x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
    returned_foo = (Foo*)pop(new_stack);
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
    if (returned_foo == new_foo4) printf("Order matches for new_foo4.\n");
    returned_foo = (Foo*)pop(new_stack);
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
    if (returned_foo == new_foo3) printf("Order matches for new_foo3.\n");

    printf("\nVerifying stack overflow condition.\n");
    int i;
    for (i = 0; i < 7; i++)
    {
        int ret = push(new_stack, new_foo3);
        printf("Pushed %d elements, got return value %d.\n", i + 1, ret);
        printf("Pushed:  x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
        if (i >= 5 && ret == -1) printf("Got correct return value for overflow.\n");
    }
    printf("\nVerifying stack underflow condition.\n");
    for (i = 0; i < 7; i++)
    {
        returned_foo = (Foo*)pop(new_stack);
        printf("Popped %d elements, got return value %p.\n", i + 1, returned_foo);
        if (returned_foo != NULL) printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
        if (i >= 5 && returned_foo == NULL) printf("Got correct return value for underflow.\n");
    }

    // Clean up
    delete_stack(new_stack);
    free(new_foo1);
    free(new_foo2);
    free(new_foo3);
    free(new_foo4);

    return 0;
}

