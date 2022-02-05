// Used with PR1505
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include "Rectangle.h"
using namespace std;

class Box : public Rectangle
{
protected:
    double height;
    double volume;
public:
    // Default constructor
    Box() : Rectangle()
    {
        cout << "\tBox no arg constructor" << endl;
        height = 0.0; volume = 0.0;
    }

    // Constructor #2 -- Specifies base class constructor to use
    Box(double w, double len, double h) : Rectangle(w, len)
    {
        cout << "\tBox 2 arg constructor" << endl; 
        height = h;
        volume = getArea() * h;
    }

    double getHeight() const
    {
        return height;
    }

    double getVolume() const
    {
        return volume;
    }
};
#endif
