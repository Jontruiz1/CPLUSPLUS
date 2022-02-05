//EX05SharedPtr
#include <iostream> 
#include <memory> 
using namespace std;

class Dog {
public:
    void dogMessage(string str)
    {
        cout << str << " is the best!!" << endl;
    }
};

int main()
{
    shared_ptr<Dog> p1(new Dog);
    cout << "Memory address in p1: " << p1.get() << endl;
    p1->dogMessage("p1: Bailey");
    shared_ptr<Dog> p2(p1);
    cout << "\nMemory address in p2: " << p2.get() << endl;
    p2->dogMessage("p2: Murphy");

    // Returns the number shared_ptr objects pointing to same resource 
    cout << "\nReference count for resource pointed to by p1: " << p1.use_count() << endl;
    cout << "Reference count for resource pointed to by p2: " << p2.use_count() << endl;


    // p1 relinquishes ownership of the object, pointer becomes NULL 
    p1.reset();
    cout << "\nAfter p1 resets: " <<  endl;
    cout << "\tMemory address in p1: " << p1.get() << endl;
    cout << "\tMemory address in p2: " << p2.get() << endl;
    cout << "\tReference count for resource pointed to by p2: " << p2.use_count() << endl;

    // when function ends, p2 goes out of scope and resource being pointed to is deleted

    cin.get();
    return 0;
}
