#ifndef BOX_H
#define BOX_H

#include <iostream>
using namespace std;

class Box {

private:
    double length = 0;
    double width = 0;
    double height = 0;

public:
    Box() {}
    Box(double l, double w, double h) : length{ l }, width{ w }, height{ h } {}
    Box(const Box& b) : length(b.length), width(b.width), height(b.height) {} //Copy constructor

    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    double getVolume() const {
        return length * width * height;
    }

    // Overload += operator
    Box& operator+=(const Box& b) {
        length += b.length;
        width += b.width;
        height += b.height;
        return *this;
    }

};

ostream& operator<<(ostream& output, const Box& b) {
    output << "length=" << b.getLength()
        << " width=" << b.getWidth()
        << " height=" << b.getHeight()
        << " volume=" << b.getVolume();
    return output;
}
#endif
