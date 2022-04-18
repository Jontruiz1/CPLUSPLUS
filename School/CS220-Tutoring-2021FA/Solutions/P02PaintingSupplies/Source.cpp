//P02PaintingSupplies
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double wallHeight;
	double wallWidth;
	double wallArea;
	double gallonsPaintNeeded;
	int cansNeeded;

	const double SQ_FT_PER_GALLON = 350.0;
	const double GALLONS_PER_CAN = 1.0;

	// program heading / description
	cout << " *** P02: Painting Supplies ***\n" << endl;

	// Prompt user to input wall's height
	cout << " Enter wall height (feet): ";
	cin >> wallHeight;

	// Prompt user to input wall's width
	cout << " Enter wall width (feet): ";
	cin >> wallWidth;

	// Calculate results
	wallArea = wallHeight * wallWidth;  // wall's area
	gallonsPaintNeeded = wallArea / SQ_FT_PER_GALLON; // amount of paint in gallons
	cansNeeded = ceil(gallonsPaintNeeded / GALLONS_PER_CAN); // number of gallon cans rounded up

	// Output results
	cout << endl;
	cout << fixed << setprecision(2);
	cout << " Wall area: " << wallArea << " square feet" << endl;
	cout << " Paint needed: " << gallonsPaintNeeded << " gallons" << endl;
	cout << " Cans needed: " << cansNeeded << " can(s)" << endl;

	return 0;
}