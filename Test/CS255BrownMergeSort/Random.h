//RANDOM.H
/*
    Random.h / Random.cpp
    Provide functions to seed randomizer, generate random int and float
    7.13.18
    dwbrown
*/
#if !defined NULL
#define NULL = 0;
#endif

#if !defined RANDOM_H
#define RANDOM_H

//Pre : None
//Post: Randomizer is seeded with the current time
void seedRandomizer();

//Pre : low and high are ints that define the range of random 
//        numbers. low is less than high
//Post: returns an integer that is between low (inclusive) 
//        and high (exclusive)
int generateRandomInt(int low, int high);

//Pre : low and high are floats that define the range of random 
//        numbers. low is less than high
//Post: returns a float that is between low (inclusive) 
//        and high (exclusive)
float generateRandomInt(float low, float high);

#endif
