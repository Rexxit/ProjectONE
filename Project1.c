/*
 * Project1.c
 *
 *  Created on: Feb 4, 2020
 *      Author: wild_
 */

#include <stdio.h>

// Global Definitions
#define MAX 100
int array_Queue[MAX];
int rear = - 1;
int front = - 1;


// Method Declarations
int readFile(char*);
void queueInsert();
void queueDelete();
void queueShow();

int main()
{

	/* disabling buffer for eclipse to actually use printf
	 * and scanf to show on the console. */
	setbuf(stdout, NULL);


	int choice;
	readFile("TextData.txt");

	while (1)
	{
		printf("\n1. Insert into queue\n");
		printf("2. Delete from queue\n");
		printf("3. Display queue\n");
		printf("4. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			queueInsert();
			break;
		case 2:
			queueDelete();
			break;
		case 3:
			queueShow();
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice");
		}//end switch()
	}//end while()

	return 0;

}//end main

int readFile(char* file1)
{
	// Declaring the FILE variable pointer
	FILE* fileP1;

	// Declaring the character variables
	char data[100];

	//Assigning fileOne and fileTwo to the two files and setting it to read only
	fileP1 = fopen(file1, "r");

	//Printing to the screen the file is opening
	//printf("Initializing and opening file..");

	//if statement  to check if the two files are empty or not
	if (fileP1 == NULL)
	{
		printf ("Cannot open file\n");
		exit(1);
	}//end if()
	else
	{
		while (fgets(data, 100, fileP1) != NULL)
		{
			printf("%s", data);
		}//end while()

	}//end else()


	fclose(fileP1);
	return 0;
}//end readAndWrite()









void queueInsert()
{
	int item_added;

	if (rear == MAX - 1)
	{
		printf("Queue overloaded\n");
	}//end if()
	else
	{
		if (front == - 1)
		{
			/*If queue is initially empty */
			front = 0;
		}
		printf("Insert the element in queue : ");
		scanf("%d", &item_added);
		rear = rear + 1;
		array_Queue[rear] = item_added;
		//printf ("rear: %d", rear);

	}//end else()
}//end queueInsert()

void queueDelete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }//end if()
    else
    {
        printf("Element deleted from queue is : %d\n", array_Queue[front]);
        front = front + 1;
    }//end else()
}//end queueDelete()

void queueShow()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", array_Queue[i]);
        printf("\n");
    }
} /* End of display() */
