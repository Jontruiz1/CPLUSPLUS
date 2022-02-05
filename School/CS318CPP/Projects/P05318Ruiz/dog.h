#ifndef DOG_H
#define DOG_H
#include <iostream>

using namespace std;

class dog {

private:
	string name;
	string breed;
	int age;

public:
	// this is used to initialize the variables of the class
	dog(string name = "", string breed = "", int age = 0)

		: name(name), breed(breed), age(age) {}

	string getName() const { return name; }

	string getBreed() const { return breed; }

	int getAge() const { return age; }

	void setBreed(string breed) { this->breed = breed; }

	void setAge(int age) { this->age = age; }

};



// NOTE -- THIS SHOULD BE MODIFIED SLIGHTLY as in don't modify it

ostream& operator<<(ostream& out, const dog& d) {

	out << endl;
	out << "    " << d.getName() << ", " << d.getBreed() << ", " << d.getAge();
	return out;

}

#endif







