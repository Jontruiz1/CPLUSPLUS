#include <iostream>
#include <fstream>

enum TOKENS {
	INCREMENT = '+', 
	DECREMENT = '-', 
	SHIFT_LEFT = '<', 
	SHIFT_RIGHT = '>', 
	OUTPUT = '.', 
	INPUT = ',', 
	OPEN_LOOP = '[', 
	CLOSE_LOOP = ']'
};


int main() {
	using std::cout;
	std::ifstream file;
	std::string fileName;
	cout << "Enter a source file to interpret: ";
	std::cin >> fileName;
	file.open(fileName);
	if (!file) {
		cout << "File not found";
	}
	else{ 
		while (!file.eof()) {
		}
	}
}