#ifndef DOG_H
#define DOG_H
#include <iostream> 
#include <queue> 
using namespace std;

class Dog {
private:
	string name;
	string breed;
	int age;

public:
	// this is used to initialize the variables of the class 
	Dog(string name = "", string breed = "", int age = 0)
		: name(name), breed(breed), age(age) {}

	string getName() const { return name; }

	string getBreed() const { return breed; }

	int getAge() const { return age; }
};

//// operator overloading
//bool operator<(const Dog& d1, const Dog& d2) {
//	// returns true when d2's age is greater than d1's age
//	// the object with max age will be at the top
//	return d1.getAge() < d2.getAge();
//}

// operator overloading
bool operator<(const Dog& d1, const Dog& d2) {
	// returns true when d2's name is greater than d1's name
	// the object with max name will be at the top
	return d1.getName() < d2.getName();
}

ostream& operator<<(ostream& out, const Dog& d) {
	out << d.getName() << ", " << d.getBreed() << ", " << d.getAge() << "\n";
	return out;
}
#endif


