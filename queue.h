#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

/** 
 * @brief Struct for holding a queue.
 */
typedef struct
{
    size_t size; ///< Size of head
    size_t head; ///< Pointer to head of queue
    size_t tail; ///< Pointer to tail of queue
    void** base; ///< Pointer to the base of the queue
    size_t used; ///< Number of cells used
} Queue;

Queue* create_queue(int max_cells);
void delete_queue(Queue* which);
int enqueue(Queue* which, void *ptr);
void* dequeue(Queue* which);

#endif

