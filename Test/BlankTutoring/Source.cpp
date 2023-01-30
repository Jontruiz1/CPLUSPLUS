#include <iostream> 
<<<<<<< Updated upstream
#include <vector>
#include <fstream>
=======
#include <fstream>
#include <vector>
#include "statistics.h"
>>>>>>> Stashed changes

using namespace std;

// prototypes
double returnsDouble(int a, int b, double c);
int returnsInt();
void returnsNothing(vector<double> a, int b, double c, char d, float f, bool e);

// defintions
void returnsNothing(vector<double> a, int b, double c, char d, float f, bool e) {
	cout << "nothing";
}

int returnsInt() {
	return 1;
}


double returnsDouble(int a, int b, double c) {
	return 0;
}

// passing an array to a function
void changeArr(int arr[]) {
	arr[0] = 2;
	cout << arr[0] << endl;
}

void changeVect(vector<int>& arr) {
	arr[0] = 2;
	cout << arr[0] << endl;
}

int main() {
<<<<<<< Updated upstream
	int arr[] = { 1, 2, 3 };
	vector<int> barr = { 1, 2, 3 };


	changeArr(arr);
	cout << arr[0] << endl << endl;

	changeVect(barr);
	cout << barr[0];
=======
    

>>>>>>> Stashed changes
}

