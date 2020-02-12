#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RAND_SIZE 256
#define SIZE 1000

void init_random(unsigned seed)
{
    static char rand_state[RAND_SIZE];
    initstate(seed, rand_state, RAND_SIZE);
}

//low inclusive high exclusive
int my_random(int low, int high)
{
    return (int) (low + random() % (high - low));
}

bool chance(double p)
{
    double r = my_random(1,1001)/1000.0;
    return r < p;
}

#endif /* RANDOMGENERATOR_H_ */
