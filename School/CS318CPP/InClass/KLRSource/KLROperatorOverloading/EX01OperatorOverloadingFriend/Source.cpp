// EX01OperatorOverloadingFriend
#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + c2.m_cents);
}

int main()
{
	Cents cents1(30);
	Cents cents2(8);
	Cents centsSum = cents1 + cents2;
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}