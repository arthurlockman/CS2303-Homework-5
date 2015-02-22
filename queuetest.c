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
    Foo* new_foo3;
    Foo* new_foo4;
    Foo* returned_foo;
    new_foo1 = (Foo*)malloc(sizeof(Foo));
    new_foo1->x = 3;
    new_foo1->y = 34.2;
    new_foo2 = (Foo*)malloc(sizeof(Foo));
    new_foo2->x = 4;
    new_foo2->y = 36.2;
    new_foo3 = (Foo*)malloc(sizeof(Foo));
    new_foo3->x = 5;
    new_foo3->y = 9.2;
    new_foo4 = (Foo*)malloc(sizeof(Foo));
    new_foo4->x = 6;
    new_foo4->y = 2.2;
    
    //Verifying dequeueing empty queue return
    if (dequeue(q) == NULL)
        printf("Empty dequeue successfully returned null.\n");

    //Verifying overflow condition
    int i;
    for (i = 0; i < 11; i++)
    {
        if (enqueue(q, new_foo1) == -1 && i > 9)
            printf("Overflow correctly returned -1.\n");
    }

    //Verifying proper dequeue
    for (i = 0; i < 10; i++)
        dequeue(q);
    if (q->used == 0)
        printf("Queue emptied successfully.\n");

    //Verify order preservation (FIFO)
    enqueue(q, new_foo1);
    enqueue(q, new_foo2);
    enqueue(q, new_foo3);
    enqueue(q, new_foo4);

    if (dequeue(q) == new_foo1)
        printf("New foo 1 dequeued in correct order.\n");
    if (dequeue(q) == new_foo2)
        printf("New foo 2 dequeued in correct order.\n");
    if (dequeue(q) == new_foo3)
        printf("New foo 3 dequeued in correct order.\n");
    if (dequeue(q) == new_foo4)
        printf("New foo 4 dequeued in correct order.\n");
    
    delete_queue(q);
    free(new_foo2);
    free(new_foo1);
    free(new_foo3);
    free(new_foo4);
}

