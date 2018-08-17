// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac

#include "Peg.h"
#include "Disk.h"

Peg::Peg()
{
    mX = 0;
    mY = 0;
    mWidth = 0;
    mHeight = 0;
    mColor = "black";
}

Peg::Peg(int inX, int inY, int inWidth, int inHeight, std::string inColor)
{
    mX = inX;
    mY = inY;
    mWidth = inWidth;
    mHeight = inHeight;
    mColor = inColor;
}

void Peg::draw(GWindow& gw)
{
    gw.setColor("black");
    gw.fillRect(300, 50, 10, 550);
    gw.setColor("black");
    gw.fillRect(600, 50, 10, 550);
    gw.setColor("black");
    gw.fillRect(900, 50, 10, 550);
    
    for (int i = 0; i < onPeg.size(); i++)
    {
        onPeg[i].draw(gw);
    }
}

void Peg::addDisk(Disk& input)
{
    onPeg.push_back(input);
}
Disk Peg::removeDisk()
{
    onPeg.pop_back();
    Disk retVal;
    retVal = onPeg.back();
    return retVal;
}


