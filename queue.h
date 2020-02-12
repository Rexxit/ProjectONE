#ifndef QUEUE_H_
#define QUEUE_H_

// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Declarations
int qFull(struct Queue*);
int qEmpty(struct Queue*);
void qInsert(struct Queue*, int);
void qDelete(struct Queue*);
int qHead(struct Queue*);
int qTail(struct Queue*);


// A structure to represent a queue
struct Queue
{
    int head, tail, queue_size;
    unsigned capacity;
    int* array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->head = queue->queue_size = 0;
    queue->tail = capacity - 1;  // This is important, see the qInsert
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}//end Queue()

// Queue is full when size becomes equal to the capacity
int qFull(struct Queue* queue)
{  
	return (queue->queue_size == queue->capacity);  
}//end qFull()

// Queue is empty when queue_size is 0
int qEmpty(struct Queue* queue)
{  
	return (queue->queue_size == 0); 
}//end qEmpty()

// Function to add an item to the queue.
// It changes tail and queue_size
void qInsert(struct Queue* queue, int item)
{
    if (isFull(queue))
    {
        return;
    }
    queue->tail = (queue->tail + 1)%queue->capacity;
    queue->array[queue->tail] = item;
    queue->queue_size = queue->queue_size + 1;
    printf("%d enqueued to queue\n", item);
}//end qInsert()

// Function to remove an item from queue.
// It changes head and queue_size
int qDelete(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        return INT_MIN;
    }
    int item = queue->array[queue->head];
    queue->head = (queue->head + 1)%queue->capacity;
    queue->queue_size = queue->queue_size - 1;
    return item;
}//end qDelete()

// Function to get head of queue
int qHead(struct Queue* queue)
{
    if (qEmpty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->head];
}//end qHead()

// Function to get tail of queue
int qTail(struct Queue* queue)
{
    if (qEmpty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->tail];
}//end qTail()



#endif /* QUEUE_H_ */
