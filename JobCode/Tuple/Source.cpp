#include <iostream>
#include <time.h>
#include <stdlib.h>

int main() {

	srand(time(NULL));
	int x, y, z;
	for (int i = 0; i < 50; ++i) {
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;
		z = rand() % 100 + 1;

		std::cout << "{" << x << ", " << y << ", " << z << "}, ";
	}


}