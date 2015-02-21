#include "queue.h"
#include <stdio.h>

typedef struct
{
    int x;
    double y;
} Foo;

int main(void)
{
    Queue* q = create_queue(10);
    
    Foo* new_foo1;
    Foo* new_foo2;
    Foo* returned_foo;
    new_foo1 = (Foo*)malloc(sizeof(Foo));
    new_foo1->x = 3;
    new_foo1->y = 34.2;
    new_foo2 = (Foo*)malloc(sizeof(Foo));
    new_foo2->x = 4;
    new_foo2->y = 36.2;
    
    enqueue(q, new_foo1);
    enqueue(q, new_foo1);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    returned_foo = (Foo*)dequeue(q);
    printf("%p, %d, %d, %d\n", returned_foo, q->used, q->head, q->tail);
    returned_foo = (Foo*)dequeue(q);
    printf("%p, %d, %d, %d\n", returned_foo, q->used, q->head, q->tail);
    returned_foo = (Foo*)dequeue(q);
    printf("%p, %d, %d, %d\n", returned_foo, q->used, q->head, q->tail);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo2);
    enqueue(q, new_foo2);
    returned_foo = (Foo*)dequeue(q);
    printf("%p, %d, %d, %d\n", returned_foo, q->used, q->head, q->tail);
    returned_foo = (Foo*)dequeue(q);
    printf("%p, %d, %d, %d\n", returned_foo, q->used, q->head, q->tail);
    
    delete_queue(q);
    free(new_foo2);
    free(new_foo1);
}

