// Name: Hope Kim
// Email: hopekim@usc.edu
// ITP 365 Fall 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac

#include "gwindow.h"
#include "sieve.h"
#include "vector.h"

int main()
{
	// Create a 500x500 window
    GWindow gw(500, 500);
    NumberType numberType = PRIME;
    drawSquare(gw, 2, numberType, 0, 0);
    
    Vector<int> testNumbers;
    Vector<NumberType> flagNumbers;
    
    inItVectors(testNumbers, flagNumbers);
    
    // while loop redsult of calcNextPrime > 0
    // use result of calcNextPrime as the nextStartat
    int nextPrime = 2;
    while (nextPrime > 0)
    {
        nextPrime = calcNextPrime(testNumbers, flagNumbers, nextPrime);
        drawGrid(gw, testNumbers, flagNumbers);
        pause(10.0);
    }
    return 0;
}
