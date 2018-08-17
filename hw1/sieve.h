// Name: Hope Kim
// Email: hopekim@usc.edu
// ITP 365 Fall 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac

#pragma once
#include "gwindow.h"

enum NumberType
{
    UNKNOWN,
    PRIME,
    COMPOSITE,
};


void drawSquare(GWindow& gw, int number, NumberType numberType, double x, double y);

void inItVectors(Vector<int>& testNumbers, Vector<NumberType>& flagNumbers);

int calcNextPrime(Vector<int>& testNumbers, Vector<NumberType>& flagNumbers, int startAt);

void drawGrid(GWindow& gw, Vector<int>& testNumbers, Vector<NumberType>& flagNumbers);
