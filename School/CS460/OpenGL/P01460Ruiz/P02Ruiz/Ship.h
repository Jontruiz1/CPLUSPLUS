#pragma once
#if !defined SHIP_H
#define SHIP_H

/*

	Simplified space ship, can be used in Flybys, flight simulator and other applications
	Ship has a position in space, an orientation, and speed. Position is a Point. Orientation
	is given by 3 unit vectors 1 (Forward) - the vector along which the ship is moving, (2) Up,
	the vector perpendicular to the forst that adescribes which way is up if you were sitting in the ship
	(3) Right, which is really just the cross product of forward and up that is just there to simplify 
	calculations. Speed of my ship is simply the distance that the ship moves each time fly() is called

	Ship()				Initialize ship that is located at the oriin, traveling in the negative z direction
						(i.e., <0, 0, -1>, up <0, 1, 0> making right <1, 0, 0,> and an initial speed of 0.01
	getPosition()		Return the ships current position
	getDirection()		Return the ships current direction
	getVertical()		Return the ships current up vector
	teleport()			Move the ship to an absolute position, keeping the orientation and speed
	getSpeed()			Return the ships current

	pitch(theta)		Reorient the ship so that it is rising theta radians, technically this means
						rotate forwards and up theta radians around right
	roll(theta)			Rotate up and right theta radians around forward
	yaw(theta)			Rotate forward and right theta radians around up

	getSpeed()			Returns the current speed
	setSpeed(s)			Sets the current speed
*/

#include "Geometry.h"
class Ship {
private:
	double speed;
	Point position;
	Vector forward, right, up;
public:
	Ship(Point initialPosition = Point(0, 0, 0));
	Point getPosition() {
		return position;
	}
	Vector getDirection() {
		return forward;
	}
	Vector getVertical() {
		return up;
	}
	Vector getSpeed() {
		return speed;
	}
	void teleport(Point newPos) {
		position = newPos;
	}
	void fly() { position += (speed * forward); }
	void setSpeed(double s) { speed = s; }

	void pitch(double angle);
	void roll(double angle);
	void yaw(double angle);
};

inline Ship::Ship(Point initialPosition) : position(initialPosition), forward(0, 0, -1), up(0,1,0), right(1,0,0), speed(0.01) {};
inline void Ship::pitch(double angle) {
	forward = unit(forward * cos(angle) + up * sin(angle));
	up = right.cross(forward);
}
inline void Ship::roll(double angle) {
	right = unit(forward * cos(angle) + up * sin(angle));
	up = right.cross(forward);
}

inline void Ship::yaw(double angle) {
	right = unit( right * cos(angle) + forward * sin(angle));
	forward = up.cross(right);
}

#endif