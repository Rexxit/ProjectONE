#ifndef QUEUE_H_
#define QUEUE_H_

// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    queue->tail = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}//end Queue()

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue)
{  
	return (queue->queue_size == queue->capacity);  
}//end isFull()

// Queue is empty when queue_size is 0
int isEmpty(struct Queue* queue)
{  
	return (queue->queue_size == 0); 
}//end isEmpty()

// Function to add an item to the queue.
// It changes tail and queue_size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->tail = (queue->tail + 1)%queue->capacity;
    queue->array[queue->tail] = item;
    queue->queue_size = queue->queue_size + 1;
    printf("%d enqueued to queue\n", item);
}//end enqueue()

// Function to remove an item from queue.
// It changes head and queue_size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->head];
    queue->head = (queue->head + 1)%queue->capacity;
    queue->queue_size = queue->queue_size - 1;
    return item;
}//end dequeue()

// Function to get head of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->head];
}//end head()

// Function to get tail of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->tail];
}//end tail()



#endif /* QUEUE_H_ */
