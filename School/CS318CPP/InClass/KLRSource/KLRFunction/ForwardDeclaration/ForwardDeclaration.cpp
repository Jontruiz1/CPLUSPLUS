//ForwardDeclaration
#include <iostream>
using namespace std;

//int add(int x, int y); // declaration of add -- need function prototype

int main()
{
    int n{ 5 };
    int m{ 20 };
    cout << "The sum n and m is: " << add(n,m) << '\n'; 
    return 0;
}

int add(int x, int y) // definition of add
{
    return x + y;
}