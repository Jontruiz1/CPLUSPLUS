#include <string>
using namespace std;

class City {

public:
	City() : cityName("Null"), x(0), y(0) {};
	City(string c, int xc, int yc) : cityName(c), x(xc), y(yc) {};

	void print(ostream& out) const {
		out << cityName << " " << x << " " << y << endl;
	}
private:
	string cityName;
	int x;
	int y;
};

ostream& operator<<(ostream& out, const City& rhs) {
	rhs.print(out);
	return out;
}