// ITP 365 Fall 2017
// HW2 Towers of Hannoi
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac

#pragma once
#include <string>
#include "Disk.h"
#include <vector>
class Peg
{
private:
    std::vector<Disk> onPeg;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    std::string mColor;
public:
    Peg();
    Peg(int inX, int inY, int inWidth, int inHeight, std::string inColor);
    void draw(GWindow& gw);
    void addDisk(Disk& input);
    Disk removeDisk();
};
