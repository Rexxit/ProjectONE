/*
 * Project1.c
 *
 *  Created on: Feb 4, 2020
 *      Author: wild_
 */

#include <stdio.h>
#include <stdlib.h>

// Global Definitions
int SEED = 89;
int INIT_TIME = 0;
int FIN_TIME = 100000;
int ARRIVE_MIN = 17;
int ARRIVE_MAX = 23;
int QUIT_PROB = 45;
int NETWORK_PROB = 76;
int CPU_MIN = 59;
int CPU_MAX = 200;
int DISK1_MIN = 2;
int DISK1_MAX = 33;
int DISK2_MIN = 4;
int DISK2_MAX = 88;
int NETWORK_MIN = 99;
int NETWORK_MAX = 323;


// Method Declarations
//int readFile(char*);


int main()
{

	/* disabling buffer for eclipse to actually use printf
	 * and scanf to show on the console. */
	setbuf(stdout, NULL);





}//end main

/*
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
		for (int i = 0; i < sizeof(data); i++)
		{
			printf("Data at ")
		}

	}//end else()


	fclose(fileP1);
	return 0;
}//end readAndWrite()
*/

