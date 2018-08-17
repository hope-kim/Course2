// Name: Hope Kim
// Email: hopekim@usc.edu
// ITP 365 Fall 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac

#include "sieve.h"
#include <sstream>

// draws a 50x50 square
void drawSquare(GWindow& gw, int number, NumberType numberType, double x, double y)
{
    switch (numberType)
    {
        case UNKNOWN:
            gw.setColor("white");
            gw.fillRect(x, y, 50, 50);
            break;
        case PRIME:
            gw.setColor("green");
            gw.fillRect(x, y, 50, 50);
            break;
        case COMPOSITE:
            gw.setColor("red");
            gw.fillRect(x, y, 50, 50);
            break;
    }
    gw.setColor("black");
    gw.drawRect(x, y, 50, 50);
    gw.setColor("black");
    gw.drawLabel(integerToString(number), x+25, y+25);
}

void inItVectors(Vector<int>& testNumbers, Vector<NumberType>& flagNumbers)
{
    for (int i = 0; i < 100; i++)
    {
        testNumbers.add(i+2);
        flagNumbers.add(UNKNOWN);
    }
}
void drawGrid(GWindow& gw, Vector<int>& testNumbers, Vector<NumberType>& flagNumbers)
{
    double x = 0;
    double y = 0;
    for (int i = 0; i < testNumbers.size(); i++)
    {
        drawSquare(gw, testNumbers[i], flagNumbers[i], x, y);
        x += 50;
        
        if (x > 450)
        {
            x = 0;
            y += 50;
        }
    }
} 
int calcNextPrime(Vector<int>& testNumbers, Vector<NumberType>& flagNumbers, int startAt)
{
    int index = startAt - 2;
    int newPrime = -1;
    for (int i = index; i < flagNumbers.size(); i++)
    {
        if (flagNumbers[i] == UNKNOWN)
        {
            flagNumbers[i] = PRIME;
            newPrime = testNumbers[i];
            break;
        }
    }
    if (newPrime > 0)
    {
        for (int i = newPrime-1; i < flagNumbers.size(); i++)
        {
            if (testNumbers[i] % newPrime == 0)
            {
                flagNumbers[i] = COMPOSITE;
            }
        }
    }
    return newPrime;
    
}
