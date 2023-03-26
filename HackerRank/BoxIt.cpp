#include <fstream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


class Box{
public:    
  Box();
  Box(int, int, int);
  Box(Box&);
  
  int getLength();
  int getBreadth();
  int getHeight();
  long long CalculateVolume();
  
  bool operator<(Box& b);
private:
    int l, b, h;
};

Box::Box(){
    l = 0;
    b = 0;
    h = 0;
}
Box::Box(int x, int y, int z){
    l = x;
    b = y;
    h = z;
}

Box::Box(Box& c){
    l = c.l;
    b = c.b;
    h = c.h;
}

int Box::getLength(){
    return l;
}
int Box::getBreadth(){
    return b;
}
int Box::getHeight(){
    return h;
}

long long Box::CalculateVolume(){
    return (long long)l * (long long)b * (long long)h;
}

bool Box::operator<(Box& c){
    if(l < c.l) return true;
    if(b < c.b && l == c.l) return true;  
    if(h < c.h && b == c.b && l == c.l) return true;
    return false;   
}

ostream& operator<<(ostream& out, Box& B){
    out << B.getLength() << " ";
    out << B.getBreadth() << " ";
    out << B.getHeight();
    return out;
}


