// Pointers
#include <iostream>
using namespace std;

int main()
{
    int x{ 20 };
    cout << "\nValue of x " << x << '\n';
    // address of
    cout << "Memory address of x " << &x << '\n';
    // dereference 
    cout << "Value at memory address of x " << *(&x) << '\n';

    int* ptr{ &x }; // initialize ptr with address of x

    cout << "\nAddress (value) in ptr " << ptr << '\n';
    cout << "Value at memory address held in ptr " << *ptr << '\n';

    cout << "\nAddress of variable ptr " << &ptr << '\n';

    cout << "\nWhat type is being pointed to by &x" << typeid(&x).name() << '\n';
    cout << "What type is being pointed to by ptr" << typeid(ptr).name() << '\n';

    double d1{ 5.7 };
    double d2{ 47.3 };
    double* dptr{ &d1 };

    cout << "\nAddress of d1 " << &d1 << '\n';
    cout << "Address (value) in dptr " << dptr << '\n';
    cout << "Value at memory address held in dptr " << *dptr << '\n';

    dptr = &d2;

    cout << "\nAddress of d2 " << &d2 << '\n';
    cout << "Address (value) in dptr " << dptr << '\n';
    cout << "Value at memory address held in dptr " << *dptr << '\n';

    return 0;
}