// ITP 365 Fall 2017
// HW2 Towers of Hannoi
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac

#include "Disk.h"
#include <string>
#include "gwindow.h"

Disk::Disk()
{
    mX = 0;
    mY = 0;
    mWidth = 0;
    mHeight = 0;
    mColor = "black";
}
Disk::Disk(int inX, int inY, int inWidth, int inHeight, std::string inColor)
{
    mX = inX;
    mY = inY;
    mWidth = inWidth;
    mHeight = inHeight;
    mColor = inColor;
}

void Disk::setX(int inX)
{
    mX = inX;
}
void Disk::setY(int inY)
{
    mY = inY;
}
int Disk::getHeight()
{
    return mHeight;
}
void Disk::draw(GWindow& gw)
{
    gw.setColor(mColor);
    gw.fillRect(mX, mY, mWidth, mHeight);
}
