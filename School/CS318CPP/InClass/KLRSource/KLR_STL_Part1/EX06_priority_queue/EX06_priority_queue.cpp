// Dog.h
#include <iostream> 
#include <queue> 
#include "Dog.h"
using namespace std;

int main()
{

	priority_queue<Dog> dog_pq;

	dog_pq.push(Dog("Bailey", "Wheaten", 5));
	dog_pq.push(Dog("Murphy", "Lab", 14));
	dog_pq.push(Dog("Floyd", "Beagle", 12));
	dog_pq.push(Dog("Guinness", "Wheaten", 9));
	dog_pq.push(Dog("Grimlock", "Lab", 2));
	dog_pq.push(Dog("Optimus", "Bulldog", 5));

	cout << "\nSize of dog_pq: " << dog_pq.size() << "\n\n";

	while (!dog_pq.empty()) {
		cout << dog_pq.top() << "\n";
		dog_pq.pop();
	}
	return 0;
}
