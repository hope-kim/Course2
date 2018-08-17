// ITP 365 Fall 2017
// HW2 – itpPhone
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac
//
// Calculator.cpp
// Implements Calculator class
//

#include "Calculator.h"

// Function: Constructor
// Purpose: Does nothing
Calculator::Calculator()
{
	
}

// Function: pushNum
// Purpose: Pushes number onto the stack
// Input: number to push
// Output: None
void Calculator::pushNum(int number)
{
	// TODO: Implement
    integers.push(number);
}

// Function: peekTop
// Purpose: Returns the number on top of the stack
//          (provided the stack is not empty)
// Input: None
// Output: Number on top of the stack
int Calculator::peekTop()
{
    int peek = -1;
    // TODO: Implement
    if (!integers.isEmpty())
    {
        peek = integers.peek();
    }
	
	return peek; // FIX TO RETURN CORRECT VALUE
}

// Function: doCalc
// Purpose: Performs the requested arithmetic,
//          provided there are two numbers on the stack.
//          Then pushes the result onto the stack.
//          Silently fails if the stack has less than two
//          numbers on it.
// Input: Type of arithmetic to perform
// Output: None
void Calculator::doCalc(CalcType type)
{
    // TODO: Implement
    if (integers.size() >= 2)
    {
        int second = integers.pop();
        int first = integers.pop();
        int result;
        
        switch(type)
        {
            case ADD:
                result = first + second;
                break;
            case SUB:
                result = first - second;
                break;
            case MUL:
                result = first * second;
                break;
            case DIV:
                result = first / second;
                break;
        }
        Calculator::pushNum(result);
    }
}
