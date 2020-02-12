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


//Creating new job structure to implement new jobs to be created
void newjobstuff(struct jobstuff *morestuff, int* name, int* time, int* ID)
{

	morestuff->_name = name;
	morestuff->time = time;
	morestuff->ID = ID;

}//creating a new job

//Method to print to the screen
void jobprint(struct jobstuff *stuff)
{
	printf("Name: %d\n, time: %d\n, ID: %d\n", stuff->_name, stuff->time, stuff->ID);
}//printing struct details


char *type_string(enum jobType type)
{
    switch (type)
    {
        case CPU_Arrival:
            return "CPU_Arrival";
        case CPU_Continue:
            return "CPU_Continue";
        case CPU_Begin:
            return "CPU_Begin";
        case CPU_Finish:
            return "CPU_Finish";
        case Exit:
            return "Exit";
        case SIM_END:
            return "Simulation End";
    }
}








#endif /* JOB_H_ */
