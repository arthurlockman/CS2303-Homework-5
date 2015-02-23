#include "queue.h"
#include <stdio.h>

/**
 * @brief Create a queue by allocating a queue structure,
 * initializing it, and initializing its entries so that it
 * can hold data.
 *
 * @param max_cells The maximum number of entries in the queue.
 *
 * @return Pointer to queue, NULL if error.
 */
Queue* create_queue(int max_cells)
{
    Queue *new_queue;
    new_queue = (Queue*)malloc(sizeof(Queue));
    if (new_queue == NULL) return NULL;

    new_queue->size = max_cells;
    new_queue->used = 0;

    new_queue->base = (void**)malloc(sizeof(void*) * max_cells);
    if (new_queue->base == NULL)
    {
        free(new_queue);
        return NULL;
    }

    new_queue->head = 0;
    new_queue->tail = max_cells - 1;
    return new_queue;
}

/**
 * @brief Deletes a queue, including the structure and the memory
 * for holding the queue entries, but not the entries themselves.
 * @param which Pointer to Queue structure.
 */
void delete_queue(Queue* which)
{
    free(which->base);
    free(which);
}

/** 
 * @brief Enqueue an element.
 * 
 * @param which The queue to add the element to.
 * @param ptr The element to add.
 * 
 * @return 0 if success, -1 if overflow.
 */
int enqueue(Queue* which, void *ptr)
{
    if (which->used == which->size)
    {
        return -1;
    }
    which->base[which->head] = ptr;
    if (which->head >= which->size - 1)
        which->head = 0;
    else
        which->head++;
    if (which->used < which->size)
        which->used++;
    return 0;
}

/** 
 * @brief Dequeues an element from a given queue. 
 * Returns a null pointer if there is an error
 * (nothing in queue).
 * 
 * @param which The queue to dequeue the element from.
 * 
 * @return Pointer to element, NULL if error.
 */
void* dequeue(Queue* which)
{
    if (which->used == 0)
        return NULL;
    which->used--;
    if (which->tail >= which->size - 1)
        which->tail = 0;
    else
        which->tail++;
    return which->base[which->tail];
}

