// ITP 365 Fall 2017
// HW2 Towers of Hannoi
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac

#pragma once
#include "gwindow.h"
#include <string>

class Disk
{
private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    std::string mColor;
public:
    Disk();
    Disk(int mX, int mY, int mWidth, int mHeight, std::string mColor);
    void setX(int inX);
    void setY(int inY);
    int getHeight();
    void draw(GWindow& gw);
};
