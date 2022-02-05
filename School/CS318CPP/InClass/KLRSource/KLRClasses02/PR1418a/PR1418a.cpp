#include <iostream>
#include <string>
#include "MoveSemantics.h"
using namespace std;

// Function prototype
Person makePerson();
void displayPerson(Person);

int main()
{
	Person person;
	person = makePerson();
	displayPerson(person);
	return 0;
}

Person makePerson()
{
	char pStr[] = "Will MacKenzie";
	Person p(pStr);
	return p;
}

void displayPerson(Person p2)
{
	cout << p2.getName() << endl;
}