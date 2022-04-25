#include <iostream>

class Mage {
public:
	void virtual spell() {
		std::cout << "Fireball!!";
	}
};


class Necromancer : public Mage {
public:
	void spell() {
		std::cout << "Rise from the dead";
	}
};

int main() {
	Mage* p1 = new Mage();
	p1 = new Necromancer;
	p1->spell();

	delete p1;
}