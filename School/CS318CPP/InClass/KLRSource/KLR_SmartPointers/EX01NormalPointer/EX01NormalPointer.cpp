//EX01NormalPointer
//  Demonstrates memory leak
#include <iostream> 
using namespace std;

class Rectangle {
private:
    int length;
    int width;
};

void makeRec()
{
    // creates a new pointer and rectanble object
    Rectangle* p = new Rectangle();
    // since p is local it will get deleted 
    //  BUT not what it is pointing to ... memory leak
}

int main()
{
    // Infinite Loop
    int count = 1;
    while (true) {
        makeRec();
        printf("Number of rectangles created %d\n", count);
        count++;
    }
}
