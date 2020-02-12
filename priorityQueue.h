#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 15
#define QUEUE_NUM 3

//Declarations
void pqInsert(int, QUEUE*);
void pqDelete(QUEUE*);
int pqEmpty(QUEUE*);
int pqFull(QUEUE*);
void pqDisplay(QUEUE*);


struct priorityQueue
{
	int items[10];
	int head;
	int tail;
};

typedef struct priorityQueue QUEUE;

//Inserting a job to the queue
void pqInsert(int item, QUEUE *pq)
{
	//checking if the priority queue is full
	if(pqFull(pq))
	{
		printf("Queue insertion not possible\n");
		return;
	}//end if()
	
	pq->tail++;
	pq->items[pq->tail] = item;
}//end pqInsert()

//Deleting from the front of the priority queue which is the priority
void pqDelete(QUEUE *pq)
{
	int item_deleted;
	
	if(pqempty(pq))
	{
		printf("Queue is empty\nDeletion not possible\n");
		return;
	}//end if()
	
	item_deleted = pq->items[pq->head];
	pq->head++;
	
	printf("The element deleted is:\t%d\n", item_deleted);
	
	if(pq->head > pq->tail)
	{
		pq->head = 0;
		pq->tail = -1;
	}//end if()
}//end pqDelete()

//Checking to see if the priority queue is empty
int pqEmpty(QUEUE *pq)
{
	return (pq->head > pq->tail) ? 1 : 0;
}//end pqEmpty()

//Checking to see if the priority queue is full
int pqFull(QUEUE *pq)
{
	return (pq->tail == QUEUE_SIZE - 1) ? 1 : 0;
}//end pqFull()


//displaying the queue to the screen
void pqDisplay(QUEUE *q)
{
	if(pqEmpty(q))
	{
		printf("Queue is empty\nNo elements to pqDisplay\n");
		return;
	}//end if()
	
	printf("The contents of priorityQueue are:\n");
	
	for(int i = q->head; i <= q->tail; i++)
	{
		printf("%d\n", q->items[i]);
	}//end for()
}//end pqDisplay()


#endif /* PRIORITYQUEUE_H_ */
