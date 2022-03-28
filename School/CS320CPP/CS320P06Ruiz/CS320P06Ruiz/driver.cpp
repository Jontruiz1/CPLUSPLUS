#include "track.h"

using namespace std;



int main() {
	
	int cars;
	int tracks;
	int curr = 0;
	

	cout << "Enter number of cars: ";
	cin >> cars;
	
	cout << "Enter number of holding tracks: ";
	cin >> tracks;

	Track problem(cars, tracks);
	cin >> problem;

	problem.findSolution();

	cout << problem;
	

}