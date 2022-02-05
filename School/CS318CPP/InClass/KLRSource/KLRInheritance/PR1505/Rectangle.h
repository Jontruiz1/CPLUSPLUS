// Used with PR1505
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;
public:
    // Default constructor
    Rectangle()
    {
        cout << "\tRectangle no arg constructor" << endl;
        width = 0.0;
        length = 0.0;
    }

    // Constructor #2
    Rectangle(double w, double len)
    {
        cout << "\tRectangle 2 arg constructor" << endl; 
        width = w;
        length = len;
    }

    double getWidth() const
    {
        return width;
    }

    double getLength() const
    {
        return length;
    }

    double getArea() const
    {
        return width * length;
    }
};
#endif 