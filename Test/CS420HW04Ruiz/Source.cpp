#include <iostream>

using namespace std;

class Bsemaphore {
private:
	int bit = 0;

public:
	Bsemaphore() {
		bit = 0;
	}
	void down() {
		bit = 0;
	}
	void up() {
		bit = 1;
	}
	int get() {
		return bit;
	}
};


class Csemaphore{
private:
	int count;
	Bsemaphore m(1);
	Bsemaphore b(0);

public:
	Csemaphore(int init) {
		count = init;
	}
	void down() {
		// enter region
		m.down();
		count--;
		if (count < 0) {
			//m.up();		 leaving CR too early if this is left uncommented
			b.down();
		}

		// leave region
		m.up();
	}
	void up() {
		// enter region
		m.down();
		count++;
		if (count <= 0) {
			b.up();
			m.up();
		}
		else {
			m.up();
		}
		// left region with either the else of the end of the if statement
	}
	void print() {
		cout << count << " m" << m.get() << " b" << b.get() << endl;
	}
};

int main() {
	Csemaphore s(0);
	s.down();
	s.print();
	s.down();
	s.print();
	s.up();
	s.print();
	s.up();
	s.print();
	s.down();
	s.print();

}