#ifndef __POINT__
#define __POINT__
#include <iostream> 
#include <fstream>
#include <math.h>
using namespace std;
class Point
{
public:
	Point()
	{
		this->x = 0.0;
		this->y = 0.0;
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
	}
	Point(const Point& p)
	{
		this->x = p.x;
		this->y = p.y;
	}
	const Point& operator=(const Point& rhs)
	{
		if (this != &rhs) {
			x = rhs.x;
			y = rhs.y;
		}
		return *this;
	}
	bool operator==(const Point p) const
	{
		return (this->x == p.x && this->y == p.y);
	}
	bool operator!=(const Point p) const
	{
		return (this->x != p.x || this->y != p.y);
	}
	double distance(Point p) const
	{
		return sqrt((this->x - p.getX()) * (this->x - p.getX()) + (this->y - p.getY()) * (this->y - p.getY()));
	}
	double getX() const {
		return this->x;
	}
	double getY() const {
		return this->y;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	class CompareXCoordinate {
	public:
		bool operator()(const Point& p1, const Point& p2) const
		{
			return (p1.getX() < p2.getX());
		}
	};
	class CompareYCoordinate {
	public:
		bool operator()(const Point& p1, const Point& p2) const
		{
			return (p1.getY() < p2.getY());
		}
	};

private:
	double x;
	double y;
};

ifstream& operator>>(ifstream& in, Point& p) {
	double x;
	double y;

	in >> x;
	in >> y;
	p.setX(x);
	p.setY(y);
	return in;
}
ostream& operator<<(ostream& outfile, const Point& p)
{

	outfile << p.getX() << ' ' << p.getY();

	return outfile;
}
#endif 



