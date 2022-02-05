#include <iostream>
using namespace std;
template<typename T>
class Tester {
public:
	Tester();
	Tester(T);
	Tester(T, unsigned);
	bool isTrue();
	~Tester();
private:
	long value;
	short oValue;
};