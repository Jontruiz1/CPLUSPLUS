#include <iostream>
#include <fstream>


using namespace std;

int main() {
	ifstream file;
	long line;
	file.open("File1.txt");
	while (file >> line) {
		cout << line << endl;
	}
}