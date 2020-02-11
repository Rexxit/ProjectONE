#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 15
#define QUEUE_NUM 3

struct queue
{
	int items[10];
	int head;
	int tail;
};
typedef struct priorityQueue QUEUE;

int pqempty(QUEUE *pq)
{
	return (pq->head > pq->tail) ? 1 : 0;
}

int pqfull(QUEUE *pq)
{
	return (pq->tail == QUEUE_SIZE - 1) ? 1 : 0;
}

void insert_rear(int item, QUEUE *pq)
{
	if(pqfull(pq))
	{
		printf("Queue insertion not possible\n");
		return;
	}
	
	pq->tail++;
	pq->items[pq->tail] = item;
}

void delete_front(QUEUE *pq)
{
	int item_deleted;
	
	if(pqempty(pq))
	{
		printf("Queue is empty\nDeletion not possible\n");
		return;
	}
	
	item_deleted = pq->items[pq->head];
	pq->head++;
	
	printf("The element deleted is:\t%d\n", item_deleted);
	
	if(pq->head > pq->tail)
	{
		pq->head = 0;
		pq->tail = -1;
	}
}

void display(QUEUE *q)
{
	int i;
	
	if(pqempty(q))
	{
		printf("Queue is empty\nNo elements to display\n");
		return;
	}
	
	printf("The contents of priorityQueue are:\n");
	
	for(i = q->head; i <= q->tail; i++)
	{
		printf("%d\n", q->items[i]);
	}
}




#endif /* PRIORITYQUEUE_H_ */
