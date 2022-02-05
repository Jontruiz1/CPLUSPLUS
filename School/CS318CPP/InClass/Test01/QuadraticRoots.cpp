#include <iostream>;
#include <string>;

using namespace std;

int main() {
	double a, b, c;
	double root1, root2;
	double discriminant;
	
	cout << "Program computes and prints the real roots of a quadratic polynomial: a*x^2 + b*x + c.\n\n";
	cout << "Enter three real numbers a, b, and c, separated by spaces : ";

	cin >> a >> b >> c;
	cout << "\n";

	if (a != 0) {
		discriminant = pow(b,2) - 4 * a * c;
		root1 = (-b + sqrt(discriminant)) / (2 * a);
		root2 = (-b - sqrt(discriminant)) / (2 * a);
		//which 
		if (b == 0) {
			printf("The quadratic polynomial %.1f*x^2 + %.1f ", a, c);
		}
		else if (c == 0) {
			printf("The quadratic polynomial %.1f*x^2 + %.1fx ", a,b);
		}
		else {
			printf("The quadratic polynomial %.1f*x^2 + %.1fx + %.1f ", a,b,c);
		}
		//real roots
		if (discriminant > 0) {
				printf("has two distinct real roots:\nroot1 = %.1f and root2 = %.1f", root1, root2);
		}
		//equal real roots
		else if (discriminant == 0) {
			printf("has two equal real roots:\nroot1 = root2 = %.1f",root1);
		}
		//complex roots
		else {
			cout << "has two complex roots.";
		}
	}
	else {
		//linear
		if (b != 0 && c != 0) {
			printf("The only root for the linear case %.1f*x + %.1f = 0 is: %.1f", b, c, -(c / b));
		}
		//inconsistent
		else if (c != 0 && b == 0) {
			printf("No roots for the constant function %.1f", c);
		}
		//degenerate
		else {
			cout << "No roots for the degenerate case of 0 = 0.";
		}
	}
}