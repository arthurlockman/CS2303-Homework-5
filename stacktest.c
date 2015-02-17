#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
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

  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);

  return 0;
}
