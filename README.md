# ProjectONE

The purpose of this assignment is to gain some understanding of how processes move through a computing system and to put into practice some things that you've learned in 2107 and 2168, but might not have had a chance to use in a while.

In this assignment, you'll create a discrete event simulation (Links to an external site.) in C that models the very simplified machine pictured below. The diagram shows the flow of a process through the different states in its execution history. It also shows that a process must wait to use a resource if the resource is in use or busy.

### Implementation
Five non-trivial data structures:
- One FIFO queue for each component (CPU, disk1, disk2, network)
  - A priority queue used to store events:
    - Something like "a new job enetered the system"
    - "a disk read finished"
    - "a job finished at the CPU", etc
- Events should be removd from the priotity queue and processed based on the time that the event occurred.
  - Can be implemeneted as a sorted list or a minheap
- When the program begins, after initialization stes, it will add to the priority queue the arrival time of the first jon and the time the simulation should finish. 
  - if times are 0 and 100000 then it should be something like:
    - when  | what
    - 0     | job1 arrives
    - 100000| simulation finished
  - This example showes that we have to start to remove and process the events from the priority event queue. FIFO "job1 arrives" gets removed because it has the lowest time and the highest priority. To process this JOB_ARRIVAL_EVENT you:
    1. set the current time to 0, the time of the event we just removed of the queue
    2. determine the arrival time for the next job to enter the sstem and add it as an event to the priority        queue
    3. send job1 to the CPU
  - Determining the time of the next arrival, generate a random integer between ARRIVE_MIN and ARRIVE_MAX and then add it to the current time. that would be the time of the 2nd arrival 
- While the new arrival is being added to the queue we now need to add job1 to the CPU so it wont be idle.
  - At the time job1 finishes at the CPU we can generate a random integer between CPU_MIN and CPU_MAX and then add it to the current time.
    - when     ===|=== what
    - 15       ===|=== job2 arrives
    - 25       ===|=== job1 finishes at CPU
    - 100000   =|= simulation finished
- This proceeds the same way until the end of the priority queue when SIMULATION_FINISHED
- The main loop of the program would be a while loop, something like:
  - while the priority queue isn't empty
    - and while the simulation isn't finished:
      - read an event from the queue
        - handle event
- Each event in the event queue will be of a given type. The simplest way is to store these as named constants, e.g., CPU_FINISHED=1, DISK1_FINISHED=2, etc
  - Also writing handler function for each possible event type.
- The results of the program should:
  - write to a log file the values of each of the constants and the significant event 
  - calculate and print to the screen:
    - average and maximum size of each queue
    - utilization of each server(componenet):
      - time_the_server_is_busy/total_time where total_time = FIN_TIME-INIT_TIME
    - average and maximum response time of each server (response time will be the difference in time between the job arrival at a server and the completion of the job at the server)
    - The throughput(number of jobs completed per unit of time) of each server
- Run the program a number of times with different values for the parameters and a random seed.
- Examine how the utilizations relate to queue sizes
- Able to handle at least one thousane jobs
- Have a 2-3 pages README.txt files
- and a RUNS.txt file
      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
