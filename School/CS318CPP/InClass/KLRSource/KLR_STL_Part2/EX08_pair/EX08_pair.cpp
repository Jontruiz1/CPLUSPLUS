//pair demo
#include <iostream> 
#include <utility> 
using namespace std;

int main()
{
	pair <int, string> p1;

	p1.first = 10;
	p1.second = "Toto";

	cout << "p1.first " << p1.first << endl;
	cout << "p1.second " << p1.second << endl;

	return 0;
}
