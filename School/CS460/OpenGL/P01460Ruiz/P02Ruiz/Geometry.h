#pragma once
#if !defined GEOMETRY_H
#define GEOMETRY_H
#include <cmath>

//Classes and utilities for 3-D points, vectors, planes, and rays
const double EPSILON = 0.000001;

inline bool equal(double x, double y) {
	return fabs(x - y) <= EPSILON;
}

class Point;
class Vector;
class Plane;
class Ray;

/*
class for vectors
	v.i, v.j, v.k			components of a vector
	Vector(i, j, k)			Construct a vector from supplied components
	Vector(p)				Construct a vector from a single point
	u + v, u += v			Vector addition
	u - v, u -= v			Vector subtraction
	-v						<0 0 0> - v
	u.dot(v)				Dot product of u and v
	u.cross(v)				Cross product of u and v
	u * c, c * v, v *= c	Multiplicatino of a vector by a scalar
	v / c, v /= c			Division of a vector
	v.magnitude()			The length of v
	unit(v)					The vector of length 1 in the direction of v
	normalize(v)			Changes v to unit(v)
	cosine(u, v)			The cosine of the angle between u and v
	u.isPerpendicular(v)	Whether u is ALMOST perpendicular to v
	u.isParallel(v)			Wheter u is ALMOST parallel to v
	u.projectOnto(v)		The projection of u onto v
	u.reflectionAbout(v)	The mirror image of u over v	
*/

class Vector {
public:
	double i, j, k;

	Vector(double i = 0, double j = 0, double k = 0) : i(i), j(j), k(k) {}
	Vector(Point p);

	//Addition
	Vector& operator+=(Vector& rhs) {
		i += rhs.i;
		j += rhs.j;
		k += rhs.k;
		return *this;
	}
	Vector operator+(Vector rhs) {
		return Vector(i + rhs.i, j + rhs.j, k + rhs.k);
	}

	//Subtraction
	Vector operator-(Vector& rhs) {
		return Vector(i - rhs.i, j - rhs.j, k - rhs.k);
	}
	Vector& operator-=(Vector& rhs) {
		i -= rhs.i;
		j -= rhs.j;
		k -= rhs.k;
		return *this;
	}

	//Multiplication
	Vector operator*(double rhs) { return Vector(i * rhs, j * rhs, k * rhs); }
	friend Vector operator*(double lhs, Vector rhs) { return (lhs * rhs); }
	Vector& operator*=(Vector& rhs) {
		i *= rhs.i;
		j *= rhs.j;
		k *= rhs.k;
		return *this;
	}

	//Division
	Vector operator/(double rhs) {
		return Vector(i / rhs, j / rhs, k / rhs);
	}
	Vector& operator/=(double rhs) {
		i /= rhs;
		j /= rhs;
		k /= rhs;
		return *this;
	}

	double dot(Vector v) {
		return (i * v.i + j * v.j + k * v.k);
	}
	Vector cross(Vector);
	double magnitude() {
		return sqrt(this->dot(*this));
	}
	friend Vector unit(Vector v) {
		return v / v.magnitude();
	}
	friend void normalize(Vector& v) {
		v /= v.magnitude();
	}
	friend double cosine(Vector u, Vector v) {
		return (unit(u).dot(v));
	}
	bool isPerpendicular(Vector v) {
		return equal(this->dot(v), 0);
	}
	bool isParallel(Vector v) {
		return equal(cosine(*this, v), 1.0);
	}
	Vector projectionOnto(Vector v) {
		return this->dot(unit(v)) * unit(v);
	}
	Vector reflectionAbout(Vector v) {
		return 2 * projectionOnto(v) - *this;
	}
};

/*
	Class for 3-D Points
	x, y, z					Coordinates
	p + v, p += v			Add a point to a vector
	p - q					Vector from q to p
	p.distanceTo(q)			Distance from p to q
	p.distanceTo(P)			distance between p and the plane P
*/


class Point {
public:
	double x, y, z;

	Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
	Point& operator+=(Vector v) {
		x += v.i;
		y += v.j;
		z += v.k;
		return *this;
	}
	Point operator+(Vector v) {
		return Point(x + v.i, y + v.j, z + v.k);
	}
	Vector operator-(Point q) {
		return Vector(x - q.x, y - q.y, z - q.z);
	}
	double distanceTo(Point q) {
		return (q - *this).magnitude();
	}
	double distanceTo(Plane p);

};

/*

	Class for 3-D Planes
	p.a, p.b, p.c, p.d			Components(P is set of all points(x, y, z) for which 
								P.a * x + P.b * y + P.c * z + P.d = 0
	Plane(a, b, c, d)			Constructor
	Plane(p1, p2, p3)			Construct using three points that are on the plane. THIS COULD FAIl.
								Fails if points are co-linear. Right hand rule to orient normal
	P.normal()					The vector <P.a, P.b, P.c>
	




*/

class Plane {
public:
	double a, b, c, d;

	Plane(double a = 0, double b = 0, double c = 0, double d = 0) : a(a), b(b), c(c), d(d) {}
	Plane(Point p1, Point p2, Point p3);
	Vector normal() {
		return Vector(a, b, c);
	}
};

/*

	Class for 3-D Rays
	Point origin, Vector direction				Components
	Ray(origin, direction)
	r(u)										The point on r at distance u * |r.direction| from r.origin


*/
class Ray{
public:
	Point origin;
	Vector direction;

	Ray(Point origin, Vector direction) : origin(origin), direction(direction) {};
	Point operator()(double u) {
		return (origin + (u * direction));
	}
};

inline Vector::Vector(Point p) : i(p.x), j(p.y), k(p.z) {}
inline Vector Vector::cross(Vector v) {

	return Vector(j * v.k - k * v.j, k * v.i * v.k, i * v.j - j * v.i);
}
inline double Point::distanceTo(Plane p) {
	return (fabs(p.a * x + p.b * y + p.c * z + p.d) / p.normal().magnitude());
}
inline Plane::Plane(Point p1, Point p2, Point p3) {
	Vector n = (p2 - p1).cross(p3 - p1);
	a = n.i;
	b = n.j;
	c = n.k;
	d = -(Vector(p1).dot(n));
}

#endif