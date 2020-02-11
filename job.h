/*
 * job.h
 *
 *  Created on: Feb 10, 2020
 *      Author: wild_
 */



#ifndef JOB_H_
#define JOB_H_


struct jobstuff
{
	int _name;
	int time;
	int ID;
};


void jobprint(struct jobstuff *stuff)
{
	printf("Name: %d\n, time: %d\n, ID: %d\n", stuff->_name, stuff->time, stuff->ID);
}//printing struct details


//Creating new job structure to implement new jobs to be created
void newjobstuff(struct jobstuff *morestuff, int* name, int* time, int* ID)
{

	morestuff->_name;
	morestuff->time;
	morestuff->ID;

}//creating a new job


















#endif /* JOB_H_ */
